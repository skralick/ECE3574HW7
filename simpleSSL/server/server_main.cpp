#include <QApplication>
#include <QtCore>
#include <stdlib.h>
#include <QTextStream>
#include "server.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QTextStream cin(stdin);
    QString a;
    
    qDebug() <<"server will be here";

    Server server;
    //server.show();
    //qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    //server.sendString("HEELKJVSDFDSKsdfjkskdjlfhsd");
    
    return app.exec();

    return 0;;
}