#include "initwindow.h"
#include "ui_initwindow.h"

InitWindow::InitWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InitWindow)
{
    ui->setupUi(this);

    connect(ui->ipLineEdit, SIGNAL(textChanged(QString)), this, SLOT(ipChanged(QString)));
    connect(ui->portLineEdit, SIGNAL(textChanged(QString)), this, SLOT(portChanged(QString)));
    connect(ui->nameEdit, SIGNAL(textChanged(QString)), this, SLOT(nameChanged(QString)));
    connect(ui->connectToServerButton, SIGNAL(pressed()), this, SLOT(connectToServer()));
    ui->connectToServerButton->setEnabled(false);
}

InitWindow::~InitWindow()
{
    delete ui;
}

void InitWindow::ipChanged(QString ip){
    m_ip = ip;
    if(m_port != "" && m_ip != "" && m_name != ""){
        ui->connectToServerButton->setEnabled(true);
    }else{
        ui->connectToServerButton->setEnabled(false);
    }
}
void InitWindow::portChanged(QString port){
    m_port = port;
    if(m_port != "" && m_ip != "" && m_name != ""){
        ui->connectToServerButton->setEnabled(true);
    }else{
        ui->connectToServerButton->setEnabled(false);
    }
}
void InitWindow::nameChanged(QString name){
    m_name = name;
    if(m_port != "" && m_ip != "" && m_name != ""){
        ui->connectToServerButton->setEnabled(true);
    }else{
        ui->connectToServerButton->setEnabled(false);
    }
}

void InitWindow::connectToServer(){
    client = new Client();
    client->requestNewFortune(m_ip, m_port, m_name);

    sel.setClient(client);
    sel.setName(m_name);
    sel.show();
    this->setVisible(false);
}
