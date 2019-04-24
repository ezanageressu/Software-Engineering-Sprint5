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
    ui->setupUi(this);
    ui->textBuyMarketing->setVisible(false);
    ui->pushButton->setVisible(false);
    ui->unlockM->setVisible(false);
    ui->highscoretable->setVisible(false);
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

/**
 * @brief PencilProducer::update
 * updates all values displayed on the UI and
 */
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
    ui->priceOfPencil->setText("<html>Price of oui: <b>$" + str + "</b></html>");

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

    str.setNum(priceOfAPM2000, 'f', 2);
    ui->buyMore->setText("Buy More \n$" + str);

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
        if(pencilInventory.getTotalNumberOfPencilsProduced()>=3000)
        {
            if(unlock == 0)
            {
                ui->unlockM->setVisible(true);
            }
            if(pencilInventory.getIntelligence()>=100)
            {
                ui->unlockM->setEnabled(true);
            }
            else
            {
                ui->unlockM->setEnabled(false);
            }
            ui->pushButton->setVisible(true);
            if(pencilInventory.getIntelligence()>=50)
            {
                ui->pushButton->setEnabled(true);
            }
            else
            {
                ui->pushButton->setEnabled(false);
            }

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

    if(!ui->dbt->isChecked())
    {
        ui->d1->setVisible(false);
        ui->d2->setVisible(false);
        ui->d3->setVisible(false);
        ui->d4->setVisible(false);
    }
    if(ui->dbt->isChecked())
    {
        ui->d1->setVisible(true);
        ui->d2->setVisible(true);
        ui->d3->setVisible(true);
        ui->d4->setVisible(true);
    }

}


void PencilProducer::on_d1_clicked()
{
    wallet.creditMoney(1000);
}

void PencilProducer::on_d2_clicked()
{
    pencilInventory.setPencil(0,1000);
}

void PencilProducer::on_d3_clicked()
{
    pencilInventory.setPencil(1000,0);
}

void PencilProducer::on_d4_clicked()
{
    woodInventory.setMaterial(10);
    graphiteInventory.setMaterial(10);
}

void PencilProducer::on_pushButton_clicked()
{
    apm2000Inventory.FirstUpgradeAPM(pencilInventory);
    if(pencilInventory.getIntelligence()>200)
    {
        apm2000Inventory.SecondUpgradeAPM(pencilInventory);
    }
}

void PencilProducer::on_textBuyMarketing_clicked()
{
    pencilInventory.UpgradeMarketing(wallet);
}

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
///getter unlock
int PencilProducer::getunlock()
{
    return unlock;

}

///setter unlock
void PencilProducer::setunlock()
{
    unlock = unlock + 1;
}

void PencilProducer::on_newgame_clicked()
{
    ui->welcome->hide();
    ui->newgame->hide();
    ui->loadgame->hide();
    ui->highscores->hide();
    ui->welcomelab->hide();
    ui->highscoretable->hide();
}

QDataStream& operator>>(QDataStream& in, PencilProducer* pencil)
{
    Wallet wallet;
    APM2000_Inventory apm;
    Pencil_Inventory invent;
    Wood_Inventory wood;
    Graphite_Inventory graphite;
    QString unlock = QString::number(pencil->getunlock());
    QString balance = QString::number(wallet.getBankBalance());
    QString number = QString::number(apm.getNumber());
    QString rate = QString::number(apm.getRate());
    QString price = QString::number(apm.getPrice());
    QString intell_price = QString::number(apm.getIntelligencePrice());
    QString amount = QString::number(invent.getAmount());
    QString intell = QString::number(invent.getIntelligence());
    QString M = QString::number(invent.getM());
    QString marketing = QString::number(invent.getMarketingPrice());
    QString pencilprice = QString::number(invent.getPrice());
    QString publicdemand = QString::number(invent.getPublicDemand());
    QString totalnumber = QString::number(invent.getTotalNumberOfPencilsProduced());
    QString woodamount = QString::number(wood.getPrice());
    QString gamount = QString::number(graphite.getPrice());
    in >> unlock >> balance >> number >> rate >> price >>
       intell_price >> amount >> intell >> M >> marketing >>
       pencilprice >> publicdemand >> totalnumber >> woodamount >>
       gamount;
    return in;
}


void PencilProducer::on_highscores_clicked()
{
    //Connecting the function to get the data from the file
    QNetworkAccessManager *score = new QNetworkAccessManager(this);
    connect(score, &QNetworkAccessManager::finished, this, &PencilProducer::netfunc);
    const QUrl url = QUrl(myURL);
    QNetworkRequest request(url);
    score->get(request);

}
void PencilProducer::netfuncurl(QNetworkReply *reply)
{
    QString str;
    str = reply->readAll();
    ///Getting the link value
    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["link"].toArray();
    /// Appending to received URL
    myURL = "http://";
    myURL.append(jsonObject["link"].toString()) ;
    myURL.append("/getscores") ;
    postURL = "http://";
    postURL.append(jsonObject["link"].toString()) ;
    postURL.append("/uploadscore") ;
}


