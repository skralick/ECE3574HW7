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

    //connect(hostLineEdit, SIGNAL(textChanged(QString)),
    //        this, SLOT(enableGetFortuneButton()));
    //connect(portLineEdit, SIGNAL(textChanged(QString)),
    //        this, SLOT(enableGetFortuneButton()));
    //connect(getFortuneButton, SIGNAL(clicked()),
    //        this, SLOT(requestNewFortune()));
    //connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(secureSocket, SIGNAL(readyRead()), this, SLOT(readFortune()));
    connect(secureSocket, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    //QGridLayout *mainLayout = new QGridLayout;
    //mainLayout->addWidget(hostLabel, 0, 0);
    //mainLayout->addWidget(hostLineEdit, 0, 1);
    //mainLayout->addWidget(portLabel, 1, 0);
    /*mainLayout->addWidget(portLineEdit, 1, 1);
    mainLayout->addWidget(statusLabel, 2, 0, 1, 2);
    mainLayout->addWidget(buttonBox, 3, 0, 1, 2);
    setLayout(mainLayout);

    setWindowTitle(tr("Secure Fortune Client"));
    portLineEdit->setFocus();*/
}

void Client::requestNewFortune(QString hostIp, QString port)
{
    //getFortuneButton->setEnabled(false);
    blockSize = 0;
    secureSocket->abort();
    secureSocket->setPeerVerifyMode(QSslSocket::QueryPeer);
    secureSocket->connectToHostEncrypted(hostIp,
                             port.toInt());
    if (!secureSocket->waitForEncrypted(1000)) {
         QMessageBox::critical(this, "ERROR", "ERROR: Could not connect to host");
         return;
    }
    //displayCertificateWindow();
    QSslCertificate peerCertificate = secureSocket->peerCertificate();
    qDebug() << "Peer Certificate is: " << endl;
    qDebug() << peerCertificate << endl;
    QSslCertificate localCertificate = secureSocket->localCertificate();
    qDebug() << "Local Certificate is: " << endl;
    qDebug() << localCertificate << endl;
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
    QDataStream in(secureSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
        if (secureSocket->bytesAvailable() < (int)sizeof(quint16))
            return;
        in >> blockSize;
    }

    if (secureSocket->bytesAvailable() < blockSize)
        return;

    QString nextFortune;
    in >> nextFortune;

    if (nextFortune == currentFortune) {
        QTimer::singleShot(0, this, SLOT(requestNewFortune()));
        return;
    }

    currentFortune = nextFortune;
    qDebug() << currentFortune;
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

