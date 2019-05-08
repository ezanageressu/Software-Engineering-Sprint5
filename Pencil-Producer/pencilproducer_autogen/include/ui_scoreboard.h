/********************************************************************************
** Form generated from reading UI file 'scoreboard.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREBOARD_H
#define UI_SCOREBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scoreboard
{
public:
    QWidget *centralWidget;
    QLabel *highscore;
    QLabel *user0;
    QLabel *user1;
    QLabel *user2;
    QLabel *user3;
    QLabel *user4;
    QLabel *user5;
    QLabel *user6;
    QLabel *user7;
    QLabel *user8;
    QLabel *user9;
    QLabel *score0;
    QLabel *score1;
    QLabel *score2;
    QLabel *score3;
    QLabel *score4;
    QLabel *score5;
    QLabel *score6;
    QLabel *score7;
    QLabel *score8;
    QLabel *score9;
    QPushButton *goback;

    void setupUi(QMainWindow *Scoreboard)
    {
        if (Scoreboard->objectName().isEmpty())
            Scoreboard->setObjectName(QStringLiteral("Scoreboard"));
        Scoreboard->resize(682, 533);
        centralWidget = new QWidget(Scoreboard);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        highscore = new QLabel(centralWidget);
        highscore->setObjectName(QStringLiteral("highscore"));
        highscore->setGeometry(QRect(170, 0, 341, 111));
        user0 = new QLabel(centralWidget);
        user0->setObjectName(QStringLiteral("user0"));
        user0->setGeometry(QRect(170, 130, 171, 20));
        user1 = new QLabel(centralWidget);
        user1->setObjectName(QStringLiteral("user1"));
        user1->setGeometry(QRect(170, 160, 181, 17));
        user2 = new QLabel(centralWidget);
        user2->setObjectName(QStringLiteral("user2"));
        user2->setGeometry(QRect(170, 190, 191, 17));
        user3 = new QLabel(centralWidget);
        user3->setObjectName(QStringLiteral("user3"));
        user3->setGeometry(QRect(170, 220, 201, 17));
        user4 = new QLabel(centralWidget);
        user4->setObjectName(QStringLiteral("user4"));
        user4->setGeometry(QRect(170, 250, 211, 17));
        user5 = new QLabel(centralWidget);
        user5->setObjectName(QStringLiteral("user5"));
        user5->setGeometry(QRect(170, 280, 221, 17));
        user6 = new QLabel(centralWidget);
        user6->setObjectName(QStringLiteral("user6"));
        user6->setGeometry(QRect(170, 310, 191, 17));
        user7 = new QLabel(centralWidget);
        user7->setObjectName(QStringLiteral("user7"));
        user7->setGeometry(QRect(170, 340, 201, 17));
        user8 = new QLabel(centralWidget);
        user8->setObjectName(QStringLiteral("user8"));
        user8->setGeometry(QRect(170, 370, 211, 17));
        user9 = new QLabel(centralWidget);
        user9->setObjectName(QStringLiteral("user9"));
        user9->setGeometry(QRect(170, 400, 201, 17));
        score0 = new QLabel(centralWidget);
        score0->setObjectName(QStringLiteral("score0"));
        score0->setGeometry(QRect(420, 130, 141, 17));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        score0->setFont(font);
        score0->setTextFormat(Qt::AutoText);
        score1 = new QLabel(centralWidget);
        score1->setObjectName(QStringLiteral("score1"));
        score1->setGeometry(QRect(420, 160, 141, 17));
        score1->setFont(font);
        score2 = new QLabel(centralWidget);
        score2->setObjectName(QStringLiteral("score2"));
        score2->setGeometry(QRect(420, 190, 141, 17));
        score2->setFont(font);
        score3 = new QLabel(centralWidget);
        score3->setObjectName(QStringLiteral("score3"));
        score3->setGeometry(QRect(420, 220, 141, 17));
        score3->setFont(font);
        score4 = new QLabel(centralWidget);
        score4->setObjectName(QStringLiteral("score4"));
        score4->setGeometry(QRect(420, 250, 141, 17));
        score4->setFont(font);
        score5 = new QLabel(centralWidget);
        score5->setObjectName(QStringLiteral("score5"));
        score5->setGeometry(QRect(420, 280, 141, 17));
        score5->setFont(font);
        score6 = new QLabel(centralWidget);
        score6->setObjectName(QStringLiteral("score6"));
        score6->setGeometry(QRect(420, 310, 141, 17));
        score6->setFont(font);
        score7 = new QLabel(centralWidget);
        score7->setObjectName(QStringLiteral("score7"));
        score7->setGeometry(QRect(420, 340, 141, 17));
        score7->setFont(font);
        score8 = new QLabel(centralWidget);
        score8->setObjectName(QStringLiteral("score8"));
        score8->setGeometry(QRect(420, 370, 141, 17));
        score8->setFont(font);
        score9 = new QLabel(centralWidget);
        score9->setObjectName(QStringLiteral("score9"));
        score9->setGeometry(QRect(420, 400, 141, 17));
        score9->setFont(font);
        goback = new QPushButton(centralWidget);
        goback->setObjectName(QStringLiteral("goback"));
        goback->setGeometry(QRect(10, 20, 89, 31));
        Scoreboard->setCentralWidget(centralWidget);

        retranslateUi(Scoreboard);

        QMetaObject::connectSlotsByName(Scoreboard);
    } // setupUi

    void retranslateUi(QMainWindow *Scoreboard)
    {
        Scoreboard->setWindowTitle(QApplication::translate("Scoreboard", "Scoreboard", Q_NULLPTR));
        highscore->setText(QApplication::translate("Scoreboard", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600;\">Top 10 High Scores</span></p></body></html>", Q_NULLPTR));
        user0->setText(QApplication::translate("Scoreboard", "TextLabel", Q_NULLPTR));
        user1->setText(QApplication::translate("Scoreboard", "TextLabel", Q_NULLPTR));
        user2->setText(QApplication::translate("Scoreboard", "TextLabel", Q_NULLPTR));
        user3->setText(QApplication::translate("Scoreboard", "TextLabel", Q_NULLPTR));
        user4->setText(QApplication::translate("Scoreboard", "TextLabel", Q_NULLPTR));
        user5->setText(QApplication::translate("Scoreboard", "TextLabel", Q_NULLPTR));
        user6->setText(QApplication::translate("Scoreboard", "TextLabel", Q_NULLPTR));
        user7->setText(QApplication::translate("Scoreboard", "TextLabel", Q_NULLPTR));
        user8->setText(QApplication::translate("Scoreboard", "TextLabel", Q_NULLPTR));
        user9->setText(QApplication::translate("Scoreboard", "TextLabel", Q_NULLPTR));
        score0->setText(QApplication::translate("Scoreboard", "<html><head/><body><p>TextLabel</p></body></html>", Q_NULLPTR));
        score1->setText(QApplication::translate("Scoreboard", "<html><head/><body><p><span style=\" font-weight:600;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        score2->setText(QApplication::translate("Scoreboard", "<html><head/><body><p><span style=\" font-weight:600;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        score3->setText(QApplication::translate("Scoreboard", "<html><head/><body><p><span style=\" font-weight:600;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        score4->setText(QApplication::translate("Scoreboard", "<html><head/><body><p><span style=\" font-weight:600;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        score5->setText(QApplication::translate("Scoreboard", "<html><head/><body><p><span style=\" font-weight:600;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        score6->setText(QApplication::translate("Scoreboard", "<html><head/><body><p><span style=\" font-weight:600;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        score7->setText(QApplication::translate("Scoreboard", "<html><head/><body><p><span style=\" font-weight:600;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        score8->setText(QApplication::translate("Scoreboard", "<html><head/><body><p><span style=\" font-weight:600;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        score9->setText(QApplication::translate("Scoreboard", "<html><head/><body><p><span style=\" font-weight:600;\">TextLabel</span></p></body></html>", Q_NULLPTR));
        goback->setText(QApplication::translate("Scoreboard", "Back", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Scoreboard: public Ui_Scoreboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREBOARD_H
