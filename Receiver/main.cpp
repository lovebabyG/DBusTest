#include <QtDBus>
#include <QDBusConnection>
#include <QtWidgets/QApplication>
#include <QtDBus>

#include "receiver.h"
#include "MyMessageAdaptor.h"
#include "../Message/message.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Message::registerMetaType();

    MyMessageAdaptor *pReceiverAdaptor = NULL;
    Receiver *receiver = new Receiver();

    pReceiverAdaptor = new MyMessageAdaptor(receiver);
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.registerObject("/MyMessage", receiver);
    connection.registerService("Demo.MyMessage");

    receiver->show();

    return app.exec();
}
