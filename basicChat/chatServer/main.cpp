/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <mqueue.h>
#include "../include/common.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Creates and displays the main window
    MainWindow w;
    w.show();

    return a.exec();    //Enter the QApplication event loop
}
