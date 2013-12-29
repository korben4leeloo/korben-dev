/********************************************************************************
** Form generated from reading UI file 'OkdEditorMainWnd.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKDEDITORMAINWND_H
#define UI_OKDEDITORMAINWND_H

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

class Ui_OkdEditorMainWndClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OkdEditorMainWndClass)
    {
        if (OkdEditorMainWndClass->objectName().isEmpty())
            OkdEditorMainWndClass->setObjectName(QStringLiteral("OkdEditorMainWndClass"));
        OkdEditorMainWndClass->resize(600, 400);
        centralWidget = new QWidget(OkdEditorMainWndClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        OkdEditorMainWndClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OkdEditorMainWndClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        OkdEditorMainWndClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(OkdEditorMainWndClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        OkdEditorMainWndClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(OkdEditorMainWndClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        OkdEditorMainWndClass->setStatusBar(statusBar);

        retranslateUi(OkdEditorMainWndClass);

        QMetaObject::connectSlotsByName(OkdEditorMainWndClass);
    } // setupUi

    void retranslateUi(QMainWindow *OkdEditorMainWndClass)
    {
        OkdEditorMainWndClass->setWindowTitle(QApplication::translate("OkdEditorMainWndClass", "OkdEditorMainWnd", 0));
    } // retranslateUi

};

namespace Ui {
    class OkdEditorMainWndClass: public Ui_OkdEditorMainWndClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKDEDITORMAINWND_H
