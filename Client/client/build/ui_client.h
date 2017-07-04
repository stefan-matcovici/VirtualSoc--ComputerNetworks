/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *grettingsLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *IPLabel;
    QLineEdit *IPEdit;
    QLabel *PortLabel;
    QLineEdit *PortEdit;
    QVBoxLayout *verticalLayout_2;
    QPushButton *LocalButton;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *ConnectButton;

    void setupUi(QMainWindow *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName(QStringLiteral("client"));
        client->resize(648, 300);
        client->setMinimumSize(QSize(600, 300));
        QPalette palette;
        QBrush brush(QColor(59, 89, 152, 255));
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
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        QBrush brush7(QColor(247, 247, 247, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush7);
        QBrush brush8(QColor(223, 227, 238, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
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
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
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
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush11);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush9);
        client->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("TeX Gyre Bonum"));
        font.setBold(true);
        font.setWeight(75);
        client->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        client->setWindowIcon(icon);
        client->setWindowOpacity(1);
        client->setAutoFillBackground(false);
        centralWidget = new QWidget(client);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        grettingsLabel = new QLabel(centralWidget);
        grettingsLabel->setObjectName(QStringLiteral("grettingsLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grettingsLabel->sizePolicy().hasHeightForWidth());
        grettingsLabel->setSizePolicy(sizePolicy);
        QPalette palette1;
        QBrush brush12(QColor(0, 255, 255, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        grettingsLabel->setPalette(palette1);
        QFont font1;
        font1.setFamily(QStringLiteral("Purisa"));
        font1.setPointSize(14);
        grettingsLabel->setFont(font1);

        verticalLayout_3->addWidget(grettingsLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(50, -1, -1, -1);
        IPLabel = new QLabel(centralWidget);
        IPLabel->setObjectName(QStringLiteral("IPLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(IPLabel->sizePolicy().hasHeightForWidth());
        IPLabel->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(IPLabel);

        IPEdit = new QLineEdit(centralWidget);
        IPEdit->setObjectName(QStringLiteral("IPEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(IPEdit->sizePolicy().hasHeightForWidth());
        IPEdit->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(IPEdit);

        PortLabel = new QLabel(centralWidget);
        PortLabel->setObjectName(QStringLiteral("PortLabel"));

        verticalLayout->addWidget(PortLabel);

        PortEdit = new QLineEdit(centralWidget);
        PortEdit->setObjectName(QStringLiteral("PortEdit"));

        verticalLayout->addWidget(PortEdit);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 45, -1, 40);
        LocalButton = new QPushButton(centralWidget);
        LocalButton->setObjectName(QStringLiteral("LocalButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(LocalButton->sizePolicy().hasHeightForWidth());
        LocalButton->setSizePolicy(sizePolicy3);

        verticalLayout_2->addWidget(LocalButton);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer_4 = new QSpacerItem(429, 38, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_3->addItem(horizontalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(250, -1, 250, -1);
        ConnectButton = new QPushButton(centralWidget);
        ConnectButton->setObjectName(QStringLiteral("ConnectButton"));
        sizePolicy3.setHeightForWidth(ConnectButton->sizePolicy().hasHeightForWidth());
        ConnectButton->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(ConnectButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        client->setCentralWidget(centralWidget);

        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QMainWindow *client)
    {
        client->setWindowTitle(QApplication::translate("client", "VirtualSoc", 0));
        grettingsLabel->setText(QApplication::translate("client", "<html><head/><body><p align=\"center\"><span style=\" color:#f7f7f7;\">Welcome to VirtualSoc! Please enter your server's ip</span></p><p align=\"center\"><span style=\" color:#f7f7f7;\">and address.</span></p></body></html>", 0));
        IPLabel->setText(QApplication::translate("client", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#f7f7f7;\">IP</span></p></body></html>", 0));
        PortLabel->setText(QApplication::translate("client", "<html><head/><body><p align=\"center\"><span style=\" color:#f7f7f7;\">Port</span></p></body></html>", 0));
        LocalButton->setText(QApplication::translate("client", "local", 0));
        ConnectButton->setText(QApplication::translate("client", "connect", 0));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
