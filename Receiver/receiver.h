#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QWidget>

#include "../Message/message.h"

class QLabel;
class QTextEdit;

class Receiver : public QWidget
{
    Q_OBJECT
public:
    Receiver(QWidget *parent = 0);

public Q_SLOTS:
    void sendMessage(Message message);
    void sendSignal(QString string);
    void sendSignal2(const QList<int> &signal2);
    void sendMessage2(messageList message);

private:
    QLabel *m_label;
    QTextEdit *m_textEdit;
};

#endif // RECEIVER_H
