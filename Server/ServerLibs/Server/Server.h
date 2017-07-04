#ifndef SERVER_H
#define SERVER_H

#include "Communication/Communication.h" /* for Communication class */
#include "Server/Structs.h"              /* for ThreadArgs */
#include <pthread.h>                     /* for POSIX threads */
#include <map>                           /* for std::map */


extern std::map<pthread_t,ThreadArgs*> g_threads; 

class Server
{
  private:
    unsigned int                           m_listenSocket; /* Socket to listen for new connections */

  public:
    /*! Constructor. Initializes members.
    */
    Server();

    /*! Destructor.
    */
    ~Server();

    /*! Waits and accepts client
    \param[in] server's listen socket
    \return -1 in case of error or accepted client's socket in case of succes
    */
    unsigned int acceptTCPConnection();

    /*! Creates socket for TCP server
    \param[in] port to be opened for server
    \return -1 in case of error or 0 in case of succes
    */
    int createTCPListeningSocket(int);

    /*! Creates thread for TCP server
    \param[in] socket descriptor of accepted client
    \return -1 in case of error or 0 in case of succes
    */
    int createThread(unsigned int);

    /*! Main program of a thread
    \param[in] arguments for thread
    \return TO BE DETERMINED
    */
    static void *threadMain(void*);
};

#endif // SERVER_H