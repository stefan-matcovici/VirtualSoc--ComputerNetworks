#pragma once
#include "Server/Structs.h"     /* for ThreadArgs */
#include "Command/Command.h"    /* for Command instance */
#include <jansson.h>            /* for json_t */
#include <sqlite3.h>            /* for sqlite3 */
#include <map>                  /* for std::map */

extern std::map<pthread_t,ThreadArgs*> g_threads;

class Handler
{
private:
    sqlite3*                        m_databaseHandler;  /* Pointer to database which enables executing queries */
    json_t*                         m_received;         /* Received Json */
    json_t*                         m_sent;             /* Json to be sent */
    Command*                        m_command;          /* Command instance */

  public:
    /*! Constructor. Initializes members.
    */
    Handler();

    /*! Reads script file defined as SCRIPT and executes creating database sql statements
        \return -1 in case of error or 0 in case of succes
    */
    int createDbFileFromScript();

    /*! Compiles and executes one-line sql statements from script file
    \param[in] database handler
    \param[in] sql statement
    */
    void execLine(sqlite3 *db, const char *sql);

    /*! Opens database handle, receives messages, gets arguments and send to appropiate command method
    \return -1 in case of error or 0 in case of succes
    */
    void run();

    /*! Quits thread taking care of closing the socket, databaseHandler and erasing current thread from g_threads
    */
    void terminate();

    /*! Verifies if login is succesful and registers in g_threads or if user is already logged in
    */
    void verifyLogin();
};