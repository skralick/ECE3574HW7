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
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Server* ser;

private:
    Ui::MainWindow *ui;
    QThread *m_thread;

signals:
    void startServer();

private slots:
    void writeText(QString string);

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
