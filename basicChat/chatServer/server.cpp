/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#include "server.h"

//Constructor
Server::Server()
{

}

//Send a message to all active users
void Server::sendToAllClients(QString sendString)
{
    //Iterate through the hash table
    QHash<QString, int>::iterator i;
    for (i = mq_external.begin(); i != mq_external.end(); ++i) {
        mq_send(i.value(), sendString.toLocal8Bit().data(), sendString.length(), 0);    //Send message
    }
}

//Send the list of all currently active users to a particular user
void Server::sendListOfClients(QString boxName)
{
    //Iterate through the hash table
    QHash<QString, int>::iterator i;
    for (i = mq_external.begin(); i != mq_external.end(); ++i) {
        //Don't send the name of the user to the same person as particular user
        if(boxName != i.key()){
            mq_send(mq_external[boxName], ("new:" + i.key()).toLocal8Bit().data(), ("new:" + i.key()).length(), 0);     //Send mailbox name
        }
    }

}

//Function to perform message receiving and parsing/processing
void Server::doWork()
{
    //Attributes and message queue object for the server mailbox
    struct mq_attr attr;
    mqd_t mq_central;

    //Set up the attributes for the central mailbox.  4 messages are needed
    //to store stores from all four external mailboxes
    //MSG_Size is 50 bytes
    attr.mq_maxmsg = 4;
    attr.mq_msgsize = MSG_SIZE;
    attr.mq_flags = 0;

    //Close the server mailbox to make sure it is unused, before creating it
    mq_unlink(CENTRALBOX);
    mq_central = mq_open(CENTRALBOX, O_RDONLY | O_CREAT, S_IRWXU, &attr);

    //Infinite loop for message receiving and processing
    while (1) {
        //Message receive buffer
        char buf[MSG_SIZE] = "";

        //Check for message being received
        msgVal = mq_receive(mq_central, buf, MSG_SIZE, 0);

        //Check if a message exists
        if (msgVal != -1) {
            //Convert message into readable QString
            QString recMessage = QString::fromLocal8Bit(buf);

            //Check for message tag
            //Message tag to start a new client
            if (recMessage.left(5) == "start") {
                //Add user's name and mailbox
                QString boxName = recMessage.remove("start");
                mq_external[boxName] = (mq_open(boxName.toLocal8Bit().data(), O_RDWR));

                //Notify all clients of the new user and give all the client names to the new user
                sendToAllClients("new:" + boxName);
                sendListOfClients(boxName);

                //Update GUI
                emit sendText("client " + boxName + ": Has joined the chat session");

             //Message tag of a user leaving
             } else if (recMessage.left(4) == "exit") {
                //Notifies all users of the user leaving the chat
                QString boxName = recMessage.remove("exit");
                sendToAllClients("old:" + boxName);

                //Close the connection to the mailbox of the user that left
                mq_close(mq_external[boxName]);

                //Update GUI
                emit sendText("client " + (boxName) + ": Has exited the chat session");

            //Message tag of a general message
            } else if (recMessage.left(7) == "general") {
                //Parses the message received
                QString boxName = recMessage.remove("general").split(":")[0];
                QString msg = recMessage.split(":")[1];
                QString msgSend = QString(buf);

                //Sends the reconfigure message to all clients
                sendToAllClients(msgSend);

                //Update GUI
                emit sendText("client " + boxName + ": " + msg);

            //Private message
            } else {
                //Parses the message received
                QString destination = recMessage.split(":")[0];
                QString message = recMessage.remove(destination);

                //Update GUI
                emit sendText("client " + recMessage.split(":")[1] + " has sent a private message to " + destination + ": "+ recMessage.split(":")[2]);

                //Send the intended user the message
                mq_send(mq_external[destination], (message).toLocal8Bit().data(), (message).length(), 0);
            }
        }
    }

    //Will never reach here

    //Unlink from server mailbox
    mq_unlink(CENTRALBOX);

    //Run through hash to close all connections to all mailboxes
    QHash<QString, int>::iterator i;
    for (i = mq_external.begin(); i != mq_external.end(); ++i) {
        mq_close(i.value());
    }
}

//Function to close all mailbox connections
void Server::killConnections(){
    //Unlink from server mailbox
    mq_unlink(CENTRALBOX);

    //Run through hash to close all connections to all mailboxes
    QHash<QString, int>::iterator i;
        for (i = mq_external.begin(); i != mq_external.end(); ++i)
            mq_close(i.value());
}
