#ifndef SERVERWINDOW_H
#define SERVERWINDOW_H

#include <QMainWindow>
#include "server.h"
namespace Ui {
class serverWindow;
}

class serverWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit serverWindow(QWidget *parent = 0);
    ~serverWindow();

private:
    Ui::serverWindow *ui;
    Server *m_server;
    void closeEvent(QCloseEvent *event);
};

#endif // SERVERWINDOW_H
