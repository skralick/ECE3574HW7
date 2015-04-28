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
    MainWindow w;
    w.show();

    return a.exec();
}
