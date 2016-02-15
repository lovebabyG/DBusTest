QT += dbus \
    widgets \
    core

HEADERS += MyMessageInterface.h \
    sender.h
SOURCES += MyMessageInterface.cpp \
    main.cpp \
    sender.cpp

#unix:!macx: LIBS += -L$$OUT_PWD/../Message/ -lMessage

#INCLUDEPATH += $$PWD/../Message
#DEPENDPATH += $$PWD/../Message

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Message/release/ -lMessage
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Message/debug/ -lMessage
else:unix: LIBS += -L$$OUT_PWD/../Message/ -lMessage

INCLUDEPATH += $$PWD/../Message
DEPENDPATH += $$PWD/../Message
