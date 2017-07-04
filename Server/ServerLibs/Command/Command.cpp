#include "Command.h"
#include <string>
#include <cstring>

Command::Command()
{
}

std::string Command::checkRequest(std::string username)
{
    if (username.compare(g_threads[pthread_self()]->username)==0)
    {
        return "You cannot add yourself to any group";
    }

    return "";
}

std::string Command::checkLogin(std::string username,std::string password)
{
    if (username.size() == 0 || password.size() == 0)
    {
        return "Please enter password and username. You cannot have one of them blank";
    }

    return "";
}

std::string Command::checkRegister(std::string username,std::string password)
{
    if (username.size() == 0 || password.size() == 0)
    {
        return "Please enter password and username. You cannot have one of them blank";
    }

    return "";
}

commandType Command::parse(json_t* in,int time)
{
    m_name = json_string_value(json_object_get(in, "MSG"));

    if (m_name.compare("ACCEPT") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Username"));
        std::string group = json_string_value(json_object_get(in, "Group"));

        accept(username,group,time);

        return DeleteAndInsert;
    }
    else if (m_name.compare("ADMINACCEPT") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Username"));

        acceptAdmin(username,time);

        return DeleteAndInsert;
    }
    else if (m_name.compare("ACCEPTCONV") == 0)
    {
        int conv = json_integer_value(json_object_get(in, "Conversation"));

        acceptConv(conv,time);

        return DeleteAndInsert;
    }
    else if (m_name.compare("ADD") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Who"));
        int conv = json_integer_value(json_object_get(in, "Conversation"));

        addToConv(username,conv);

        return InsertDeleteUpdate;
    }
    else if (m_name.compare("DECLINE") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Username"));
        std::string group = json_string_value(json_object_get(in, "Group"));

        decline(username,group);

        return InsertDeleteUpdate;
    }
    else if (m_name.compare("DECLINECONV") == 0)
    {
        int conv = json_integer_value(json_object_get(in, "Conversation"));

        declineConv(conv);

        return InsertDeleteUpdate;
    }
    else if (m_name.compare("DELETE") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Username"));
        std::string group = json_string_value(json_object_get(in, "Group"));

        del(username,group);

        return InsertDeleteUpdate;
    }
    else if (m_name.compare("ADMINDECLINE") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Username"));

        deleteAdmin(username);

        return InsertDeleteUpdate;
    }
    else if (m_name.compare("DELETEPOST") == 0)
    {
        std::string text = json_string_value(json_object_get(in, "Text"));
        std::string username = json_string_value(json_object_get(in, "Username"));


        deletePost(username,text);

        return InsertDeleteUpdate;
    }
    else if (m_name.compare("ADMINDEL") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Username"));

        deleteUser(username);

        return InsertDeleteUpdate;
    }
    else if (m_name.compare("LOGIN") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Username"));
        std::string password = json_string_value(json_object_get(in, "Password"));

        m_errMessage = checkLogin(username,password);
        if ( m_errMessage.size() == 0)
        {
            loginUser(username,password);
            return Select;
        }
        else
        {
            return Error;
        }
    }
    else if (m_name.compare("REGISTER") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Username"));
        std::string password = json_string_value(json_object_get(in, "Password"));

        m_errMessage = checkRegister(username,password);
        if ( m_errMessage.size() == 0)
        {
            registerUser(username,password,time);
            return InsertAndInsert;
        }
        else
        {
            return Error;
        }
    }
    else if (m_name.compare("FINGER") == 0)
    {
        std::string group = json_string_value(json_object_get(in, "Group"));
        if (group.compare("All") == 0)
            fingerAll();
        else
            fingerGroup(group);

        return Select;
    }
    else if (m_name.compare("GET") == 0)
    {
        if (json_is_string(json_object_get(in,"Group")))
        {
            std::string group = json_string_value(json_object_get(in, "Group"));
            if (group.compare("Admins")==0)
                getAdmins();
            else
                getGroup(group);
        }
        else
        {
            if (json_is_string(json_object_get(in,"What")))
            {
                std::string what = json_string_value(json_object_get(in, "What"));
                if (what.compare("Conversations")==0)
                    getConversations();
                if (what.compare("Buddies")==0)
                {
                    int conv = json_integer_value(json_object_get(in, "Conversation"));
                    getBuddies(conv);
                }
                if (what.compare("Messages")==0)
                {
                    int conv = json_integer_value(json_object_get(in, "Conversation"));
                    getMessages(conv);
                }
            }
            else
            {
                if (json_is_string(json_object_get(in,"Username")))
                {
                    std::string user = json_string_value(json_object_get(in, "Username"));
                    getUser(user);
                }
                else
                    getMe();
            }
        }

        return Select;
    }
    else if (m_name.compare("POST") == 0)
    {
        std::string group = json_string_value(json_object_get(in, "Group"));
        std::string content = json_string_value(json_object_get(in, "Content"));

        post(content,group);

        return InsertDeleteUpdate;
    }
    else if (m_name.compare("REQUEST") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Username"));
        std::string group = json_string_value(json_object_get(in, "Group"));

        m_errMessage = checkRequest(username);
        if ( m_errMessage.size() == 0)
        {
            request(username,group);
            return InsertDeleteUpdate;
        }
        else
        {
            return Error;
        }
    }
    else if (m_name.compare("GETPROFILE") == 0)
    {
        std::string username;
        if (json_string_value(json_object_get(in, "Username"))==NULL)
            username="";
        else
            username= json_string_value(json_object_get(in, "Username"));

        getProfile(username);

        return Select;
    }
    else if (m_name.compare("UPDATEPROFILE") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Username"));
        std::string password = json_string_value(json_object_get(in, "Password"));
        std::string name = json_string_value(json_object_get(in, "Name"));
        std::string surname = json_string_value(json_object_get(in, "Surname"));
        std::string words = json_string_value(json_object_get(in, "Words"));
        std::string type = json_string_value(json_object_get(in, "Type"));
        int age = json_integer_value(json_object_get(in, "Age"));

        if (time==0)
            updateProfile(name,surname,age,words,type);
        else
            updateUser(username,password);

        return InsertAndInsert;
    }
    else if (m_name.compare("ADMINGET") == 0)
    {
        std::string user = json_string_value(json_object_get(in, "Username"));
        getAdminUser(user);

        return Select;
    }
    else if (m_name.compare("ADMINREGISTER") == 0)
    {
        std::string username = json_string_value(json_object_get(in, "Username"));
        std::string password = json_string_value(json_object_get(in, "Password"));
        std::string message = json_string_value(json_object_get(in, "Message"));

        registerAdmin(username,password,message);

        return InsertDeleteUpdate;
    }
    else if (m_name.compare("SENDMESSAGE") == 0)
    {
        std::string message = json_string_value(json_object_get(in, "Message"));
        int conv = json_integer_value(json_object_get(in, "Conversation"));

        sendMessage(conv,message);

        return InsertDeleteUpdate;
    }
    else if (m_name.compare("NEWCONV") == 0)
    {
        std::string name = json_string_value(json_object_get(in, "Name"));
        
        newConv(name,time);

        return InsertAndInsert;
    }
    else if (m_name.compare("LOGOUT") == 0)
    {
        return Nothing;
    }
    else if (m_name.compare("LEAVE") == 0)
    {
        int conv = json_integer_value(json_object_get(in, "Conversation"));

        leaveConv(conv);

        return InsertDeleteUpdate;
    }

    return Error;
}

