/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#include "clientwindow.h"
#include "ui_clientwindow.h"

//Constructor
clientWindow::clientWindow(QString name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientWindow)
{
    ui->setupUi(this);

    //Initially creating the general chat destination for messages to be sent
    ui -> destinationSelect -> addItem("general");

    //Get name of user
    m_name = name;

    //Start the client object with the name
    m_client = new Client(name,0);
    //Thread
    m_thread = new QThread;
    //Connection for making the client check for messages
    connect(this,SIGNAL(startClient()),m_client,SLOT(doWork()));
    //Start the thread
    m_client->moveToThread(m_thread);
    m_thread->start();

    //Starts the client object working
    emit startClient();

    //Connection for updating the chat log of the GUI
    connect(m_client, SIGNAL(sendToWindow(QString)), this, SLOT(appendToRecieveArea(QString)));

    //Connection to add a client name to the combo box
    connect(m_client, SIGNAL(addClient(QString)), this, SLOT(addClient(QString)));

    //Connection to remove a client name from the combo box
    connect(m_client, SIGNAL(removeClient(QString)), this, SLOT(removeClient(QString)));

    //Connection to attempt to remove the blank window
    connect(m_client, SIGNAL(closeThisWindow()), this, SLOT(closeEarly()));

    //Connection to close the window
    connect(ui -> exitChatButton, SIGNAL(clicked()), this, SLOT(close()));

    //Connection to send a message after the enter or return button was pressed
    connect(ui -> messageLine, SIGNAL(returnPressed()), ui -> sendButton, SLOT(click()));
    this->setWindowTitle(m_name + "'s Chat Window");
}

//Destructor
clientWindow::~clientWindow()
{
    delete ui;
}

//Function to send a message upon the button being clicked
void clientWindow::on_sendButton_clicked()
{
    m_client -> sendMessage(ui  ->messageLine -> displayText(), ui -> destinationSelect -> currentText());
}

//Function to update the chat
void clientWindow::appendToRecieveArea(QString in)
{
    ui -> recieveArea -> append(in);
}

//Function to add a client to the combo box
void clientWindow::addClient(QString in)
{
    //Ensures the current user is not able to send a message to themselves
    if(in != m_name) {
        ui -> destinationSelect -> addItem(in);
    }
}

//Function to remove a client from the combo box
void clientWindow::removeClient(QString in)
{
    ui -> destinationSelect -> removeItem(ui -> destinationSelect -> findText(in));
}

//Attempts to makes the blank window to invisible
void clientWindow::closeEarly()
{
    this -> setVisible(false);

}

//Function to close the object and notify the server of the objet closing
void clientWindow::closeEvent(QCloseEvent *event)
{
    m_client -> exit();
}
