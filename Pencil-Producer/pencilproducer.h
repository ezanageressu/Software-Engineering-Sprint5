/**
 *  @file     PencilProducer.h
 *  @brief    Class and method declarations.
 *  @author   Ardit Shala
 *  @include  ui_PencilProducer.h
 */

#ifndef PENCILPRODUCER_H
#define PENCILPRODUCER_H

#include <QMainWindow>
#include "apm2000_inventory.h"
#include <QTimer>
#include <QMessageBox>

namespace Ui {
class PencilProducer;
}

/**
 *  @class  PencilProducer
 *  @brief  Class to implement the Pencil Producer game
 *  @detail In this class we will define the constructor/descructor and all the other methods we need to make it run. As for the first Spring, we are in need of a cons/dest only.
 */

class PencilProducer : public QMainWindow
{
    Q_OBJECT

public:
    /**
     *   Default constructor.
     */
    explicit PencilProducer(QWidget *parent = nullptr);
    /**
     * Default desctructor.
     */
    ~PencilProducer();

    /**
     * @brief function that unlocks intelligence after pencils produced reach 3000
     * @return
     */
    int getunlock();

    /**
     * @brief   Method which is used to take a snapshot of the current PencilProduction
     *          member and write the data into a QMap.
     * @param   data The QMap to which the snapshot data is written in.
     */
    void saveData(QMap<QString, QString> &data);

    /**
     * @brief   Method which is used to open a snapshot from a previously saved
     *          state of the game.
     * @param   data The QMap from which the snapshot data is read from.
     */
    void uploadData(const QMap<QString, QString> data);

    /**
     * @brief function to make POST request to the server and upload the score
     */
    void uploadscoretoserver();

    /**
     * @brief function to set player username
     * @param sets username of the player to name
     */
    void setplayername(QString name);

private slots:
    /**
     * @brief SLOT handler for pencil price decrease button
     */
    void on_minus_clicked();

    /**
     * @brief SLOT handler for pencil price increase button
     */
    void on_plus_clicked();

    /**
     * @brief SLOT handler for buy wood button
     */
    void on_buyWood_clicked();

    /**
     * @brief SLOT handler for buy graphite button
     */
    void on_buyGraphite_clicked();

    /**
     * @brief SLOT handler for make pencil button
     */
    void on_makePencil_clicked();

    /**
     * @brief SLOT handler for buy APM button
     */
    void on_buyMore_clicked();

    /**
     * @brief SLOT handler that will make pencils automatically, sell pencils, generate intelligence
     * change price of wood and graphite and so on
     */
    void updateAll();

    /**
     * @brief SLOT handler that will show debugging tools when button is checked, otherwise not
     */
    void check();

    /**
     * @brief SLOT handler for balance debugging button
     */
    void on_d1_clicked();

    /**
     * @brief SLOT handler for pencil debugging button
     */
    void on_d2_clicked();

    /**
     * @brief SLOT handler for wood and graphite debugging button
     */
    void on_d4_clicked();

    /**
     * @brief SLOT handler for upgrade APM button
     */
    void on_upgradeAPM_clicked();

    /**
     * @brief SLOT handler for buy marketing button
     */
    void on_textBuyMarketing_clicked();

    /**
     * @brief SLOT handler for unlock marketing button
     */
    void on_unlockM_clicked();

    /**
     * @brief function to unlock intelligence and marketing
     */
    void setunlock();

    /**
     * @brief SLOT handler for save button
     */
    void on_save_clicked();

    /**
     * @brief SLOT handler for quit button
     */
    void on_quit_clicked();

    /**
     * @brief function to get link to the server
     */
    void netfuncurl(QNetworkReply*);

    /**
     * @brief function to store response of the server after POST request
     * has been made
     */
    void onfinish(QNetworkReply*);

    /**
     * @brief SLOT handler for intelligence debugging tool
     */
    void on_d5_clicked();

    /**
     * @brief SLOT handler for marketing debugging tool
     */
    void on_d6_clicked();

    /**
     * @brief SLOT handler for exit button in the game over view
     */
    void on_exit_clicked();

    /**
     * @brief SLOT handler to upload score to the server in the game over view
     */
    void on_upload_clicked();

private:
    /**
     * @brief Create the UI widget for the window
     */
    Ui::PencilProducer *ui;
    /**
     * @brief object of Wallet class
     */
    Wallet wallet;

    /**
     * @brief object of Graphite_Inventory class
     */
    Graphite_Inventory graphiteInventory;

    /**
     * @brief object of Wood_Inventory class
     */
    Wood_Inventory woodInventory;

    /**
     * @brief object of Pencil_Inventory class
     */
    Pencil_Inventory pencilInventory;

    /**
     * @brief object of APM2000_Inventory class
     */
    APM2000_Inventory apm2000Inventory;

    /**
     * @brief link to do POST request
     */
    QString postURL;

    /**
     * @brief function to update text lables in the UI
     */
    void update();

    /**
     * @brief function to startTimer to sell pencils, produce pencils and update prices
     */
    void startTimer();

    /**
     * @brief varible to indicate whether intelligence is unlocked or not
     */
    int unlock = 0;

    /**
     * @brief username of the player
     */
    QString player_name;

    /**
     * @brief object of QMessageBox to display errors
     */
    QMessageBox messageBox;

signals:
    /**
     * @brief singal handler when quit button is clicked to get back to homescreen
     */
    void quitgameclicked();
};

#endif // PENCILPRODUCER_H
