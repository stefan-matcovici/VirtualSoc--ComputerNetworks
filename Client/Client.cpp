#include "Client.h"

Client::Client()
{
}

int Client::composeAcceptJson(json_t* json,const char* username,const char* group)
{
    json_object_set(json, "MSG", json_string("ACCEPT"));
    json_object_set(json, "Username", json_string(username));
    json_object_set(json, "Group", json_string(group));

    return 0;
}

int Client::composeDeleteJson(json_t* json,const char* username,const char* group)
{
    json_object_set(json, "MSG", json_string("DELETE"));
    json_object_set(json, "Username", json_string(username));
    json_object_set(json, "Group", json_string(group));

    return 0;
}

int Client::composeDeclineJson(json_t* json,const char* username,const char* group)
{
    json_object_set(json, "MSG", json_string("DECLINE"));
    json_object_set(json, "Username", json_string(username));
    json_object_set(json, "Group", json_string(group));

    return 0;
}

int Client::composeLeaveConvJson(json_t* json,int convId)
{
    json_object_set(json, "MSG", json_string("LEAVE"));
    json_object_set(json, "Conversation", json_integer(convId));

    return 0;
}

int Client::composeLoginJson(json_t* json,const char* username,const char* password)
{
    json_object_set(json, "MSG", json_string("LOGIN")) ;
    json_object_set(json, "Username", json_string(username));
    json_object_set(json, "Password", json_string(password));

    return 0;
}

int Client::composeGetCurrentJson(json_t* json)
{
    json_object_set(json, "MSG", json_string("GET")) ;

    return 0;
}

int Client::composeRegisterJson(json_t* json,const char* username,const char* password)
{
    json_object_set(json, "MSG", json_string("REGISTER")) ;
    json_object_set(json, "Username", json_string(username));
    json_object_set(json, "Password", json_string(password));

    return 0;
}

int Client::composeRegisterAdminJson(json_t* json,const char* username,const char* password,const char* message)
{
    json_object_set(json, "MSG", json_string("ADMINREGISTER")) ;
    json_object_set(json, "Username", json_string(username));
    json_object_set(json, "Password", json_string(password));
    json_object_set(json, "Message", json_string(message));

    return 0;
}

int Client::composeAdminAcceptJson(json_t* json,const char* username)
{
    json_object_set(json, "MSG", json_string("ADMINACCEPT")) ;
    json_object_set(json, "Username", json_string(username));

    return 0;
}

int Client::composeAdminDeclineJson(json_t* json, const char* username)
{
    json_object_set(json, "MSG", json_string("ADMINDECLINE")) ;
    json_object_set(json, "Username", json_string(username));

    return 0;
}

int Client::composeFingerAllJson(json_t* json)
{
    json_object_set(json, "MSG", json_string("FINGER"));
    json_object_set(json, "Group", json_string("All"));

    return 0;
}

int Client::composeFingerGroupJson(json_t* json,const char* group)
{
    json_object_set(json, "MSG", json_string("FINGER"));
    json_object_set(json, "Group", json_string(group));

    return 0;
}

int Client::composeAdminGetUserJson(json_t* json,const char* username)
{
    json_object_set(json, "MSG", json_string("ADMINGET"));
    json_object_set(json, "Username", json_string(username));

    return 0;
}

int Client::composeAdminDeleteUserJson(json_t* json,const char* username)
{
    json_object_set(json, "MSG", json_string("ADMINDEL"));
    json_object_set(json, "Username", json_string(username));

    return 0;
}

int Client::composeDeletePostJson(json_t* json,const char* username,const char* text)
{
    json_object_set(json, "MSG", json_string("DELETEPOST"));
    json_object_set(json, "Username", json_string(username));
    json_object_set(json, "Text", json_string(text));

    return 0;
}


int Client::composeGetUserJson(json_t* json,const char* username)
{
    json_object_set(json, "MSG", json_string("GET"));
    json_object_set(json, "Username", json_string(username));

    return 0;
}

int Client::composeGetAllJson(json_t* json)
{
    json_object_set(json, "MSG", json_string("GET"));
    json_object_set(json, "Group", json_string("All"));

    return 0;
}

int Client::composeGetAdminsJson(json_t* json)
{
    json_object_set(json, "MSG", json_string("GET"));
    json_object_set(json, "Group", json_string("Admins"));

    return 0;
}

int Client::composeGetGroupJson(json_t* json,const char* group)
{
    json_object_set(json, "MSG", json_string("GET"));
    json_object_set(json, "Group", json_string(group));

    return 0;
}

