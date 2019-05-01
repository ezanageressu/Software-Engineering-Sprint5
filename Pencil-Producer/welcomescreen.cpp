#include "welcomescreen.h"
#include "ui_welcomescreen.h"
#include <QMessageBox>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* initializing gamescreen ui as widget 1 */
    ui->stackedWidget->insertWidget(1, &gamescreen);
     /* initializing scoreboad ui as widget 2 */
    ui->stackedWidget->insertWidget(2, &score);

    /* if back and quit game button is clicked in scoreboard UI and gamescreen UI
     * respectively, we call moveback SLOT to get back to home screen */
    connect(&gamescreen, SIGNAL(quitgameclicked()), this, SLOT(moveback()));
    connect(&score, SIGNAL(backbuttonclicked()), this, SLOT(moveback()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startgame_clicked()
{
    /* sets current widget to gamescreen widget if start button is clicked */
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_loadgame_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Open Saved Game"),
        tr("*.sav"));

    if (fileName.isEmpty())
    {
        return;
    }
    else
    {

        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(this, tr("Unable to open file"),
                                     file.errorString());
            return;
        }

        QDataStream in(&file);
        in.setVersion(QDataStream::Qt_4_5);
        QMap<QString, QString> data;
        in >> data;
        gamescreen.uploadData(data);
    }
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::moveback()
{
    /* get back to homescreen */
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_highscore_clicked()
{
    /* sets current widget to scoreboard widget if highscore button is clicked */
    score.on_highscores_clicked();
    ui->stackedWidget->setCurrentIndex(2);
}
