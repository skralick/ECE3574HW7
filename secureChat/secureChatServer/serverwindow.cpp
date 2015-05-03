/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#include "serverwindow.h"
#include "ui_serverwindow.h"

//Constructor
serverWindow::serverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serverWindow)
{
    ui->setupUi(this);

    //Sets up the new server object
    m_server = new Server();

    //Connection for the server object to update the GUI after processing the messages received
    connect(m_server, SIGNAL(displayString(QString)), ui->infoWindow, SLOT(append(QString)));

    //Update the QLabel with the server's IP address and port number
    ui->serverInfoLabel -> setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->serverInfoLabel -> setText(m_server -> getServerInfo());
}

//Destructor
serverWindow::~serverWindow()
{
    delete ui;
}

//Function to close the window and get the server object to destruct
//after sending the clsing message to all clients
void serverWindow::closeEvent(QCloseEvent *event)
{
    m_server -> exit();
}
