/********************************************************************************
** Form generated from reading UI file 'pencilproducer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PENCILPRODUCER_H
#define UI_PENCILPRODUCER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PencilProducer
{
public:
    QWidget *centralWidget;
    QTextBrowser *textBrowser;
    QTextBrowser *pencilsProduced;
    QTextBrowser *publicDemand;
    QTextBrowser *priceOfPencil;
    QTextBrowser *pencilsInInventory;
    QPushButton *minus;
    QPushButton *plus;
    QTextBrowser *graphiteLeft;
    QTextBrowser *woodLeft;
    QPushButton *buyWood;
    QPushButton *buyGraphite;
    QPushButton *makePencil;
    QPushButton *buyMore;
    QTextBrowser *textOfBankBalance;
    QTextBrowser *bankBalance;
    QTextBrowser *autoPencil2000;
    QTextBrowser *rate;
    QCheckBox *dbt;
    QPushButton *d1;
    QPushButton *d2;
    QPushButton *d4;
    QTextBrowser *intelligence;
    QPushButton *pushButton;
    QPushButton *textBuyMarketing;
    QPushButton *unlockM;
    QPushButton *save;
    QPushButton *quit;
    QPushButton *d5;
    QPushButton *d6;
    QWidget *gameover;
    QLabel *label;
    QPushButton *exit;
    QPushButton *upload;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PencilProducer)
    {
        if (PencilProducer->objectName().isEmpty())
            PencilProducer->setObjectName(QStringLiteral("PencilProducer"));
        PencilProducer->resize(682, 600);
        PencilProducer->setMouseTracking(false);
        centralWidget = new QWidget(PencilProducer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("QWidget {background-color : white}\n"
"QPushButton {color : white}"));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 371, 61));
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setLineWidth(0);
        pencilsProduced = new QTextBrowser(centralWidget);
        pencilsProduced->setObjectName(QStringLiteral("pencilsProduced"));
        pencilsProduced->setGeometry(QRect(10, 60, 331, 31));
        pencilsProduced->setStyleSheet(QStringLiteral("QTextBrowser {color: gray}"));
        pencilsProduced->setFrameShape(QFrame::NoFrame);
        pencilsProduced->setLineWidth(0);
        publicDemand = new QTextBrowser(centralWidget);
        publicDemand->setObjectName(QStringLiteral("publicDemand"));
        publicDemand->setGeometry(QRect(10, 110, 331, 31));
        publicDemand->setFrameShape(QFrame::NoFrame);
        publicDemand->setLineWidth(0);
        priceOfPencil = new QTextBrowser(centralWidget);
        priceOfPencil->setObjectName(QStringLiteral("priceOfPencil"));
        priceOfPencil->setGeometry(QRect(10, 190, 331, 31));
        priceOfPencil->setFrameShape(QFrame::NoFrame);
        priceOfPencil->setLineWidth(0);
        pencilsInInventory = new QTextBrowser(centralWidget);
        pencilsInInventory->setObjectName(QStringLiteral("pencilsInInventory"));
        pencilsInInventory->setGeometry(QRect(10, 160, 331, 31));
        pencilsInInventory->setFrameShape(QFrame::NoFrame);
        pencilsInInventory->setLineWidth(0);
        minus = new QPushButton(centralWidget);
        minus->setObjectName(QStringLiteral("minus"));
        minus->setGeometry(QRect(10, 240, 50, 50));
        minus->setStyleSheet(QLatin1String("QPushButton {background-color:rgb(65, 189, 29)}\n"
"QPushButton:Pressed {background-color : transparent}"));
        plus = new QPushButton(centralWidget);
        plus->setObjectName(QStringLiteral("plus"));
        plus->setGeometry(QRect(70, 240, 50, 50));
        plus->setStyleSheet(QLatin1String("QPushButton {background-color:rgb(65, 189, 29)}\n"
"QPushButton:Pressed {background-color : transparent}"));
        graphiteLeft = new QTextBrowser(centralWidget);
        graphiteLeft->setObjectName(QStringLiteral("graphiteLeft"));
        graphiteLeft->setGeometry(QRect(10, 340, 331, 31));
        graphiteLeft->setFrameShape(QFrame::NoFrame);
        graphiteLeft->setLineWidth(0);
        woodLeft = new QTextBrowser(centralWidget);
        woodLeft->setObjectName(QStringLiteral("woodLeft"));
        woodLeft->setGeometry(QRect(10, 300, 331, 31));
        woodLeft->setFrameShape(QFrame::NoFrame);
        woodLeft->setLineWidth(0);
        buyWood = new QPushButton(centralWidget);
        buyWood->setObjectName(QStringLiteral("buyWood"));
        buyWood->setGeometry(QRect(10, 380, 161, 61));
        buyWood->setStyleSheet(QLatin1String("QPushButton {background-color:rgb(186, 87, 9)}\n"
"QPushButton:Pressed {background-color : transparent}"));
        buyGraphite = new QPushButton(centralWidget);
        buyGraphite->setObjectName(QStringLiteral("buyGraphite"));
        buyGraphite->setGeometry(QRect(180, 380, 161, 61));
        buyGraphite->setStyleSheet(QLatin1String("QPushButton {background-color:gray}\n"
"QPushButton:Pressed {background-color : transparent}"));
        makePencil = new QPushButton(centralWidget);
        makePencil->setObjectName(QStringLiteral("makePencil"));
        makePencil->setGeometry(QRect(490, 20, 161, 61));
        makePencil->setStyleSheet(QLatin1String("QPushButton {background-color : rgb(47, 185, 255)}\n"
"QPushButton:Pressed {background-color : transparent}"));
        buyMore = new QPushButton(centralWidget);
        buyMore->setObjectName(QStringLiteral("buyMore"));
        buyMore->setGeometry(QRect(510, 320, 141, 71));
        buyMore->setStyleSheet(QLatin1String("QPushButton {background-color : rgb(254, 188, 32)}\n"
"QPushButton:Pressed {background-color : transparent}"));
        textOfBankBalance = new QTextBrowser(centralWidget);
        textOfBankBalance->setObjectName(QStringLiteral("textOfBankBalance"));
        textOfBankBalance->setGeometry(QRect(400, 120, 241, 31));
        textOfBankBalance->setFrameShape(QFrame::NoFrame);
        textOfBankBalance->setLineWidth(0);
        bankBalance = new QTextBrowser(centralWidget);
        bankBalance->setObjectName(QStringLiteral("bankBalance"));
        bankBalance->setGeometry(QRect(400, 150, 241, 51));
        bankBalance->setStyleSheet(QStringLiteral("QTextBrowser {color: rgb(65, 189, 29)}"));
        bankBalance->setFrameShape(QFrame::NoFrame);
        bankBalance->setLineWidth(0);
        autoPencil2000 = new QTextBrowser(centralWidget);
        autoPencil2000->setObjectName(QStringLiteral("autoPencil2000"));
        autoPencil2000->setGeometry(QRect(400, 260, 241, 31));
        autoPencil2000->setFrameShape(QFrame::NoFrame);
        autoPencil2000->setLineWidth(0);
        rate = new QTextBrowser(centralWidget);
        rate->setObjectName(QStringLiteral("rate"));
        rate->setGeometry(QRect(405, 280, 241, 31));
        rate->setStyleSheet(QStringLiteral("QTextBrowser {color: gray}"));
        rate->setFrameShape(QFrame::NoFrame);
        rate->setLineWidth(0);
        dbt = new QCheckBox(centralWidget);
        dbt->setObjectName(QStringLiteral("dbt"));
        dbt->setGeometry(QRect(10, 470, 141, 20));
        d1 = new QPushButton(centralWidget);
        d1->setObjectName(QStringLiteral("d1"));
        d1->setEnabled(true);
        d1->setGeometry(QRect(10, 510, 121, 41));
        QFont font;
        font.setPointSize(11);
        d1->setFont(font);
        d1->setStyleSheet(QStringLiteral("background-color: rgb(138, 226, 52);"));
        d2 = new QPushButton(centralWidget);
        d2->setObjectName(QStringLiteral("d2"));
        d2->setGeometry(QRect(140, 510, 121, 41));
        d2->setFont(font);
        d2->setStyleSheet(QStringLiteral("background-color: rgb(114, 159, 207);"));
        d4 = new QPushButton(centralWidget);
        d4->setObjectName(QStringLiteral("d4"));
        d4->setGeometry(QRect(280, 510, 121, 41));
        d4->setFont(font);
        d4->setStyleSheet(QStringLiteral("background-color: rgb(233, 185, 110);"));
        intelligence = new QTextBrowser(centralWidget);
        intelligence->setObjectName(QStringLiteral("intelligence"));
        intelligence->setGeometry(QRect(405, 190, 231, 31));
        intelligence->setStyleSheet(QLatin1String("border-color: rgba(255, 255, 255, 0);\n"
"background-color: rgba(255, 255, 255, 0);"));
        intelligence->setLineWidth(0);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(360, 320, 141, 71));
        pushButton->setStyleSheet(QLatin1String("QPushButton {background-color : rgb(254, 188, 32)}\n"
"QPushButton:Pressed {background-color : transparent}"));
        textBuyMarketing = new QPushButton(centralWidget);
        textBuyMarketing->setObjectName(QStringLiteral("textBuyMarketing"));
        textBuyMarketing->setGeometry(QRect(432, 220, 211, 41));
        textBuyMarketing->setStyleSheet(QLatin1String("QPushButton {background-color : rgb(254, 188, 32)}\n"
"QPushButton:Pressed {background-color : transparent}"));
        unlockM = new QPushButton(centralWidget);
        unlockM->setObjectName(QStringLiteral("unlockM"));
        unlockM->setGeometry(QRect(430, 220, 221, 41));
        unlockM->setStyleSheet(QLatin1String("QPushButton {background-color : rgb(254, 188, 32)}\n"
""));
        save = new QPushButton(centralWidget);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(390, 420, 113, 41));
        save->setStyleSheet(QLatin1String("color: black;\n"
""));
        quit = new QPushButton(centralWidget);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setGeometry(QRect(530, 420, 113, 41));
        quit->setStyleSheet(QLatin1String("color: black;\n"
""));
        d5 = new QPushButton(centralWidget);
        d5->setObjectName(QStringLiteral("d5"));
        d5->setGeometry(QRect(410, 510, 101, 41));
        d5->setStyleSheet(QStringLiteral("background-color: rgb(78, 154, 6);"));
        d6 = new QPushButton(centralWidget);
        d6->setObjectName(QStringLiteral("d6"));
        d6->setGeometry(QRect(530, 510, 101, 41));
        d6->setStyleSheet(QStringLiteral("background-color: rgb(117, 80, 123);"));
        gameover = new QWidget(centralWidget);
        gameover->setObjectName(QStringLiteral("gameover"));
        gameover->setGeometry(QRect(0, 0, 682, 578));
        gameover->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label = new QLabel(gameover);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 60, 211, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu"));
        font1.setPointSize(12);
        label->setFont(font1);
        exit = new QPushButton(gameover);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(280, 240, 121, 41));
        exit->setStyleSheet(QStringLiteral("background-color: rgb(252, 175, 62);"));
        upload = new QPushButton(gameover);
        upload->setObjectName(QStringLiteral("upload"));
        upload->setGeometry(QRect(280, 180, 121, 41));
        upload->setStyleSheet(QStringLiteral("background-color: rgb(138, 226, 52);"));
        PencilProducer->setCentralWidget(centralWidget);
        bankBalance->raise();
        quit->raise();
        textBrowser->raise();
        pencilsProduced->raise();
        publicDemand->raise();
        priceOfPencil->raise();
        pencilsInInventory->raise();
        minus->raise();
        plus->raise();
        graphiteLeft->raise();
        woodLeft->raise();
        buyWood->raise();
        buyGraphite->raise();
        makePencil->raise();
        buyMore->raise();
        textOfBankBalance->raise();
        autoPencil2000->raise();
        rate->raise();
        dbt->raise();
        d1->raise();
        d2->raise();
        d4->raise();
        intelligence->raise();
        pushButton->raise();
        textBuyMarketing->raise();
        unlockM->raise();
        save->raise();
        d5->raise();
        d6->raise();
        gameover->raise();
        statusBar = new QStatusBar(PencilProducer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PencilProducer->setStatusBar(statusBar);

        retranslateUi(PencilProducer);

        QMetaObject::connectSlotsByName(PencilProducer);
    } // setupUi

    void retranslateUi(QMainWindow *PencilProducer)
    {
        PencilProducer->setWindowTitle(QApplication::translate("PencilProducer", "PencilProducer", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:24pt; font-weight:600;\">Pencil Producer</span></p></body></html>", Q_NULLPTR));
        pencilsProduced->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:12pt; color:#797979;\">Pencils Produced (to date): </span></p></body></html>", Q_NULLPTR));
        publicDemand->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:14pt;\">Public Demand: </span></p></body></html>", Q_NULLPTR));
        priceOfPencil->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:14pt;\">Price of TIENSTIENSTIENS: </span></p></body></html>", Q_NULLPTR));
        pencilsInInventory->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:14pt;\">Pencils in Inventory: </span></p></body></html>", Q_NULLPTR));
        minus->setText(QApplication::translate("PencilProducer", "-", Q_NULLPTR));
        plus->setText(QApplication::translate("PencilProducer", "+", Q_NULLPTR));
        graphiteLeft->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:14pt;\">Graphite Left: </span></p></body></html>", Q_NULLPTR));
        woodLeft->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:14pt;\">Wood Left: </span></p></body></html>", Q_NULLPTR));
        buyWood->setText(QApplication::translate("PencilProducer", "Buy Wood", Q_NULLPTR));
        buyGraphite->setText(QApplication::translate("PencilProducer", "Buy Graphite", Q_NULLPTR));
        makePencil->setText(QApplication::translate("PencilProducer", "Make Pencil", Q_NULLPTR));
        buyMore->setText(QApplication::translate("PencilProducer", "Buy More", Q_NULLPTR));
        textOfBankBalance->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:14pt;\">Bank Balance</span></p></body></html>", Q_NULLPTR));
        bankBalance->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.SF NS Text'; font-size:13pt;\"><br /></p></body></html>", Q_NULLPTR));
        autoPencil2000->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:14pt;\">AutoPencil2000: </span></p></body></html>", Q_NULLPTR));
        rate->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"right\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:12pt; color:#797979;\">Rate: </span></p></body></html>", Q_NULLPTR));
        dbt->setText(QApplication::translate("PencilProducer", "Debugging Tools", Q_NULLPTR));
        d1->setText(QApplication::translate("PencilProducer", "Balance\n"
" +1000", Q_NULLPTR));
        d2->setText(QApplication::translate("PencilProducer", "Pencil\n"
" +1000", Q_NULLPTR));
        d4->setText(QApplication::translate("PencilProducer", "Wood: +1000 \n"
" Graphite: +1000", Q_NULLPTR));
        intelligence->setHtml(QApplication::translate("PencilProducer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'.SF NS Text'; font-size:13pt;\"><br /></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PencilProducer", "Upgrade APM", Q_NULLPTR));
        textBuyMarketing->setText(QApplication::translate("PencilProducer", "Buy Marketing", Q_NULLPTR));
        unlockM->setText(QApplication::translate("PencilProducer", "Unlock Marketing", Q_NULLPTR));
        save->setText(QApplication::translate("PencilProducer", "Save", Q_NULLPTR));
        quit->setText(QApplication::translate("PencilProducer", "Quit", Q_NULLPTR));
        d5->setText(QApplication::translate("PencilProducer", "Intelligence\n"
" +10", Q_NULLPTR));
        d6->setText(QApplication::translate("PencilProducer", "Marketing\n"
"+3", Q_NULLPTR));
        label->setText(QApplication::translate("PencilProducer", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:600; color:#729fcf;\">Game Over</span></p></body></html>", Q_NULLPTR));
        exit->setText(QApplication::translate("PencilProducer", "Exit", Q_NULLPTR));
        upload->setText(QApplication::translate("PencilProducer", "Upload Score", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PencilProducer: public Ui_PencilProducer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PENCILPRODUCER_H
