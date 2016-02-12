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
    void onSenderButtonClearClicked();

protected:
    void timerEvent(QTimerEvent *event);

private:
    DemoMyMessageInterface *senderInterface;
    QPushButton *m_pushButtonSend;
    QPushButton *m_pushButtonClear;
    QLineEdit   *m_lineEdit;
};

#endif // SENDER_H
