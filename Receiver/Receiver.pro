QT += dbus \
    widgets \
    core

SOURCES += MyMessageAdaptor.cpp \
    receiver.cpp \
    main.cpp
HEADERS += MyMessageAdaptor.h \
    receiver.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Message/release/ -lMessage
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Message/debug/ -lMessage
else:unix: LIBS += -L$$OUT_PWD/../Message/ -lMessage

INCLUDEPATH += $$PWD/../Message
DEPENDPATH += $$PWD/../Message
