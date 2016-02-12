#include "message.h"

Message::Message() :
        m_iNornum(0),
        m_iCallType(0)
{
}

Message::Message(const int& iNornum, const int &iCallType) :
        m_iNornum(iNornum),
        m_iCallType(iCallType)
{
}

Message::Message(const Message &other) :
        m_iNornum(other.m_iNornum),
        m_iCallType(other.m_iCallType)
{
}

Message& Message::operator=(const Message &other)
{
    m_iNornum = other.m_iNornum;
    m_iCallType = other.m_iCallType;
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

void Message::registerMetaType()
{
    qRegisterMetaType<Message>("Message");

    qDBusRegisterMetaType<Message>();
}

QDBusArgument &operator<<(QDBusArgument &argument, const Message& message)
{
    argument.beginStructure();
    argument << message.m_iNornum;
    argument << message.m_iCallType;
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, Message &message)
{
    argument.beginStructure();
    argument >> message.m_iNornum;
    argument >> message.m_iCallType;
    argument.endStructure();

    return argument;
}
