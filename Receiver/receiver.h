#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QWidget>

#include "message.h"

class QLabel;
class QTextEdit;

class Receiver : public QWidget
{
    Q_OBJECT
public:
    Receiver(QWidget *parent = 0);

public Q_SLOTS:
    void sendSignal(Message msg);
    void sendSignal(QString string);

private:
    QLabel *m_label;
    QTextEdit *m_textEdit;
};

#endif // RECEIVER_H
