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

void Receiver::sendSignal(Message msg)
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
