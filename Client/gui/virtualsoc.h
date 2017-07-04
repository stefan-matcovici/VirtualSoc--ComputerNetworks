#ifndef VIRTUALSOC_H
#define VIRTUALSOC_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "../Client.h"
#include "post.h"

namespace Ui {
class VirtualSoc;
}

class VirtualSoc : public QMainWindow
{
    Q_OBJECT

public:
    explicit VirtualSoc(QWidget *parent = 0,Client* client = 0,const char* username=0);
    ~VirtualSoc();

    void closeEvent (QCloseEvent *event);


private slots:
    void acceptConversation();
    void acceptUser();
    void addColleague();
    void addConvUser();
    void addFriend();
    void addOther();
    void declineConversation();
    void declineUser();
    void deleteUser();
    void refreshMessages();
    void userProfile();
    void userPosts();

    void on_BackButton_clicked();
    void on_ConversationList_itemClicked(QListWidgetItem *item);
    void on_GroupsCombo_activated(const QString &arg1);
    void on_LeaveConvButton_clicked();
    void on_NewConvButton_clicked();
    void on_PostButton_clicked();
    void on_RequestList_customContextMenuRequested(const QPoint &pos);
    void on_SaveButton_clicked();
    void on_SendButton_clicked();
    void on_ServicesTab_tabBarClicked(int index);
    void on_UsersList_customContextMenuRequested(const QPoint& pos);
    void on_myProfileButton_toggled(bool checked);

private:
    Client*         m_client;
    int             m_pipe[2];
    Ui::VirtualSoc* m_ui;

    std::vector<int> active;
    std::vector<int> request;

    QTimer* m_timer;

    void            ProvideContextMenu(const QPoint &);
    void            terminate();
    void            printError();
    void            printError(const char*);
};

#endif // VIRTUALSOC_H
