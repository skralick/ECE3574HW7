/********************************************************************************
** Form generated from reading UI file 'clientinit.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTINIT_H
#define UI_CLIENTINIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientInit
{
public:
    QPushButton *connectAsButton;
    QLineEdit *serverNameEdit;
    QLabel *label;

    void setupUi(QWidget *clientInit)
    {
        if (clientInit->objectName().isEmpty())
            clientInit->setObjectName(QStringLiteral("clientInit"));
        clientInit->resize(400, 86);
        connectAsButton = new QPushButton(clientInit);
        connectAsButton->setObjectName(QStringLiteral("connectAsButton"));
        connectAsButton->setGeometry(QRect(290, 40, 99, 27));
        serverNameEdit = new QLineEdit(clientInit);
        serverNameEdit->setObjectName(QStringLiteral("serverNameEdit"));
        serverNameEdit->setGeometry(QRect(10, 40, 271, 31));
        label = new QLabel(clientInit);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 101, 17));

        retranslateUi(clientInit);

        QMetaObject::connectSlotsByName(clientInit);
    } // setupUi

    void retranslateUi(QWidget *clientInit)
    {
        clientInit->setWindowTitle(QApplication::translate("clientInit", "Form", 0));
        connectAsButton->setText(QApplication::translate("clientInit", "Connect As", 0));
        label->setText(QApplication::translate("clientInit", "Client Name", 0));
    } // retranslateUi

};

namespace Ui {
    class clientInit: public Ui_clientInit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTINIT_H
