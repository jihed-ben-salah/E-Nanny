#include "accueil.h"
#include "ui_accueil.h"
#include "mainwindow1.h"
#include "activiteloisirs.h"
#include "secu.h"
#include "education.h"
#include "gestionc.h"
#include "produitalimentaire.h"
#include <QMediaPlayer>
#include <QMediaPlaylist>
accueil::accueil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::accueil)
{
    ui->setupUi(this);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).
}

accueil::~accueil()
{
    delete ui;
}

void accueil::on_pushButton_7_clicked()
{mainwindow1 w;

    w.exec();

}

void accueil::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->lineEdit->setText("Alarme activé"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->lineEdit->setText("Alarme désactivée");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}

void accueil::on_desact_Alarme_clicked()
{

  A.write_to_arduino("0");
}

void accueil::on_pushButton_8_clicked()
{
    mainwindow1 w;
        w.exec();

}

void accueil::on_pushButton_clicked()
{secu s;
    s.exec();

}

void accueil::on_securite_clicked()
{
    secu s;
        s.exec();
}

void accueil::on_pushButton_3_clicked()
{
    Education E;
    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/souma/Desktop/smart_parental_monitoring_2A22-gestion_securite/song/bienvenue.mp3"));
    player->play();
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(1);
    E.exec();
}

void accueil::on_pushButton_4_clicked()
{
    Education E;
    QMediaPlayer* player;
    player= new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/souma/Desktop/smart_parental_monitoring_2A22-gestion_securite/song/bienvenue.mp3"));
        player->play();
        qDebug()<<player->errorString();
        QThread::sleep(1);
    E.exec();
}

void accueil::on_pushButton_5_clicked()
{ gestionc  G;
    G.exec();


}

void accueil::on_comptes_clicked()
{
    gestionc  G;
        G.exec();
}

void accueil::on_pushButton_9_clicked()
{
    produitalimentaire P;
    P.exec();
}

void accueil::on_pushButton_12_clicked()
{
    produitalimentaire P;
    P.exec();
}

void accueil::on_pushButton_11_clicked()
{
    activiteloisirs m;
  m.exec();
}

void accueil::on_pushButton_10_clicked()
{
    activiteloisirs m;
  m.exec();
}
