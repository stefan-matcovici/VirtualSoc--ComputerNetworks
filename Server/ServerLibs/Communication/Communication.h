#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), bind(), connect(), recv() and send() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */
#include <pthread.h>    /* for POSIX threads */
#include <errno.h>      /* for errno error codes */
#include <jansson.h>    /* for handling json */
#include <sqlite3.h>

class Communication
{
public:
    /*! Constructor
    */
    Communication();

    /*! Destructor.
    */
    ~Communication();

public:
    /*! Sends json through socket
    \param /in json to be send
    \return error or 0
    */
    static int     sendMessage(int socket,json_t* json);
    
    /*! Receives json from socket
    \param /out json to be filled with information
    \return error or 0
    */
    static json_t*     recvMessage(int socket);
};
#endif // COMMUNICATION
