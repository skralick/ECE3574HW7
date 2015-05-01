/********************************************************************************
** Form generated from reading UI file 'initwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITWINDOW_H
#define UI_INITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *connectToServerButton;
    QLineEdit *ipLineEdit;
    QLineEdit *portLineEdit;
    QLabel *label_3;
    QLineEdit *nameEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InitWindow)
    {
        if (InitWindow->objectName().isEmpty())
            InitWindow->setObjectName(QStringLiteral("InitWindow"));
        InitWindow->resize(400, 217);
        centralWidget = new QWidget(InitWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 0, 101, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 111, 17));
        connectToServerButton = new QPushButton(centralWidget);
        connectToServerButton->setObjectName(QStringLiteral("connectToServerButton"));
        connectToServerButton->setGeometry(QRect(258, 120, 131, 27));
        ipLineEdit = new QLineEdit(centralWidget);
        ipLineEdit->setObjectName(QStringLiteral("ipLineEdit"));
        ipLineEdit->setGeometry(QRect(10, 20, 381, 27));
        portLineEdit = new QLineEdit(centralWidget);
        portLineEdit->setObjectName(QStringLiteral("portLineEdit"));
        portLineEdit->setGeometry(QRect(10, 70, 381, 27));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 100, 131, 17));
        nameEdit = new QLineEdit(centralWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setGeometry(QRect(12, 120, 231, 27));
        InitWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(InitWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        InitWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InitWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        InitWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(InitWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        InitWindow->setStatusBar(statusBar);

        retranslateUi(InitWindow);

        QMetaObject::connectSlotsByName(InitWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InitWindow)
    {
        InitWindow->setWindowTitle(QApplication::translate("InitWindow", "InitWindow", 0));
        label->setText(QApplication::translate("InitWindow", "Server IP", 0));
        label_2->setText(QApplication::translate("InitWindow", "ServerPort", 0));
        connectToServerButton->setText(QApplication::translate("InitWindow", "Connect To Server", 0));
        label_3->setText(QApplication::translate("InitWindow", "Client Name", 0));
    } // retranslateUi

};

namespace Ui {
    class InitWindow: public Ui_InitWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITWINDOW_H
