#include "welcomescreen.h"
#include "ui_welcomescreen.h"
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>


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
    int a = 1;
    while (a){
        bool exists = false;
        bool ok;
        // creating player
        QString text = QInputDialog::getText(this, tr("Player"),
                                                 tr("Player Name:"), QLineEdit::Normal,
                                                 QDir::home().dirName(), &ok);
        // if ok button is clicked
        if (ok && !text.isEmpty()){

            // checking for duplicate username form the file
            QString filename = "usernames.txt";
            QFile file(filename);
            if (file.open(QIODevice::ReadWrite)){
                QTextStream stream(&file);
                QString line;
                while(!stream.atEnd()){
                    line = stream.readLine();

                    // if username exists, displayes error message
                    if (line == text) {
                        exists = true;
                        messageBox.information(0,"Error", "Username already exist");
                        break;
                    }

                }
                // if username doesn't exist, player can start the game
                if (!exists){
                    stream << text << endl;
                    gamescreen.setplayername(text);
                    /* sets current widget to gamescreen widget if start button is clicked */
                    ui->stackedWidget->setCurrentIndex(1);
                    a = 0;
                }
            }
            file.close();
        }
        // if cancel button is clicked, go back
        else{
            a = 0;
        }
    }
}

void MainWindow::on_loadgame_clicked()
{
    // loading the save file
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
        // uploading data varibales from the sav file
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

void MainWindow::on_deleteplayer_clicked()
{
    bool ok;
    bool deleted = false;
    int a = 1;
    while (a){
        // deleting player
        QString text = QInputDialog::getText(this, tr("Player"),
                                                 tr("Player Name:"), QLineEdit::Normal,
                                                 QDir::home().dirName(), &ok);
        // if ok is clicked
        if (ok && !text.isEmpty()){

            // checking whether username is in file
            QString filename = "usernames.txt";
            QFile file(filename);
            if (file.open(QIODevice::ReadWrite)){
                QString s;
                QTextStream stream(&file);
                QString line;
                while(!stream.atEnd()){
                    line = stream.readLine();
                    // other usernames are stored in the string
                    if (line != text) {
                        s.append(line + "\n");
                    }
                    // if the username is found, that will be deleted
                    else{
                        deleted = true;
                    }

                }
                file.resize(0);
                // copying all other usernames from string to a file
                stream << s;
                file.close();
            }
            // displaying message if the deletion was successful or not
            if (deleted == true){
                messageBox.information(0,"Information", "Player Sucessfully Deleted");
                a = 0;
            }
            else{
                messageBox.information(0,"Error", "No Such Player Exists");
            }
        }
        // if cancel button is clicked go back
        else{
            a = 0;
        }

    }
}
