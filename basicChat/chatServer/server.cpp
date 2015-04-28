#include "server.h"

Server::Server(){

}

void Server::sendToAllClients(QString sendString){
    QHash<QString, int>::iterator i;
    for (i = mq_external.begin(); i != mq_external.end(); ++i){
        mq_send(i.value(), sendString.toLocal8Bit().data(), sendString.length(), 0);
    }
}

void Server::sendListOfClients(QString boxName){
    QHash<QString, int>::iterator i;
    for (i = mq_external.begin(); i != mq_external.end(); ++i){
        if(boxName != i.key()){
            mq_send(mq_external[boxName], ("new:" + i.key()).toLocal8Bit().data(), ("new:" + i.key()).length(), 0);
        }
    }

}

void Server::doWork(){
    //mqd_t mq_external[4], mq_central;
    struct mq_attr attr;
    //QVector <mqd_t> mq_external;
    mqd_t mq_central;

    // Set up the attributes for the central mailbox.  4 messages are needed 
    // to store stores from all four external mailboxes
    attr.mq_maxmsg = 4;
    attr.mq_msgsize = MSG_SIZE;
    attr.mq_flags = 0;

    // Close the central mailbox to make sure it is unused, before creating it
    mq_unlink(CENTRALBOX);
    mq_central = mq_open(CENTRALBOX, O_RDONLY | O_CREAT, S_IRWXU, &attr);

    while(1){
        char buf[MSG_SIZE] = "";
        mq_receive(mq_central, buf, MSG_SIZE, 0);
        QString recMessage = QString::fromLocal8Bit(buf);
        if(recMessage.left(5) == "start"){
            QString boxName = recMessage.remove("start");
            mq_external[boxName] = (mq_open(boxName.toLocal8Bit().data(), O_RDWR));
            sendToAllClients("new:" + boxName);
            sendListOfClients(boxName);
            emit sendText("client " + boxName + ": Has joined the chat session");
        }else if(recMessage.left(4) == "exit"){
            QString boxName = recMessage.remove("exit");
            sendToAllClients("old:" + boxName);
            mq_close(mq_external[boxName]);//we wanna close here
            emit sendText("client " + (boxName) + ": Has exited the chat session");
        }else if(recMessage.left(7) == "general"){
            QString boxName = recMessage.remove("general").split(":")[0];
            QString msg = recMessage.split(":")[1];
            QString msgSend = QString(buf);
            sendToAllClients(msgSend);
            emit sendText("client " + boxName + ": " + msg);
        }else{
            QString destination = recMessage.split(":")[0];
            QString message = recMessage.remove(destination);
            emit sendText("client " + recMessage.split(":")[1] + " has sent a private message to " + destination + ": "+ recMessage.split(":")[2]);
            mq_send(mq_external[destination], (message).toLocal8Bit().data(), (message).length(), 0);
        }
    }

    // Close all mailboxes
    mq_unlink(CENTRALBOX);
    QHash<QString, int>::iterator i;
        for (i = mq_external.begin(); i != mq_external.end(); ++i)
            mq_close(i.value());
    //mq_close(mq_external[0]);
    //mq_close(mq_external[1]);
    //mq_close(mq_external[2]);
    //mq_close(mq_external[3]);
}

void Server::killConnections(){
    mq_unlink(CENTRALBOX);
    QHash<QString, int>::iterator i;
        for (i = mq_external.begin(); i != mq_external.end(); ++i)
            mq_close(i.value());
}
