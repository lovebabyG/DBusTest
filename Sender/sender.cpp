#include "sender.h"

#include <QDBusConnection>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

#include "message.h"

sender::sender(QWidget *parent)
    : QWidget(parent)
{
    senderInterface = new DemoMyMessageInterface("Demo.MyMessage", "/MyMessage", QDBusConnection::sessionBus(), this);
    m_pushButtonSend = new QPushButton("Send signal");
    m_pushButtonClear = new QPushButton("Clear signal");
    m_lineEdit = new QLineEdit();

    QObject::connect(m_pushButtonSend, &QPushButton::clicked, this, &sender::onSenderButtonSendClicked);
    QObject::connect(m_pushButtonClear, &QPushButton::clicked, this, &sender::onSenderButtonClearClicked);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(m_lineEdit, 0, 0);
    mainLayout->addWidget(m_pushButtonSend, 1, 0);
    mainLayout->addWidget(m_pushButtonClear, 1, 1);
    setLayout(mainLayout);

    startTimer(1000);
}

void sender::onSenderButtonSendClicked()
{
//    Message msg(11111111, 2);
//    senderInterface->sendMessage(msg);

    QString strInputText = m_lineEdit->text();
    senderInterface->sendSignal(strInputText);
}

void sender::onSenderButtonClearClicked()
{
    m_lineEdit->clear();
}

void sender::timerEvent(QTimerEvent *event)
{
    Q_UNUSED(event);
    qDebug() << "senderInterface valid = " << senderInterface->isValid();
}
