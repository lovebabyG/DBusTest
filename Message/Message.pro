#-------------------------------------------------
#
# Project created by QtCreator 2016-02-12T12:46:16
#
#-------------------------------------------------

QT       += widgets dbus

QT       -= gui

TARGET = Message
TEMPLATE = lib

DEFINES += MESSAGE_LIBRARY

SOURCES += message.cpp

HEADERS += message.h\
        message_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
