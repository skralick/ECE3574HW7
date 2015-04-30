#ifndef SERVER_H
#define SERVER_H

#include <SSLServer.h>
#include <QTcpServer>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QNetworkInterface>

class Server : public QWidget
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);

private slots:
    void sendString();

private:
	SSLServer *sslServer;

};

#endif
