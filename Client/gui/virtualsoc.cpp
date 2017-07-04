#include "virtualsoc.h"
#include "ui_virtualsoc.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QMenu>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <QTimer>

VirtualSoc::VirtualSoc(QWidget *parent, Client* client,const char* username) :
    QMainWindow(parent),
    m_ui(new Ui::VirtualSoc)
{
    m_client=client;
    m_ui->setupUi(this);
    setWindowTitle(QString(username)+"'s VirtualSoc");

    m_ui->GroupsCombo->addItem(QString("All"));
    m_ui->GroupsCombo->addItem(QString("Close Friends"));
    m_ui->GroupsCombo->addItem(QString("Colleagues"));
    m_ui->GroupsCombo->addItem(QString("Others"));
    m_ui->GroupsCombo->addItem(QString("Requesting"));

    m_ui->GroupPostCombo->addItem(QString("All"));
    m_ui->GroupPostCombo->addItem(QString("Close Friends"));
    m_ui->GroupPostCombo->addItem(QString("Colleagues"));
    m_ui->GroupPostCombo->addItem(QString("Others"));

    m_ui->PrivateCheck->setVisible(false);
    m_ui->PasswordEdit->setVisible(false);
    m_ui->PasswordLabel->setVisible(false);

    m_ui->UsersList->setContextMenuPolicy(Qt::CustomContextMenu);
    m_ui->RequestList->setContextMenuPolicy(Qt::CustomContextMenu);

    m_timer = new QTimer(this);
    QObject::connect(m_timer, SIGNAL(timeout()), this, SLOT(refreshMessages()));

    int error = ::pipe(m_pipe);
    if (error)
    {
        QMessageBox::information( this, windowTitle(),
                                                                       "Couldn't create pipe.\n"
                                                                       );
    }

    ::close(STDERR_FILENO);
    ::dup2(m_pipe[1],STDERR_FILENO);
}

VirtualSoc::~VirtualSoc()
{
    delete m_ui;
    delete m_timer;
}

void VirtualSoc::acceptConversation()
{
    json_t* message = json_object();
    m_client->composeAcceptConvJson(message,request[m_ui->RequestList->currentRow()]);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        QMessageBox::information( this, windowTitle(), "Conversation accepted.\n");
    else
        printError(json_string_value(json_object_get(message,"Error")));

    refreshMessages();
}

