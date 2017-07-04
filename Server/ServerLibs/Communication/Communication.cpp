#include "Communication.h"
#define DELIMITER '*'

Communication::Communication()
{

}

Communication::~Communication()
{

}

int Communication::sendMessage(int socket,json_t* json)
{
    char* 	sendBuffer = NULL;
    char* 	jsonBuffer = NULL;
    int 	jsonSize;

    //get char* from json_t
    jsonBuffer 	= json_dumps(json,JSON_PRESERVE_ORDER);
    if (jsonBuffer == NULL)
    {
        fprintf(stderr, "Error dumping json.");
        return -1;
    }
    jsonSize 	= strlen(jsonBuffer);

    //construct send buffer, adding a header with size in bytes of JSON and * terminator
    sendBuffer = (char*)calloc( (10 + jsonSize + 1), sizeof(char));
    sprintf(sendBuffer,"%d%c%s",jsonSize,DELIMITER,jsonBuffer);

    //send buffer through socket
    if ( (send(socket,sendBuffer,strlen(sendBuffer),0)) <= 0 )
    {
        free(sendBuffer);
        fprintf(stderr,"Error sending message:%s",strerror(errno));
        return -1;
    }
    //printf("%s\n",sendBuffer);

    free(sendBuffer);
    return 0;
}

json_t* Communication::recvMessage(int socket)
{
    json_t*     json;
    int 		jsonSize;				// size in bytes received or
    int 		recvSize;              
    int			headerSize;
    char 		header[11];
    char* 		buffer;
    char* 		delimiter;


    //peek header
    if ( (recvSize = recv(socket, header, 11, MSG_PEEK)) <= 0)
    {
        if (recvSize == -1)
            fprintf(stderr,"Error peeking header:%s\n",strerror(errno));
        return NULL;
    }


    //get size of JSON message
    delimiter 			= strchr(header,'*');
    headerSize 			= delimiter - header + 1;
    header[headerSize -1]	= 0;
    jsonSize = atoi(header);
    buffer = (char*)calloc(jsonSize + 1,sizeof(char));

    //parse header
    if ((recvSize 	= recv(socket, header, headerSize, 0)) <= 0)
    {
        if (recvSize == -1)
            fprintf(stderr,"Error receiving header:%s\n",strerror(errno));
        return NULL;
    }

    if ((recvSize 	= recv(socket, buffer, jsonSize, 0)) <= 0)
    {
        if (recvSize == -1)
            fprintf(stderr,"Error receiving full message:%s\n",strerror(errno));
        return NULL;
    }
    buffer[recvSize] = '\0';

    //printf("%s\n",buffer);

    //construct JSON
    json_error_t *err = NULL;
    json = json_loadb(buffer, jsonSize, JSON_PRESERVE_ORDER, err);
    
    if (json == NULL)
    {
        fprintf(stderr,"Error loading json:%s",err->text);
        return NULL;
    }

    return json;
}
