/**
 *  @file     PencilProducer.cpp
 *  @brief    The logic of the calculator.
 *  @author   Ardit Shala
 *  @include  PencilProducer.h
 */

#include "pencilproducer.h"
#include "ui_pencilproducer.h"
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <QJsonDocument>
#include <QByteArray>

PencilProducer::PencilProducer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PencilProducer)
{
    // setting up the UI in the beginning
    ui->setupUi(this);
    ui->gameover->hide();
    ui->textBuyMarketing->setVisible(false);
    ui->upgradeAPM->setVisible(false);
    ui->unlockM->setVisible(false);
    update();
    startTimer();

    //Calling the network function to get the Json link
    QNetworkAccessManager *url_rq = new QNetworkAccessManager(this);
    connect(url_rq, &QNetworkAccessManager::finished, this, &PencilProducer::netfuncurl);

    QString URL = "https://matiusulung.com/se.json";
    const QUrl url = QUrl(URL);

    QNetworkRequest request(url);
    url_rq->get(request);
}

PencilProducer::~PencilProducer()
{
    delete ui;
}


// updates all values displayed on the UI
void PencilProducer::update()
{
    QString str;
    int pencilsProduced = pencilInventory.getTotalNumberOfPencilsProduced();
    float publicDemand = pencilInventory.getPublicDemand();
    int pencilsInInventory = pencilInventory.getAmount();
    float priceOfPencil = pencilInventory.getPrice();
    float woodLeft = woodInventory.getAmount();
    float graphiteLeft = graphiteInventory.getAmount();
    float bankBalance = wallet.getBankBalance();
    int autoPencil2000 = apm2000Inventory.getNumber();
    float priceOfWood = woodInventory.getPrice();
    float priceOfGraphite = graphiteInventory.getPrice();
    float priceOfAPM2000 = apm2000Inventory.getPrice();
    float rate = apm2000Inventory.getRate();

    // Update Values in order to show the changes occurred
    str.setNum(pencilsProduced);
    ui->pencilsProduced->setText("<html>Pencils Produced (to date): <b>" + str + "</b></html>");

    str.setNum(publicDemand, 'f', 2);
    ui->publicDemand->setText("<html>Public Demand: <b>" + str + "</b></html>");

    str.setNum(pencilsInInventory);
    ui->pencilsInInventory->setText("<html>Pencils in Inventory: <b>" + str + "</b></html>");

    str.setNum(priceOfPencil, 'f', 2);
    ui->priceOfPencil->setText("<html>Price of Pencil: <b>$" + str + "</b></html>");

    str.setNum(woodLeft, 'f', 2);
    ui->woodLeft->setText("<html>Wood Left: <b>" + str + " m</b></html>");

    str.setNum(graphiteLeft, 'f', 2);
    ui->graphiteLeft->setText("<html>Graphite Left: <b>" + str + " m</b></html>");

    str.setNum(bankBalance, 'f', 2);
    ui->bankBalance->setText("<html><b><p style=\"text-align: right; font-size: 30px\">$" + str + "</p></b></html>");

    str.setNum(autoPencil2000);
    ui->autoPencil2000->setText("<html><p style=\"text-align: right\">AutoPencil2000: <b>" + str + "</b></p></html>");

    str.setNum(priceOfWood, 'f', 2);
    ui->buyWood->setText("Buy Wood \n$" + str + " / 100.00 m");

    str.setNum(priceOfGraphite, 'f', 2);
    ui->buyGraphite->setText("Buy Graphite \n$" + str + " / 100.00 m");

    str.setNum(apm2000Inventory.getIntelligencePrice());
    ui->upgradeAPM->setText("Upgrade APM \n" + str + "IQ");

    str.setNum(priceOfAPM2000, 'f', 2);
    ui->buyMore->setText("Buy APM \n$" + str);

    str.setNum(rate);
    ui->rate->setText("<html><p style=\"text-align: right\">Rate: <b>" + str + "</b> pencils / minute</p></html>");

    int numInt = pencilInventory.getIntelligence();
    str.setNum(numInt);
    ui->intelligence->setText("<html><p style=\"text-align: right\">Intelligence: <b>" + str + "</b></p></html>");

    //Disable a button when there is not enough money in the wallet.
    ui->makePencil->setEnabled(pencilInventory.canProducePencil(graphiteInventory, woodInventory));
    ui->buyWood->setEnabled(woodInventory.canBuy(wallet));
    ui->buyGraphite->setEnabled(graphiteInventory.canBuy(wallet));
    ui->buyMore->setEnabled(apm2000Inventory.canBuyAPM2000(wallet));
    ui->textBuyMarketing->setText(QString("Buy Marketing\n$ " + QString::number(pencilInventory.getMarketingPrice(),'f',2)));
}