void VirtualSoc::acceptUser()
{
    json_t* message = json_object();
    std::string s =  m_ui->UsersList->currentItem()->text().toStdString();
    int pos = s.find(' ');
    m_client->composeAcceptJson(message, s.substr(0,pos).c_str(),s.substr(pos+10).c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        QMessageBox::information( this, windowTitle(), "Added.\n");

    else
        printError(json_string_value(json_object_get(message,"Error")));

    m_ui->GroupsCombo->activated(m_ui->GroupsCombo->currentText());
}

void VirtualSoc::addColleague()
{
    json_t* message = json_object();
    m_client->composeRequestJson(message, m_ui->UsersList->currentItem()->text().toStdString().c_str(),"Colleagues");

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        QMessageBox::information( this, windowTitle(), "Successfull request.\n");
    else
        printError(json_string_value(json_object_get(message,"Error")));
}

void VirtualSoc::addConvUser()
{
    const char* user = m_ui->UsersList->currentItem()->text().toStdString().c_str();
    json_t* message = json_object();
    m_client->composeAddToConvJson(message,active[m_ui->ConversationList->currentRow()], user);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        QMessageBox::information( this, windowTitle(), "Request sent.\n");
    else
        printError(json_string_value(json_object_get(message,"Error")));
}

void VirtualSoc::addFriend()
{
    json_t* message = json_object();
    m_client->composeRequestJson(message, m_ui->UsersList->currentItem()->text().toStdString().c_str(),"Close Friends");

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        QMessageBox::information( this, windowTitle(), "Successfull request.\n");
    else
        printError(json_string_value(json_object_get(message,"Error")));
}

void VirtualSoc::addOther()
{
    json_t* message = json_object();
    m_client->composeRequestJson(message, m_ui->UsersList->currentItem()->text().toStdString().c_str(),"Others");

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        QMessageBox::information( this, windowTitle(), "Successfull request.\n");
    else
        printError(json_string_value(json_object_get(message,"Error")));
}

void VirtualSoc::declineConversation()
{
    json_t* message = json_object();
    m_client->composeDeclineConvJson(message,request[m_ui->RequestList->currentRow()]);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        QMessageBox::information( this, windowTitle(), "Conversation declined.\n");
    else
        printError(json_string_value(json_object_get(message,"Error")));
}

void VirtualSoc::declineUser()
{
    json_t* message = json_object();
    std::string s =  m_ui->UsersList->currentItem()->text().toStdString();
    int pos = s.find(' ');
    m_client->composeDeclineJson(message, s.substr(0,pos).c_str(),s.substr(pos+10).c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        QMessageBox::information( this, windowTitle(), "Declined request.\n");
    else
        printError(json_string_value(json_object_get(message,"Error")));

    m_ui->GroupsCombo->activated(m_ui->GroupsCombo->currentText());
}

void VirtualSoc::deleteUser()
{
    json_t* message = json_object();
    m_client->composeDeleteJson(message, m_ui->UsersList->currentItem()->text().toStdString().c_str(),m_ui->GroupsCombo->currentText().toStdString().c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        QMessageBox::information( this, windowTitle(), "Successfully deleted.\n");
    else
        printError(json_string_value(json_object_get(message,"Error")));

    m_ui->GroupsCombo->activated(m_ui->GroupsCombo->currentText());
}

void VirtualSoc::refreshMessages()
{
    int selected = m_ui->ConversationList->currentRow();
    json_t* message=json_object();

    if (selected!=-1)
    {
        m_ui->MessageList->clear();
        selected = m_ui->ConversationList->currentRow();

        m_client->composeGetMessagesJson(message,active[m_ui->ConversationList->currentRow()]);

        if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
            terminate();

        message = Communication::recvMessage(m_client->getSocket());
        if (message == NULL)
            terminate();

        if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        {
            for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
            {
                m_ui->MessageList->addItem(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"username")))+
                                           ":"+
                                           QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"message"))));
            }
        }
        else
            printError(json_string_value(json_object_get(message,"Error")));

        m_ui->ConversationList->itemClicked(
                    m_ui->ConversationList->item(selected));
    }

    m_ui->RequestList->clear();
    m_ui->ConversationList->clear();
    active.clear();
    request.clear();

    message = json_object();
    m_client->composeGetConversationsJson(message);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
        {
            m_ui->ConversationList->addItem(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"name"))));
            active.push_back(json_integer_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"id")));
        }
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));

    if (selected != -1)
        m_ui->ConversationList->setCurrentRow(selected);


    m_client->composeFingerConvRequestsJson(message);
    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
        {
            m_ui->RequestList->addItem(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"name"))));
            request.push_back(json_integer_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"id")));
        }
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));

}

void VirtualSoc::userProfile()
{
    json_t* message = json_object();
    const char* user = m_ui->UsersList->currentItem()->text().toStdString().c_str();
    m_client->composeProfileJson(message,user);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        if (json_array_size(json_object_get(message,"Data"))>0)
        {
             m_ui->myProfileButton->setChecked(false);

            m_ui->PasswordEdit->setText(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"password"))));
            m_ui->AgeEdit->setText(QString::number(json_integer_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"age"))));
            m_ui->NameEdit->setText(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"name"))));
            m_ui->UsernameEdit->setText(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"username"))));
            m_ui->SurnameEdit->setText(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"surname"))));
            m_ui->WordsEdit->setText(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"words"))));
            m_ui->PrivateCheck->setChecked(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"type")))=="private");
        }
        else
        {
            QMessageBox::information( this, windowTitle(), "This user has a private profile. Sorry...\n");
            return;
        }
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));

    m_ui->PostsList_2->clear();
    m_client->composeGetUserJson(message,user);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
    {
        const char* username = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"username"));
        const char* content = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"date"));
        const char* date = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"content"));
        const char* group = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"type"));

        Post* myItem = new Post(this,username,content,date,group,false,m_client);
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(120,250));
        m_ui->PostsList_2->addItem(item);
        m_ui->PostsList_2->setItemWidget(item,myItem);
    }
}

