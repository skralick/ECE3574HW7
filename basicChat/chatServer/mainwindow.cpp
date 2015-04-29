/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#include "mainwindow.h"
#include "ui_mainwindow.h"

//COnstructor
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Server object
    ser = new Server();

    //THread for server
    m_thread = new QThread;

    //Connection to signal the server class to start working and checking for messages
    connect(this, SIGNAL(startServer()), ser, SLOT(doWork()));

    //Connection to notify the GUI to update
    connect(ser, SIGNAL(sendText(QString)), this, SLOT(writeText(QString)));

    //Start the thread
    ser->moveToThread(m_thread);
    m_thread->start();

    //Start the server working to check for messages
    emit startServer();
}

//Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

//Function to write to the text edit inorder to update the GUI on messages
void MainWindow::writeText(QString string){
    ui -> msgArea -> append(string);
}

//Function to close the window and end the server object
void MainWindow::closeEvent(QCloseEvent *event)
{
    //Signals the server object to remove all connections to mailboxes
    ser -> killConnections();
}
