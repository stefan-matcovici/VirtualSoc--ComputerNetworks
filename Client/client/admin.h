#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "../Client/Client.h"
#include "post.h"

namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = 0,Client* c=0);
    ~Admin();

    void closeEvent (QCloseEvent *event);

private slots:
    void acceptAdmin();
    void declineAdmin();
    void deleteUser();

    void on_LogoutButton_clicked();
    void on_PostsList_customContextMenuRequested(const QPoint &pos);
    void on_RequestsList_customContextMenuRequested(const QPoint &pos);
    void on_RefreshButton_clicked();
    void on_UsersList_customContextMenuRequested(const QPoint &pos);
    void on_UsersList_itemClicked(QListWidgetItem *item);

private:
    Client*         m_client;
    int             m_pipe[2];
    Ui::Admin*      m_ui;

    void            printError();
    void            printError(const char*);
    void            terminate();
};

#endif // ADMIN_H
