/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
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
    Q_OBJECT        //forward declaration macro for QObject
public:
    //Constructor
    Client(QString name, QObject* parent = 0);

    //Function to send a message to a mailbox
    void sendMessage(QString msg, QString type);

signals:
    //Sends a newly received message to the GUI to be updated
    void sendToWindow(QString out);

    //Signals a new user was added
    void addClient(QString name);

    //Signals a user has left
    void removeClient(QString name);

    //Signals the closing of the chat window
    void closeThisWindow(void);

public slots:
    //Function to check and receive messages
    void doWork(void);

    //Function to notify the server that the user is leaving
    void exit(void);

private:
    //Mailbox name
    QString m_boxName;

    //Mailbox attributes
    struct mq_attr m_attr;

    //Value of message for checking for any message queue failures
    int m_msgVal;

    //Client mailbox
    mqd_t m_clientBox;

    //Server mailbox
    mqd_t mq_centralBox;

    //Boolean for whether or not the window should be closed
    bool m_shouldDie;
};
#endif // CLIENT_H
