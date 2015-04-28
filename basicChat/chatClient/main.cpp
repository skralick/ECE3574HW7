/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#include "clientinit.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //Checked for the command line argument for the number of client
    if( argc != 2){
        qDebug() << "chatClient missing number of clients: usage ./chatClient num_clients";
        return 1;
    }

    //Extract the value of the command line argument
    bool ok;
    int clientCount = QString::fromLocal8Bit(argv[1]).toInt(&ok, 10);
    if( !ok ){
        qDebug() << "Not a number: usage ./chatClient num_clients";
        return 1;
    }

    //Creating the inputted number of client windows
    clientInit* windows[clientCount];

    //Display every window
    for(int i = 0; i < clientCount; i++){
        windows[i] = new clientInit();
        windows[i]->show();
    }

    return a.exec();    //Run the QApplication Event Loop
}
