/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#include "selectionwindow.h"
#include "ui_selectionwindow.h"

//Constructor
SelectionWindow::SelectionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectionWindow)
{
    ui->setupUi(this);
}

//Destructor
SelectionWindow::~SelectionWindow()
{
    delete ui;
}

//Sends the string in the line edit
void SelectionWindow::on_sendButton_clicked()
{
    m_client -> sendString(ui -> sendLine -> displayText());
}

//Sets up all the connections to use the window/GUI
void SelectionWindow::setClient(Client *client)
{
    //Sets up the client object
    m_client = client;

    //Connection to update the GUI when receiving a message
    connect(m_client, SIGNAL(recievedString(QString)), ui -> receiveArea, SLOT(append(QString)));

    //Connection to close the window when the object signals it to
    connect(m_client, SIGNAL(closeThisWindow()), this, SLOT(close()));

    //Connection to update the users on the combo box
    connect(m_client, SIGNAL(addClientToList(QString)), this, SLOT(addClientToComboBox(QString)));

    //Connection to begin chatting with a user
    connect(m_client, SIGNAL(startChatWith(QString)), this, SLOT(startChatWith(QString)));

    //Connection to remove a dead client from the combo box
    connect(m_client, SIGNAL(removePossibleClient(QString)), this, SLOT(takeItemFromBox(QString)));
}

//Function to set the name of the client
void SelectionWindow::setName(QString name)
{
    m_name = name;

    this->setWindowTitle(name + "'s Selection Window");
}

//Function to add a client name to the combo box
void SelectionWindow::addClientToComboBox(QString input)
{
    ui -> clientSelectBox -> addItem(input);
}

//Function to set up a chat with another client
void SelectionWindow::startChatWith(QString name)
{
    //Set up communications by getting the name and client object
    m_client -> setPartnerName(name);
    m_chatWindow.setClient(m_client);
    m_chatWindow.setName(m_name);

    connect(&m_chatWindow, SIGNAL(chatClosing()), this, SLOT(show()));
    m_chatWindow.show();
    this -> hide();
}

//Send the server who you want to connect with
void SelectionWindow::on_connectButton_clicked()
{
    //Update the client object and let the server know
    m_client -> setPartnerName(ui -> clientSelectBox -> currentText());
    m_client -> sendString("S:" + m_name + ":" + ui -> clientSelectBox -> currentText());

    //Update GUI
    m_chatWindow.setName(m_name);
    m_chatWindow.setClient(m_client);
    m_chatWindow.show();
    this -> hide();

}

//Closes the window and the client object
void SelectionWindow::closeEvent(QCloseEvent *event)
{
    //Closing the client object
    m_client -> exit();
}

//Function to remove a client name from the combo box
void SelectionWindow::takeItemFromBox(QString item)
{
    ui -> clientSelectBox -> removeItem(ui -> clientSelectBox -> findText(item));
}
