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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *clientWindow)
    {
        if (clientWindow->objectName().isEmpty())
            clientWindow->setObjectName(QStringLiteral("clientWindow"));
        clientWindow->resize(400, 300);
        menuBar = new QMenuBar(clientWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        clientWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(clientWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        clientWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(clientWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        clientWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(clientWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        clientWindow->setStatusBar(statusBar);

        retranslateUi(clientWindow);

        QMetaObject::connectSlotsByName(clientWindow);
    } // setupUi

    void retranslateUi(QMainWindow *clientWindow)
    {
        clientWindow->setWindowTitle(QApplication::translate("clientWindow", "clientWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class clientWindow: public Ui_clientWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWINDOW_H
