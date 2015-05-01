#include "server.h"

Server::Server(QWidget *parent) : QWidget(parent)
{

    sslServer = new SSLServer(this);
    if (!sslServer->listen()) {
        QMessageBox::critical(this, tr("Secure Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(sslServer->errorString()));
        close();
        return;
    }
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


    qDebug() << (tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the Secure Fortune Client example now.")
                         .arg(ipAddress).arg(sslServer->serverPort()));


    /*fortunes << tr("You've been leading a dog's life. Stay off the furniture.")
             << tr("You can always think about tomorrow later...")
             << tr("You will be surprised by a loud noise.")
             << tr("The Hokies will not be ACC champs this year. Maybe next?")
             << tr("Notre Dame in the ACC?! Give me a break!!")
             << tr("If only Blacksburg had a Trader Joes!!")
             << tr("You will feel hungry again in another hour.")
             << tr("Thank goodness we now have a Chipoltes.")
             << tr("Your time would be better spent tweeting.")
             << tr("You cannot kill time without injuring eternity.")
             << tr("You can do anything with Qt.")
             << tr("Computers are not intelligent. They only think they are.")
             << tr("Security is important as your clasmates are always wiresharking your traffic.")
             << tr("You will survive ECE 3574.");*/
    //connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(sslServer, SIGNAL(newConnection()), this, SLOT(handleNewConnection()));

    //QHBoxLayout *buttonLayout = new QHBoxLayout;
    //buttonLayout->addStretch(1);
    //buttonLayout->addWidget(quitButton);
    //buttonLayout->addStretch(1);

    //QVBoxLayout *mainLayout = new QVBoxLayout;
    //mainLayout->addWidget(statusLabel);
    //mainLayout->addLayout(buttonLayout);
    //setLayout(mainLayout);

    //setWindowTitle(tr("Secure Fortune Server"));
}
void Server::handleNewConnection(){
    QSslSocket *clientConnection = sslServer->nextPendingConnection();
    if (!clientConnection->waitForEncrypted(1000)){
        qDebug() << "Waited for 1 second for encryption handshake without success";
        return;
    }
    qDebug() << "Successfully waited for secure handshake...";
    connect(clientConnection, SIGNAL(disconnected()),
            clientConnection, SLOT(deleteLater()));

    socketList["First"] = clientConnection;
    sendString("stefdfgd");
}
void Server::sendString(QString input)
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

    socketList["First"]->write(block);
    socketList["First"]->disconnectFromHost();
}
