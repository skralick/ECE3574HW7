#include "clientinit.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    if( argc != 2){
        qDebug() << "chatClient: usage ./chatClient num_clients";
        return 1;
    }
    bool ok;
    int clientCount = QString::fromLocal8Bit(argv[1]).toInt(&ok, 10);
    if( !ok ){
        qDebug() << "chatClient: usage ./chatClient num_clients";
        return 1;
    }

    clientInit* windows[clientCount];
    for(int i = 0; i < clientCount; i++){
        windows[i] = new clientInit();
        windows[i]->show();
    }

    return a.exec();
}
