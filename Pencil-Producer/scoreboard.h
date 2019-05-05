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

    /**
     * @brief function to make get request to the server to get scores
     */
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

    /**
     * @brief function to get link to the server
     * @param reply is the data we get after making GET request
     */
    void netfuncurl(QNetworkReply *reply);

    /**
     * @brief function to get high scores from the server and present them in UI
     * @param reply is the data we get after making GET request
     */
    void netfunc(QNetworkReply *reply);

private:
    /**
     * @brief pointer to the UI
     */
    Ui::Scoreboard *ui;

    /**
     * @brief URL to get high scores
     */
    QString myURL;

signals:
    /**
     * @brief emits this signal when back button is clicked in the UI
     * to get back to homescreen
     */
    void backbuttonclicked();
};

#endif // SCOREBOARD_H
