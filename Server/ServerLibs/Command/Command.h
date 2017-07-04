#pragma once
#include "Server/Structs.h"
#include <jansson.h>
#include <sqlite3.h>
#include <string>
#include <map>

extern std::map<pthread_t, ThreadArgs *> g_threads;

class Command
{

  private:
    std::string m_name;       /* Command's name' */
    std::string m_sql;        /* Query to be executed */
    std::string m_errMessage; /* Error message */

  public:
    /*! Constructor.
    */
    Command();

    /*! Parse received json and calls appropiate function to compose sql query.
    \param[in] received json
    \param[in] time called (when 2 or more queries must be executed)
    \return command to be executed
    */
    commandType parse(json_t *, int time = 0);

    /*! Check methods before executing query 
    \return empty string or error message in case of error
    */
    std::string checkLogin(std::string, std::string);
    std::string checkRegister(std::string, std::string);
    std::string checkRequest(std::string);

    /*! Methods that compose queries for execution
    */
    void accept(std::string, std::string, int);
    void acceptAdmin(std::string, int);
    void acceptConv(int, int);
    void addToConv(std::string, int);
    void decline(std::string, std::string);
    void declineConv(int);
    void del(std::string, std::string);
    void deleteAdmin(std::string username);
    void deletePost(std::string username, std::string text);
    void deleteUser(std::string username);
    void fingerAll();
    void fingerGroup(std::string group);
    void getAdminUser(std::string username);
    void getAdmins();
    void getAll();
    void getBuddies(int);
    void getConversations();
    void getGroup(std::string group);
    void getMe();
    void getMessages(int);
    void getProfile(std::string username);
    void getUser(std::string username);
    void leaveConv(int);
    void loginUser(std::string, std::string);
    void newConv(std::string username,int time);
    void post(std::string content, std::string username);
    void registerAdmin(std::string, std::string, std::string);
    void registerUser(std::string, std::string, int);
    void request(std::string username, std::string group);
    void sendMessage(int, std::string);
    void setProfile(std::string username, std::string name, std::string surname, int age, std::string words, std::string type);
    void updateProfile(std::string name, std::string surname, int age, std::string words, std::string type);
    void updateUser(std::string username,std::string password);

    /*! Composes an error json with m_errMessage in Message field
    \return resulting json
    */
    json_t *error();

    /*! Executes an insert, delete or update query
    \param[in] database handler
    \return resulting json with ok as MSG field or error message
    */
    json_t *insertDeleteExec(sqlite3 *db);

    /*! Executes a select query filling a json with resulting rows
    \param[in] database handler
    \return resulting json
    */
    json_t *selectExec(sqlite3 *db);
};