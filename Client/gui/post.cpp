#include "post.h"
#include "ui_post.h"
#include <QMessageBox>

Post::Post(QWidget *parent,const char* author, const char* date, const char* content,const char* group,bool del,Client* client) :
    QWidget(parent),
    ui(new Ui::Post)
{
    m_client=client;
    ui->setupUi(this);
    ui->AuthorLabel->setText(author);
    ui->DateLabel->setText(date);
    ui->GroupLabel->setText(ui->GroupLabel->text()+group);
    ui->ContentLabel->setText(content);
    ui->deleteButton->setVisible(del);
}

Post::~Post()
{
    delete ui;
}

void Post::on_deleteButton_clicked()
{
    json_t* message = json_object();

    json_object_set(message, "MSG", json_string("DELETEPOST"));
    json_object_set(message, "Username", json_string(ui->AuthorLabel->text().toStdString().c_str()));
    json_object_set(message, "Text", json_string(ui->ContentLabel->toPlainText().toStdString().c_str()));

    if ( Communication::sendMessage(m_client->getSocket(),message) == -1)
    {
        ::close(m_client->getSocket());
        QMessageBox::critical( this, windowTitle(),
                                                                        tr("Connection with server broken...\n"),
                                                                        QMessageBox::Ok);
        QApplication::quit();
    }
    message = Communication::recvMessage(m_client->getSocket());
    if (message == NULL)
    {
        ::close(m_client->getSocket());
        QMessageBox::critical( this, "login",
                                                                        tr("Connection with server broken...\n"),
                                                                        QMessageBox::Ok);
        QApplication::quit();
    }


    if (json_equal(json_object_get(message,"MSG"),json_string("OK")))
    {
        QMessageBox::information( this, windowTitle(),
                                                                       "Deleted.\n"
                                                                       "" );
    }
    else
        QMessageBox::warning(this, tr(json_string_value(json_object_get(message,"Error"))),
                             QString(json_string_value(json_object_get(message,"Error"))),
                             QMessageBox::Ok);
    this->deleteLater();
}
