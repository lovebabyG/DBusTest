QT += dbus \
    widgets \
    core

HEADERS += MyMessageInterface.h \
    sender.h
SOURCES += MyMessageInterface.cpp \
    main.cpp \
    sender.cpp

DISTFILES += \
    MyMessage.xml


unix:!macx: LIBS += -L$$OUT_PWD/../Message/ -lMessage

INCLUDEPATH += $$PWD/../Message
DEPENDPATH += $$PWD/../Message
