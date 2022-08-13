#ifndef GESTIONC_H
#define GESTIONC_H

#include <QDialog>
#include "enfant.h"
#include "compte.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
namespace Ui {
class gestionc;
}

class gestionc : public QDialog
{
    Q_OBJECT

public:
    explicit gestionc(QWidget *parent = nullptr);
    ~gestionc();
    void update();
    void refrech();
private slots:


    void on_ajouter_enfant_clicked();

    void on_supprimer_clicked();

    void on_afficher_enfant_activated(const QModelIndex &index);

    void on_afficher_enfant_clicked(const QModelIndex &index);

    void on_modifier_clicked();

    void on_tri_clicked();

    void on_recherche_textChanged(const QString &arg1);





    void on_creer_compte_clicked();

    void on_afficher_compte_activated(const QModelIndex &index);



    void on_supprimer_compte_clicked();



    void on_afficher_compte_clicked(const QModelIndex &index);

    void on_modifier_compte_clicked();




    void on_imprimer_clicked();



    void on_impdos_2_clicked();

void on_Archive_clicked();
void on_sup_clicked();


    void on_restoration_clicked();


private:
    Ui::gestionc *ui;
    Enfant tmpenfant;
    compte tmpcompte;

    int id_enfant=0;
    int id_compte=0;
};

#endif // GESTIONC_H
