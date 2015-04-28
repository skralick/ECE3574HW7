#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->msgArea->setText("thisis text");

    ser = new Server();
    m_thread = new QThread;
    connect(this,SIGNAL(startServer()),ser,SLOT(doWork()));
    connect(ser,SIGNAL(sendText(QString)),this,SLOT(writeText(QString)));
    ser->moveToThread(m_thread);
    m_thread->start();
    emit startServer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeText(QString string){
    ui->msgArea->append(string);
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    ser->killConnections();
}
