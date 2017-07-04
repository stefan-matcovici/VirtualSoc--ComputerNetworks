#define DATABASE "userDatabase.db"
#define SCRIPT "script.sql"

#include "Handler.h"
#include "Communication/Communication.h"

#include <iostream>
#include <fstream>
using namespace std;

extern pthread_mutex_t g_lock;

Handler::Handler()
{
    m_command = new Command();
    m_received = NULL;
    m_sent = NULL;
    m_databaseHandler = NULL;
}

void Handler::run()
{
    if (access(DATABASE, 0) != 0)
    {
        printf("Couldn't find userDatabase.db. Trying to create new one from script: %s\n", strerror(errno));
        if (createDbFileFromScript() != 0)
        {
            fprintf(stderr, "Couldn't either create userDatabase.db from script file. Exiting server...\n");
            terminate();   
        }
        else
            printf("Created userDatabase.db from script file. Continuing serving clients using empty database\n");
    }

    if (sqlite3_open(DATABASE, &m_databaseHandler) != SQLITE_OK)
    {
        fprintf(stderr, "[Server]Error opening database: %s", sqlite3_errmsg(m_databaseHandler));
        terminate();
    }

    printf("[thread]- %d - Waiting for message...\n", g_threads[pthread_self()]->threadId);
    fflush(stdout);

    do
    {
        if ((m_received = Communication::recvMessage(g_threads[pthread_self()]->clientSocket)) == NULL)
            terminate();

        commandType c = m_command->parse(m_received);
        switch(c)
        {
            case Select:
            {
                m_sent = m_command->selectExec(m_databaseHandler);

                verifyLogin();
                
                if ( Communication::sendMessage(g_threads[pthread_self()]->clientSocket,m_sent) == -1)
                    terminate();
                
                break;
            }
            case InsertDeleteUpdate:
            {
                m_sent = m_command->insertDeleteExec(m_databaseHandler);
                if ( Communication::sendMessage(g_threads[pthread_self()]->clientSocket,m_sent) == -1)
                    terminate();
                break;
            }
            case DeleteAndInsert:
            {
                m_sent = m_command->insertDeleteExec(m_databaseHandler);
                
                std::string aux1 = json_string_value(json_object_get(m_sent,"MSG"));
                if (aux1.compare("OK")==0)
                {
                    m_command->parse(m_received,1);
                    m_sent = m_command->insertDeleteExec(m_databaseHandler);
                }
                if ( Communication::sendMessage(g_threads[pthread_self()]->clientSocket,m_sent) == -1)
                    terminate();
                break;
            }
            case InsertAndInsert:
            {
                m_sent = m_command->insertDeleteExec(m_databaseHandler);

                std::string aux1 = json_string_value(json_object_get(m_sent, "MSG"));
                if (aux1.compare("OK") == 0)
                {
                    m_command->parse(m_received, 1);
                    m_sent = m_command->insertDeleteExec(m_databaseHandler);
                }
                if (Communication::sendMessage(g_threads[pthread_self()]->clientSocket, m_sent) == -1)
                    terminate();
                break;
            }
            case Nothing:
            {
                printf("[thread]- %d - User %u logged out ...\n", g_threads[pthread_self()]->threadId, g_threads[pthread_self()]->user);

                pthread_mutex_lock(&g_lock);
                g_threads[pthread_self()]->user = -1;
                g_threads[pthread_self()]->username = NULL;
                pthread_mutex_unlock(&g_lock);
                break;
            }
            default:
                m_sent = m_command->error();
                if (Communication::sendMessage(g_threads[pthread_self()]->clientSocket, m_sent) == -1)
                    terminate();
                break;
        }

    } while (m_received != NULL);
}

void Handler::terminate()
{
    printf("[thread]- %d - Done conversation...\n", g_threads[pthread_self()]->threadId);
    sqlite3_close(m_databaseHandler);

    close((int)g_threads[pthread_self()]->clientSocket);

    pthread_mutex_lock(&g_lock);
    g_threads.erase(pthread_self());
    pthread_mutex_unlock(&g_lock);

    pthread_exit(0);
}

void Handler::verifyLogin()
{
    std::string aux2 = json_string_value(json_object_get(m_sent,"MSG"));
    std::string aux1 = json_string_value(json_object_get(m_received, "MSG"));

    if (aux1.compare("LOGIN") == 0 && aux2.compare("OK") == 0 && json_array_size(json_object_get(m_sent,"Data"))>0)
    {
        pthread_mutex_lock(&g_lock);
        for (std::map<pthread_t, ThreadArgs *>::iterator it = g_threads.begin(); it != g_threads.end(); it++)
        {
            if (it->second->username != NULL)
            {
                if (strcmp(it->second->username, json_string_value(json_object_get(json_array_get(json_object_get(m_sent, "Data"), 0), "username")))==0)
                {
                    printf("[thread]- %d - User %s already logged in ...\n", g_threads[pthread_self()]->threadId, it->second->username);
                    json_object_set(m_sent, "MSG", json_string("ERROR"));
                    json_object_set(m_sent, "Error", json_string("User already logged in"));
                    pthread_mutex_unlock(&g_lock);
                    return;
                }
            }
        }
        g_threads[pthread_self()]->user = json_integer_value(json_object_get(json_array_get(json_object_get(m_sent, "Data"), 0), "id"));
        g_threads[pthread_self()]->username = json_string_value(json_object_get(json_array_get(json_object_get(m_sent,"Data"),0),"username"));
        printf("[thread]- %d - User %u logged in ...\n", g_threads[pthread_self()]->threadId,g_threads[pthread_self()]->user);

        pthread_mutex_unlock(&g_lock);
    }
}

void Handler::execLine(sqlite3 *db,const char *sql)
{
  sqlite3_stmt *stmt;
  int rc=sqlite3_prepare(db,sql,-1,&stmt,0);
  if (rc != SQLITE_OK) 
  {
    fprintf(stderr, "sqlite3_prepare:%s\n",sqlite3_errmsg(db));
    return;
  }

  rc=sqlite3_step(stmt);
  if (rc == SQLITE_ROW) 
  {
    sqlite3_finalize(stmt);
    return;
  }
  sqlite3_finalize(stmt);
}

int Handler::createDbFileFromScript()
{
    sqlite3 *db;
    int rc = sqlite3_open(DATABASE, &db);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr,"%s\n", sqlite3_errmsg(db));
        return -1;
    }

    ifstream sql;
    sql.open(SCRIPT);
    if (!sql.is_open())
    {
        fprintf(stderr,"Error opening script file:%s\n",strerror(errno));
        return -1;
    }

    string line;
    while (sql.good())
    {
        getline(sql, line);
        if (!sql.eof())
        {
            execLine(db, line.c_str());
        }
    }

    sql.close();
    sqlite3_close(db);
    return 0;
}