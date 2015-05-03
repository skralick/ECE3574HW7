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

#include <QDialog>
#include <QTcpSocket>
#include <QSslError>
#include <QSslCertificate>
#include <QSslKey>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSslSocket>
#include <QSslCertificate>
#include <QWidget>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QMessageBox>
#include <QString>
#include <QStringList>

class Client : public QDialog
{
    Q_OBJECT        //Forward declaration of QObject

public:
    //Constructor
    Client(QWidget *parent = 0);

    //Function to set the name of the client you are messaging
    void setPartnerName(QString pName);

    //Function to send a message to the client you are connected to
    void sendMessageToPartner(QString msg);

    //Function to close allo windows and destroy the client object
    void exit();

    //Function to return the name of the partner client
    QString getPartner();

public slots:
    //Function to send a message
    void sendString(QString input);
    //Function to request a fortune from the server
    void requestNewFortune(QString hostIp, QString port, QString name);

private slots:
    //void requestNewFortune();
    //void requestNewFortune(QString hostIp, QString port);

    //Function to read the fortune received
    void readFortune();

    //Function to display a socket error
    void displayError(QAbstractSocket::SocketError socketError);

    //Function to enable the button to receive a fortune
    void enableGetFortuneButton();

    //Function to handle all SSL errors received
    void handleSSLError(QList<QSslError>);

private:
    //Function to get the SSL certificate
    QString getCertificateString(const QSslCertificate&);

    //Function to display the certificate window
    void displayCertificateWindow();

    //Text edit object for the certificates
    QTextEdit certificateWindow;

    //SSL object
    QSslSocket *secureSocket;

    //Current fortune
    QString currentFortune;

    //Size of the message
    quint16 blockSize;

    //Client name
    QString m_name;

    //Partner client name
    QString m_partnerName;

signals:
    //Signals a new message is received
    void recievedString(QString string);

    //Signals the windows need to close
    void closeThisWindow();

    //Signals the need to add a client to the combo box
    void addClientToList(QString name);

    //Signals the start of chatting with another client
    void startChatWith(QString name);

    //Signals a message received
    void recievedMsg(QString msg);

    //Signals the removal of a client
    void removePossibleClient(QString client);

    //Signals the removal of the client you're trying to connect to
    void removePossibleConnectedClient(QString client);
};

#endif