//Begin a timer which uses the function "updateAll".
void PencilProducer::startTimer()
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &PencilProducer::updateAll);
    timer->start(500);
    QTimer *timer1 = new QTimer(this);
    connect(timer1, &QTimer::timeout, this, &PencilProducer::check);
    timer1->start(100);
}

void PencilProducer::on_minus_clicked()
{
    pencilInventory.decreasePrice();
    update();
}

void PencilProducer::on_plus_clicked()
{
    pencilInventory.increasePrice();
    update();
}

void PencilProducer::on_buyWood_clicked()
{
    woodInventory.buy(wallet);
    update();
}

void PencilProducer::on_buyGraphite_clicked()
{
    graphiteInventory.buy(wallet);
    update();
}

void PencilProducer::on_makePencil_clicked()
{
    pencilInventory.producePencil(graphiteInventory, woodInventory);
    update();
}

void PencilProducer::on_buyMore_clicked()
{
    apm2000Inventory.buyAPM2000(wallet);
    update();
}

void PencilProducer::updateAll()
{
    static int count = 1;
    static int counter = 0;
    QString str;

    if (pencilInventory.getTotalNumberOfPencilsProduced() >= 25000){
        apm2000Inventory.setNumber(0);
        ui->gameover->show();
    }

    //Produce and Sell a Pencil every one second.
    if (counter % 2 == 0)
    {
        apm2000Inventory.producePencil(pencilInventory, graphiteInventory, woodInventory);
        counter++;
    }
    else
    {
        pencilInventory.sellPencil(wallet, pencilInventory.getNumberOfPencilsToBeSold());
        pencilInventory.changeIntelligence();
        // if pencils > 3000, unlock marketing
        if(pencilInventory.getTotalNumberOfPencilsProduced()>=3000)
        {
            if(unlock == 0)
            {
                ui->unlockM->setVisible(true);
            }
            // if already unlocked, change label to buy marketing
            else if (unlock == 1){
                if (wallet.getBankBalance() >= pencilInventory.getMarketingPrice()
                        && pencilInventory.getM() < 30){
                    ui->textBuyMarketing->setEnabled(true);
                }
                else{
                    ui->textBuyMarketing->setEnabled(false);
                }
            }
            if(pencilInventory.getIntelligence()>=100)
            {
                ui->unlockM->setEnabled(true);
            }
            else
            {
                ui->unlockM->setEnabled(false);
            }
            ui->upgradeAPM->setVisible(true);

            // unlock the upgrade APM button
            if(pencilInventory.getIntelligence() >= 50 && apm2000Inventory.getVersion() == 0)
            {
                ui->upgradeAPM->setEnabled(true);
            }
            else if (pencilInventory.getIntelligence() >= 200 && apm2000Inventory.getVersion() == 1
                     && pencilInventory.getTotalNumberOfPencilsProduced() >= 5000){
                ui->upgradeAPM->setEnabled(true);
            }
            else
            {
                ui->upgradeAPM->setEnabled(false);
            }

        }
        else{
            ui->unlockM->setVisible(false);
            ui->upgradeAPM->setVisible(false);
        }
        counter = 0;
    }
    //Change the Price Of Wood/Graphite every five seconds. /10 * 500msec = 5sec/
    if (count % 10 == 0)
    {
        count = 1;
        woodInventory.setPrice();
        graphiteInventory.setPrice();
    }
    else
        count++;

    update();
}

void PencilProducer::check()
{
    // if debugging tool is not checked
    if(!ui->dbt->isChecked())
    {
        ui->d1->setVisible(false);
        ui->d2->setVisible(false);
        ui->d5->setVisible(false);
        ui->d4->setVisible(false);
         ui->d6->setVisible(false);
    }
    // if debugging tool is checked
    if(ui->dbt->isChecked())
    {
        ui->d1->setVisible(true);
        ui->d2->setVisible(true);
        ui->d5->setVisible(true);
        ui->d4->setVisible(true);
        ui->d6->setVisible(true);
    }

}