void VirtualSoc::userPosts()
{
    m_ui->PostsList->clear();
    json_t* message=json_object();
    m_client->composeGetUserJson(message,m_ui->UsersList->currentItem()->text().toStdString().c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
    {
        const char* username = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"username"));
        const char* content = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"date"));
        const char* date = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"content"));
        const char* group = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"type"));

        Post* myItem = new Post(this,username,content,date,group,false,m_client);
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(120,250));
        m_ui->PostsList->addItem(item);
        m_ui->PostsList->setItemWidget(item,myItem);
    }
}

void VirtualSoc::on_BackButton_clicked()
{
    json_t* message = json_object();
    m_client->composeLogoutJson(message);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    destroy();
    parentWidget()->show();
}

void VirtualSoc::on_ConversationList_itemClicked(QListWidgetItem *item)
{
    item->setSelected(false);
    m_ui->MessageList->clear();
    json_t* message = json_object();
    m_client->composeGetMessagesJson(message,active[m_ui->ConversationList->currentRow()]);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
        {
            m_ui->MessageList->addItem(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"username")))+
                                       ":"+
                                       QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"message"))));
        }
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));

    m_ui->BuddyList->clear();
    m_client->composeGetBuddiesJson(message,active[m_ui->ConversationList->currentRow()]);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
        {
            m_ui->BuddyList->addItem(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"username"))));
        }
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));
}

void VirtualSoc::on_LeaveConvButton_clicked()
{
    json_t* message = json_object();
    m_client->composeLeaveConvJson(message,active[m_ui->ConversationList->currentRow()]);
    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        QMessageBox::information( this, windowTitle(),"Left current conversation.\n");
        m_ui->MessageEdit->clear();
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));
}

void VirtualSoc::on_NewConvButton_clicked()
{
    json_t* message = json_object();
    m_client->composeNewConvJson(message,m_ui->NewConvEdit->text().toStdString().c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        QMessageBox::information( this, windowTitle(),"Conversation started!\n");
        m_ui->NewConvEdit->clear();
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));
}

void VirtualSoc::on_PostButton_clicked()
{
    json_t* message = json_object();
    m_client->composePostJson(message,m_ui->NewPostEdit->toPlainText().toStdString().c_str(),m_ui->GroupPostCombo->currentText().toStdString().c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        QMessageBox::information( this, windowTitle(),"Successfull post.\n");
        m_ui->NewPostEdit->clear();
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));

    m_ui->GroupsCombo->activated(m_ui->GroupsCombo->currentText());
}

void VirtualSoc::on_RequestList_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem* widget = m_ui->RequestList->itemAt(pos);
    if(widget != 0)
    {
        QPoint globalPos = m_ui->RequestList->mapToGlobal(pos);

        QMenu myMenu;

        myMenu.addAction("Accept conversation", this, SLOT(acceptConversation()));
        myMenu.addAction("Decline conversation", this, SLOT(declineConversation()));

        myMenu.exec(globalPos);
    }
}

void VirtualSoc::on_SaveButton_clicked()
{
    json_t* message = json_object();
    const char* type;
    if (m_ui->PrivateCheck->isChecked())
        type="private";
    else
        type="public";
    m_client->composeUpdateProfile(message,m_ui->UsernameEdit->text().toStdString().c_str(),
                                   m_ui->PasswordEdit->text().toStdString().c_str(),
                                   m_ui->NameEdit->text().toStdString().c_str(),
                                   m_ui->SurnameEdit->text().toStdString().c_str(),
                                   m_ui->AgeEdit->text().toInt(),
                                   m_ui->WordsEdit->toPlainText().toStdString().c_str(),
                                   type);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        QMessageBox::information( this, windowTitle(),"Profile successfully updated.\n");
    else
        printError(json_string_value(json_object_get(message,"Error")));

}

