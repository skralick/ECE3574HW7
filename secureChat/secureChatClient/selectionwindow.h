/////////////////////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick and Jacky Cheng
//       E-mail:     skralick@vt.edu and jcheng95@vt.edu
//
//
/////////////////////////////////////////////////////////////
#ifndef SELECTIONWINDOW_H
#define SELECTIONWINDOW_H

#include <QWidget>
#include "client.h"
#include "chatwindow.h"
namespace Ui {

class SelectionWindow;

}

class SelectionWindow : public QWidget
{
    Q_OBJECT        //Forward declaration for QObject

public:
    //Constructor
    explicit SelectionWindow(QWidget *parent = 0);

    //Destructor
    ~SelectionWindow();

    //Function to set up client GUI
    void setClient(Client *client);

    //Function to set up name of client
    void setName(QString name);

private slots:
    //Function to update the GUI upon clicking the send button
    void on_sendButton_clicked();

    //Function to add a client name to the combo box
    void addClientToComboBox(QString input);

    //Function to being chatting with another client
    void startChatWith(QString name);

    //Function to update the GUI upon clicking the connect button
    void on_connectButton_clicked();

    //Function to remove a client name from the combo box
    void takeItemFromBox(QString item);

private:
    //Ui object
    Ui::SelectionWindow *ui;

    //Client object
    Client *m_client;

    //Chat window object
    ChatWindow m_chatWindow;

    //Client name
    QString m_name;

protected:
    //Function to close the window
    void closeEvent(QCloseEvent *event);
};

#endif // SELECTIONWINDOW_H
