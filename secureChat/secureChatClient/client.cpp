/****************************************************************************
  From the Qt examples
  Modified to do a secure SSL connection
****************************************************************************/

#include <QtGui>
#include <QtNetwork>
#include <QDebug>
#include "client.h"

Client::Client(QWidget *parent) : QDialog(parent)
{
    //hostLabel = new QLabel(tr("&Server name:"));
    //portLabel = new QLabel(tr("S&erver port:"));

    // find out which IP to connect to
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    //hostLineEdit = new QLineEdit(ipAddress);
    //portLineEdit = new QLineEdit;
    //portLineEdit->setValidator(new QIntValidator(1, 65535, this));

    //hostLabel->setBuddy(hostLineEdit);
    //portLabel->setBuddy(portLineEdit);

    //statusLabel = new QLabel(tr("This examples requires that you run the "
     //                           "Secure Fortune Server example as well."));

    //getFortuneButton = new QPushButton(tr("Get Fortune"));
    //getFortuneButton->setDefault(true);
    //getFortuneButton->setEnabled(false);

    //quitButton = new QPushButton(tr("Quit"));

    //buttonBox = new QDialogButtonBox;
    //buttonBox->addButton(getFortuneButton, QDialogButtonBox::ActionRole);
    //buttonBox->addButton(quitButton, QDialogButtonBox::RejectRole);

    secureSocket = new QSslSocket(this);

    // special slot to handle errors with the certificates
    // in particular the fact that they are self-signed
    connect(secureSocket, SIGNAL(sslErrors(QList<QSslError>)), this,
            SLOT(handleSSLError(QList<QSslError>)));

    connect(secureSocket, SIGNAL(readyRead()), this, SLOT(readFortune()));
    connect(secureSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

}

void Client::requestNewFortune(QString hostIp, QString port, QString name)
{
    blockSize = 0;
    m_name = name;
    secureSocket->abort();
    secureSocket->setPeerVerifyMode(QSslSocket::QueryPeer);
    secureSocket->connectToHostEncrypted(hostIp,
                             port.toInt());
    if (!secureSocket->waitForEncrypted(1000)) {
         QMessageBox::critical(this, "ERROR", "ERROR: Could not connect to host");
         return;
    }
    QSslCertificate peerCertificate = secureSocket->peerCertificate();
    qDebug() << "Peer Certificate is: " << endl;
    qDebug() << peerCertificate << endl;
    QSslCertificate localCertificate = secureSocket->localCertificate();
    qDebug() << "Local Certificate is: " << endl;
    qDebug() << localCertificate << endl;

    sendString("A:" + name);
}

void Client::sendString(QString input)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    qDebug() << "In sendClient";
    out << (quint16)0;
    //out << fortunes.at(qrand() % fortunes.size());
    out << input;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    //connect(secureSocket, SIGNAL(readyRead()), this, SLOT(readIncomingMsg()));
    secureSocket->write(block);
    //socketList["First"]->disconnectFromHost();
}

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

void Client::displayCertificateWindow()
{
    certificateWindow.setWindowTitle("Certificate Information");
    certificateWindow.setMinimumSize(400,300);
    QString peerCertificateInformation("Peer Certificate Information:\n");
    QSslCertificate peerCertificate = secureSocket->peerCertificate();
    peerCertificateInformation += getCertificateString(peerCertificate);
    certificateWindow.append(peerCertificateInformation);
    QString localCertificateInformation("Local Certificate Information:\n");
    QSslCertificate localCertificate = secureSocket->localCertificate();
    localCertificateInformation += getCertificateString(localCertificate);
    certificateWindow.append(localCertificateInformation);
    certificateWindow.show();
}

void Client::readFortune()
{
    qDebug() << "readFortuneCalled";// << secureSocket->canReadLine();
    if(secureSocket->bytesAvailable() == 0){
        return;
    }
    QDataStream in(secureSocket);
    in.setVersion(QDataStream::Qt_4_0);
    //blockSize = 0;
    //if (blockSize == 0) {
        //qDebug() << "blockSize was zero";
        //if (secureSocket->bytesAvailable() < (int)sizeof(quint16))
            //return;
        in >> blockSize;
    //}
    qDebug() << "blocksize" << blockSize << "bytes avail" << secureSocket->bytesAvailable();
    if (secureSocket->bytesAvailable() < blockSize)
        return;

    QString nextFortune;
    in >> nextFortune;

    currentFortune = nextFortune;
    qDebug() << currentFortune;
    if(currentFortune == "ClientNameTaken"){
        emit closeThisWindow();
    }
    if(currentFortune.left(2)== "A:" && currentFortune.split(":")[1] != m_name){
        emit addClientToList(currentFortune.split(":")[1]);
    }else if(currentFortune.left(2)== "S:"){
        emit startChatWith(currentFortune.split(":")[1]);
    }else if(currentFortune.left(2)== "M:"){
        emit recievedMsg(currentFortune.split(":")[1] +":" + currentFortune.split(":")[3]);
    }else if(currentFortune.left(2)== "R:"){
        emit removePossibleClient(currentFortune.split(":")[1]);
        emit removePossibleConnectedClient(currentFortune.split(":")[1]);//this could be simpelr send a bool also not working
    }
    emit recievedString(currentFortune);
    blockSize = 0;

    if(secureSocket->bytesAvailable() > 0){
        readFortune();
    }
    //statusLabel->setText(currentFortune);
    //getFortuneButton->setEnabled(true);
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

    //getFortuneButton->setEnabled(true);
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
    sendString("R:" + m_name);
}
QString Client::getPartner(){
    return m_partnerName;
}
