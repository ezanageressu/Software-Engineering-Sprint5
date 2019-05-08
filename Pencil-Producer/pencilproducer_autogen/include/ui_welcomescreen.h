/********************************************************************************
** Form generated from reading UI file 'welcomescreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMESCREEN_H
#define UI_WELCOMESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *startgame;
    QPushButton *loadgame;
    QPushButton *highscore;
    QLabel *welcome;
    QPushButton *deleteplayer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(682, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 682, 600));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        startgame = new QPushButton(page);
        startgame->setObjectName(QStringLiteral("startgame"));
        startgame->setGeometry(QRect(290, 150, 101, 41));
        startgame->setStyleSheet(QStringLiteral("background-color: rgb(138, 226, 52);"));
        loadgame = new QPushButton(page);
        loadgame->setObjectName(QStringLiteral("loadgame"));
        loadgame->setGeometry(QRect(290, 210, 101, 41));
        loadgame->setStyleSheet(QStringLiteral("background-color: rgb(233, 185, 110);"));
        highscore = new QPushButton(page);
        highscore->setObjectName(QStringLiteral("highscore"));
        highscore->setGeometry(QRect(290, 270, 101, 41));
        highscore->setStyleSheet(QStringLiteral("background-color: rgb(239, 41, 41);"));
        welcome = new QLabel(page);
        welcome->setObjectName(QStringLiteral("welcome"));
        welcome->setGeometry(QRect(260, 50, 161, 81));
        deleteplayer = new QPushButton(page);
        deleteplayer->setObjectName(QStringLiteral("deleteplayer"));
        deleteplayer->setGeometry(QRect(290, 330, 101, 41));
        deleteplayer->setStyleSheet(QStringLiteral("background-color: rgb(92, 53, 102);"));
        stackedWidget->addWidget(page);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        startgame->setText(QApplication::translate("MainWindow", "Start Game", Q_NULLPTR));
        loadgame->setText(QApplication::translate("MainWindow", "Load Game", Q_NULLPTR));
        highscore->setText(QApplication::translate("MainWindow", "Highscore", Q_NULLPTR));
        welcome->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600; color:#3465a4;\">Welcome</span></p></body></html>", Q_NULLPTR));
        deleteplayer->setText(QApplication::translate("MainWindow", "Delete Player", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMESCREEN_H
