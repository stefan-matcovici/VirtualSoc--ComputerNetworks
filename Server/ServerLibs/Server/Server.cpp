#include "Server.h"
#include "Handler/Handler.h" 

pthread_mutex_t g_lock = PTHREAD_MUTEX_INITIALIZER;

Server::Server()
{
    m_listenSocket = -1;
    g_lock = PTHREAD_MUTEX_INITIALIZER; 
}

Server::~Server()
{
}

unsigned int Server::acceptTCPConnection()
{
    int                 client;
    struct sockaddr_in  from;
    int                 length = sizeof(from);

    if ((client = accept(m_listenSocket, (struct sockaddr *)&from, (socklen_t *)&length)) < 0)
    {
        perror("Error on accept():");
        return -1;
    }

    return client;
}

int Server::createTCPListeningSocket(int serverPort)
{
    unsigned int        serverSocket;
    struct sockaddr_in  server;

    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error on socket():");
        return -1;
    }

    int on = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    bzero(&server, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(serverPort);

    if (bind(serverSocket, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
    {
        perror("Error on bind():");
        return -1;
    }
    
    if (listen(serverSocket, 2) == -1)
    {
        perror("Error on listen():");
        return -1;
    }

    printf("Waiting clients on port %d ...\n", serverPort);

    m_listenSocket = serverSocket;
    return 0;
}

int Server::createThread(unsigned int client)
{
    pthread_t   thread;
    ThreadArgs* threadArgs;

    if ((threadArgs = (ThreadArgs *)malloc(sizeof(ThreadArgs))) == NULL)
    {
        perror("Error allocating memory");
        return -1;
    }

    pthread_mutex_lock(&g_lock);

    threadArgs->clientSocket = client;
    threadArgs->user = -1;
    threadArgs->username = NULL;
    threadArgs->threadId     = g_threads.size();

    if (pthread_create(&thread, NULL, threadMain, NULL) != 0)
    {
        perror("Error on creating thread():");
        return -1;
    }

    g_threads.insert(std::make_pair(thread,threadArgs));

    pthread_mutex_unlock(&g_lock);

    return 0;
}

void* Server::threadMain(void *arg)
{
    pthread_detach(pthread_self());

    Handler h;
    h.run();
    h.terminate();
    
    return NULL;
}