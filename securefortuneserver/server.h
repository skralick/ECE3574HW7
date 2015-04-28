/****************************************************************************
  From Qt Examples
****************************************************************************/

#ifndef SERVER_H
#define SERVER_H

#include <SSLServer.h>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QTcpServer>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

class Server : public QDialog
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);

private slots:
    void sendFortune();

private:
    QLabel *statusLabel;
    QPushButton *quitButton;
    SSLServer *sslServer;
    QStringList fortunes;
};

#endif
