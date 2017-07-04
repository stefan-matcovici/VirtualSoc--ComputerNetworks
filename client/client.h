#ifndef CLIENTGUI_H
#define CLIENTGUI_H

#include <QMainWindow>
#include "login.h"

namespace Ui {
class client;
}

class client : public QMainWindow
{
    Q_OBJECT

public:
    Client*     m_client;
    login*      m_loginWindow;

    explicit    client(QWidget *parent = 0);
    ~client();

private slots:
    void        on_ConnectButton_clicked();
    void        on_LocalButton_clicked();

private:
    int             m_pipe[2];
    Ui::client*     m_ui;

    void            printError();
};

#endif // CLIENTGUI_H
