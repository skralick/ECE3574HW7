#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include "client.h"
namespace Ui {
class clientWindow;
}

class clientWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit clientWindow(QString name, QWidget *parent = 0);
    ~clientWindow();

private:
    Ui::clientWindow *ui;

    QString m_name;
    QThread *m_thread;
    Client *m_client;

signals:
    void startClient(void);
private slots:
    void on_sendButton_clicked();
    void appendToRecieveArea(QString in);
    void addClient(QString in);
    void removeClient(QString in);
    void on_exitChatButton_clicked();
    void closeEarly();

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // CLIENTWINDOW_H
