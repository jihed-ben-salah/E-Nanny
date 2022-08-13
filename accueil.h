#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QDialog>
#include"personned_aides.h"
#include "reclamation.h"
#include"smtp.h"
#include<QtMultimedia/QSound>
#include<QTimer>
#include <QDialog>
#include <QFileDialog>
#include <QtCharts>
#include "arduino.h"
namespace Ui {
class accueil;
}

class accueil : public QDialog
{
    Q_OBJECT

public:
    explicit accueil(QWidget *parent = nullptr);
    ~accueil();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_securite_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_comptes_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
        // ce slot est lancé à chaque réception d'un message de Arduino


     void on_desact_Alarme_clicked();

private:
    Ui::accueil *ui;
    QByteArray data; // variable contenant les données reçues

        Arduino A; // objet temporaire
};

#endif // ACCUEIL_H
