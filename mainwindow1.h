#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QDialog>
#include"personned_aides.h"
#include "reclamation.h"
#include"smtp.h"
#include<QtMultimedia/QSound>
#include<QTimer>
#include <QDialog>
#include <QFileDialog>
#include <QtCharts>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QFileDialog>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
namespace Ui {
class mainwindow1;
}

class mainwindow1 : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow1(QWidget *parent = nullptr);
    ~mainwindow1();
    void update_personne_list();

    void update_mail_list();
    bool controleNumTel(int test);

    bool controleVide(QString test);

    bool controleVideInt(int test);

    bool controleEmail(QString test);
    int R_BCS1();
    int R_BCS2();
    int R_BCS3();
    int R_BCS4();
    int R_BCS5();
    int R_BCS6();


    QChartView* barchart();
private slots:


    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on_tri_clicked();
    void file();

    void on_afficher_personne_activated(const QModelIndex &index);

    void on_afficher_personne_clicked(const QModelIndex &index);

    void on_envoyer_clicked();

    void on_modifier_rec_clicked();

    void on_supprimer_rec_clicked();

    void on_afficher_rec_activated(const QModelIndex &index);

    void on_afficher_rec_clicked(const QModelIndex &index);

    void on_stop_2_clicked();

    void on_stop_clicked();

    void on_tabWidget_2_tabBarClicked(int index);

 void on_Excel_clicked();

    void on_pdf_clicked();

private:
    Ui::mainwindow1 *ui;
    Personned_aides P;
    int id_personne=0;

    int ref_reclamation=0;
    reclamation R;
    QSound *sound;
    QSound *sound1;
 QStringList files;


};

#endif // MAINWINDOW1_H
