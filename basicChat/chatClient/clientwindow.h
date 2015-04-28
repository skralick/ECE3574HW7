/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QMainWindow>
#include "client.h"
namespace Ui {
class clientWindow;
}

class clientWindow : public QMainWindow
{
    Q_OBJECT        //Forward declaration macro for QObject

public:
    //Constructor
    explicit clientWindow(QString name, QWidget *parent = 0);

    //Destructor
    ~clientWindow();

private:
    //Ui object
    Ui::clientWindow *ui;

    //Mailbox name
    QString m_name;

    //GUI thread
    QThread *m_thread;

    //Client object
    Client *m_client;

signals:
    //Signal to have the client start checking for messages in its mailbox
    void startClient(void);

private slots:
    //Function to send a message upon the button being clicked
    void on_sendButton_clicked();

    //Function to update the chat log
    void appendToRecieveArea(QString in);

    //Function to add a client name to the combo box
    void addClient(QString in);

    //Function to remove a client name from the combo box
    void removeClient(QString in);

    //Function attempting to remove the blank window
    void closeEarly();

protected:
    //Function to close the window
    void closeEvent(QCloseEvent *event);
};

#endif // CLIENTWINDOW_H
