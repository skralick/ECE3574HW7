/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#include "clientinit.h"
#include "ui_clientinit.h"

//Constructor
clientInit::clientInit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientInit)
{
    ui->setupUi(this);

    //Initializing the connecting button to disabled
    ui -> connectAsButton -> setEnabled(false);

    //Connection for the button to ping to the server to try to connect
    connect(ui -> connectAsButton, SIGNAL(pressed()), this, SLOT(makeClientWindow()));
}

//Destructor
clientInit::~clientInit()
{
    delete ui;
}

//Function to check for the user input of a name
void clientInit::on_serverNameEdit_textChanged(const QString &arg1)
{
    ui->connectAsButton->setEnabled(arg1 != "");
}

//Function to create the actual chat window
void clientInit::makeClientWindow(){
    //Disables the connect button
    ui -> connectAsButton -> setEnabled(false);

    //Creates the actual chate window
    m_realWindow = new clientWindow("/" + ui -> serverNameEdit -> displayText(), 0);

    //FUnction to make the current window invisible
    this -> setVisible(false);

    //Displays the real window
    m_realWindow -> show();
}
