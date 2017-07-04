#include "admin.h"
#include "ui_admin.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QMenu>


Admin::Admin(QWidget *parent,Client* c) :
    QMainWindow(parent),
    m_ui(new Ui::Admin)
{
    m_ui->setupUi(this);
    m_client = c;

    m_ui->UsersList->setContextMenuPolicy(Qt::CustomContextMenu);
    m_ui->PostsList->setContextMenuPolicy(Qt::CustomContextMenu);
    m_ui->RequestsList->setContextMenuPolicy(Qt::CustomContextMenu);

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

Admin::~Admin()
{
    delete m_ui;
}

void Admin::acceptAdmin()
{
    json_t* message = json_object();
    m_client->composeAdminAcceptJson(message,m_ui->RequestsList->currentItem()->text().toStdString().substr(0,m_ui->RequestsList->currentItem()->text().toStdString().find(":")).c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        QMessageBox::information( this, windowTitle(),
                                                                       "Accepted.\n"
                                                                       "" );
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));

    m_ui->RefreshButton->click();
}

void Admin::declineAdmin()
{
    json_t* message = json_object();
    m_client->composeAdminDeclineJson(message,m_ui->RequestsList->currentItem()->text().toStdString().substr(0,m_ui->RequestsList->currentItem()->text().toStdString().find(":")).c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        QMessageBox::information( this, windowTitle(),
                                                                       "Declined.\n"
                                                                       "" );
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));

    m_ui->RefreshButton->click();
}

void Admin::deleteUser()
{
    json_t* message = json_object();
    m_client->composeAdminDeleteUserJson(message,m_ui->UsersList->currentItem()->text().toStdString().c_str());

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        QMessageBox::information( this, windowTitle(),
                                                                       "Deleted.\n"
                                                                       "" );
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));

    m_ui->RefreshButton->click();
}

void Admin::on_LogoutButton_clicked()
{
    json_t* message = json_object();
    m_client->composeLogoutJson(message);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();

    destroy();
    parentWidget()->show();
}

void Admin::on_PostsList_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem* widget = m_ui->PostsList->itemAt(pos);
    if(widget != 0)
    {
        QPoint globalPos = m_ui->PostsList->mapToGlobal(pos);
        QMenu myMenu;
        myMenu.addAction("Delete Post", this, SLOT(deletePost()));
        myMenu.exec(globalPos);
    }
}

void Admin::on_RequestsList_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem* widget = m_ui->RequestsList->itemAt(pos);
    if(widget != 0)
    {
        QPoint globalPos = m_ui->RequestsList->mapToGlobal(pos);
        QMenu myMenu;
        myMenu.addAction("Accept admin", this, SLOT(acceptAdmin()));
        myMenu.addAction("Decline admin", this, SLOT(declineAdmin()));
        myMenu.exec(globalPos);
    }
}

void Admin::on_RefreshButton_clicked()
{
    m_ui->PostsList->clear();
    m_ui->UsersList->clear();
    m_ui->RequestsList->clear();

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

    m_client->composeGetAdminsJson(message);

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
        terminate();
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
        terminate();

    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        for (unsigned int i=0;i<json_array_size(json_object_get(message,"Data"));i++)
        {
            m_ui->RequestsList->addItem(QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"username")))
                                        +":" + QString(json_string_value(json_object_get(json_array_get(json_object_get(message,"Data"),i),"message"))) );
        }
    }
    else
        printError(json_string_value(json_object_get(message,"Error")));
}

void Admin::on_UsersList_customContextMenuRequested(const QPoint &pos)
{
    QListWidgetItem* widget = m_ui->UsersList->itemAt(pos);
    if(widget != 0)
    {
        QPoint globalPos = m_ui->UsersList->mapToGlobal(pos);

        QMenu myMenu;
        myMenu.addAction("Delete User", this, SLOT(deleteUser()));
        myMenu.exec(globalPos);
    }
}

void Admin::on_UsersList_itemClicked(QListWidgetItem *item)
{
    json_t* message = json_object();

    m_ui->PostsList->clear();

    m_client->composeAdminGetUserJson(message,item->text().toStdString().c_str());

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
        m_ui->PostsList->addItem(item);
        m_ui->PostsList->setItemWidget(item,myItem);
    }
}

void Admin::closeEvent (QCloseEvent *event)
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

void Admin::printError()
{
    char message[1000];
    int rd=::read(m_pipe[0],message,1000);
    message[rd]=0;

    QMessageBox::warning(this, tr("Error!"),
                            QString(message),
                            QMessageBox::Ok);
}

void Admin::printError(const char* message)
{
    QMessageBox::warning(this, tr("Error!"),
                         QString(message),
                         QMessageBox::Ok);
}

void Admin::terminate()
{
    ::close(m_client->getSocket());
    QMessageBox::critical( this, windowTitle(),
                                                                    tr("Connection with server broken...\n"),
                                                                    QMessageBox::Ok);
    QApplication::quit();
}
