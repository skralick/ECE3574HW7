/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
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
    Q_OBJECT        //forward declaration macro QObject
public:
    //Constructor
    Server();

    //Function to terminate the connection to all mailboxes
    void killConnections();

private:
    //Hash table of all mailboxes sorted by name of user
    QHash <QString, mqd_t> mq_external;

    //Function to send a message to all users in the hash table
    void sendToAllClients(QString sendString);

    //Function to send the list of all the active clients to the new client
    void sendListOfClients(QString boxName);

    int msgVal;

public slots:
    //Function to check for messages and process each message
    void doWork();

signals:
    //Signal to notify the GUI to update
    void sendText(QString);

};
#endif // SERVER_H
