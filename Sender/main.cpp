#include <QtDBus>
#include <QtWidgets>
#include "MyMessageInterface.h"
#include "sender.h"
#include "../Message/message.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Message::registerMetaType();

    sender s;
    s.show();

    return app.exec();
}

