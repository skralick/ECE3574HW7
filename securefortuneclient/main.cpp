/****************************************************************************
  From Qt examples
****************************************************************************/

#include <QApplication>
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Client client;
    client.show();
    return client.exec();
}