void VirtualSoc::on_SendButton_clicked()
{
    json_t* message = json_object();
    m_client->composeSendMessageJson(message,active[m_ui->ConversationList->currentRow()],m_ui->MessageEdit->toPlainText().toStdString().c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        QMessageBox::information( this, windowTitle(),"Message sent.\n");
        m_ui->MessageEdit->clear();
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));
}

void VirtualSoc::on_ServicesTab_tabBarClicked(int index)
{
    if (index==2)
    {
        refreshMessages();
        m_timer->start(10000);
    }
    else
    {
        if (m_timer->isActive())
            m_timer->stop();

        if (index==0)
        {
            m_ui->GroupsCombo->activated("All");
        }
        else if(index==1)
        {
            m_ui->myProfileButton->toggled(true);
            m_ui->myProfileButton->setChecked(true);

        }

    }
}

void VirtualSoc::on_UsersList_customContextMenuRequested(const QPoint& pos)
{
    QListWidgetItem* widget = m_ui->UsersList->itemAt(pos);
    if(widget != 0)
    {
        QPoint globalPos = m_ui->UsersList->mapToGlobal(pos);

        QMenu myMenu;

        if (m_ui->GroupsCombo->currentText()=="All")
        {
            myMenu.addAction("Add to close friends", this, SLOT(addFriend()));
            myMenu.addAction("Add to colleagues", this, SLOT(addColleague()));
            myMenu.addAction("Add to others",this,SLOT(addOther()));
        }

        else if (m_ui->GroupsCombo->currentText()=="Requesting")
        {
            myMenu.addAction("Accept request",  this, SLOT(acceptUser()));
            myMenu.addAction("Decline request",  this, SLOT(declineUser()));
        }
        else
        {
            myMenu.addAction("Delete from current list",this, SLOT(deleteUser()));
        }

        if (m_ui->ServicesTab->tabText(m_ui->ServicesTab->currentIndex())=="Posts")
        {
            myMenu.addAction("View posts",this, SLOT(userPosts()));
        }
        else if (m_ui->ServicesTab->tabText(m_ui->ServicesTab->currentIndex())=="Profiles")
        {
            myMenu.addAction("View profile",this, SLOT(userProfile()));
        }
        else
        {
            myMenu.addAction("Add to current conversation",this, SLOT(addConvUser()));
        }

        myMenu.exec(globalPos);
    }
}

void VirtualSoc::on_myProfileButton_toggled(bool checked)
{
    m_ui->UsernameEdit->clear();
    m_ui->AgeEdit->clear();
    m_ui->NameEdit->clear();
    m_ui->SurnameEdit->clear();
    m_ui->WordsEdit->clear();

    m_ui->AgeEdit->setReadOnly(!checked);
    m_ui->NameEdit->setReadOnly(!checked);
    m_ui->SurnameEdit->setReadOnly(!checked);
    m_ui->WordsEdit->setReadOnly(!checked);

    m_ui->PasswordEdit->setVisible(checked);
    m_ui->PasswordLabel->setVisible(checked);
    m_ui->PrivateCheck->setVisible(checked);
    m_ui->SaveButton->setVisible(checked);

    if (checked)
    {
        json_t* message = json_object();
        m_client->composeProfileJson(message);

        if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
            terminate();
        message = Communication::recvMessage(m_client->getSocket());
        if (message == NULL)
            terminate();

        if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        {
            if (json_array_size(json_object_get(message,"Data"))>0)
            {
                m_ui->PasswordEdit->setText(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"password"))));
                m_ui->AgeEdit->setText(QString::number(json_integer_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"age"))));
                m_ui->NameEdit->setText(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"name"))));
                m_ui->UsernameEdit->setText(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"username"))));
                m_ui->SurnameEdit->setText(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"surname"))));
                m_ui->WordsEdit->setText(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"words"))));
                m_ui->PrivateCheck->setChecked(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"type")))=="private");
            }
        }
        else
            printError(json_string_value(json_object_get(message,"Error")));

        m_ui->PostsList_2->clear();

        m_client->composeGetCurrentJson(message);

        if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
            terminate();
        message = Communication::recvMessage(m_client->getSocket());
        if (message == NULL)
            terminate();

        for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
        {
            const char* username = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"username"));
            const char* content = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"date"));
            const char* date = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"content"));
            const char* group = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"type"));

            Post* myItem = new Post(this,username,content,date,group,true,m_client);
            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(QSize(120,250));
            m_ui->PostsList_2->addItem(item);
            m_ui->PostsList_2->setItemWidget(item,myItem);
        }
    }
}

