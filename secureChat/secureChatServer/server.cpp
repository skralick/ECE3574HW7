/////////////////////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick and Jacky Cheng
//       E-mail:     skralick@vt.edu and jcheng95@vt.edu
//
//
/////////////////////////////////////////////////////////////
#include "server.h"

//Constructor
Server::Server(QWidget *parent) : QWidget(parent)
{
    //Creates a new SSL server object
    m_sslServer = new SSLServer(this);

    //Check if the server is able to start up
    if (!m_sslServer -> listen()) {
        QMessageBox::critical(this, tr("Secure Fortune Server"),
                              tr("Unable to start the server: %1.")
                              .arg(m_sslServer->errorString()));
        close();
        return;
    }

    //Connection for the server class to handle all new connections by clients
    connect(m_sslServer, SIGNAL(newConnection()), this, SLOT(handleNewConnection()));

    //Displays the server's IP address and port number
    displayServerInfo();
}

//Function to display the server's IP address and port number
void Server::displayServerInfo()
{
    // Finding an open IP address to use
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

    //Emits a signal to display the server's IP address and port number on the GUI
    emit displayString(tr("The server is running on\n\nIP: %1\nport: %2\n\n"
                            "Run the client now.")
                         .arg(ipAddress).arg(m_sslServer -> serverPort()));
}

//Function to retrieve the server IP address and port number
QString Server::getServerInfo()
{
    //Finding an open IP address to use
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

    //Returns the server's IP address and port number
    return (tr("The server is running on\nIP: %1\nport: %2\n"
                            "Run clients now.")
                         .arg(ipAddress).arg(m_sslServer -> serverPort()));
}

//Function to handle a new connection from a client
void Server::handleNewConnection()
{
    //Grabs the next available socket from the SSL server
    m_tempSocket = m_sslServer -> nextPendingConnection();

    //Connection for the socket to be able to send a message and have the server object receive and process the message
    connect(m_tempSocket, SIGNAL(readyRead()), this, SLOT(readIncomingMsg()));

    //Checking for successful encryption handshake
    if (!m_tempSocket -> waitForEncrypted(1000)){
        //qDebug() << "Waited for 1 second for encryption handshake without success";
        return;
    }
    //qDebug() << "Successfully waited for secure handshake...";

    //Connection for the socket to disconnect and have the object be deleted once the event loop can do so
    connect(m_tempSocket, SIGNAL(disconnected()),
            m_tempSocket, SLOT(deleteLater()));
}

//Sends a message to the newly added socket
void Server::sendString(QString input)
{
    //Sets up the data to be sent to the socket
    QByteArray block;

    //Transfers message from the datastream to the block
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    //qDebug() << "In sendClient";
    out << (quint16)0;
    out << input;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));
    qDebug() << "sening a message to most recent socket";
    //Sends the message to the newly added socket
    m_tempSocket->write(block);
    m_tempSocket->flush();
}

//Function to send a message to a particular client
void Server::sendStringToClient(QString client, QString input)
{
    //Sets up the data to be sent to the socket
    QByteArray block;

    //Transfers message from the datastream to the block
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << (quint16)0;
    out << input;
    out.device()->seek(0);
    out << (quint16)(block.size() - sizeof(quint16));

    //Sends the message to the particular client listed in the list of available clients (sockets)
    m_socketList[client]->write(block);
    m_socketList[client]->flush();
}

//Function to send a message to all avaiable clients
void Server::sendStringToAllClients(QString input)
{
    //Iterator for the hash table of SSL sockets
    QHash<QString, QSslSocket*>::const_iterator i = m_socketList.constBegin();

    //Loop through each available clients and send the message
    while (i != m_socketList.constEnd()) {
        sendStringToClient(i.key(), input);
        ++i;
    }
}

//Sends the list of available clients to the newly added client (socket)
void Server::sendClientList(QString destinationClient)
{
    //Hash table iterator for the SSL sockets
    QHash<QString, QSslSocket*>::const_iterator i = m_socketList.constBegin();

    //Loop through sending the active clients to the newly added client (socket)
    while (i != m_socketList.constEnd()) {
        sendStringToClient(destinationClient, "A:" + i.key());
        ++i;
    }
}

