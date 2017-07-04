#include "Server/Server.h" /* for Server class */

std::map<pthread_t,ThreadArgs*> g_threads; /* Shared map with info abaout each thread */

int main (int argc, char *argv[])
{
  unsigned int          client;
  Server                server;

  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
    exit(1);
  }
  
  if ( server.createTCPListeningSocket(atoi(argv[1])) == -1 )
    exit(1);
  
  while(1)
  {
    if ( (client = server.acceptTCPConnection()) == -1 )
      continue;

    if ( server.createThread(client) == -1)
      continue;
  }

  return 0;
}