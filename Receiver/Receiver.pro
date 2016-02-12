QT += dbus \
    widgets \
    core

SOURCES += MyMessageAdaptor.cpp \
    receiver.cpp \
    main.cpp
HEADERS += MyMessageAdaptor.h \
    receiver.h

unix:!macx: LIBS += -L$$OUT_PWD/../Message/ -lMessage

INCLUDEPATH += $$PWD/../Message
DEPENDPATH += $$PWD/../Message

