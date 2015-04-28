#include "clientinit.h"
#include "ui_clientinit.h"

clientInit::clientInit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clientInit)
{
    ui->setupUi(this);

    ui->connectAsButton->setEnabled(false);
    connect(ui->connectAsButton, SIGNAL(pressed()), this, SLOT(makeClientWindow()));
}

clientInit::~clientInit()
{
    delete ui;
}

void clientInit::on_serverNameEdit_textChanged(const QString &arg1)
{
    ui->connectAsButton->setEnabled(arg1 != "");
}
void clientInit::makeClientWindow(){
    ui->connectAsButton->setEnabled(false);
    m_realWindow = new clientWindow("/" + ui->serverNameEdit->displayText(), 0);
    this->setVisible(false);
    m_realWindow->show();
}
