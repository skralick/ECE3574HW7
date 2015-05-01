/********************************************************************************
** Form generated from reading UI file 'selectionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTIONWINDOW_H
#define UI_SELECTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectionWindow
{
public:
    QLineEdit *sendLine;
    QPushButton *sendButton;
    QTextEdit *receiveArea;
    QComboBox *clientSelectBox;
    QPushButton *connectButton;
    QLabel *label;

    void setupUi(QWidget *SelectionWindow)
    {
        if (SelectionWindow->objectName().isEmpty())
            SelectionWindow->setObjectName(QStringLiteral("SelectionWindow"));
        SelectionWindow->resize(832, 350);
        sendLine = new QLineEdit(SelectionWindow);
        sendLine->setObjectName(QStringLiteral("sendLine"));
        sendLine->setGeometry(QRect(12, 80, 261, 31));
        sendButton = new QPushButton(SelectionWindow);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(288, 80, 91, 27));
        receiveArea = new QTextEdit(SelectionWindow);
        receiveArea->setObjectName(QStringLiteral("receiveArea"));
        receiveArea->setGeometry(QRect(13, 120, 371, 221));
        clientSelectBox = new QComboBox(SelectionWindow);
        clientSelectBox->setObjectName(QStringLiteral("clientSelectBox"));
        clientSelectBox->setGeometry(QRect(14, 30, 251, 27));
        connectButton = new QPushButton(SelectionWindow);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setGeometry(QRect(280, 30, 99, 27));
        label = new QLabel(SelectionWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 231, 17));

        retranslateUi(SelectionWindow);

        QMetaObject::connectSlotsByName(SelectionWindow);
    } // setupUi

    void retranslateUi(QWidget *SelectionWindow)
    {
        SelectionWindow->setWindowTitle(QApplication::translate("SelectionWindow", "Form", 0));
        sendButton->setText(QApplication::translate("SelectionWindow", "Send", 0));
        connectButton->setText(QApplication::translate("SelectionWindow", "Connect", 0));
        label->setText(QApplication::translate("SelectionWindow", "ChatClient", 0));
    } // retranslateUi

};

namespace Ui {
    class SelectionWindow: public Ui_SelectionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTIONWINDOW_H
