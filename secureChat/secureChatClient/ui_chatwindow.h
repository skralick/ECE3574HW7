/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QTextEdit *chatArea;
    QLineEdit *msgEdit;
    QPushButton *exitButton;
    QPushButton *SendButton;

    void setupUi(QWidget *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName(QStringLiteral("ChatWindow"));
        ChatWindow->resize(372, 310);
        chatArea = new QTextEdit(ChatWindow);
        chatArea->setObjectName(QStringLiteral("chatArea"));
        chatArea->setGeometry(QRect(10, 10, 351, 211));
        msgEdit = new QLineEdit(ChatWindow);
        msgEdit->setObjectName(QStringLiteral("msgEdit"));
        msgEdit->setGeometry(QRect(12, 230, 341, 31));
        exitButton = new QPushButton(ChatWindow);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(120, 270, 111, 27));
        SendButton = new QPushButton(ChatWindow);
        SendButton->setObjectName(QStringLiteral("SendButton"));
        SendButton->setGeometry(QRect(240, 270, 111, 27));

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QWidget *ChatWindow)
    {
        ChatWindow->setWindowTitle(QApplication::translate("ChatWindow", "Form", 0));
        exitButton->setText(QApplication::translate("ChatWindow", "Exit", 0));
        SendButton->setText(QApplication::translate("ChatWindow", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
