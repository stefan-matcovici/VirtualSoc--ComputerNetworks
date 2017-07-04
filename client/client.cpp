#include "client.h"
#include "ui_client.h"
#include <QDebug>
#include <QMessageBox>

client::client(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::client)
{
    m_ui->setupUi(this);
    m_client=new Client;
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

client::~client()
{
    delete m_ui;
}

void client::on_ConnectButton_clicked()
{
    if (m_client->createTCPSocket(m_ui->IPEdit->text().toStdString().c_str(),m_ui->PortEdit->text().toInt()) == -1)
    {
        printError();
    }

    else
    {
        this->hide();
        m_loginWindow=new login(this,m_client);
        m_loginWindow->show();
    }

}

void client::on_LocalButton_clicked()
{
    m_ui->IPEdit->setText("127.0.0.1");
    m_ui->PortEdit->setText("6666");
}

void client::printError()
{
    char message[1000];
    int rd=::read(m_pipe[0],message,1000);
    message[rd]=0;

    QMessageBox::warning(this, tr("Error!"),
                            QString(message),
                            QMessageBox::Ok);
}