void PencilProducer::netfunc(QNetworkReply *reply)
{
    if(ui->highscoretable->isVisible() == true)
    {
        ui->highscoretable->setVisible(false);
    }
    else
    {
        QString str;
        str = reply->readAll();

        if(str.isEmpty()==true)
        {
            qDebug() << "Error no data found";
            exit(1);
        }

        QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        QJsonArray jsonArray = jsonObject["highscores"].toArray();
        QList<QString> usernames;
        QString finaltable;
        QString key2;
        int scores[10];
        int i= 0;
        int n = jsonArray.size();
        int j, key;
        ///Getting and sorting the score values we get
        while(i<n)
        {
            foreach (const QJsonValue & value, jsonArray)
            {
                QJsonObject obj = value.toObject();
                usernames.append(obj["game-username"].toString()) ;
                scores[i] = obj["score"].toInt();
                i++;
            }

        }

        for (i = 1; i < n; i++)
        {
            key = scores[i];
            key2 = usernames[i];
            j = i - 1;

            while (j >= 0 && scores[j] < key)
            {
                scores[j + 1] = scores[j];
                usernames[j+1] = usernames[j];
                j = j - 1;

            }
            scores[j + 1] = key;
            usernames[j+1] = key2;

        }
        ///Displaying the final scores table
        finaltable.append("\n") ;
        finaltable.append("Highscores") ;

        for(i=0; i<10; i++)
        {
            finaltable.append("\n\n") ;
            finaltable.append(usernames[i]) ;
            finaltable.append(":") ;
            finaltable.append(QString::number(scores[i]));


        }

        ui->highscoretable->setText(finaltable);
        ui->highscoretable->setVisible(true);
    }

}
QDataStream& operator<<(QDataStream& out, PencilProducer* pencil)
{
    Wallet wallet;
    APM2000_Inventory apm;
    Pencil_Inventory invent;
    Wood_Inventory wood;
    Graphite_Inventory graphite;
    QString unlock = QString::number(pencil->getunlock());
    QString balance = QString::number(wallet.getBankBalance());
    QString number = QString::number(apm.getNumber());
    QString rate = QString::number(apm.getRate());
    QString price = QString::number(apm.getPrice());
    QString intell_price = QString::number(apm.getIntelligencePrice());
    QString amount = QString::number(invent.getAmount());
    QString intell = QString::number(invent.getIntelligence());
    QString M = QString::number(invent.getM());
    QString marketing = QString::number(invent.getMarketingPrice());
    QString pencilprice = QString::number(invent.getPrice());
    QString publicdemand = QString::number(invent.getPublicDemand());
    QString totalnumber = QString::number(invent.getTotalNumberOfPencilsProduced());
    QString woodamount = QString::number(wood.getPrice());
    QString gamount = QString::number(graphite.getPrice());
    out << unlock << balance << number << rate << price <<
        intell_price << amount << intell << M << marketing <<
        pencilprice << publicdemand << totalnumber << woodamount << gamount;
    return out;
}


