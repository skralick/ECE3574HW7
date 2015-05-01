#ifndef SELECTIONWINDOW_H
#define SELECTIONWINDOW_H

#include <QWidget>
#include "client.h"
#include "chatwindow.h"
namespace Ui {
class SelectionWindow;
}

class SelectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SelectionWindow(QWidget *parent = 0);
    ~SelectionWindow();
    void setClient(Client *client);
    void setName(QString name);

private slots:
    void on_sendButton_clicked();
    void addClientToComboBox(QString input);
    void startChatWith(QString name);
    void on_connectButton_clicked();
    void takeItemFromBox(QString item);

private:
    Ui::SelectionWindow *ui;
    Client *m_client;
    ChatWindow m_chatWindow;
    QString m_name;

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // SELECTIONWINDOW_H
