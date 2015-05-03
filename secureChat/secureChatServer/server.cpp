#include "server.h"

Server::Server(QWidget *parent) : QWidget(parent)
{

    m_sslServer = new SSLServer(this);
    if (!m_sslServer->listen()) {
        QMessageBox::critical(this, tr("Secure Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(m_sslServer->errorString()));
        close();
        return;
    }

    connect(m_sslServer, SIGNAL(newConnection()), this, SLOT(handleNewConnection()));
    displayServerInfo();
}

void Server::displayServerInfo(){
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


    emit displayString(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the client now.")
                         .arg(ipAddress).arg(m_sslServer->serverPort()));
}

QString Server::getServerInfo(){
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


    return (tr("The server is running on\nIP: %1\nport: %2\n"
                            "Run clients now.")
                         .arg(ipAddress).arg(m_sslServer->serverPort()));
}

void Server::handleNewConnection(){
    m_tempSocket = m_sslServer->nextPendingConnection();
    connect(m_tempSocket, SIGNAL(readyRead()), this, SLOT(readIncomingMsg()));
    if (!m_tempSocket->waitForEncrypted(1000)){
        //qDebug() << "Waited for 1 second for encryption handshake without success";
        return;
    }
    //qDebug() << "Successfully waited for secure handshake...";
    connect(m_tempSocket, SIGNAL(disconnected()),
            m_tempSocket, SLOT(deleteLater()));
}
void Server::sendString(QString input)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    //qDebug() << "In sendClient";
    out << (quint16)0;
    out << input;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    m_tempSocket->write(block);
    m_tempSocket->flush();
}

void Server::sendStringToClient(QString client, QString input)
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << input;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    m_socketList[client]->write(block);
    m_socketList[client]->flush();
}

void Server::sendStringToAllClients(QString input)
{
    QHash<QString, QSslSocket*>::const_iterator i = m_socketList.constBegin();
    while (i != m_socketList.constEnd()) {
        sendStringToClient(i.key(), input);
        ++i;
    }
}

void Server::sendClientList(QString destinationClient)
{
    QHash<QString, QSslSocket*>::const_iterator i = m_socketList.constBegin();
    while (i != m_socketList.constEnd()) {
        sendStringToClient(destinationClient, "A:" + i.key());
        ++i;
    }
}

void Server::readIncomingMsg()
{
    quint16 blockSize = 0;
    QSslSocket *localSocket = m_tempSocket;
    QHash<QString, QSslSocket*>::const_iterator i = m_socketList.constBegin();
    while (i != m_socketList.constEnd()) {
        //qDebug() << i.key() << ": " << i.value()->bytesAvailable() << endl;
        if(i.value()->bytesAvailable()){
            localSocket = m_socketList[i.key()];
            break;
        }
        ++i;
    }
    if(localSocket == 0){
        return;
    }
    QDataStream in(localSocket);
    in.setVersion(QDataStream::Qt_4_0);

    if (blockSize == 0) {
        if (localSocket->bytesAvailable() < (int)sizeof(quint16)){
            return;
        }
        in >> blockSize;
    }
    if (localSocket->bytesAvailable() < blockSize){
        return;
    }
    QString nextFortune;
    in >> nextFortune;
    if (nextFortune.left(2) == "A:"){
        QString msg = "ConnectionSuccess";
        QHash<QString, QSslSocket*>::const_iterator i = m_socketList.constBegin();
        while (i != m_socketList.constEnd()) {
            if(i.key() == nextFortune.split(":")[1]){
                msg = "ClientNameTaken";
                return;
            }
            ++i;
        }
        sendString(msg);
        sendStringToAllClients(nextFortune);//send the newGuy message to everyOne
        m_socketList[nextFortune.split(":")[1]] = m_tempSocket;
        m_thread = new QThread();
        m_tempSocket->moveToThread(m_thread);
        m_thread->start();
        m_tempSocket = 0;
        sendClientList(nextFortune.split(":")[1]);//send the current clientsList to newGuy
        emit displayString("New Client: " + nextFortune.split(":")[1]);
    }else if (nextFortune.left(2) == "M:"){
        sendStringToClient(nextFortune.split(":")[2], nextFortune);//sendSplit[2] a message from split[1]
        emit displayString("Message from: " + nextFortune.split(":")[1] + " to " + nextFortune.split(":")[2]);
    }else if (nextFortune.left(2) == "R:"){
        //disconnectClient(nextFortune.split(":")[1]);
        m_socketList.remove(nextFortune.split(":")[1]);
        sendStringToAllClients(nextFortune);
        emit displayString("Closing client: " + nextFortune.split(":")[1]);
    }else if (nextFortune.left(2) == "S:"){
        sendStringToAllClients("E:" + nextFortune.split(":")[1]);
        sendStringToAllClients("E:" + nextFortune.split(":")[2]);
        sendStringToClient(nextFortune.split(":")[2], nextFortune);
        emit displayString("Starting conversation with: " + nextFortune.split(":")[1] + " and " + nextFortune.split(":")[2]);
    }

    qDebug() << nextFortune;
}
//this should probably be used above when an R: is revieved but it seg faults...is it because the cleint closes the connection faster
void Server::disconnectClient(QString clientName){
    m_socketList[clientName]->disconnectFromHost();
}

void Server::exit(){
    sendStringToAllClients("Server has closed");
}
