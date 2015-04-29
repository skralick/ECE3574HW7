/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include "server.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT        //forward declaration macro QObject

public:
    //Constructor
    explicit MainWindow(QWidget *parent = 0);

    //Destructor
    ~MainWindow();

    //Server object
    Server* ser;

private:
    //Ui object
    Ui::MainWindow *ui;

    //Server thread
    QThread *m_thread;

signals:
    //Signal to start the server to do work (check for messages received)
    void startServer();

private slots:
    //Function to update the GUI
    void writeText(QString string);

protected:
    //Function to close the window
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
