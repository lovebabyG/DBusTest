#ifndef MESSAGE_H
#define MESSAGE_H

#include "message_global.h"
#include <QtDBus>

#define MESSAGE_SERVICE "test.dbus.message"
#define MESSAGE_PATH "/mymessage"

class MESSAGESHARED_EXPORT Message
{
public:
    Message();
    Message(const int& m_iNornum, const int &m_iCallType);
    Message(const Message &other);
    Message& operator=(const Message &other);
    ~Message();

    friend QDBusArgument &operator<<(QDBusArgument &argument, const Message &message);
    friend const QDBusArgument &operator>>(const QDBusArgument &argument, Message &message);

    int getNornum() const;
    int getCallType() const;

    //register Message with the Qt type system
    static void registerMetaType();

private:
    int m_iNornum;
    int m_iCallType;
};

Q_DECLARE_METATYPE(Message)

#endif // MESSAGE_H
