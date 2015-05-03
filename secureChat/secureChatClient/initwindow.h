/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#ifndef INITWINDOW_H
#define INITWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "selectionwindow.h"

namespace Ui {

class InitWindow;

}

class InitWindow : public QMainWindow
{
    Q_OBJECT        //Forward declaration of QObject

public:
    //Constructor
    explicit InitWindow(QWidget *parent = 0);

    //Destructor
    ~InitWindow();

private:
    //Ui object
    Ui::InitWindow *ui;

    //IP address
    QString m_ip;

    //Port number
    QString m_port;

    //Client name
    QString m_name;

    //Client object
    Client *client;

    //Window object for selecting which client to talk to
    SelectionWindow sel;

private slots:
    //Function to update the IP address
    void ipChanged(QString ip);

    //Function to update the port number
    void portChanged(QString port);

    //Function to update the client name
    void nameChanged(QString name);

    //Function to try to connect to the server
    void connectToServer();
};

#endif // INITWINDOW_H
