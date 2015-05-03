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
    void exit();

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
    QString getServerInfo();

signals:
    void displayString(QString);

private:
    SSLServer *m_sslServer;
    QSslSocket *m_tempSocket;
    QHash<QString, QSslSocket*> m_socketList;
    QThread *m_thread;

};

#endif