void Command::accept(std::string username,std::string group,int time)
{
    switch(time)
    {
        case 0:
        {
            decline(username,group);
            break;            
        }
        case 1:
        {
            m_sql = "INSERT INTO groups VALUES (";
            m_sql += std::to_string(g_threads[pthread_self()]->user);
            m_sql += ", \'";
            m_sql += group;
            m_sql += "\', (SELECT id FROM users WHERE username = \'";
            m_sql += username;
            m_sql += "\') )";
            break;
        }
    }

}

void Command::acceptAdmin(std::string username,int time)
{
    switch(time)
    {
        case 0:
        {
            m_sql = "INSERT INTO users (username,password,type) VALUES (\'";
            m_sql += username;
            m_sql += "\',(SELECT password FROM admin WHERE username = \'";
            m_sql += username;
            m_sql += "\'),";
            m_sql += "\'admin\');";
            break;            
        }
        case 1:
        {
            deleteAdmin(username);
            break;
        }
    }
}

void Command::acceptConv(int id,int time)
{
     switch(time)
    {
    case 0:
    {
        m_sql = "INSERT INTO buddies VALUES (";
        m_sql += std::to_string(g_threads[pthread_self()]->user);
        m_sql += ",";
        m_sql += std::to_string(id);
        m_sql += ")";
        break;
    }
    case 1:
    {
        declineConv(id);
        break;
        }
    }
}

