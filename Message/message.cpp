#include "message.h"

Message::Message() :
        m_iNornum(0),
        m_iCallType(0),
        m_iCount(0),
        m_strDateTime("")
{
}

Message::Message(const int iNornum, const int iCallType, const int iCount, const QString strDatetime) :
        m_iNornum(iNornum),
        m_iCallType(iCallType),
        m_iCount(iCount),
        m_strDateTime(strDatetime)
{
}

Message::Message(const Message &other) :
        m_iNornum(other.m_iNornum),
        m_iCallType(other.m_iCallType),
        m_iCount(other.m_iCount),
        m_strDateTime(other.m_strDateTime)
{
}

Message& Message::operator=(const Message &other)
{
    m_iNornum = other.m_iNornum;
    m_iCallType = other.m_iCallType;
    m_iCount = other.m_iCount;
    m_strDateTime = other.m_strDateTime;
    return *this;
}

Message::~Message()
{
}

int Message::getNornum() const
{
    return m_iNornum;
}

int Message::getCallType() const
{
    return m_iCallType;
}

int Message::getCount() const
{
    return m_iCount;
}

QString Message::getDateTime() const
{
    return m_strDateTime;
}

void Message::registerMetaType()
{
    //qRegisterMetaType<Message>("Message");
    qDBusRegisterMetaType<Message>();
    qDBusRegisterMetaType<messageList>();
}

QDBusArgument &operator<<(QDBusArgument &argument, const Message& message)
{
    argument.beginStructure();
    argument << message.m_iNornum;
    argument << message.m_iCallType;
    argument << message.m_iCount;
    argument << message.m_strDateTime;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, Message &message)
{
    argument.beginStructure();
    argument >> message.m_iNornum;
    argument >> message.m_iCallType;
    argument >> message.m_iCount;
    argument >> message.m_strDateTime;
    argument.endStructure();

    return argument;
}
