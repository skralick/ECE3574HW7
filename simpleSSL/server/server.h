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
	void handleNewConnection();
public slots:
    void sendString(QString input);

private:
	SSLServer *sslServer;
	QHash<QString, QSslSocket*> socketList;

};

#endif
