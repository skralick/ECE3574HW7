#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include "client.h"

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = 0);
    ~ChatWindow();
    void setClient(Client *client);
    void setName(QString name);

private slots:
    void on_SendButton_clicked();
    void recievedMsg(QString msg);
    void removePossilePartner(QString client);

private:
    Ui::ChatWindow *ui;
    Client *m_client;
    QString m_name;

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // CHATWINDOW_H
