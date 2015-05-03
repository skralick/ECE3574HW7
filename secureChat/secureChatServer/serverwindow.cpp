#include "serverwindow.h"
#include "ui_serverwindow.h"

serverWindow::serverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serverWindow)
{
    ui->setupUi(this);

    m_server = new Server();
    connect(m_server, SIGNAL(displayString(QString)), ui->infoWindow, SLOT(append(QString)));
    ui->serverInfoLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    ui->serverInfoLabel->setText(m_server->getServerInfo());
}

serverWindow::~serverWindow()
{
    delete ui;
}

void serverWindow::closeEvent(QCloseEvent *event)
{
    m_server->exit();
}
