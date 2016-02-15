#include "receiver.h"

#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>

Receiver::Receiver(QWidget *parent)
    : QWidget(parent)
{
    m_textEdit = new QTextEdit;
    m_textEdit->setReadOnly(true);

    m_label = new QLabel("Waiting ...");

    QVBoxLayout *VLayout = new QVBoxLayout;
    VLayout->addWidget(m_label);
    VLayout->addWidget(m_textEdit);
    setLayout(VLayout);
}

void Receiver::sendMessage(Message msg)
{
    m_label->clear();
    m_label->setText("Received signal");

    QString strNornum = QString::number(msg.getNornum());
    QString strCallType = QString::number(msg.getCallType());
    QString text = QString("Nornum: ") + strNornum + QString(" CallType: ") + strCallType;
    m_textEdit->setText(text);

}

void Receiver::sendSignal(QString string)
{
    m_textEdit->setText(string);
}

void Receiver::sendSignal2(const QList<int> &signal2)
{
    for (int i = 0; i < signal2.size(); ++i)
    {
        qDebug()<<signal2.at(i);
    }
}

void Receiver::sendMessage2(messageList message)
{
    QString text;
    for (int i = 0; i < message.size(); ++i)
    {
        QString strNornum = QString::number(message.at(i).getNornum());
        QString strCallType = QString::number(message.at(i).getCallType());
        QString strCount = QString::number(message.at(i).getCount());
        QString strDateTIme = message.at(i).getDateTime();
        text += QString("Nornum: ") + strNornum +
                       QString(" CallType: ") + strCallType +
                       QString(" Count:") + strCount + strDateTIme + "\n";

    }
    m_textEdit->setText(text);
}
