/////////////////////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick and Jacky Cheng
//       E-mail:     skralick@vt.edu and jcheng95@vt.edu
//
//
/////////////////////////////////////////////////////////////
#include <QDebug>
#include "SSLServer.h"

// For the documentation: Suppose you create an SSL server class as a subclass
// of QTcpServer. You would override QTcpServer::incomingConnection() with 
// something like the example below, which first constructs an
// instance of QSslSocket and then calls setSocketDescriptor() to set 
// the new socket's descriptor to
// the existing one passed in. It then initiates the SSL handshake by calling
// startServerEncryption().

//Constructor
SSLServer::SSLServer(QObject *parent) : QTcpServer(parent)
{
     //qDebug() << "Constructing SSLServer Object";
}

//Overloaded function to handle the incoming connection from a new client
void SSLServer::incomingConnection(qintptr socketDescriptor)
{
    // On an incoming connection we want
    // to create a new secure socket. 
    QSslSocket *secureSocket = new QSslSocket;

    // Add to list so that we can find it with
    // nextConnection
    m_secureSocketList.append(secureSocket);

    // We need to read in the local certificate and 
    // and the private key that we generated 
    // with openssl.  Read the README to see
    // how these are generated.
    secureSocket->setLocalCertificate("cacert.pem");
    secureSocket->setPrivateKey("privkey.pem");

    // Check that the certificate / private key are not null
    if (secureSocket->localCertificate().isNull()) {
       qDebug() << "WARNING: The local certificate appears to be null! ";
    }
    if (secureSocket->privateKey().isNull()) {
       qDebug() << "WARNING: The private key appears to be null! ";
    }

    // debug message on success
    //qDebug() << "Created the SSL socket, Read local cert. / private key files";

    // From incoming connection we obtain the socket descriptor,
    // we associate this with our new SSL socket
    secureSocket->setSocketDescriptor(socketDescriptor);

    // Begin encryption.  Note from the documentation
    // all the key stuff must be done prior to doing this.
    secureSocket->startServerEncryption();
    //qDebug() << "Started encryption for new secure socket";
}

//Function to return the most recent connection made
QSslSocket *SSLServer::nextPendingConnection()
{
    QSslSocket *secureSocket = NULL;

    //Check if the list of sockets is empty
    if (m_secureSocketList.isEmpty()) {
        qDebug() << "nextPendingConnection: ERROR: Why is this list empty??";
    } else {
        //Pick up the most recently used socket
        secureSocket = m_secureSocketList.last();
        m_secureSocketList.removeLast();
    }
    //Return the most recently used socket
    return secureSocket;
}

