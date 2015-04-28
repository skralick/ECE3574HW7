#include "clientwindow.h"
#include "ui_clientwindow.h"

clientWindow::clientWindow(QString name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientWindow)
{
    ui->setupUi(this);

    ui->destinationSelect->addItem("general");
    m_name = name;
    m_client = new Client(name,0);
    m_thread = new QThread;
    connect(this,SIGNAL(startClient()),m_client,SLOT(doWork()));
    m_client->moveToThread(m_thread);
    m_thread->start();
    emit startClient();
    //connect(ui->exitChatButton, SIGNAL(clicked()), m_client, SLOT(exit()));
    connect(m_client, SIGNAL(sendToWindow(QString)), this, SLOT(appendToRecieveArea(QString)));
    connect(m_client, SIGNAL(addClient(QString)), this, SLOT(addClient(QString)));
    connect(m_client, SIGNAL(removeClient(QString)), this, SLOT(removeClient(QString)));
    connect(m_client, SIGNAL(closeThisWindow()), this, SLOT(closeEarly()));
    connect(ui->exitChatButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->messageLine, SIGNAL(returnPressed()), ui->sendButton, SLOT(click()));
    this->setWindowTitle(m_name + "'s Chat Window");
}

clientWindow::~clientWindow()
{
    delete ui;
}

void clientWindow::on_sendButton_clicked()
{
    m_client->sendMessage(ui->messageLine->displayText(), ui->destinationSelect->currentText());
}

void clientWindow::appendToRecieveArea(QString in){
    ui->recieveArea->append(in);
}
void clientWindow::addClient(QString in){
    if(in != m_name){
        ui->destinationSelect->addItem(in);
    }
}

void clientWindow::removeClient(QString in){
    ui->destinationSelect->removeItem(ui->destinationSelect->findText(in));
}

void clientWindow::on_exitChatButton_clicked()
{
    //m_client->exit();
    //this->close();
}

void clientWindow::closeEarly()
{
    this->setVisible(false);
    //this->close();

}

void clientWindow::closeEvent(QCloseEvent *event)
{
    m_client->exit();
}
