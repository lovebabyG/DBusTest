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
    Message(const int iNornum, const int iCallType, const int iCount, QString strDateTime);
    Message(const Message &other);
    Message& operator=(const Message &other);
    ~Message();

    friend QDBusArgument &operator<<(QDBusArgument &argument, const Message &message);
    friend const QDBusArgument &operator>>(const QDBusArgument &argument, Message &message);

    int getNornum() const;
    int getCallType() const;
    int getCount() const;
    QString getDateTime() const;

    //register Message with the Qt type system
    static void registerMetaType();

private:
    int m_iNornum;
    int m_iCallType;
    int m_iCount;
    QString m_strDateTime;
};

typedef QList<Message> messageList;

Q_DECLARE_METATYPE(Message)
Q_DECLARE_METATYPE(messageList)

#endif // MESSAGE_H