void Command::addToConv(std::string username, int id)
{
    m_sql = "INSERT INTO requests VALUES (";
    m_sql += std::to_string(g_threads[pthread_self()]->user);
    m_sql += ",";
    m_sql += std::to_string(id);
    m_sql += ",(SELECT id FROM users WHERE username =\'";
    m_sql += username;
    m_sql += "\'))";
}

void Command::decline(std::string username,std::string group)
{
    m_sql = "DELETE FROM requests WHERE id1=(SELECT id FROM users WHERE username=\'";
    m_sql += username;
    m_sql += "\') AND groupType = \'";
    m_sql += group;
    m_sql += "\' AND id2 = ";
    m_sql += std::to_string(g_threads[pthread_self()]->user);

}

void Command::declineConv(int id)
{
    m_sql = "DELETE FROM requests WHERE id2=";
    m_sql += std::to_string(g_threads[pthread_self()]->user);
    m_sql += " AND groupType=\'";
    m_sql += std::to_string(id);
    m_sql += "\'";
}

void Command::del(std::string username,std::string group)
{
    m_sql = "DELETE FROM groups WHERE id2=(SELECT id FROM users WHERE username=\'";
    m_sql += username;
    m_sql += "\') AND type = \'";
    m_sql += group;
    m_sql += "\' AND id1 = ";
    m_sql += std::to_string(g_threads[pthread_self()]->user);
}

void Command::deleteAdmin(std::string username)
{
    m_sql = "DELETE FROM admin WHERE username=\'";
    m_sql += username;
    m_sql += "\'";
}

void Command::deletePost(std::string username,std::string text)
{
    m_sql = "DELETE FROM posts WHERE id=(SELECT id FROM users WHERE username=\'";
    m_sql += username;
    m_sql += "\') AND content = \'";
    m_sql += text;
    m_sql += "\'";
}

void Command::deleteUser(std::string username)
{
    m_sql = "DELETE FROM users WHERE username=\'";
    m_sql += username;
    m_sql += "\'";
}

void Command::fingerAll()
{
    m_sql = "SELECT username FROM users WHERE type=\'usual\'";
}

void Command::fingerGroup(std::string group)
{
    if (group.compare("Requesting")==0)
    {
        m_sql = "SELECT username,groupType FROM users JOIN requests ON id1=id WHERE id2=";
        m_sql += std::to_string(g_threads[pthread_self()]->user);
    }
    else if (group.compare("Conversations")==0)
    {
        m_sql = "SELECT id,name FROM requests JOIN conversations ON requests.groupType=conversations.id WHERE id2=";
        m_sql += std::to_string(g_threads[pthread_self()]->user);
    }
    else
    {
        m_sql = "SELECT username FROM users JOIN groups ON id2=id WHERE id1=";
        m_sql += std::to_string(g_threads[pthread_self()]->user);
        m_sql += " AND groups.type=\'";
        m_sql += group;
        m_sql += "\';";
    }   
}

void Command::getAdminUser(std::string username)
{
    m_sql = "SELECT username,content,date,posts.type FROM users,posts WHERE users.id=posts.id AND username=\'";
    m_sql += username;
    m_sql += "\'";
}

void Command::getAdmins()
{
    m_sql = "SELECT username,message FROM admin";
}

void Command::getAll()
{
    m_sql = "SELECT username,content,date,p.type FROM users,posts WHERE users.id=posts.id AND p.type=\'All\'";
}

void Command::getBuddies(int id)
{
    m_sql = "SELECT username FROM buddies JOIN users ON buddies.buddyId=users.id WHERE convId=";
    m_sql += std::to_string(id);
}

void Command::getConversations()
{
    m_sql = "SELECT * FROM conversations WHERE EXISTS(SELECT * FROM buddies WHERE convId=conversations.id AND buddyId=";
    m_sql += std::to_string(g_threads[pthread_self()]->user);
    m_sql += ")";
}

void Command::getGroup(std::string group)
{
    m_sql  = "SELECT username,content,date,p.type FROM users u ,posts p WHERE u.id=p.id AND p.type=\'";
    m_sql += group;
    m_sql += "\'";
    if (group.compare("All")!=0)
    { 
        m_sql += " AND ";
        m_sql += std::to_string(g_threads[pthread_self()]->user);
        m_sql += " IN (SELECT id2 FROM groups WHERE id1=u.id AND type=\'";
        m_sql += group;
        m_sql += "\' )";
    }
    m_sql += " ORDER BY 3 DESC";
}

void Command::getMe()
{
    m_sql = "SELECT username,content,date,posts.type FROM users,posts WHERE users.id=posts.id AND username=\'";
    m_sql += g_threads[pthread_self()]->username;
    m_sql += "\'";
    m_sql += " ORDER BY 3 DESC";
}

