/********************************************************************************
** Form generated from reading UI file 'serverwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_serverWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *infoWindow;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *serverWindow)
    {
        if (serverWindow->objectName().isEmpty())
            serverWindow->setObjectName(QStringLiteral("serverWindow"));
        serverWindow->resize(409, 318);
        centralWidget = new QWidget(serverWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        infoWindow = new QTextEdit(centralWidget);
        infoWindow->setObjectName(QStringLiteral("infoWindow"));
        infoWindow->setGeometry(QRect(13, 17, 381, 231));
        serverWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(serverWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 409, 25));
        serverWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(serverWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        serverWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(serverWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        serverWindow->setStatusBar(statusBar);

        retranslateUi(serverWindow);

        QMetaObject::connectSlotsByName(serverWindow);
    } // setupUi

    void retranslateUi(QMainWindow *serverWindow)
    {
        serverWindow->setWindowTitle(QApplication::translate("serverWindow", "serverWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class serverWindow: public Ui_serverWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
