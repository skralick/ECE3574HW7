#include "selectionwindow.h"
#include "ui_selectionwindow.h"

SelectionWindow::SelectionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectionWindow)
{
    ui->setupUi(this);
}

SelectionWindow::~SelectionWindow()
{
    delete ui;
}

void SelectionWindow::on_sendButton_clicked()
{
    m_client->sendString(ui->sendLine->displayText());
}

void SelectionWindow::setClient(Client *client){
    m_client = client;
    connect(m_client, SIGNAL(recievedString(QString)), ui->receiveArea, SLOT(append(QString)));
    connect(m_client, SIGNAL(closeThisWindow()), this, SLOT(close()));
    connect(m_client, SIGNAL(addClientToList(QString)), this, SLOT(addClientToComboBox(QString)));
    connect(m_client, SIGNAL(startChatWith(QString)), this, SLOT(startChatWith(QString)));
    connect(m_client, SIGNAL(removePossibleClient(QString)), this, SLOT(takeItemFromBox(QString)));
}

void SelectionWindow::setName(QString name){
    m_name = name;
}
void SelectionWindow::addClientToComboBox(QString input){
    ui->clientSelectBox->addItem(input);
}
void SelectionWindow::startChatWith(QString name){
    m_client->setPartnerName(name);
    m_chatWindow.setName(m_name);
    m_chatWindow.setClient(m_client);
    m_chatWindow.show();
    this->hide();
}
void SelectionWindow::on_connectButton_clicked()
{
    m_client->setPartnerName(ui->clientSelectBox->currentText());
    m_client->sendString("S:" + m_name + ":" + ui->clientSelectBox->currentText());
    m_chatWindow.setName(m_name);
    m_chatWindow.setClient(m_client);
    m_chatWindow.show();
    this->hide();

}
void SelectionWindow::closeEvent(QCloseEvent *event)
{
    m_client->exit();
}
void SelectionWindow::takeItemFromBox(QString item){
    ui->clientSelectBox->removeItem(ui->clientSelectBox->findText(item));
}
