#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    connect(ui->msgEdit, SIGNAL(returnPressed()), ui->SendButton, SLOT(click()));
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::setClient(Client *client){
    m_client = client;
    connect(m_client, SIGNAL(recievedMsg(QString)), this, SLOT(recievedMsg(QString)));
    connect(m_client, SIGNAL(removePossibleConnectedClient(QString)), this, SLOT(removePossiblePartner(QString)));
    //good spot to connect more client connections
}

void ChatWindow::on_SendButton_clicked()
{
    m_client->sendMessageToPartner(ui->msgEdit->displayText());
    ui->chatArea->append("<font color=blue>" + m_name + "</font>: " + ui->msgEdit->displayText());
    ui->msgEdit->clear();
}

void ChatWindow::setName(QString name){
    m_name = name;
}

void ChatWindow::recievedMsg(QString msg){
    ui->chatArea->append("<font color=red>" + msg.split(":")[0] + "</font>: " + msg.split(":")[1]);
}

void ChatWindow::closeEvent(QCloseEvent *event)
{
    m_client->exit();
}

void ChatWindow::removePossilePartner(QString client)
{
    qDebug() << "die " << client << " is dead";
    if(client == m_client->getPartner()){
        this->close();
    }
}
