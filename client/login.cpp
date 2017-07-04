#include "login.h"
#include "ui_login.h"
#include <QCloseEvent>
#include <QMessageBox>
#include "post.h"

login::login(QWidget *parent,Client* client) :
    QMainWindow(parent),
    m_ui(new Ui::login)
{
    m_ui->setupUi(this);
    m_client=client;

    int error = ::pipe(m_pipe);
    if (error)
    {
        QMessageBox::information( this, windowTitle(),
                                                                       "Couldn't create pipe.\n"
                                                                       );
    }
    ::close(STDERR_FILENO);
    ::dup2(m_pipe[1],STDERR_FILENO);

    connect(m_ui->UsersList, SIGNAL(itemClicked(QListWidgetItem*)),
                this, SLOT(on_UserListClicked(QListWidgetItem*)));

}

login::~login()
{
    delete m_ui;
}

void login::on_AdminBox_toggled(bool checked)
{
    m_ui->AdminText->setVisible(checked);
}

void login::on_LoginButton_clicked()
{
    json_t* message = json_object();
    m_client->composeLoginJson(message,m_ui->UsernameEdit->text().toStdString().c_str(),m_ui->PasswordEdit->text().toStdString().c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        if (json_array_size(json_object_get(message,"Data"))>0)
        {
            m_ui->UsernameEdit->clear();
            m_ui->PasswordEdit->clear();
            if (strcmp(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"type")),"usual")==0)
            {          
                this->hide();
                m_virtualSoc=new VirtualSoc(this,m_client,json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"username")));
                m_virtualSoc->show();
            }
            else if (strcmp(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),0),"type")),"admin")==0)
            {
                this->hide();
                m_admin=new Admin(this,m_client);
                m_admin->show();
            }
        }
        else
        {
            printError("Wrong user or password!");
        }
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));

}

void login::on_RegisterButton_clicked()
{
    json_t* message = json_object();
    if (m_ui->AdminBox->isChecked())
        m_client->composeRegisterAdminJson(message,m_ui->UsernameEdit_2->text().toStdString().c_str(),
                                           m_ui->PasswordEdit_2->text().toStdString().c_str(),
                                           m_ui->AdminText->toPlainText().toStdString().c_str());
    else
        m_client->composeRegisterJson(message,m_ui->UsernameEdit_2->text().toStdString().c_str(),m_ui->PasswordEdit_2->text().toStdString().c_str());


    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        if (m_ui->AdminBox->isChecked())
        {
            QMessageBox::information( this, windowTitle(),
                                                                           "Register successfully.\n"
                                                                            "You have to wait now for an admin to accept your request" );
            m_ui->AdminText->clear();
        }
        else
        {
            QMessageBox::information( this, windowTitle(),
                                                                       "Register successfully.\n"
                                                                       "You can login with entered credentials" );
        }

        m_ui->UsernameEdit_2->clear();
        m_ui->PasswordEdit_2->clear();
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));

}

void login::on_userRegisterTab_tabBarClicked(int index)
{
    if (index==1)
        m_ui->RefreshButton->click();
}

void login::on_RefreshButton_clicked()
{
    m_ui->UsersList->clear();

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

void login::on_UserListClicked(QListWidgetItem* item)
{
    json_t* message = json_object();

    m_ui->PostsList->clear();

    m_client->composeGetUserJson(message,item->text().toStdString().c_str());

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

        Post* myItem = new Post(this,username,content,date,group);
        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(120,250));
        m_ui->PostsList->addItem(item);
        m_ui->PostsList->setItemWidget(item,myItem);
    }
}

void login::closeEvent (QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn;
    resBtn = QMessageBox::question( this, windowTitle(),
                                                                tr("Are you sure?\n"),
                                                                QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                QMessageBox::Yes);

    if (resBtn != QMessageBox::Yes)
    {
        event->ignore();
    }
    else
    {
        ::close(m_client->getSocket());
        event->accept();
    }
}

void login::printError()
{
    char message[1000];
    int rd=::read(m_pipe[0],message,1000);
    message[rd]=0;

    QMessageBox::warning(this, tr("Error!"),
                            QString(message),
                            QMessageBox::Ok);
}

void login::printError(const char* message)
{
    QMessageBox::warning(this, tr("Error!"),
                            QString(message),
                         QMessageBox::Ok);
}

void login::terminate()
{
    ::close(m_client->getSocket());
    QMessageBox::critical( this, "login",
                                                                    tr("Connection with server broken...\n"),
                                                                    QMessageBox::Ok);
    QApplication::quit();
}
