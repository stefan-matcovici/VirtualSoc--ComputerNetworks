#pragma once

/*! Structure to store thread arguments
    \member threadId - id of thread
    \member clientSocket - corresponding clientSocket
    \member user - corresponding user id from database after loggin in
    \member username - correspinding username
*/
struct ThreadArgs
{
  int           threadId;
  unsigned int  clientSocket;
  unsigned int  user;
  const char*   username;
};

/*! Structure to store types of query to execute after parsing
    \member Select - select query
    \member InsertDeleteUpdate - insert, delete or update query
    \member DeleteAndInsert - delete and then insert
    \member InsertAndInsert - two inserts
    \member Nothing - no query to be executed
    \member Error - error
*/
enum commandType
{
    Select,
    InsertDeleteUpdate,
    DeleteAndInsert,
    InsertAndInsert,
    Nothing,
    Error
};