void Command::getMessages(int id)
{
    m_sql = "SELECT username,message FROM messages JOIN users ON userId=users.id WHERE convId=";
    m_sql += std::to_string(id);
}

void Command::getProfile(std::string username)
{
    m_sql = "SELECT password,username,age,name,surname,words,profiles.type FROM profiles JOIN users ON profiles.id=users.id ";
    if (username.size()==0)
    {
        m_sql += "WHERE profiles.id = ";
        m_sql += std::to_string(g_threads[pthread_self()]->user);
    }
    else
    {
        m_sql += "AND profiles.id=(SELECT id FROM users WHERE username=\'";
        m_sql += username;
        m_sql += "\') AND (profiles.type='public' OR EXISTS(SELECT * FROM groups WHERE id1=";
        m_sql += "(SELECT id FROM users WHERE username=\'";
        m_sql += username;
        m_sql += "\'";
        m_sql += ") AND id2=";
        m_sql += std::to_string(g_threads[pthread_self()]->user);
        m_sql += ") )";
    }
}

void Command::getUser(std::string username)
{
    m_sql = "SELECT username,content,date,posts.type FROM users,posts WHERE users.id=posts.id AND username=\'";
    m_sql += username;
    m_sql += "\' AND (posts.type=\'All\' OR EXISTS(SELECT * FROM groups WHERE type=posts.type AND id1=users.id AND id2=";
    m_sql += std::to_string(g_threads[pthread_self()]->user);
    m_sql += "))";
    m_sql += " ORDER BY 3 DESC";
}

void Command::leaveConv(int id)
{
    m_sql = "DELETE FROM buddies WHERE buddyId=";
    m_sql += std::to_string(g_threads[pthread_self()]->user);
    m_sql += " AND convId=";
    m_sql += std::to_string(id);
}

void Command::loginUser(std::string username, std::string password)
{
    m_sql = "SELECT * FROM users WHERE username=\'";
    m_sql += username;
    m_sql += "\' AND password=\'";
    m_sql += password;
    m_sql += "\';";
}

void Command::newConv(std::string name,int time)
{
    switch(time)
    {
        case 0:
        {
            m_sql = "INSERT INTO conversations (name,date) VALUES (\'";
            m_sql += name;
            m_sql += "\',date(\"now\"))";
            break;
        }
        case 1:
        {
            m_sql = "INSERT INTO buddies VALUES (";
            m_sql += std::to_string(g_threads[pthread_self()]->user);
            m_sql += ",(SELECT MAX(id) FROM conversations))";
            break;
        }
    }
}

void Command::post(std::string content,std::string group)
{
    m_sql = "INSERT INTO posts VALUES (";
    m_sql += std::to_string(g_threads[pthread_self()]->user);
    m_sql += ",\"";
    m_sql += content;
    m_sql += "\",\"";
    m_sql += group;
    m_sql += "\",datetime((SELECT strftime('%s','now')), 'unixepoch', 'localtime'))";
}

void Command::registerAdmin(std::string username,std::string password,std::string message)
{
    m_sql = "INSERT INTO admin VALUES (\'";
    m_sql += username;
    m_sql += "\', \'";
    m_sql += password;
    m_sql += "\', \'";
    m_sql += message;
    m_sql += "\')";
}

void Command::registerUser(std::string username, std::string password,int time)
{
    switch(time)
    {
        case 0:
        {
            m_sql = "INSERT INTO users (username,password,type) VALUES (\'";
            m_sql += username;
            m_sql += "\', \'";
            m_sql += password;
            m_sql += "\', \'usual\');";
            break;            
        }
        case 1:
        {
            std::string empty;
            std::string pri("private");
            setProfile(username,empty,empty,0,empty,pri);
            break;
        }
    }
}

void Command::request(std::string username,std::string group)
{
     m_sql = "INSERT INTO requests VALUES (";
     m_sql += std::to_string(g_threads[pthread_self()]->user);
     m_sql += ", \'";
     m_sql += group;
     m_sql += "\',(SELECT id FROM users WHERE username=\'";
     m_sql += username;
     m_sql += "\'))";
}

void Command::sendMessage(int id, std::string message)
{
    m_sql = "INSERT INTO messages VALUES(";
    m_sql += std::to_string(id);
    m_sql += ",";
    m_sql += std::to_string(g_threads[pthread_self()]->user);
    m_sql += ",\'";
    m_sql += message;
    m_sql += "\')";
}

