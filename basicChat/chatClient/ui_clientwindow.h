/********************************************************************************
** Form generated from reading UI file 'clientwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWINDOW_H
#define UI_CLIENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientWindow
{
public:
    QWidget *centralWidget;
    QPushButton *exitChatButton;
    QLineEdit *messageLine;
    QPushButton *sendButton;
    QTextEdit *recieveArea;
    QComboBox *destinationSelect;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *clientWindow)
    {
        if (clientWindow->objectName().isEmpty())
            clientWindow->setObjectName(QStringLiteral("clientWindow"));
        clientWindow->resize(400, 300);
        centralWidget = new QWidget(clientWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        exitChatButton = new QPushButton(centralWidget);
        exitChatButton->setObjectName(QStringLiteral("exitChatButton"));
        exitChatButton->setGeometry(QRect(290, 210, 99, 27));
        messageLine = new QLineEdit(centralWidget);
        messageLine->setObjectName(QStringLiteral("messageLine"));
        messageLine->setGeometry(QRect(10, 0, 371, 27));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setGeometry(QRect(290, 30, 91, 27));
        recieveArea = new QTextEdit(centralWidget);
        recieveArea->setObjectName(QStringLiteral("recieveArea"));
        recieveArea->setGeometry(QRect(3, 87, 391, 111));
        destinationSelect = new QComboBox(centralWidget);
        destinationSelect->setObjectName(QStringLiteral("destinationSelect"));
        destinationSelect->setGeometry(QRect(10, 30, 151, 27));
        clientWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(clientWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        clientWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(clientWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        clientWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(clientWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        clientWindow->setStatusBar(statusBar);

        retranslateUi(clientWindow);

        QMetaObject::connectSlotsByName(clientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *clientWindow)
    {
        clientWindow->setWindowTitle(QApplication::translate("clientWindow", "clientWindow", 0));
        exitChatButton->setText(QApplication::translate("clientWindow", "Exit Chat", 0));
        sendButton->setText(QApplication::translate("clientWindow", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class clientWindow: public Ui_clientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
