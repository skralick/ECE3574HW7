/////////////////////////////////////////////
//
//       Assignment: ECE 3574 Homework 7
//
//       Name:       Stephen Kralick
//       E-mail:     skralick@vt.edu
//
//
/////////////////////////////////////////////
#ifndef CLIENTINIT_H
#define CLIENTINIT_H

#include <QWidget>
#include "clientwindow.h"

namespace Ui {
class clientInit;
}

class clientInit : public QWidget
{
    Q_OBJECT        //Forward declaration for macro QObject

public:
    //Constructor
    explicit clientInit(QWidget *parent = 0);

    //Destructor
    ~clientInit();

private slots:
    //Function for checking that the line edit has a name in it
    void on_serverNameEdit_textChanged(const QString &arg1);

    //Function to create the actual chat window
    void makeClientWindow();

private:
    //Ui Object
    Ui::clientInit *ui;

    //Object of the chat window
    clientWindow *m_realWindow;
};

#endif // CLIENTINIT_H