void Command::setProfile(std::string username,std::string name,std::string surname,int age,std::string words,std::string type)
{
    m_sql = "INSERT INTO profiles VALUES (";
    m_sql += "(SELECT id FROM users WHERE username=\'";
    m_sql += username;
    m_sql += "\'),\'";
    m_sql += name;
    m_sql += "\',\'";
    m_sql += surname;
    m_sql += "\',";
    m_sql += std::to_string(age);
    m_sql += ",\'";
    m_sql += words;
    m_sql += "\',\'";
    m_sql += type;
    m_sql += "\')";
}

void Command::updateProfile(std::string name,std::string surname,int age,std::string words,std::string type)
{
    m_sql = "UPDATE profiles SET name=\'";
    m_sql += name;
    m_sql += "\',surname=\'";
    m_sql += surname;
    m_sql += "\',age=";
    m_sql += std::to_string(age);
    m_sql += ",words=\'";
    m_sql += words;
    m_sql += "\',type=\'";
    m_sql += type;
    m_sql += "\' WHERE id=";
    m_sql += std::to_string(g_threads[pthread_self()]->user);
}

void Command::updateUser(std::string username,std::string password)
{
    m_sql = "UPDATE users SET username=\'";
    m_sql += username;
    m_sql += "\',password=\'";
    m_sql += password;
    m_sql += "\' WHERE id=";
    m_sql += std::to_string(g_threads[pthread_self()]->user);
}

json_t* Command::error()
{
    json_t* responseJson = json_object();
    json_object_set(responseJson,"MSG",json_string("ERROR"));
    json_object_set(responseJson,"Error",json_string(m_errMessage.c_str()));

    m_errMessage.clear();

    return responseJson;
}

json_t* Command::insertDeleteExec(sqlite3* db)
{
    json_t* responseJson = json_object();
    int noColumns;
    m_errMessage = "Illegal action";
    sqlite3_stmt *stmt;

    //compiling query
    sqlite3_prepare_v2(db, m_sql.c_str(), strlen(m_sql.c_str()), &stmt, NULL);

    if (sqlite3_step(stmt) == SQLITE_DONE)
    {
        json_object_set(responseJson,"MSG",json_string("OK"));
    }
    else
    {
        json_object_set(responseJson, "MSG", json_string("ERROR"));
        json_object_set(responseJson, "Error", json_string(m_errMessage.c_str()));
        //json_object_set(responseJson, "Error", json_string(sqlite3_errmsg(db)));
    }

    sqlite3_finalize(stmt);

    m_errMessage.clear();

    return responseJson;
}

json_t* Command::selectExec(sqlite3* db)
{
    json_t* responseJson = json_object();
    json_t* data         = json_array();
    int  noColumns;
    int  error           = 0;
    m_errMessage = "Illegal action...";
    sqlite3_stmt *stmt;

    //compiling query
    sqlite3_prepare_v2(db, m_sql.c_str(), strlen(m_sql.c_str()), &stmt, NULL);

    //looping through results
    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
        if (error)
            break;

        noColumns = sqlite3_data_count(stmt);
        if (noColumns == 0)
        {
            error = 1;
            //errMessage = "Couldn't get number of columns";
            break;
        }

        json_t* row = json_object();
        if (row == NULL)
        {
            //errMessage = "Couldn't create json object";
            error = 1;
            break;
        }

        //add object to array of data acordingly with their type
        for (int i=0;i<noColumns;i++)
        {
            switch(sqlite3_column_type(stmt,i))
            {
                case SQLITE_INTEGER:
                    if ( (error = json_object_set(row,sqlite3_column_name(stmt,i),json_integer(sqlite3_column_int(stmt,i)))) == -1 );
                        //errMessage = "Couldn't create json object";
                break;
                case SQLITE_TEXT:
                    if ( (error = json_object_set(row,sqlite3_column_name(stmt,i),json_string((const char*)sqlite3_column_text(stmt,i)))) == -1 );
                        //errMessage = "Couldn't create json object";
                break;
            }
        }

        if (!error)
            if ( (error = json_array_append(data,row)) == -1);
                //errMessage = "Couldn't add to array";
    }

    sqlite3_finalize(stmt);

    if (error)
    {
        json_object_set(responseJson,"MSG",json_string("ERROR"));
        json_object_set(responseJson,"Error",json_string(m_errMessage.c_str()));
    }
    else
    {
        json_object_set(responseJson,"MSG",json_string("OK"));
        json_object_set(responseJson,"Data",data);
    }

    m_errMessage.clear();

    return responseJson;

}