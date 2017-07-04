/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QWidget *loginWidget;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Photo;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *Username;
    QLabel *UsernameLabel;
    QLineEdit *UsernameEdit;
    QVBoxLayout *Password;
    QLabel *PasswordLabel;
    QLineEdit *PasswordEdit;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *LoginButton;
    QSpacerItem *horizontalSpacer_9;
    QTabWidget *userRegisterTab;
    QWidget *RegisterTab;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *UsernameLabel_2;
    QLabel *PasswordLabel_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *UsernameEdit_2;
    QLineEdit *PasswordEdit_2;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *AdminBox;
    QTextBrowser *AdminText;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *RegisterButton;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_13;
    QWidget *UsersTab;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QListWidget *UsersList;
    QVBoxLayout *verticalLayout_7;
    QLabel *label;
    QListWidget *PostsList;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *RefreshButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(800, 600);
        login->setMinimumSize(QSize(800, 600));
        QPalette palette;
        QBrush brush(QColor(247, 247, 247, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(139, 157, 195, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(88, 134, 228, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(73, 111, 190, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(29, 44, 76, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(39, 59, 101, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        QBrush brush6(QColor(59, 89, 152, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush6);
        QBrush brush7(QColor(255, 255, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush7);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush8(QColor(223, 227, 238, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        QBrush brush9(QColor(0, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush9);
        QBrush brush10(QColor(157, 172, 203, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush10);
        QBrush brush11(QColor(255, 255, 220, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush9);
        login->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("TeX Gyre Bonum"));
        font.setBold(true);
        font.setWeight(75);
        login->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        login->setWindowIcon(icon);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        loginWidget = new QWidget(centralwidget);
        loginWidget->setObjectName(QStringLiteral("loginWidget"));
        loginWidget->setEnabled(true);
        loginWidget->setMinimumSize(QSize(801, 171));
        loginWidget->setAcceptDrops(false);
        loginWidget->setAutoFillBackground(true);
        verticalLayout_5 = new QVBoxLayout(loginWidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalSpacer = new QSpacerItem(780, 28, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Photo = new QLabel(loginWidget);
        Photo->setObjectName(QStringLiteral("Photo"));
        Photo->setMaximumSize(QSize(300, 70));
        Photo->setPixmap(QPixmap(QString::fromUtf8(":/log.png")));
        Photo->setScaledContents(true);

        horizontalLayout_3->addWidget(Photo);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(428, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        Username = new QVBoxLayout();
        Username->setObjectName(QStringLiteral("Username"));
        UsernameLabel = new QLabel(loginWidget);
        UsernameLabel->setObjectName(QStringLiteral("UsernameLabel"));

        Username->addWidget(UsernameLabel);

        UsernameEdit = new QLineEdit(loginWidget);
        UsernameEdit->setObjectName(QStringLiteral("UsernameEdit"));

        Username->addWidget(UsernameEdit);


        horizontalLayout->addLayout(Username);

        Password = new QVBoxLayout();
        Password->setObjectName(QStringLiteral("Password"));
        PasswordLabel = new QLabel(loginWidget);
        PasswordLabel->setObjectName(QStringLiteral("PasswordLabel"));

        Password->addWidget(PasswordLabel);

        PasswordEdit = new QLineEdit(loginWidget);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));
        PasswordEdit->setEchoMode(QLineEdit::Password);

        Password->addWidget(PasswordEdit);


        horizontalLayout->addLayout(Password);


        verticalLayout_4->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(618, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        LoginButton = new QPushButton(loginWidget);
        LoginButton->setObjectName(QStringLiteral("LoginButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginButton->sizePolicy().hasHeightForWidth());
        LoginButton->setSizePolicy(sizePolicy);
        LoginButton->setMaximumSize(QSize(200, 100));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush9);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush12(QColor(13, 39, 127, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        LoginButton->setPalette(palette1);
        QFont font1;
        font1.setFamily(QStringLiteral("Courier 10 Pitch"));
        font1.setBold(true);
        font1.setWeight(75);
        LoginButton->setFont(font1);
        LoginButton->setFlat(false);

        horizontalLayout_4->addWidget(LoginButton);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalSpacer_9 = new QSpacerItem(780, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_5->addItem(horizontalSpacer_9);

        LoginButton->raise();

        verticalLayout_6->addWidget(loginWidget);

        userRegisterTab = new QTabWidget(centralwidget);
        userRegisterTab->setObjectName(QStringLiteral("userRegisterTab"));
        userRegisterTab->setAutoFillBackground(true);
        RegisterTab = new QWidget();
        RegisterTab->setObjectName(QStringLiteral("RegisterTab"));
        QFont font2;
        font2.setFamily(QStringLiteral("Courier 10 Pitch"));
        RegisterTab->setFont(font2);
        RegisterTab->setAutoFillBackground(true);
        verticalLayout_3 = new QVBoxLayout(RegisterTab);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(775, 58, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_6 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        UsernameLabel_2 = new QLabel(RegisterTab);
        UsernameLabel_2->setObjectName(QStringLiteral("UsernameLabel_2"));

        verticalLayout_2->addWidget(UsernameLabel_2);

        PasswordLabel_2 = new QLabel(RegisterTab);
        PasswordLabel_2->setObjectName(QStringLiteral("PasswordLabel_2"));

        verticalLayout_2->addWidget(PasswordLabel_2);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        UsernameEdit_2 = new QLineEdit(RegisterTab);
        UsernameEdit_2->setObjectName(QStringLiteral("UsernameEdit_2"));

        verticalLayout->addWidget(UsernameEdit_2);

        PasswordEdit_2 = new QLineEdit(RegisterTab);
        PasswordEdit_2->setObjectName(QStringLiteral("PasswordEdit_2"));

        verticalLayout->addWidget(PasswordEdit_2);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        horizontalSpacer_7 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_7);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalSpacer_14 = new QSpacerItem(775, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_14);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_8 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        AdminBox = new QCheckBox(RegisterTab);
        AdminBox->setObjectName(QStringLiteral("AdminBox"));
        AdminBox->setChecked(true);

        horizontalLayout_6->addWidget(AdminBox);

        AdminText = new QTextBrowser(RegisterTab);
        AdminText->setObjectName(QStringLiteral("AdminText"));
        AdminText->setReadOnly(false);

        horizontalLayout_6->addWidget(AdminText);

        horizontalSpacer_10 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_10);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalSpacer_15 = new QSpacerItem(775, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_15);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_11 = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);

        RegisterButton = new QPushButton(RegisterTab);
        RegisterButton->setObjectName(QStringLiteral("RegisterButton"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        RegisterButton->setPalette(palette2);
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        RegisterButton->setFont(font3);

        horizontalLayout_7->addWidget(RegisterButton);

        horizontalSpacer_12 = new QSpacerItem(378, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);


        verticalLayout_3->addLayout(horizontalLayout_7);

        horizontalSpacer_13 = new QSpacerItem(775, 81, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_13);

        userRegisterTab->addTab(RegisterTab, QString());
        UsersTab = new QWidget();
        UsersTab->setObjectName(QStringLiteral("UsersTab"));
        UsersTab->setAutoFillBackground(true);
        verticalLayout_8 = new QVBoxLayout(UsersTab);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        UsersList = new QListWidget(UsersTab);
        UsersList->setObjectName(QStringLiteral("UsersList"));
        UsersList->setModelColumn(0);

        horizontalLayout_8->addWidget(UsersList);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label = new QLabel(UsersTab);
        label->setObjectName(QStringLiteral("label"));
        QFont font4;
        font4.setFamily(QStringLiteral("Purisa"));
        font4.setPointSize(14);
        label->setFont(font4);

        verticalLayout_7->addWidget(label);

        PostsList = new QListWidget(UsersTab);
        PostsList->setObjectName(QStringLiteral("PostsList"));
        PostsList->setFrameShadow(QFrame::Sunken);
        PostsList->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        PostsList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        PostsList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        PostsList->setProperty("isWrapping", QVariant(false));
        PostsList->setViewMode(QListView::ListMode);
        PostsList->setModelColumn(0);
        PostsList->setWordWrap(true);

        verticalLayout_7->addWidget(PostsList);


        horizontalLayout_8->addLayout(verticalLayout_7);


        verticalLayout_8->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(140, -1, -1, -1);
        RefreshButton = new QPushButton(UsersTab);
        RefreshButton->setObjectName(QStringLiteral("RefreshButton"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        RefreshButton->setPalette(palette3);

        horizontalLayout_9->addWidget(RefreshButton);

        horizontalSpacer_4 = new QSpacerItem(538, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_4);


        verticalLayout_8->addLayout(horizontalLayout_9);

        userRegisterTab->addTab(UsersTab, QString());

        verticalLayout_6->addWidget(userRegisterTab);

        login->setCentralWidget(centralwidget);

        retranslateUi(login);

        userRegisterTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QApplication::translate("login", "VirtualSocLogin", 0));
        Photo->setText(QString());
        UsernameLabel->setText(QApplication::translate("login", "Username", 0));
        PasswordLabel->setText(QApplication::translate("login", "Password", 0));
        LoginButton->setText(QApplication::translate("login", "Login", 0));
        UsernameLabel_2->setText(QApplication::translate("login", "Username", 0));
        PasswordLabel_2->setText(QApplication::translate("login", "Password", 0));
        AdminBox->setText(QApplication::translate("login", "Admin", 0));
        AdminText->setHtml(QApplication::translate("login", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Courier 10 Pitch'; font-size:9pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-style:italic;\">Request message</span></p></body></html>", 0));
        RegisterButton->setText(QApplication::translate("login", "Register now!", 0));
        userRegisterTab->setTabText(userRegisterTab->indexOf(RegisterTab), QApplication::translate("login", "Register", 0));
        label->setText(QApplication::translate("login", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">Posts</span></p></body></html>", 0));
        RefreshButton->setText(QApplication::translate("login", "Refresh", 0));
        userRegisterTab->setTabText(userRegisterTab->indexOf(UsersTab), QApplication::translate("login", "Users", 0));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
