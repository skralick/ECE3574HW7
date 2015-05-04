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
    connect(ui->msgEdit, SIGNAL(returnPressed()), ui->SendButton, SLOT(click()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));
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
    if(m_client == client){
        shouldConnect = false;
    }
    //Set up the client object
    m_client = client;
    if(shouldConnect){
        //Connection for receiving a message and updating the GUI
        connect(m_client, SIGNAL(recievedMsg(QString)), this, SLOT(recievedMsg(QString)));

        //Connection to remove connection to another client
        //connect(m_client, SIGNAL(removePossibleConnectedClient(QString)), this, SLOT(removePossiblePartner(QString)));
        //good spot to connect more client connections

        connect(m_client, SIGNAL(writeStringToChatWindow(QString)), ui->chatArea, SLOT(append(QString)));
    }
}


//Function to update the chat window once connected to the other client
void ChatWindow::on_SendButton_clicked()
{
    m_client -> sendMessageToPartner(ui -> msgEdit -> displayText());
    ui -> chatArea -> append("<font color=blue>" + m_name + "</font>: " + ui -> msgEdit -> displayText());
    ui -> msgEdit -> clear();
}

//Function to set up the client name
void ChatWindow::setName(QString name)
{
    m_name = name;
    this->setWindowTitle(name + "'s Chat Window");
}

void ChatWindow::recievedMsg(QString msg)
{
    qDebug() << "revieved x times";
    ui->chatArea->append("<font color=red>" + msg.split(":")[0] + "</font>: " + msg.split(":")[1]);
}

//Function to close the window and client object
void ChatWindow::closeEvent(QCloseEvent *event)
{
    emit chatClosing();
    m_client -> endChat();
    //Closing client object
    //m_client -> exit();
}

//Function to remove the connection to the partner client and close the window
void ChatWindow::removePossilePartner(QString client)
{
    if (client == m_client -> getPartner()) {
        this -> close();
    }
}
