/********************************************************************************
** Form generated from reading UI file 'virtualsoc.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIRTUALSOC_H
#define UI_VIRTUALSOC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VirtualSoc
{
public:
    QWidget *VirtualSoc_2;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QPushButton *BackButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QTabWidget *ServicesTab;
    QWidget *PostsTab;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label;
    QSpacerItem *horizontalSpacer_18;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *NewPostEdit;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QComboBox *GroupPostCombo;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *PostButton;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *PostsList;
    QWidget *ProfilesTab;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_6;
    QLabel *UsernameLabel;
    QLineEdit *UsernameEdit;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_9;
    QLabel *AgeLabel;
    QLineEdit *AgeEdit;
    QHBoxLayout *horizontalLayout_17;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_7;
    QLabel *NameLabel;
    QLineEdit *NameEdit;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_8;
    QLabel *SurnameLabel;
    QLineEdit *SurnameEdit;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_10;
    QLabel *PasswordLabel;
    QLineEdit *PasswordEdit;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *verticalLayout_3;
    QLabel *WordsLabel;
    QVBoxLayout *verticalLayout;
    QTextEdit *WordsEdit;
    QHBoxLayout *horizontalLayout_12;
    QRadioButton *myProfileButton;
    QCheckBox *PrivateCheck;
    QPushButton *SaveButton;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_11;
    QListWidget *PostsList_2;
    QWidget *MessagesTab;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_19;
    QListWidget *RequestList;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *NewConvEdit;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *NewConvButton;
    QSpacerItem *horizontalSpacer_15;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_6;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_20;
    QVBoxLayout *verticalLayout_9;
    QListWidget *ConversationList;
    QLabel *label_7;
    QListWidget *BuddyList;
    QListWidget *MessageList;
    QHBoxLayout *horizontalLayout_22;
    QPushButton *LeaveConvButton;
    QSpacerItem *horizontalSpacer_16;
    QHBoxLayout *horizontalLayout_21;
    QTextEdit *MessageEdit;
    QVBoxLayout *verticalLayout_10;
    QPushButton *SendButton;
    QSpacerItem *horizontalSpacer_17;
    QVBoxLayout *verticalLayout_2;
    QComboBox *GroupsCombo;
    QListWidget *UsersList;

    void setupUi(QMainWindow *VirtualSoc)
    {
        if (VirtualSoc->objectName().isEmpty())
            VirtualSoc->setObjectName(QStringLiteral("VirtualSoc"));
        VirtualSoc->resize(800, 600);
        VirtualSoc->setMinimumSize(QSize(800, 600));
        QPalette palette;
        QBrush brush(QColor(247, 247, 247, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(59, 89, 152, 255));
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
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush7(QColor(223, 227, 238, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush7);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        QBrush brush9(QColor(157, 172, 203, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        QBrush brush10(QColor(255, 255, 220, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush8);
        VirtualSoc->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("TeX Gyre Bonum"));
        font.setBold(true);
        font.setWeight(75);
        VirtualSoc->setFont(font);
        VirtualSoc_2 = new QWidget(VirtualSoc);
        VirtualSoc_2->setObjectName(QStringLiteral("VirtualSoc_2"));
        verticalLayout_7 = new QVBoxLayout(VirtualSoc_2);
        verticalLayout_7->setSpacing(10);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        BackButton = new QPushButton(VirtualSoc_2);
        BackButton->setObjectName(QStringLiteral("BackButton"));

        horizontalLayout->addWidget(BackButton);

        horizontalSpacer = new QSpacerItem(678, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_7->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(10);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        ServicesTab = new QTabWidget(VirtualSoc_2);
        ServicesTab->setObjectName(QStringLiteral("ServicesTab"));
        ServicesTab->setMinimumSize(QSize(600, 561));
        PostsTab = new QWidget();
        PostsTab->setObjectName(QStringLiteral("PostsTab"));
        verticalLayout_6 = new QVBoxLayout(PostsTab);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalSpacer_6 = new QSpacerItem(618, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_6);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label = new QLabel(PostsTab);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Purisa"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        horizontalLayout_23->addWidget(label);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_23->addItem(horizontalSpacer_18);


        verticalLayout_6->addLayout(horizontalLayout_23);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(68, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        NewPostEdit = new QTextEdit(PostsTab);
        NewPostEdit->setObjectName(QStringLiteral("NewPostEdit"));
        NewPostEdit->setMinimumSize(QSize(441, 49));

        horizontalLayout_2->addWidget(NewPostEdit);

        horizontalSpacer_5 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);


        verticalLayout_6->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(278, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        GroupPostCombo = new QComboBox(PostsTab);
        GroupPostCombo->setObjectName(QStringLiteral("GroupPostCombo"));

        horizontalLayout_3->addWidget(GroupPostCombo);

        horizontalSpacer_7 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        PostButton = new QPushButton(PostsTab);
        PostButton->setObjectName(QStringLiteral("PostButton"));

        horizontalLayout_3->addWidget(PostButton);

        horizontalSpacer_8 = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);


        verticalLayout_6->addLayout(horizontalLayout_3);

        label_2 = new QLabel(PostsTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);
        label_2->setToolTipDuration(-1);

        verticalLayout_6->addWidget(label_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(75, -1, 75, -1);
        PostsList = new QListWidget(PostsTab);
        PostsList->setObjectName(QStringLiteral("PostsList"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PostsList->sizePolicy().hasHeightForWidth());
        PostsList->setSizePolicy(sizePolicy);
        PostsList->setMinimumSize(QSize(320, 400));
        PostsList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_4->addWidget(PostsList);


        verticalLayout_6->addLayout(horizontalLayout_4);

        ServicesTab->addTab(PostsTab, QString());
        ProfilesTab = new QWidget();
        ProfilesTab->setObjectName(QStringLiteral("ProfilesTab"));
        verticalLayout_5 = new QVBoxLayout(ProfilesTab);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_3 = new QLabel(ProfilesTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout_5->addWidget(label_3);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        UsernameLabel = new QLabel(ProfilesTab);
        UsernameLabel->setObjectName(QStringLiteral("UsernameLabel"));

        horizontalLayout_6->addWidget(UsernameLabel);

        UsernameEdit = new QLineEdit(ProfilesTab);
        UsernameEdit->setObjectName(QStringLiteral("UsernameEdit"));
        UsernameEdit->setReadOnly(true);
        UsernameEdit->setClearButtonEnabled(false);

        horizontalLayout_6->addWidget(UsernameEdit);


        horizontalLayout_13->addLayout(horizontalLayout_6);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        AgeLabel = new QLabel(ProfilesTab);
        AgeLabel->setObjectName(QStringLiteral("AgeLabel"));

        horizontalLayout_9->addWidget(AgeLabel);

        AgeEdit = new QLineEdit(ProfilesTab);
        AgeEdit->setObjectName(QStringLiteral("AgeEdit"));
        AgeEdit->setReadOnly(true);

        horizontalLayout_9->addWidget(AgeEdit);


        horizontalLayout_13->addLayout(horizontalLayout_9);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        NameLabel = new QLabel(ProfilesTab);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));

        horizontalLayout_7->addWidget(NameLabel);

        NameEdit = new QLineEdit(ProfilesTab);
        NameEdit->setObjectName(QStringLiteral("NameEdit"));
        NameEdit->setReadOnly(true);

        horizontalLayout_7->addWidget(NameEdit);


        horizontalLayout_14->addLayout(horizontalLayout_7);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_11);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        SurnameLabel = new QLabel(ProfilesTab);
        SurnameLabel->setObjectName(QStringLiteral("SurnameLabel"));

        horizontalLayout_8->addWidget(SurnameLabel);

        SurnameEdit = new QLineEdit(ProfilesTab);
        SurnameEdit->setObjectName(QStringLiteral("SurnameEdit"));
        SurnameEdit->setReadOnly(true);

        horizontalLayout_8->addWidget(SurnameEdit);


        horizontalLayout_15->addLayout(horizontalLayout_8);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_12);


        verticalLayout_4->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        PasswordLabel = new QLabel(ProfilesTab);
        PasswordLabel->setObjectName(QStringLiteral("PasswordLabel"));

        horizontalLayout_10->addWidget(PasswordLabel);

        PasswordEdit = new QLineEdit(ProfilesTab);
        PasswordEdit->setObjectName(QStringLiteral("PasswordEdit"));

        horizontalLayout_10->addWidget(PasswordEdit);


        horizontalLayout_16->addLayout(horizontalLayout_10);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_13);


        verticalLayout_4->addLayout(horizontalLayout_16);


        horizontalLayout_17->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        WordsLabel = new QLabel(ProfilesTab);
        WordsLabel->setObjectName(QStringLiteral("WordsLabel"));

        verticalLayout_3->addWidget(WordsLabel);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        WordsEdit = new QTextEdit(ProfilesTab);
        WordsEdit->setObjectName(QStringLiteral("WordsEdit"));
        WordsEdit->setReadOnly(true);

        verticalLayout->addWidget(WordsEdit);


        verticalLayout_3->addLayout(verticalLayout);


        horizontalLayout_17->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_17);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(100, -1, 100, -1);
        myProfileButton = new QRadioButton(ProfilesTab);
        myProfileButton->setObjectName(QStringLiteral("myProfileButton"));
        myProfileButton->setChecked(false);

        horizontalLayout_12->addWidget(myProfileButton);

        PrivateCheck = new QCheckBox(ProfilesTab);
        PrivateCheck->setObjectName(QStringLiteral("PrivateCheck"));

        horizontalLayout_12->addWidget(PrivateCheck);

        SaveButton = new QPushButton(ProfilesTab);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));

        horizontalLayout_12->addWidget(SaveButton);


        verticalLayout_5->addLayout(horizontalLayout_12);

        label_4 = new QLabel(ProfilesTab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout_5->addWidget(label_4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_11->setContentsMargins(100, -1, 150, -1);
        PostsList_2 = new QListWidget(ProfilesTab);
        PostsList_2->setObjectName(QStringLiteral("PostsList_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PostsList_2->sizePolicy().hasHeightForWidth());
        PostsList_2->setSizePolicy(sizePolicy1);
        PostsList_2->setMinimumSize(QSize(320, 400));

        horizontalLayout_11->addWidget(PostsList_2);


        verticalLayout_5->addLayout(horizontalLayout_11);

        ServicesTab->addTab(ProfilesTab, QString());
        MessagesTab = new QWidget();
        MessagesTab->setObjectName(QStringLiteral("MessagesTab"));
        verticalLayout_11 = new QVBoxLayout(MessagesTab);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_5 = new QLabel(MessagesTab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        verticalLayout_11->addWidget(label_5);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(-1, 0, -1, -1);
        RequestList = new QListWidget(MessagesTab);
        RequestList->setObjectName(QStringLiteral("RequestList"));

        horizontalLayout_19->addWidget(RequestList);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        NewConvEdit = new QLineEdit(MessagesTab);
        NewConvEdit->setObjectName(QStringLiteral("NewConvEdit"));

        verticalLayout_8->addWidget(NewConvEdit);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalSpacer_14 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_14);

        NewConvButton = new QPushButton(MessagesTab);
        NewConvButton->setObjectName(QStringLiteral("NewConvButton"));

        horizontalLayout_18->addWidget(NewConvButton);

        horizontalSpacer_15 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_15);


        verticalLayout_8->addLayout(horizontalLayout_18);


        horizontalLayout_19->addLayout(verticalLayout_8);


        verticalLayout_11->addLayout(horizontalLayout_19);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        label_6 = new QLabel(MessagesTab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font1);

        horizontalLayout_24->addWidget(label_6);

        label_8 = new QLabel(MessagesTab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);

        horizontalLayout_24->addWidget(label_8);


        verticalLayout_11->addLayout(horizontalLayout_24);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(5);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_20->setContentsMargins(-1, 5, -1, -1);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(5);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        ConversationList = new QListWidget(MessagesTab);
        ConversationList->setObjectName(QStringLiteral("ConversationList"));

        verticalLayout_9->addWidget(ConversationList);

        label_7 = new QLabel(MessagesTab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font1);

        verticalLayout_9->addWidget(label_7);

        BuddyList = new QListWidget(MessagesTab);
        BuddyList->setObjectName(QStringLiteral("BuddyList"));

        verticalLayout_9->addWidget(BuddyList);


        horizontalLayout_20->addLayout(verticalLayout_9);

        MessageList = new QListWidget(MessagesTab);
        MessageList->setObjectName(QStringLiteral("MessageList"));

        horizontalLayout_20->addWidget(MessageList);


        verticalLayout_11->addLayout(horizontalLayout_20);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalLayout_22->setContentsMargins(15, -1, -1, -1);
        LeaveConvButton = new QPushButton(MessagesTab);
        LeaveConvButton->setObjectName(QStringLiteral("LeaveConvButton"));

        horizontalLayout_22->addWidget(LeaveConvButton);

        horizontalSpacer_16 = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_16);


        verticalLayout_11->addLayout(horizontalLayout_22);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout_21->setContentsMargins(-1, -1, -1, 15);
        MessageEdit = new QTextEdit(MessagesTab);
        MessageEdit->setObjectName(QStringLiteral("MessageEdit"));

        horizontalLayout_21->addWidget(MessageEdit);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        SendButton = new QPushButton(MessagesTab);
        SendButton->setObjectName(QStringLiteral("SendButton"));

        verticalLayout_10->addWidget(SendButton);

        horizontalSpacer_17 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_10->addItem(horizontalSpacer_17);


        horizontalLayout_21->addLayout(verticalLayout_10);


        verticalLayout_11->addLayout(horizontalLayout_21);

        ServicesTab->addTab(MessagesTab, QString());

        horizontalLayout_5->addWidget(ServicesTab);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        GroupsCombo = new QComboBox(VirtualSoc_2);
        GroupsCombo->setObjectName(QStringLiteral("GroupsCombo"));
        GroupsCombo->setDuplicatesEnabled(false);

        verticalLayout_2->addWidget(GroupsCombo);

        UsersList = new QListWidget(VirtualSoc_2);
        UsersList->setObjectName(QStringLiteral("UsersList"));
        UsersList->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        UsersList->setTextElideMode(Qt::ElideMiddle);
        UsersList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        UsersList->setProperty("isWrapping", QVariant(false));
        UsersList->setWordWrap(true);

        verticalLayout_2->addWidget(UsersList);


        horizontalLayout_5->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(horizontalLayout_5);

        VirtualSoc->setCentralWidget(VirtualSoc_2);

        retranslateUi(VirtualSoc);

        ServicesTab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(VirtualSoc);
    } // setupUi

    void retranslateUi(QMainWindow *VirtualSoc)
    {
        VirtualSoc->setWindowTitle(QApplication::translate("VirtualSoc", "VirtualSoc", 0));
        BackButton->setText(QApplication::translate("VirtualSoc", "Logout", 0));
        label->setText(QApplication::translate("VirtualSoc", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#f7f7f7;\">New Post</span></p></body></html>", 0));
        PostButton->setText(QApplication::translate("VirtualSoc", "Post", 0));
        label_2->setText(QApplication::translate("VirtualSoc", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#f7f7f7;\">Posts</span></p></body></html>", 0));
        ServicesTab->setTabText(ServicesTab->indexOf(PostsTab), QApplication::translate("VirtualSoc", "Posts", 0));
        label_3->setText(QApplication::translate("VirtualSoc", "<html><head/><body><p><span style=\" color:#f7f7f7;\">Profile</span></p></body></html>", 0));
        UsernameLabel->setText(QApplication::translate("VirtualSoc", "Username", 0));
        AgeLabel->setText(QApplication::translate("VirtualSoc", "Age", 0));
        NameLabel->setText(QApplication::translate("VirtualSoc", "Name", 0));
        SurnameLabel->setText(QApplication::translate("VirtualSoc", "Surname", 0));
        PasswordLabel->setText(QApplication::translate("VirtualSoc", "Password", 0));
        WordsLabel->setText(QApplication::translate("VirtualSoc", "Some words", 0));
        myProfileButton->setText(QApplication::translate("VirtualSoc", "MyProfile", 0));
        PrivateCheck->setText(QApplication::translate("VirtualSoc", "Private", 0));
        SaveButton->setText(QApplication::translate("VirtualSoc", "Save", 0));
        label_4->setText(QApplication::translate("VirtualSoc", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#f7f7f7;\">Posts</span></p></body></html>", 0));
        ServicesTab->setTabText(ServicesTab->indexOf(ProfilesTab), QApplication::translate("VirtualSoc", "Profiles", 0));
        label_5->setText(QApplication::translate("VirtualSoc", "<html><head/><body><p><span style=\" color:#f7f7f7;\">Requests</span></p></body></html>", 0));
        NewConvButton->setText(QApplication::translate("VirtualSoc", "Start new conversation", 0));
        label_6->setText(QApplication::translate("VirtualSoc", "<html><head/><body><p><span style=\" color:#f7f7f7;\">Active conversations</span></p></body></html>", 0));
        label_8->setText(QApplication::translate("VirtualSoc", "<html><head/><body><p><span style=\" color:#f7f7f7;\">Messages</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("VirtualSoc", "<html><head/><body><p align=\"center\"><span style=\" color:#f7f7f7;\">Buddies</span></p></body></html>", 0));
        LeaveConvButton->setText(QApplication::translate("VirtualSoc", "Leave current conversation", 0));
        SendButton->setText(QApplication::translate("VirtualSoc", "Send", 0));
        ServicesTab->setTabText(ServicesTab->indexOf(MessagesTab), QApplication::translate("VirtualSoc", "Messages", 0));
    } // retranslateUi

};

namespace Ui {
    class VirtualSoc: public Ui_VirtualSoc {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIRTUALSOC_H
