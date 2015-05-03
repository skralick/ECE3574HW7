/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#include "initwindow.h"
#include "ui_initwindow.h"

//Constructor
InitWindow::InitWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InitWindow)
{
    ui -> setupUi(this);

    //Connection to update the IP address if the IP address in the GUI is updated
    connect(ui -> ipLineEdit, SIGNAL(textChanged(QString)), this, SLOT(ipChanged(QString)));

    //Connection to update the port number if the port number in the GUI is update
    connect(ui -> portLineEdit, SIGNAL(textChanged(QString)), this, SLOT(portChanged(QString)));

    //Connection to update the client name when the GUI is updated
    connect(ui -> nameEdit, SIGNAL(textChanged(QString)), this, SLOT(nameChanged(QString)));

    //Connection to attempt to connect to the server once the connect button is pressed
    connect(ui -> connectToServerButton, SIGNAL(pressed()), this, SLOT(connectToServer()));

    //Initially disable the connect button
    //Should only be enabled when the user has a client name
    ui -> connectToServerButton->setEnabled(false);

    this->setWindowTitle("Server Connection Window");
}

//Destructor
InitWindow::~InitWindow()
{
    delete ui;
}

//Function to update the IP address and update the connect button only when the name, IP address, and port number are not blank
void InitWindow::ipChanged(QString ip)
{
    //Update the IP address
    m_ip = ip;

    //Enabling or disabling the conenct button baesd on the IP address, port number, and client name
    if (m_port != "" && m_ip != "" && m_name != "") {
        ui -> connectToServerButton -> setEnabled(true);
    } else {
        ui -> connectToServerButton -> setEnabled(false);
    }
}

//Function to update the port number and update the connect button only when the name, IP address, and port number are not blank
void InitWindow::portChanged(QString port)
{
    //Update the port number
    m_port = port;

    //Enabling or disabling the conenct button baesd on the IP address, port number, and client name
    if(m_port != "" && m_ip != "" && m_name != ""){
        ui -> connectToServerButton -> setEnabled(true);
    }else{
        ui -> connectToServerButton -> setEnabled(false);
    }
}

//Function to update the client name and update the connect button only when the name, IP address, and port number are not blank
void InitWindow::nameChanged(QString name)
{
    //Update the client name
    m_name = name;

    //Enabling or disabling the conenct button baesd on the IP address, port number, and client name
    if(m_port != "" && m_ip != "" && m_name != ""){
        ui -> connectToServerButton -> setEnabled(true);
    }else{
        ui -> connectToServerButton -> setEnabled(false);
    }
}

//Function to attempt to connect to the server
void InitWindow::connectToServer()
{
    //Create a new client object
    client = new Client();

    //Make client request for a fortune
    client -> requestNewFortune(m_ip, m_port, m_name);

    //Update the selection window
    sel.setClient(client);
    sel.setName(m_name);
    sel.show();

    //Make this window appear as if it closed
    this -> setVisible(false);
}
