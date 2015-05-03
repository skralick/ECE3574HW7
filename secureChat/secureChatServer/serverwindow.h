/////////////////////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick and Jacky Cheng
//       E-mail:     skralick@vt.edu and jcheng95@vt.edu
//
//
/////////////////////////////////////////////////////////////
#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include "server.h"
namespace Ui {
class serverWindow;
}

class serverWindow : public QMainWindow
{
    Q_OBJECT        //Forward declaration of QObject macro

public:
    //Constructor
    explicit serverWindow(QWidget *parent = 0);

    //Destructor
    ~serverWindow();

private:
    //Ui object
    Ui::serverWindow *ui;

    //Server object
    Server *m_server;

    //Function to close the window and destruct the server object
    void closeEvent(QCloseEvent *event);
};

#endif // SERVERWINDOW_H
