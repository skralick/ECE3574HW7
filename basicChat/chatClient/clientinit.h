#ifndef CLIENTINIT_H
#define CLIENTINIT_H

#include <QWidget>
#include "clientwindow.h"

namespace Ui {
class clientInit;
}

class clientInit : public QWidget
{
    Q_OBJECT

public:
    explicit clientInit(QWidget *parent = 0);
    ~clientInit();

private slots:
    void on_serverNameEdit_textChanged(const QString &arg1);
    void makeClientWindow();

private:
    Ui::clientInit *ui;
    clientWindow *m_realWindow;
};

#endif // CLIENTINIT_H
