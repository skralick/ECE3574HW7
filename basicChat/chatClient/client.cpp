/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#include "client.h"

//Constructor
Client::Client(QString name, QObject* parent)
{
    setParent(parent);

    //Initializes the client name to the name inputted by the user
    m_boxName = name;

    //Window should not close
    m_shouldDie = false;

    //Message queue attributes
    m_attr.mq_maxmsg = 2;           //Maximum number of messages is 2
    m_attr.mq_msgsize = MSG_SIZE;   //Maximum message length is 50 bytes
    m_attr.mq_flags = 0;            //No flags should be used

    //Opens the mailbox
    m_clientBox = mq_open(m_boxName.toLocal8Bit().data(), O_RDONLY | O_CREAT | O_EXCL, S_IRWXU, &m_attr);

    //Checks if the open failed
    if( m_clientBox == (mqd_t)-1) {
        //Sends an error of a repeated mailox/username
        QMessageBox msgBox;
        msgBox.setText("This name has already been used!");

        //Commands the client window close and execute the message box
        emit closeThisWindow();
        msgBox.exec();
        emit closeThisWindow();
        m_shouldDie = true;
    }

    //Connect to the server/central mailbox
    mq_centralBox = mq_open(CENTRALBOX, O_RDWR);

    //Checks if the server exists
    if(mq_centralBox == (mqd_t)-1) {
        //Sends an error message of the server not existing
        QMessageBox msgBox;
        msgBox.setText("The server hasnt been started!");

        //Commands the client window close and execute the message box
        emit closeThisWindow();
        msgBox.exec();
        emit closeThisWindow();
        m_shouldDie = true;
    }
    //Creates the message buffer
    char buf[MSG_SIZE];

    //Notifies the server of starting
    sprintf(buf, "start%s", m_boxName.toLocal8Bit().data());
    mq_send(mq_centralBox, buf, strlen(buf), 0);
}

//Function to check for a message receive and process the mesage
void Client::doWork()
{
    //Check whether or not the window should close
    if(m_shouldDie) {
        emit closeThisWindow();
    }

    //Infinite loop for message receiving
    while(1) {
        //Message receive buffer
        char recieveBuffer[MSG_SIZE];

        //Check the mailbox
        int msgVal = mq_receive(m_clientBox, recieveBuffer, MSG_SIZE, 0);

        //Clean the receive meessage buffer
        recieveBuffer[msgVal] = 0;

        //Check if a message exists
        if(msgVal != -1) {
            //Check for instruction type tag
                //New user
            if( QString(recieveBuffer).left(3) == "new") {
                emit addClient(QString(recieveBuffer).split(":")[1]);
                //User leaving
            } else if( QString(recieveBuffer).left(3) == "old"){
                emit removeClient(QString(recieveBuffer).split(":")[1]);
                //General or private message
            } else {
                QString temp = QString(recieveBuffer);
                QString out = "";
                //Check if the message is a general message
                if(temp.left(7) == "general") {
                    temp.remove("general");
                    out += "client " + temp.split(":")[0] + ":"+ temp.split(":")[1];
                //Private message
                } else {
                    out += "client " + temp.split(":")[1] + " has sent a private message to " + m_boxName + ": " + temp.split(":")[2];
                }
                //Update GUI
                emit sendToWindow(out);
            }
        }

    }
}

//Function to send a message
void Client::sendMessage(QString msg, QString destination)
{
    char buf[MSG_SIZE];
    //Checks for a general message and formats
    if(destination == "general") {
        sprintf(buf, "%s%s: %s", destination.toLocal8Bit().data(), m_boxName.toLocal8Bit().data(), msg.toLocal8Bit().data());
    //Private message
    } else {
        sprintf(buf, "%s:%s: %s", destination.toLocal8Bit().data(), m_boxName.toLocal8Bit().data(), msg.toLocal8Bit().data());
    }
    //Sends message to server
    mq_send(mq_centralBox, buf, strlen(buf), 0);
}

//Function to let the server know the user is leaving and then removing connections to the user's mailbox
void Client::exit()
{
    char buf[MSG_SIZE];

    //Sends the server the message
    sprintf(buf, "exit%s", m_boxName.toLocal8Bit().data());
    mq_send(mq_centralBox, buf, strlen(buf), 0);

    //Removes connections to the mailbox
    mq_unlink(m_boxName.toLocal8Bit().data());
}
