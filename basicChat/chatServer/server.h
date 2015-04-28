#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include <string.h>
#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>
#include <QtCore>
#include "../include/common.h"

class Server : public QObject
{
    Q_OBJECT
public:
    Server();
    void killConnections();

private:
    QHash <QString, mqd_t> mq_external;
    void sendToAllClients(QString sendString);
    void sendListOfClients(QString boxName);
public slots:
    void doWork();
signals:
    void sendText(QString);

};
#endif // SERVER_H
