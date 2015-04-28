#ifndef CLIENT_H
#define CLIENT_H
#include "../include/common.h"
#include <QtCore>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <mqueue.h>
#include "unistd.h"
#include <QMessageBox>

class Client : public QObject
{
    Q_OBJECT
public:
    Client(QString name, QObject* parent = 0);
    void sendMessage(QString msg, QString type);

signals:
    void workState(int, int);
    void sendToWindow(QString out);
    void addClient(QString name);
    void removeClient(QString name);
    void closeThisWindow(void);

public slots:
    void doWork(void);
    void exit(void);

private:
    QString m_boxName;
    struct mq_attr m_attr;
    int m_msgVal;
    mqd_t m_clientBox;
    mqd_t mq_centralBox;
    bool m_shouldDie;


};
#endif // CLIENT_H