//Function to receive and process a message
void Server::readIncomingMsg()
{
    //Preparing for the message
    quint16 blockSize = 0;

    //Default the local socket to be the most recently used socket
    QSslSocket *localSocket = m_tempSocket;

    //Hash table iterator
    QHash<QString, QSslSocket*>::const_iterator i = m_socketList.constBegin();

    //Loop to check for a message from any of the currently available clients (sockets)
    while (i != m_socketList.constEnd()) {
        //qDebug() << i.key() << ": " << i.value()->bytesAvailable() << endl;

        //Check for an available message
        if(i.value() -> bytesAvailable()){
            localSocket = m_socketList[i.key()];
            break;
        }
        ++i;
    }

    //Check if no message was received and the temp socket has not been used
    if (localSocket == 0) {
        return;
    }

    //Get the message from the local socket as a datastream
    QDataStream in(localSocket);
    in.setVersion(QDataStream::Qt_4_0);

    //Check if a message is available
    if (blockSize == 0) {
        //Checks if the message is the wrong size
        if (localSocket -> bytesAvailable() < (int)sizeof(quint16)) {
            return;
        }

        //Read in the message
        in >> blockSize;
    }

    //Checks if the message received by the server is different from the message sent by the client
    if (localSocket -> bytesAvailable() < blockSize) {
        return;
    }

    //New message as a QString
    QString nextFortune;
    in >> nextFortune;

    //Processing the type of message
    //Addition of a new client
    if (nextFortune.left(2) == "A:") {
        //Initially assume the name of the client is not taken
        QString msg = "ConnectionSuccess";

        //Hash table iterator
        QHash<QString, QSslSocket*>::const_iterator i = m_socketList.constBegin();

        //Look to check if the name of the new client is already taken
        while (i != m_socketList.constEnd()) {
            if(i.key() == nextFortune.split(":")[1]){
                qDebug() << "refusing someone service";
                msg = "ClientNameTaken";
                sendString(msg);
                return;
            }
            ++i;
        }

        //Lets the new client know they are now connected
        sendString(msg);

        //Sends all currently active clients the newly added client information
        sendStringToAllClients(nextFortune);

        //Add the newly added client name and socket to the socket hash table
        m_socketList[nextFortune.split(":")[1]] = m_tempSocket;

        //Creates a thread for the newly added client (socket)
        m_thread = new QThread();
        m_tempSocket->moveToThread(m_thread);
        m_thread->start();

        //Refreshes the socket to be blank
        m_tempSocket = 0;

        //Sends the list of all currently active clients to the new client
        sendClientList(nextFortune.split(":")[1]);

        //Update the GUI with the newly added client
        emit displayString("New Client: " + nextFortune.split(":")[1]);

    //Message from one client to another
    } else if (nextFortune.left(2) == "M:") {
        //Sends the whole message to the receiving client
        sendStringToClient(nextFortune.split(":")[2], nextFortune);

        //Update the GUI of the message
        emit displayString("Message from: " + nextFortune.split(":")[1] + " to " + nextFortune.split(":")[2]);

    //Removing a disconnected client
    } else if (nextFortune.left(2) == "R:") {
        //disconnectClient(nextFortune.split(":")[1]);

        //Removes the client socket from the hash table
        m_socketList.remove(nextFortune.split(":")[1]);

        //Sends the message to all clients that the client disconnected
        sendStringToAllClients(nextFortune);

        //Updates the GUI of the disconnected client
        emit displayString("Closing client: " + nextFortune.split(":")[1]);

    //Start of chat communication between two clients
    } else if (nextFortune.left(2) == "S:") {
        //Notifies the clients that they have entered a chat with each other
        sendStringToAllClients("E:" + nextFortune.split(":")[1]);
        sendStringToAllClients("E:" + nextFortune.split(":")[2]);

        //Notifies all other clients of the two chatting clients
        sendStringToClient(nextFortune.split(":")[2], nextFortune);

        //Update GUI of the two clients chatting
        emit displayString("Starting conversation with: " + nextFortune.split(":")[1] + " and " + nextFortune.split(":")[2]);
    } else if (nextFortune.left(2) == "D:") {
        sendStringToAllClients(nextFortune);
    }

    qDebug() << nextFortune;
}
//Is not used because it should only be called once by the client
void Server::disconnectClient(QString clientName)
{
    m_socketList[clientName] -> disconnectFromHost();
}

//Function to notify all clients that the server has shut down
void Server::exit()
{
    sendStringToAllClients("Server has closed");
}
