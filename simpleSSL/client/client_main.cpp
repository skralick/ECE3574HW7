#include <QApplication>
#include <QtCore>
#include <stdlib.h>
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    qDebug() <<"client will be here";

	QString hostIp = QString("192.168.2.5");
    QString port = QString("56362");
    

    if(argc == 3){
    	hostIp = QString(argv[1]);
    	port = QString(argv[2]);
    }

    Client cl;
    cl.requestNewFortune(hostIp, port);

    return 0;;
}