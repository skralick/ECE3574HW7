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
    Q_OBJECT

public:
    Server(QWidget *parent = 0);

private slots:
    void handleNewConnection();
    void readIncomingMsg();

public slots:
    void sendString(QString input);
    void sendStringToAllClients(QString input);
    void sendStringToClient(QString client, QString input);
    void sendClientList(QString destinationClient);
    void disconnectClient(QString clientName);
    void displayServerInfo();

signals:
    void displayString(QString);

private:
    SSLServer *sslServer;
    QSslSocket *tempSocket;
    QHash<QString, QSslSocket*> socketList;
    QThread *m_thread;

};

#endif
