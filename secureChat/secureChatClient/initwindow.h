#ifndef INITWINDOW_H
#define INITWINDOW_H

#include <QMainWindow>
#include "client.h"
#include "selectionwindow.h"

namespace Ui {
class InitWindow;
}

class InitWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InitWindow(QWidget *parent = 0);
    ~InitWindow();

private:
    Ui::InitWindow *ui;
    QString m_ip;
    QString m_port;
    QString m_name;
    Client *client;
    SelectionWindow sel;

private slots:
    void ipChanged(QString ip);
    void portChanged(QString port);
    void nameChanged(QString name);
    void connectToServer();
};

#endif // INITWINDOW_H
