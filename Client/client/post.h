#ifndef POST_H
#define POST_H

#include <QWidget>
#include "../Client/Client.h"

namespace Ui {
class Post;
}

class Post : public QWidget
{
    Q_OBJECT

public:
    explicit Post(QWidget *parent = 0,const char* author=0, const char* date=0, const char* content=0,const char* group=0,bool del=false,Client* client=0);
    ~Post();

private slots:
    void on_deleteButton_clicked();

private:
    Client* m_client;
    Ui::Post *ui;
};

#endif // POST_H