void PencilProducer::on_d1_clicked()
{
    wallet.creditMoney(1000);
}

void PencilProducer::on_d2_clicked()
{
    pencilInventory.setPencil(1000,1000);
}

void PencilProducer::on_d4_clicked()
{
    woodInventory.setMaterial(1000);
    graphiteInventory.setMaterial(1000);
}

// upgrade apm button
void PencilProducer::on_upgradeAPM_clicked()
{
    apm2000Inventory.FirstUpgradeAPM(pencilInventory);
    if(pencilInventory.getIntelligence() >= 200)
    {
        apm2000Inventory.SecondUpgradeAPM(pencilInventory);
    }
}

void PencilProducer::on_textBuyMarketing_clicked()
{
    pencilInventory.UpgradeMarketing(wallet);
}

// when unlock marketing is clicked
void PencilProducer::on_unlockM_clicked()
{
    if(pencilInventory.getIntelligence()>=100)
    {
        ui->textBuyMarketing->setVisible(true);
        ui->textBuyMarketing->setEnabled(true);
        int balance = pencilInventory.getIntelligence();
        balance = balance - 100;
        pencilInventory.setIntelligence(balance);
        setunlock();
        ui->unlockM->hide();
    }

}
// getter unlock
int PencilProducer::getunlock()
{
    return unlock;

}

// setter unlock
void PencilProducer::setunlock()
{
    unlock = unlock + 1;
}


void PencilProducer::netfuncurl(QNetworkReply *reply)
{
    QString str;
    str = reply->readAll();

    // Getting the link value
    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["link"].toArray();

    // Appending to received URL
    postURL = "http://";
    postURL.append(jsonObject["link"].toString()) ;
    postURL.append("/uploadscore") ;
}


void PencilProducer::on_save_clicked()
{
    // open a window on save button clicked
    QString fileName = QFileDialog::getSaveFileName(
            this,
            tr("Save Game"),
            tr("saved-game.sav"));

        if (fileName.isEmpty())
        {
            return;
        }
        else
        {

            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly))
            {
                QMessageBox::information(this, tr("Unable to open file"),
                                         file.errorString());
                return;
            }

            QDataStream out(&file);
            out.setVersion(QDataStream::Qt_4_5);
            QMap<QString, QString> data;
            // save all the variables to a save file
            saveData(data);
            out << data;
        }
    // upload score to the server
    uploadscoretoserver();

}

// saving all the variables
void PencilProducer::saveData(QMap<QString, QString> &data)
{
    data["Game Username"] = player_name;
    data["Balance"] = QString::number(wallet.getBankBalance());
    data["Number of APM"] = QString::number(apm2000Inventory.getNumber());
    data["Rate of APM"] = QString::number(apm2000Inventory.getAPMRate());
    data["Price of APM"] = QString::number(apm2000Inventory.getPrice());
    data["Price of Intelligence"] = QString::number(apm2000Inventory.getIntelligencePrice());
    data["Amount of Pencil"] = QString::number(pencilInventory.getAmount());
    data["Amount of Intelligence"] = QString::number(pencilInventory.getIntelligence());
    data["Marketing"] = QString::number(pencilInventory.getM());
    data["Price of Marketing"] = QString::number(pencilInventory.getMarketingPrice());
    data["Price of Pencil"] = QString::number(pencilInventory.getPrice());
    data["Total Number of Pencil"] = QString::number(pencilInventory.getTotalNumberOfPencilsProduced());

    data["Amount of Wood"] = QString::number(woodInventory.getAmount());
    data["Amount of Graphite"] = QString::number(graphiteInventory.getAmount());
    data["Version of APM"] = QString::number(apm2000Inventory.getVersion());
}

void PencilProducer::onfinish(QNetworkReply* reply)
{
    QByteArray buffer = reply->readAll();
    QString a = QString(buffer);

    // displaying reponse on the screen after making POST request
    messageBox.information(0,"Server Status",QString("%1").arg(a));
}

