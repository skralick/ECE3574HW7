/********************************************************************************
** Form generated from reading UI file 'listwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTWINDOW_H
#define UI_LISTWINDOW_H

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

class Ui_listWindow
{
public:
    QLineEdit *sendEdit;
    QPushButton *sendButton;
    QTextEdit *receiveArea;

    void setupUi(QWidget *listWindow)
    {
        if (listWindow->objectName().isEmpty())
            listWindow->setObjectName(QStringLiteral("listWindow"));
        listWindow->resize(499, 325);
        sendEdit = new QLineEdit(listWindow);
        sendEdit->setObjectName(QStringLiteral("sendEdit"));
        sendEdit->setGeometry(QRect(10, 20, 471, 27));
        sendButton = new QPushButton(listWindow);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(380, 60, 99, 27));
        receiveArea = new QTextEdit(listWindow);
        receiveArea->setObjectName(QStringLiteral("receiveArea"));
        receiveArea->setGeometry(QRect(13, 97, 471, 211));

        retranslateUi(listWindow);

        QMetaObject::connectSlotsByName(listWindow);
    } // setupUi

    void retranslateUi(QWidget *listWindow)
    {
        listWindow->setWindowTitle(QApplication::translate("listWindow", "Form", 0));
        sendButton->setText(QApplication::translate("listWindow", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class listWindow: public Ui_listWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTWINDOW_H
