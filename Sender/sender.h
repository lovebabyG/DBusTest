#ifndef SENDER_H
#define SENDER_H

#include "MyMessageInterface.h"

#include <QWidget>

class QPushButton;
class QLineEdit;

class sender : public QWidget
{
    Q_OBJECT

public:
    sender(QWidget *parent = 0);

private slots:
    void onSenderButtonSendClicked();
    void onSenderButton2Clicked();
    void onSenderButton3Clicked();
    void onSenderButtonClearClicked();

private:
    DemoMyMessageInterface *senderInterface;
    QPushButton *m_pushButtonSend;
    QPushButton *m_pushButtonSend2;
    QPushButton *m_pushButtonClear;
    QLineEdit   *m_lineEdit;
};

#endif // SENDER_H