void VirtualSoc::terminate()
{
    ::close(m_client->getSocket());
    QMessageBox::critical( this, "login",
                           tr("Connection with server broken...\n"),
                           QMessageBox::Ok);
    QApplication::quit();
}

void VirtualSoc::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn;
    resBtn = QMessageBox::question( this, windowTitle(),
                                    tr("Are you sure?\n"),
                                    QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                    QMessageBox::Yes);

    if (resBtn != QMessageBox::Yes) {
        event->ignore();
    } else {
        ::close(m_client->getSocket());
        event->accept();
    }
}

void VirtualSoc::printError()
{
    char message[1000];
    int rd=::read(m_pipe[0],message,1000);
    message[rd]=0;

    QMessageBox::warning(this, tr("Error!"),
                         QString(message),
                         QMessageBox::Ok);
}

void VirtualSoc::printError(const char* message)
{
    QMessageBox::warning(this, tr("Error!"),
                         QString(message),
                         QMessageBox::Ok);
}

void VirtualSoc::on_GroupsCombo_activated(const QString &arg1)
{
    json_t* message = json_object();
    m_ui->UsersList->clear();
    if (arg1=="All")
    {
        json_t* message = json_object();
        m_client->composeFingerAllJson(message);

        if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
            terminate();
        message = Communication::recvMessage(m_client->getSocket());
        if (message == NULL)
            terminate();


        if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        {
            for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
            {
                m_ui->UsersList->addItem(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"username"))));
            }
        }
        else
            printError(json_string_value(json_object_get(message,"Error")));
    }
    else if (arg1=="Requesting")
    {
        m_client->composeFingerGroupJson(message,arg1.toStdString().c_str());

        Communication::sendMessage(m_client->getSocket(),message);
        message = Communication::recvMessage(m_client->getSocket());

        if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        {
            for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
            {
                QString username = QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"username")));
                QString group= QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"groupType")));
                if (group.toStdString().compare("Close Friends")==0 || group.toStdString().compare("Colleagues")==0 || group.toStdString().compare("Others")==0 )
                    m_ui->UsersList->addItem(username+" requests " + group);
            }
        }
        else
            printError(json_string_value(json_object_get(message,"Error")));
    }
    else
    {
        m_client->composeFingerGroupJson(message,arg1.toStdString().c_str());

        if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
            terminate();
        message = Communication::recvMessage(m_client->getSocket());
        if (message == NULL)
            terminate();

        if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
        {
            for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
            {
                m_ui->UsersList->addItem(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"username"))));
            }
        }
        else
            printError(json_string_value(json_object_get(message,"Error")));
    }

    m_ui->PostsList->clear();
    if (arg1.compare("Requesting")==0)
        m_client->composeGetAllJson(message);
    else
        m_client->composeGetGroupJson(message,arg1.toStdString().c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
    {
        const char* username = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"username"));
        const char* content = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"date"));
        const char* date = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"content"));
        const char* group = json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"type"));

        Post* myItem = new Post(this,username,content,date,group,false,m_client);
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(120,250));
        m_ui->PostsList->addItem(item);
        m_ui->PostsList->setItemWidget(item,myItem);
    }
}
