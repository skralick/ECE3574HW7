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

#include <SSLServer.h>
#include <QTcpServer>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QNetworkInterface>
#include <QThread>

class Server : public QWidget
{
    Q_OBJECT        //Forward declaration of QObject

public:
    //Constructor
    Server(QWidget *parent = 0);

    //Function to signal the closing of the server class to all clients
    void exit();

private slots:
    //Function to deal with new clients
    void handleNewConnection();

    //Function to receive and process a newly received message
    void readIncomingMsg();

public slots:
    //Function to send a message to the newly added socket
    void sendString(QString input);

    //Sends a message to all clients currently active
    void sendStringToAllClients(QString input);

    //Function to send a string to a particular client
    void sendStringToClient(QString client, QString input);

    //Function to send a new client the list of all currently active clients
    void sendClientList(QString destinationClient);

    //Function to process a client disconnecting
    void disconnectClient(QString clientName);

    //Function to display the server's IP address and port number
    void displayServerInfo();

    //Function to return the server's IP address and port number
    QString getServerInfo();

signals:
    //Signals a message to be displayed
    void displayString(QString);

private:
    //SSL server object
    SSLServer *m_sslServer;

    //SSL socket object
    QSslSocket *m_tempSocket;

    //Hash table of the names and SSL sockets of all clients
    QHash<QString, QSslSocket*> m_socketList;

    //Thread object
    QThread *m_thread;

};

#endif
