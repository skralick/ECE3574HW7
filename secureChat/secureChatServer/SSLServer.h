/////////////////////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick and Jacky Cheng
//       E-mail:     skralick@vt.edu and jcheng95@vt.edu
//
//
/////////////////////////////////////////////////////////////
#ifndef SSLSERVER_H
#define SSLSERVER_H

#include <QTcpServer>
#include <QSslSocket>
#include <QSslKey>
#include <QList>

class SSLServer : public QTcpServer
{
    Q_OBJECT        //Forward declaration of the QObject macro

public:
    //Constructor
    SSLServer(QObject *parent = 0);
    // Since we have a new version of incomingComing connection, we have
    // to keep track of the SSL sockets created and return them with a
    // a revised version of nextPendingConnection.

    //Function to return the most recently used SSL socket
    QSslSocket *nextPendingConnection();
protected:
    // override of QTcpServer::incomingConnection(), see documentation 
    // for QSslSocket.  

    //Overloaded function from QTcpServer that handles the incoming connection
    void incomingConnection(qintptr socketDescriptor);
private:
    // List of all socket connections with clients made
    QList<QSslSocket *> m_secureSocketList;
};

#endif // SSLSERVER_H
