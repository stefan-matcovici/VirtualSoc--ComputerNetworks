#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "../Client/Client.h"
#include "virtualsoc.h"
#include "admin.h"

namespace Ui {
class login;
}

class login : public QMainWindow

{
    Q_OBJECT

public:
    void closeEvent (QCloseEvent *event);

    explicit login(QWidget *parent = 0,Client* client = 0);
    ~login();

private slots:
    void on_AdminBox_toggled(bool checked);
    void on_LoginButton_clicked();
    void on_RegisterButton_clicked();
    void on_RefreshButton_clicked();
    void on_UserListClicked(QListWidgetItem* item);
    void on_userRegisterTab_tabBarClicked(int index);

private:
    Admin*      m_admin;
    Client*     m_client;
    QWidget*    m_parent;
    int         m_pipe[2];    
    Ui::login*  m_ui;
    VirtualSoc* m_virtualSoc;

    void        printError();
    void        printError(const char*);
    void        terminate();
};

#endif // LOGIN_H