void PencilProducer::on_save_clicked()
{
    ofstream myfile("../save/data.sav");
    if (myfile.is_open())
    {
        myfile << "a- Balance = "<< wallet.getBankBalance() << "\n";
        myfile << "b- Number of APM = "<< apm2000Inventory.getNumber() << "\n";
        myfile << "c- Rate of APM = "<< apm2000Inventory.getAPMRate()<< "\n";
        myfile << "d- Price of APM = "<< apm2000Inventory.getPrice() << "\n";
        myfile << "e- Price of Intelligence = "<< apm2000Inventory.getIntelligencePrice() << "\n";
        myfile << "f- Amount of Pencil = "<< pencilInventory.getAmount() << "\n";
        myfile << "g- Amount of Intelligence = "<< pencilInventory.getIntelligence() << "\n";
        myfile << "h- Marketing = "<< pencilInventory.getM() << "\n";
        myfile << "i- Price of Marketing = "<< pencilInventory.getMarketingPrice() << "\n";
        myfile << "j- Price of Pencil = "<< pencilInventory.getPrice()  << "\n";
        myfile << "k- Total Number of Pencil = "<< pencilInventory.getTotalNumberOfPencilsProduced() << "\n";
        myfile << "l- Amount of Wood = "<< woodInventory.getAmount() << "\n";
        myfile << "m- Amount of Graphite = "<< graphiteInventory.getAmount() << "\n";
        myfile << "n- Version of APM = " << apm2000Inventory.getVersion() << "\n";

        myfile.close();
    }
    else cout << "Unable to open file";

    QString histignore;
    QString username;
    QString se_token;
    QString game_username;

    int currentscore = pencilInventory.getTotalNumberOfPencilsProduced();
    QString score = QString::number(currentscore); ///Converting integer to QString
    score.append("}");

    ///Setting up temporary environment variables for testing. Use this to make sure
    ///environment variables are working. ADD details inside the quotation marks

//    qputenv ("JACOBS_ID", " ");
//    qputenv("SE_TOKEN", " ");
//    qputenv("GAME_USERNAME", " ");

    histignore = std::getenv("HISTIGNORE");
    username =  std::getenv("JACOBS_ID");
    se_token =  std::getenv("SE_TOKEN");
    game_username = std::getenv("GAME_USERNAME");

    ///Combining the environment variables to send as a POST request. After combining it looks like the form below. Remove the square brackets obviously
    ///QByteArray jsonString = "{\"jacobs-id\": \"[USERNAME]\",\"se-token\":\"[SE_TOKEN]\",\"game-username\":\"[GAME_USERNAME]\",\"score\": [SCORE]}";

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

    qDebug()<< "String: " << jsonString << endl;

    // For your "Content-Length" header
    QByteArray postDataSize = QByteArray::number(jsonString.size());

    // Time for building your request
    QUrl serviceURL(postURL);
    QNetworkRequest request(serviceURL);

    // Add the headers specifying their names and their values with the following method : void QNetworkRequest::setRawHeader(const QByteArray & headerName, const QByteArray & headerValue);
    request.setRawHeader("Content-Type", "application/json");
    request.setRawHeader("Content-Length", postDataSize);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this,
            SLOT(onfinish(QNetworkReply*)));
    manager->post(request, jsonString);
}

void PencilProducer::onfinish(QNetworkReply* reply)
{
    QByteArray buffer = reply->readAll();
    qDebug() << buffer;
}

void PencilProducer::on_loadgame_clicked()
{
    ///Exit welcome screen and go to game screen
    ui->welcome->hide();
    ui->newgame->hide();
    ui->loadgame->hide();
    ui->highscores->hide();
    ui->welcomelab->hide();

    string line;
    ifstream myfile ("../save/data.sav");
    if(myfile.is_open())
    {
        while (getline(myfile,line))
        {
            if (line[0] == 'a')  ///Check if correct line is being read or not
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str()); ///str is the sub-string after the "=" sign
                double val = str.toDouble();
                wallet.setBankBalance(val);
                cout << val << endl;
            }
            if (line[0] == 'b')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                apm2000Inventory.setNumber(val);
                cout << val << endl;
            }
            if (line[0] == 'c')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                apm2000Inventory.setAPMRate(val);
                cout << val << endl;
            }
            if (line[0] == 'd')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                apm2000Inventory.setPrice(val);
                cout << val << endl;
            }
            if (line[0] == 'e')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                apm2000Inventory.setIntelligencePrice(val);
                cout << val << endl;
            }
            if (line[0] == 'f')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                pencilInventory.setAmount(val);
                cout << val << endl;
            }
            if (line[0] == 'g')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                pencilInventory.setIntelligence(val);
                cout << val << endl;
            }
            if (line[0] == 'h')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                pencilInventory.setM(val);
                cout << val << endl;
            }
            if (line[0] == 'i')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                pencilInventory.setMarketingPrice(val);
                cout << val << endl;
            }
            if (line[0] == 'j')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                pencilInventory.setPrice(val);
                cout << val << endl;
            }

            if (line[0] == 'k')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                pencilInventory.setTotalNumberOfPencilsProduced(val);
                cout << val << endl;
            }
            if (line[0] == 'l')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                woodInventory.setAmount(val);
                cout << val << endl;
            }
            if (line[0] == 'm')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                graphiteInventory.setAmount(val);
                cout << val << endl;
            }
            if (line[0] == 'n')
            {
                QString str = ((line.substr(line.find("=") + 1)).c_str());
                double val = str.toDouble();
                apm2000Inventory.setVersion(val);
                cout << val << endl;
            }
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void PencilProducer::on_quit_clicked()
{
    wallet.setBankBalance(145);
    apm2000Inventory.setNumber(0);
    apm2000Inventory.setAPMRate(0);
    apm2000Inventory.setPrice(150);
    apm2000Inventory.setIntelligencePrice(0);
    pencilInventory.setAmount(0);
    pencilInventory.setIntelligence(0);
    pencilInventory.setM(0);
    pencilInventory.setMarketingPrice(500);
    pencilInventory.setPrice(1);
    pencilInventory.setTotalNumberOfPencilsProduced(0);
    woodInventory.setAmount(1000);
    graphiteInventory.setAmount(1000);
    apm2000Inventory.setVersion(1);

    ui->welcome->show();
    ui->newgame->show();
    ui->loadgame->show();
    ui->highscores->show();
    ui->welcomelab->show();
}
