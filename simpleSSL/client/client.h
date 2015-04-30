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
public slots:
    void requestNewFortune(QString hostIp, QString port);
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

    //QLabel *hostLabel;
    //QLabel *portLabel;
    //QLineEdit *hostLineEdit;
    //QLineEdit *portLineEdit;
    //QLabel *statusLabel;
    //QPushButton *getFortuneButton;
    //QPushButton *quitButton;
    //QDialogButtonBox *buttonBox;
    QTextEdit certificateWindow;

    QSslSocket *secureSocket;
    QString currentFortune;
    quint16 blockSize;
};

#endif
