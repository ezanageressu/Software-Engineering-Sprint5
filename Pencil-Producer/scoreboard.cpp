#include "scoreboard.h"
#include "ui_scoreboard.h"
#include <QTimer>
#include <string>

/* initializing the constructor */
Scoreboard::Scoreboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Scoreboard)
{
    ui->setupUi(this);

    //Calling the network function to get the Json link
    QNetworkAccessManager *url_rq = new QNetworkAccessManager(this);
    connect(url_rq, &QNetworkAccessManager::finished, this, &Scoreboard::netfuncurl);

    QString URL = "https://matiusulung.com/se.json";
    const QUrl url = QUrl(URL);

    QNetworkRequest request(url);
    url_rq->get(request);

}

Scoreboard::~Scoreboard()
{
    delete ui;
}

void Scoreboard::on_highscores_clicked()
{
    //Connecting the function to get the data from the file
    QNetworkAccessManager *score = new QNetworkAccessManager(this);
    connect(score, &QNetworkAccessManager::finished, this, &Scoreboard::netfunc);
    const QUrl url = QUrl(myURL);
    QNetworkRequest request(url);
    score->get(request);

}

void Scoreboard::netfuncurl(QNetworkReply *reply)
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
}


void Scoreboard::netfunc(QNetworkReply *reply)
{
    QString str;
    str = reply->readAll();

    if(str.isEmpty()==true){
        qDebug() << "Error no data found";
        exit(1);
    }

    QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    QJsonArray jsonArray = jsonObject["highscores"].toArray();
    QString username[10] = {""};
    QString score[10] = {""};
    vector< pair <int,QString> > vect;
    foreach (const QJsonValue & value, jsonArray){
        QJsonObject obj = value.toObject();
        vect.push_back(make_pair(obj["score"].toInt(),obj["game-username"].toString()));
    }
    sort(vect.begin(), vect.end());
    int vect_size = vect.size();
    int j = 9;
    for (int i = vect_size - 1; i >= 0; i--) {
        QString bn = QString::number(vect[i].first);
        username[j] = QString("%1").arg(vect[i].second);
        score[j] = QString("%1").arg(bn);
        j = j - 1;
    }
    ui->user0->setText(username[9]);
    ui->score0->setText(score[9]);
    ui->user1->setText(username[8]);
    ui->score1->setText(score[8]);
    ui->user2->setText(username[7]);
    ui->score2->setText(score[7]);
    ui->user3->setText(username[6]);
    ui->score3->setText(score[6]);
    ui->user4->setText(username[5]);
    ui->score4->setText(score[5]);
    ui->user5->setText(username[4]);
    ui->score5->setText(score[4]);
    ui->user6->setText(username[3]);
    ui->score6->setText(score[3]);
    ui->user7->setText(username[2]);
    ui->score7->setText(score[2]);
    ui->user8->setText(username[1]);
    ui->score8->setText(score[1]);
    ui->user9->setText(username[0]);
    ui->score9->setText(score[0]);

}


void Scoreboard::on_goback_clicked()
{
    /* emits the signal when back button is clicked, which takes back to home screen */
    emit backbuttonclicked();
}
