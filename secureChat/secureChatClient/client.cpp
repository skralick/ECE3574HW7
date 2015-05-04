/////////////////////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick and Jacky Cheng
//       E-mail:     skralick@vt.edu and jcheng95@vt.edu
//
//
/////////////////////////////////////////////////////////////
#include <QtGui>
#include <QtNetwork>
#include <QDebug>
#include "client.h"

Client::Client(QWidget *parent) : QDialog(parent)
{
    // Find out which IP to connect to
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // Use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // If we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    secureSocket = new QSslSocket(this);

    //Connection that allows the socket to handle errors with certificates
    //Particularly, self-signed certificates
    connect(secureSocket, SIGNAL(sslErrors(QList<QSslError>)), this,
            SLOT(handleSSLError(QList<QSslError>)));

    //Connection that allows the object to read a new message
    connect(secureSocket, SIGNAL(readyRead()), this, SLOT(readFortune()));

    //Connection to handle all other socket errors
    connect(secureSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    //Boolean for preventing repeated names
    m_shouldNotifyServerRemove = false;

}

//Function to receive a new message
void Client::requestNewFortune(QString hostIp, QString port, QString name)
{
    //Sets up the message size and client name
    blockSize = 0;
    m_name = name;

    //Wait for message
    secureSocket -> abort();
    secureSocket -> setPeerVerifyMode(QSslSocket::QueryPeer);
    secureSocket -> connectToHostEncrypted(hostIp,
                             port.toInt());
    //Checks whether or not the client can connect to the server
    if (!secureSocket -> waitForEncrypted(1000)) {
         QMessageBox::critical(this, "ERROR", "ERROR: Could not connect to host");
         return;
    }
    //Checks the certificates
    QSslCertificate peerCertificate = secureSocket -> peerCertificate();
    qDebug() << "Peer Certificate is: " << endl;
    qDebug() << peerCertificate << endl;
    QSslCertificate localCertificate = secureSocket -> localCertificate();
    qDebug() << "Local Certificate is: " << endl;
    qDebug() << localCertificate << endl;

    //Sends a message to the server to add the client
    sendString("A:" + name);
}

//Function to send a message to the server
void Client::sendString(QString input)
{
    //Gets the message through a datastream
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << input;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    //Sends the message to the socket
    secureSocket -> write(block);
    secureSocket -> flush();
}

//Function to get the certificates
QString Client::getCertificateString(const QSslCertificate &cert)
{
    QString certInfo;
    certInfo += "Issuer Org: ";
    certInfo += cert.issuerInfo(QSslCertificate::Organization).join(" ") + QString("\n");
    certInfo += "Common Name: ";
    certInfo += cert.issuerInfo(QSslCertificate::CommonName).join(" ") + "\n";
    certInfo += "Effective Date: ";
    certInfo += cert.effectiveDate().toString() + "\n";
    certInfo += "Expiry Date: ";
    certInfo += cert.expiryDate().toString() + "\n";
    certInfo += "Public Key: ";
    certInfo += cert.publicKey().toPem() + "\n";
    certInfo += "Serial Number: ";
    certInfo += cert.serialNumber() + "\n";
    return certInfo;
}

//Function to display the certificates that the client has
void Client::displayCertificateWindow()
{
    certificateWindow.setWindowTitle("Certificate Information");
    certificateWindow.setMinimumSize(400,300);
    QString peerCertificateInformation("Peer Certificate Information:\n");
    QSslCertificate peerCertificate = secureSocket -> peerCertificate();
    peerCertificateInformation += getCertificateString(peerCertificate);
    certificateWindow.append(peerCertificateInformation);
    QString localCertificateInformation("Local Certificate Information:\n");
    QSslCertificate localCertificate = secureSocket -> localCertificate();
    localCertificateInformation += getCertificateString(localCertificate);
    certificateWindow.append(localCertificateInformation);
    certificateWindow.show();
}

//Function to read and interpret the new message
void Client::readFortune()
{
    //If there is no message end the function
    if (secureSocket -> bytesAvailable() == 0) {
        return;
    }
    //Get the message through a datastream
    QDataStream in(secureSocket);
    in.setVersion(QDataStream::Qt_4_0);
    in >> blockSize;

    //Check if the message received by the client and the message sent are different sizes
    if (secureSocket -> bytesAvailable() < blockSize) {
        return;
    }

    //Convert the message into a QString
    QString nextFortune;
    in >> nextFortune;

    //Update the private variable
    currentFortune = nextFortune;

    //If the object is new, check if the name is available for connection
    if (currentFortune == "ClientNameTaken") {
        QMessageBox msgBox;
        msgBox.setText("This name has already been used!");
        msgBox.exec();
        m_shouldNotifyServerRemove = false;
        emit closeThisWindow();
    } else if (currentFortune == "ConnectionSuccess") {
        m_shouldNotifyServerRemove = true;
    }

    //Processes other codes
    //Adds a client
    if (currentFortune.left(2)== "A:" && currentFortune.split(":")[1] != m_name) {
        emit addClientToList(currentFortune.split(":")[1]); //Adds to the list for the combo box
    //Starting a chat between clients
    } else if (currentFortune.left(2)== "S:") {
        emit startChatWith(currentFortune.split(":")[1]);
    //Receiving a message
    } else if (currentFortune.left(2)== "M:") {
        emit recievedMsg(currentFortune.split(":")[1] +":" + currentFortune.split(":")[3]);
    //Removing a user because they disconnected
    } else if (currentFortune.left(2)== "R:") {
        emit removePossibleClient(currentFortune.split(":")[1]);
        if (currentFortune.split(":")[1] == m_partnerName) {
            qDebug() << "your partner didnt just disconnect";
            emit writeStringToChatWindow("Partner disconnected");
        }
    //Clients entering a chat with each other
    } else if (currentFortune.left(2)== "E:" && currentFortune.split(":")[1] != m_name ) {
        emit removePossibleClient(currentFortune.split(":")[1]);
    //The server object has closed before the client object
    } else if (currentFortune == "Server has closed") {
        emit writeStringToChatWindow(currentFortune);
    } else if (currentFortune.left(2) == "D:" && currentFortune.split(":")[1] == m_partnerName) {
        emit writeStringToChatWindow("Partner disconnected");//your partner sent a D: to you
        emit addClientToList(currentFortune.split(":")[1]);//so add them to your clients you can add
    } else if (currentFortune.left(2) == "D:" && currentFortune.split(":")[1] == m_name) {
        //you were the one to send it out dont do anytihng
    } else if(currentFortune.left(2) == "D:" ) {
        //you observed a converstaion end add them both to your clientlist
        emit addClientToList(currentFortune.split(":")[1]);
    }
    //Restart the message
    blockSize = 0;

    if (secureSocket -> bytesAvailable() > 0) {
        readFortune();
    }
}

void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(this, tr("Fortune Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(secureSocket->errorString()));
    }
}

void Client::enableGetFortuneButton()
{
    //getFortuneButton->setEnabled(!hostLineEdit->text().isEmpty()
    //                             && !portLineEdit->text().isEmpty());
}

// special slot to handle SSL errors...
void Client::handleSSLError(QList<QSslError> errorList)
{
    foreach ( QSslError error, errorList) {
       qDebug() << "Neet to handle SSL error:" << error;
    }
    secureSocket->ignoreSslErrors();
}

void Client::setPartnerName(QString pName){
    m_partnerName = pName;
}

void Client::sendMessageToPartner(QString msg){
    sendString("M:" + m_name + ":" + m_partnerName + ":" + msg);
}
void Client::exit(){
    if(m_shouldNotifyServerRemove){
        sendString("R:" + m_name);
    }
}
QString Client::getPartner(){
    return m_partnerName;
}


void Client::endChat(){
    sendString("D:" + m_name);
}
