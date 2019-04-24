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

    int getunlock();
///main slots for buttons
private slots:
    void on_minus_clicked();

    void on_plus_clicked();

    void on_buyWood_clicked();

    void on_buyGraphite_clicked();

    void on_makePencil_clicked();

    void on_buyMore_clicked();

    void updateAll();

    void check();

    void on_d1_clicked();

    void on_d2_clicked();

    void on_d3_clicked();

    void on_d4_clicked();

    void on_pushButton_clicked();

    void on_textBuyMarketing_clicked();

    void on_unlockM_clicked();



    void setunlock();

    void on_save_clicked();

    void on_loadgame_clicked();

    void on_newgame_clicked();

    void on_quit_clicked();

    void on_highscores_clicked();

    void netfunc(QNetworkReply*);
    void netfuncurl(QNetworkReply*);

    void onfinish(QNetworkReply*);


private:
    /** Create the UI widget for the window
         */
    Ui::PencilProducer *ui;
    Wallet wallet;
    Graphite_Inventory graphiteInventory;
    Wood_Inventory woodInventory;
    Pencil_Inventory pencilInventory;
    APM2000_Inventory apm2000Inventory;
    QString myURL;
    QString postURL;
    void update();
    void startTimer();
    int unlock = 0;
    friend QDataStream& operator>>(QDataStream& in, PencilProducer* pencil);
    friend QDataStream& operator>>(QDataStream& in, Graphite_Inventory* graphite);
    friend QDataStream& operator>>(QDataStream& in, Wood_Inventory* wood);
    friend QDataStream& operator>>(QDataStream& in, Wallet* wallet);
    friend QDataStream& operator>>(QDataStream& in, APM2000_Inventory* apm);
    friend QDataStream& operator>>(QDataStream& in, Pencil_Inventory* invent);
    friend QDataStream& operator<<(QDataStream& out, PencilProducer* pencil);
    friend QDataStream& operator<<(QDataStream& out, Graphite_Inventory* graphite);
    friend QDataStream& operator<<(QDataStream& out, Wood_Inventory* wood);
    friend QDataStream& operator<<(QDataStream& out, Wallet* wallet);
    friend QDataStream& operator<<(QDataStream& out, APM2000_Inventory* apm);
    friend QDataStream& operator<<(QDataStream& out, Pencil_Inventory* invent);
};

#endif // PENCILPRODUCER_H
