#include "serverwindow.h"
#include "ui_serverwindow.h"

serverWindow::serverWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::serverWindow)
{
    ui->setupUi(this);

    m_server = new Server();
    connect(m_server, SIGNAL(displayString(QString)), ui->infoWindow, SLOT(append(QString)));
    m_server->displayServerInfo();
}

serverWindow::~serverWindow()
{
    delete ui;
}
