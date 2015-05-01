/****************************************************************************
  From the Qt examples
  Modified for secure socket connection
****************************************************************************/

#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QSslError>
#include <QSslCertificate>
#include <QSslKey>
#include <QTextEdit>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSslSocket>
#include <QSslCertificate>
#include <QWidget>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QMessageBox>
#include <QString>
#include <QStringList>

class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);
    void setPartnerName(QString pName);
    void sendMessageToPartner(QString msg);
    void exit();
    QString getPartner();
public slots:
    void sendString(QString input);
    void requestNewFortune(QString hostIp, QString port, QString name);
private slots:
    //void requestNewFortune();
    //void requestNewFortune(QString hostIp, QString port);
    void readFortune();
    void displayError(QAbstractSocket::SocketError socketError);
    void enableGetFortuneButton();
    void handleSSLError(QList<QSslError>);

private:
    QString getCertificateString(const QSslCertificate&);
    void displayCertificateWindow();
    QTextEdit certificateWindow;

    QSslSocket *secureSocket;
    QString currentFortune;
    quint16 blockSize;
    QString m_name;
    QString m_partnerName;

signals:
    void recievedString(QString string);
    void closeThisWindow();
    void addClientToList(QString name);
    void startChatWith(QString name);
    void recievedMsg(QString msg);
    void removePossibleClient(QString client);
    void removePossibleConnectedClient(QString client);
};

#endif