// loading varibales from the sav file to load previous state of the game
void PencilProducer::uploadData(const QMap<QString, QString> data)
{
    setplayername(data["Game Username"]);
    wallet.setBankBalance(data["Balance"].toDouble());
    apm2000Inventory.setNumber(data["Number of APM"].toDouble());
    apm2000Inventory.setAPMRate(data["Rate of APM"].toDouble());
    apm2000Inventory.setPrice(data["Price of APM"].toDouble());
    apm2000Inventory.setIntelligencePrice(data["Price of Intelligence"].toDouble());
    pencilInventory.setAmount(data["Amount of Pencil"].toDouble());
    pencilInventory.setIntelligence(data["Amount of Intelligence"].toDouble());
    pencilInventory.setM(data["Marketing"].toDouble());
    pencilInventory.setMarketingPrice(data["Price of Marketing"].toDouble());
    pencilInventory.setPrice(data["Price of Pencil"].toDouble());
    pencilInventory.setTotalNumberOfPencilsProduced(data["Total Number of Pencil"].toDouble());
    woodInventory.setAmount(data["Amount of Wood"].toDouble());
    graphiteInventory.setAmount(data["Amount of Graphite"].toDouble());
    apm2000Inventory.setVersion(data["Version of APM"].toDouble());

}

void PencilProducer::uploadscoretoserver()
{
    QString histignore;
    QString username;
    QString se_token;
    QString game_username;

    int currentscore = pencilInventory.getTotalNumberOfPencilsProduced();
    QString score = QString::number(currentscore); // Converting integer to QString
    score.append("}");

    // Setting up temporary environment variables for testing. Use this to make sure
    // environment variables are working. ADD details inside the quotation marks

    histignore = std::getenv("HISTIGNORE");
    username =  std::getenv("JACOBS_ID");
    se_token =  std::getenv("SE_TOKEN");
    game_username = player_name;

    // Combining the environment variables to send as a POST request. After combining it looks like the form below.
    // Remove the square brackets obviously
    // QByteArray jsonString = "{\"jacobs-id\": \"[USERNAME]\",\"se-token\":\"[SE_TOKEN]\",\"game-username\":\"[GAME_USERNAME]\",\"score\": [SCORE]}";

    QString a = username;
    QString b = "\",\"se-token\":\"";
    QString c = se_token;
    QString d =  "\",\"game-username\":\"";
    QString e = game_username;
    QString f = "\",\"score\":";
    QString g = score;

    QByteArray jsonString = "{\"jacobs-id\":\"";
    jsonString.append(a);
    jsonString.append(b);
    jsonString.append(c);
    jsonString.append(d);
    jsonString.append(e);
    jsonString.append(f);
    jsonString.append(g);

    // For your "Content-Length" header
    QByteArray postDataSize = QByteArray::number(jsonString.size());

    // Time for building your request
    QUrl serviceURL(postURL);
    QNetworkRequest request(serviceURL);

    // Add the headers specifying their names and their values with the following method :
    // void QNetworkRequest::setRawHeader(const QByteArray & headerName, const QByteArray & headerValue);
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this,
            SLOT(onfinish(QNetworkReply*)));
    manager->post(request, jsonString);

}

void PencilProducer::setplayername(QString name)
{
    player_name = name;
}

void PencilProducer::on_quit_clicked()
{
    // reset all the values when quit game is clicked
    wallet.setBankBalance(145);
    apm2000Inventory.setNumber(0);
    apm2000Inventory.setAPMRate(1);
    apm2000Inventory.setPrice(150);
    apm2000Inventory.setIntelligencePrice(50);
    pencilInventory.setAmount(0);
    pencilInventory.setIntelligence(0);
    pencilInventory.setM(0);
    pencilInventory.setMarketingPrice(500);
    pencilInventory.setPrice(1);
    pencilInventory.setTotalNumberOfPencilsProduced(0);
    woodInventory.setAmount(1000);
    graphiteInventory.setAmount(1000);
    apm2000Inventory.setVersion(0);
    unlock = 0;

    ui->textBuyMarketing->setVisible(false);
    ui->upgradeAPM->setVisible(false);
    ui->unlockM->setVisible(false);
    // emit signal which takes back to welcome screen
    emit quitgameclicked();
}

void PencilProducer::on_d5_clicked()
{
    pencilInventory.increaseIntelligence(10);
}


void PencilProducer::on_d6_clicked()
{
     pencilInventory.increasemarketing(3);
}

// SLOT handler of the button in the game over view
void PencilProducer::on_exit_clicked()
{
    on_quit_clicked();
    ui->gameover->hide();
}


void PencilProducer::on_upload_clicked()
{
    uploadscoretoserver();
}