int Client::composeSendMessageJson(json_t* json, int convId, const char* message)
{
    json_object_set(json, "MSG", json_string("SENDMESSAGE"));
    json_object_set(json, "Message", json_string(message));
    json_object_set(json, "Conversation", json_integer(convId));


    return 0;
}

int Client::composeGetConversationsJson(json_t* json)
{
    json_object_set(json, "MSG", json_string("GET"));
    json_object_set(json, "What", json_string("Conversations"));

    return 0;
}

int Client::composeGetBuddiesJson(json_t* json,int convId)
{
    json_object_set(json, "MSG", json_string("GET"));
    json_object_set(json, "What", json_string("Buddies"));
    json_object_set(json, "Conversation", json_integer(convId));

    return 0;
}

int Client::composeFingerConvRequestsJson(json_t* json)
{
    json_object_set(json, "MSG", json_string("FINGER"));
    json_object_set(json, "Group", json_string("Conversations"));

    return 0;
}

int Client::composeGetMessagesJson(json_t* json,int convId)
{
    json_object_set(json, "MSG", json_string("GET"));
    json_object_set(json, "What", json_string("Messages"));
    json_object_set(json, "Conversation", json_integer(convId));

    return 0;
}

int Client::composeNewConvJson(json_t* json,const char* name)
{
    json_object_set(json, "MSG", json_string("NEWCONV"));
    json_object_set(json, "Name", json_string(name));

    return 0;
}

int Client::composeAddToConvJson(json_t* json,int convId,const char* username)
{
    json_object_set(json, "MSG", json_string("ADD"));
    json_object_set(json, "Conversation", json_integer(convId));
    json_object_set(json, "Who", json_string(username));

    return 0;
}

int Client::composeAcceptConvJson(json_t* json,int convId)
{
    json_object_set(json, "MSG", json_string("ACCEPTCONV"));
    json_object_set(json, "Conversation", json_integer(convId));

    return 0;
}

int Client::composeRequestJson(json_t* json,const char* username,const char* group)
{
    json_object_set(json, "MSG", json_string("REQUEST"));
    json_object_set(json, "Username", json_string(username));
    json_object_set(json, "Group", json_string(group));

    return 0;
}

int Client::composeProfileJson(json_t* json,const char* username)
{
    json_object_set(json, "MSG", json_string("GETPROFILE"));
    json_object_set(json, "Username", json_string(username));

    return 0;
}

int Client::composeDeclineConvJson(json_t* json,int convId)
{
    json_object_set(json, "MSG", json_string("DECLINECONV"));
    json_object_set(json, "Conversation", json_integer(convId));

    return 0;
}

int Client::composeLogoutJson(json_t* json)
{
    json_object_set(json, "MSG", json_string("LOGOUT"));

    return 0;
}

int Client::composePostJson(json_t* json, const char* content, const char* group)
{
    json_object_set(json, "MSG", json_string("POST"));
    json_object_set(json, "Content", json_string(content));
    json_object_set(json, "Group", json_string(group));

    return 0;
}


int Client::composeUpdateProfile(json_t* json,const char* username,const char* password,const char* name,const char* surname,int age,const char* words,const char* type)
{
    json_object_set(json, "MSG", json_string("UPDATEPROFILE"));
    json_object_set(json, "Username", json_string(username));
    json_object_set(json, "Password", json_string(password));
    json_object_set(json, "Name", json_string(name));
    json_object_set(json, "Surname", json_string(surname));
    json_object_set(json, "Age", json_integer(age));
    json_object_set(json, "Words", json_string(words));
    json_object_set(json, "Type", json_string(type));

    return 0;
}

int Client::createTCPSocket(const char* serverIp, int serverPort)
{
    struct sockaddr_in  server;
    int        socketDescriptor;

    if ((socketDescriptor = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        fprintf(stderr,"Error on creating socket: %s\n",strerror(errno));
        return -1;
    }

    server.sin_family       = AF_INET;
    server.sin_addr.s_addr  = inet_addr(serverIp);
    server.sin_port         = htons(serverPort);

    if (connect(socketDescriptor, (struct sockaddr *)&server, sizeof(struct sockaddr)) == -1)
    {
        fprintf(stderr,"Error connecting to server: %s\n",strerror(errno));
        return -1;
    }

    m_socket = socketDescriptor;

    return 0;
}

int Client::getSocket()
{
    return m_socket;
}
