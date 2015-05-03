/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include "client.h"

namespace Ui {

class ChatWindow;

}

class ChatWindow : public QWidget
{
    Q_OBJECT        //Forward declaration of QObject

public:
    //Constructor
    explicit ChatWindow(QWidget *parent = 0);

    //Destructor
    ~ChatWindow();

    //Function to set up the client object
    void setClient(Client *client);

    //Function to set up the client name
    void setName(QString name);

private slots:
    //Function to update the GUI upon connecting to the other client
    void on_SendButton_clicked();

    //Function to update the GUI with a newly received message
    void recievedMsg(QString msg);

    //Function to remove connection to another client
    void removePossilePartner(QString client);

private:
    //Ui object
    Ui::ChatWindow *ui;

    //Client object
    Client *m_client;

    //Client name
    QString m_name;

protected:
    //Function to clsoe the window
    void closeEvent(QCloseEvent *event);
};

#endif // CHATWINDOW_H
