/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#include "serverwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    serverWindow w;
    w.show();

    return a.exec();    //Returns the QApplication event loop
}
