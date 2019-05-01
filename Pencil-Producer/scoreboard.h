#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QMainWindow>
#include <QJsonDocument>
#include <QByteArray>
#include <iostream>
#include <cstring>
#include <vector>
#include <QtNetwork>

using namespace std;

namespace Ui {
class Scoreboard;
}
/**
 * @brief   A singleton class which represents scoreboard screen GUI class. 
 */
class Scoreboard : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief constructor of the scoreboard class
     */
    explicit Scoreboard(QWidget *parent = nullptr);

    void on_highscores_clicked();

    /**
     * destructor of the scoreboad class
     */
    ~Scoreboard();

private slots:
    /**
     * @brief function that will take action when back button
     * is clicked on the UI
     */
    void on_goback_clicked();

    void netfuncurl(QNetworkReply *reply);

    void netfunc(QNetworkReply *reply);

private:
    /**
     * @brief pointer to the UI
     */
    Ui::Scoreboard *ui;

    QString myURL;

signals:
    /**
     * @brief emits this signal when back button is clicked in the UI
     * to get back to homescreen
     */
    void backbuttonclicked();
};

#endif // SCOREBOARD_H
