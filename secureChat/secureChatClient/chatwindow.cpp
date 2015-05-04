/////////////////////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick and Jacky Cheng
//       E-mail:     skralick@vt.edu and jcheng95@vt.edu
//
//
/////////////////////////////////////////////////////////////
#include "chatwindow.h"
#include "ui_chatwindow.h"

//Constructor
ChatWindow::ChatWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);

    //Connection to send a message using the enter button as if the send button was clicked
    connect(ui -> msgEdit, SIGNAL(returnPressed()), ui -> SendButton, SLOT(click()));

    //Connection to connect the quit button to closing the window
    connect(ui -> exitButton, SIGNAL(clicked()), this, SLOT(close()));
}

//Destructor
ChatWindow::~ChatWindow()
{
    delete ui;
}

//Function to set up the client object and its connections to the GUI
void ChatWindow::setClient(Client *client)
{
    bool shouldConnect = true;
    if (m_client == client) {
        shouldConnect = false;
        ui -> chatArea -> clear();
    }
    //Set up the client object
    m_client = client;
    if (shouldConnect) {
        //Connection for receiving a message and updating the GUI
        connect(m_client, SIGNAL(recievedMsg(QString)), this, SLOT(recievedMsg(QString)));

        //Connection to update the GUI after the client sends its message
        connect(m_client, SIGNAL(writeStringToChatWindow(QString)), ui -> chatArea, SLOT(append(QString)));
    }
}


//Function to update the chat window once connected to the other client
void ChatWindow::on_SendButton_clicked()
{
    //Send message through client object
    m_client -> sendMessageToPartner(ui -> msgEdit -> displayText());

    //Update GUI
    ui -> chatArea -> append("<font color=blue>" + m_name + "</font>: " + ui -> msgEdit -> displayText());
    ui -> msgEdit -> clear();
}

//Function to set up the client name
void ChatWindow::setName(QString name)
{
    m_name = name;
    this -> setWindowTitle(name + "'s Chat Window");
}

//Funtion to update the GUI from a received message
void ChatWindow::recievedMsg(QString msg)
{
    ui -> chatArea -> append("<font color=red>" + msg.split(":")[0] + "</font>: " + msg.split(":")[1]);
}

//Function to close the window and client object
void ChatWindow::closeEvent(QCloseEvent *event)
{
    //Emits the signal that the client is leaving the chat
    emit chatClosing();

    //Ends the chat with the partner
    m_client -> endChat();
}

//Function to remove the connection to the partner client and close the window
void ChatWindow::removePossilePartner(QString client)
{
    if (client == m_client -> getPartner()) {
        this -> close();
    }
}
