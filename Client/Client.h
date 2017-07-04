#ifndef CLIENT_H
#define CLIENT_H

#include "../Server/ServerLibs/Communication/Communication.h"

class Client
{
private:
    unsigned int m_socket;
public:
    Client();

    int createTCPSocket(const char* serverIp, int serverPort);

    int composeAdminGetUserJson(json_t* json,const char* username);
    int composeAdminDeleteUserJson(json_t*,const char* username);
    int composeDeletePostJson(json_t*,const char* username,const char* text);

    int composeAdminAcceptJson(json_t* json,const char* username);
    int composeAdminDeclineJson(json_t* json, const char* username);

    int composeAcceptJson(json_t* json,const char* username,const char* group);
    int composeDeleteJson(json_t* json,const char* username,const char* group);
    int composeDeclineJson(json_t* json,const char* username,const char* group);

    int composeLoginJson(json_t* json,const char* username,const char* password);

    int composeFingerAllJson(json_t* json);
    int composeFingerGroupJson(json_t* json,const char* group);

    int composeGetAllJson(json_t* json);
    int composeGetGroupJson(json_t* json,const char* group);
    int composeGetUserJson(json_t* json,const char* username);
    int composeGetAdminsJson(json_t* json);

    int composeGetConversationsJson(json_t* json);
    int composeGetBuddiesJson(json_t* json,int convId);
    int composeFingerConvRequestsJson(json_t* json);
    int composeGetMessagesJson(json_t* json,int convId);

    int composeNewConvJson(json_t* json,const char* name);
    int composeAddToConvJson(json_t* json,int convId,const char* username);
    int composeAcceptConvJson(json_t* json,int convId);
    int composeDeclineConvJson(json_t*,int convId);
    int composeSendMessageJson(json_t* json,int convId, const char* message);

    int composeLogoutJson(json_t* json);

    int composeLeaveConvJson(json_t* json,int convId);
    int composeGetCurrentJson(json_t* json);


    int composeRegisterJson(json_t* json,const char* username,const char* password);
    int composeRegisterAdminJson(json_t* json,const char* username,const char* password,const char* message);

    int composeRequestJson(json_t* json,const char* username,const char* group);

    int composeProfileJson(json_t* json,const char* username=0);
    int composePostJson(json_t* json,const char* content, const char* group);

    int composeUpdateProfile(json_t* json,const char* username,const char* password,const char* name,const char* surname,int age,const char* words,const char* type);

    int getSocket();

    void terminate();
};

#endif // CLIENT_H
