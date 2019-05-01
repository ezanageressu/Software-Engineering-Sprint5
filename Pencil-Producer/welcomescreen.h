#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pencilproducer.h"
#include "scoreboard.h"

namespace Ui {
class MainWindow;
}
/**
 * @brief   A singleton class which represents welcome screen GUI class. 
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow constructor
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
      * MainWindow destructor
      */
    ~MainWindow();

private slots:

    /**
     * @brief function to start the game when start game
     * button is clicked
     */
    void on_startgame_clicked();

    /**
     * @brief function to load the previous state of the game from .sav file
     */
    void on_loadgame_clicked();

    /**
     * @brief function to move back to homescreen from scoreboad UI and
     * gamescreen UI
     */
    void moveback();

    /**
     * @brief function to display highscores when high score button is clicked
     */
    void on_highscore_clicked();

private:
    /**
     * @brief pointer to UI
     */
    Ui::MainWindow *ui;

    /**
     * @brief object of HelloWorld class
     */
    PencilProducer gamescreen;

    /**
     * @brief object of Scoreboad class
     */
    Scoreboard score;
};

#endif // MAINWINDOW_H
