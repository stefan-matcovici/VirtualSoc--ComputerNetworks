#-------------------------------------------------
#
# Project created by QtCreator 2016-12-01T11:20:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app
INCLUDEPATH += /usr/local/include \

LIBS += -L"/usr/local/lib" -ljansson


SOURCES +=  main.cpp \
            login.cpp \
            ../Client/Client.cpp \
            client.cpp \
            virtualsoc.cpp \
            post.cpp \
            admin.cpp \
            ../Server/ServerLibs/Communication/Communication.cpp

HEADERS  += \
            login.h \
            ../Client/Client.h \
            client.h \
            virtualsoc.h \
            post.h \
            admin.h \
            ../Server/ServerLibs/Communication/Communication.h

FORMS    += client.ui \
            login.ui \
            virtualsoc.ui \
            post.ui \
            admin.ui

DISTFILES +=

RESOURCES += \
    resource.qrc
