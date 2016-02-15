#include "sender.h"

#include <QDBusConnection>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

#include "../Message/message.h"

sender::sender(QWidget *parent)
    : QWidget(parent)
{
    senderInterface = new DemoMyMessageInterface("Demo.MyMessage", "/MyMessage", QDBusConnection::sessionBus(), this);
    m_pushButtonSend = new QPushButton("Send signal1");
    m_pushButtonSend2 = new QPushButton("Send signal2");
    QPushButton *button3 = new QPushButton("Send signal3");
    m_pushButtonClear = new QPushButton("Clear signal");
    m_lineEdit = new QLineEdit();

    QObject::connect(m_pushButtonSend, &QPushButton::clicked, this, &sender::onSenderButtonSendClicked);
    QObject::connect(m_pushButtonSend2, &QPushButton::clicked, this, &sender::onSenderButton2Clicked);
    QObject::connect(button3, &QPushButton::clicked, this, &sender::onSenderButton3Clicked);
    QObject::connect(m_pushButtonClear, &QPushButton::clicked, this, &sender::onSenderButtonClearClicked);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(m_lineEdit, 0, 0);
    mainLayout->addWidget(m_pushButtonSend, 1, 0);
    mainLayout->addWidget(m_pushButtonSend2, 2, 0);
    mainLayout->addWidget(button3, 3, 0);
    mainLayout->addWidget(m_pushButtonClear, 4, 1);
    setLayout(mainLayout);
}

void sender::onSenderButtonSendClicked()
{
    QString strInputText = m_lineEdit->text();
    senderInterface->sendSignal(strInputText);
}

void sender::onSenderButton2Clicked()
{
//    Message msg(11111111, 2);
//    senderInterface->sendMessage(msg);
}

void sender::onSenderButton3Clicked()
{
    messageList list;
    for (int i = 0; i<10; ++i)
    {
        Message msg((i+1)*1000, i+1, 1,"test date");
        list.push_back(msg);
    }
    senderInterface->sendMessage2(list);
}

void sender::onSenderButtonClearClicked()
{
    m_lineEdit->clear();
}
