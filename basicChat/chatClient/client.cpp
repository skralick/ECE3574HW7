
#include "client.h"

Client::Client(QString name, QObject* parent)
{
    setParent(parent);
    //m_boxName = MAILBASE + QString::number(m_id);
    m_boxName = name;
    m_shouldDie = false;
    m_attr.mq_maxmsg = 2;
    m_attr.mq_msgsize = MSG_SIZE;
    m_attr.mq_flags = 0;

    //mq_unlink(m_boxName.toLocal8Bit().data());
    m_clientBox = mq_open(m_boxName.toLocal8Bit().data(), O_RDONLY | O_CREAT | O_EXCL, S_IRWXU, &m_attr);
    if( m_clientBox == -1){
        QMessageBox msgBox;
        msgBox.setText("This name has already been used!");
        emit closeThisWindow();
        msgBox.exec();
        emit closeThisWindow();
        m_shouldDie = true;
    }
    mq_centralBox = mq_open(CENTRALBOX, O_RDWR);
    if(mq_centralBox == -1){
        QMessageBox msgBox;
        msgBox.setText("The server hasnt been started!");
        emit closeThisWindow();
        msgBox.exec();
        emit closeThisWindow();
        m_shouldDie = true;
    }
    char buf[MSG_SIZE];
    sprintf(buf, "start%s", m_boxName.toLocal8Bit().data());
    mq_send(mq_centralBox, buf, strlen(buf), 0);
}

void Client::doWork()
{
    if(m_shouldDie){
        emit closeThisWindow();
    }

    //char *buf = "general 1: thi";
    //int temp = mq_send(mq_centralBox, buf, strlen(buf), 0);
    while(1){
        char recieveBuffer[MSG_SIZE];
        int msgVal = mq_receive(m_clientBox, recieveBuffer, MSG_SIZE, 0);
        recieveBuffer[msgVal] = 0;
        if(msgVal != -1){
            //QString a(recieveBuffer);
            if( QString(recieveBuffer).left(3) == "new"){
                emit addClient(QString(recieveBuffer).split(":")[1]);
            }else if( QString(recieveBuffer).left(3) == "old"){
                emit removeClient(QString(recieveBuffer).split(":")[1]);
            }else{
                QString temp = QString(recieveBuffer);
                QString out = "";
                if(temp.left(7) == "general"){
                    temp.remove("general");
                    out += "client " + temp.split(":")[0] + ":"+ temp.split(":")[1];
                }else{
                    out += "client " + temp.split(":")[1] + " has sent a private message to " + m_boxName + ": " + temp.split(":")[2];
                }
                emit sendToWindow(out);
            }
        }

    }
}

void Client::sendMessage(QString msg, QString destination){
    char buf[MSG_SIZE];
    if(destination == "general"){
        sprintf(buf, "%s%s: %s", destination.toLocal8Bit().data(), m_boxName.toLocal8Bit().data(), msg.toLocal8Bit().data());
    }else{
        sprintf(buf, "%s:%s: %s", destination.toLocal8Bit().data(), m_boxName.toLocal8Bit().data(), msg.toLocal8Bit().data());
    }
    mq_send(mq_centralBox, buf, strlen(buf), 0);
}

void Client::exit(){
    char buf[MSG_SIZE];
    sprintf(buf, "exit%s", m_boxName.toLocal8Bit().data());
    mq_send(mq_centralBox, buf, strlen(buf), 0);
    mq_unlink(m_boxName.toLocal8Bit().data());
}
