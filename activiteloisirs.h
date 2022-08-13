#ifndef ACTIVITELOISIRS_H
#define ACTIVITELOISIRS_H

#include <QDialog>
#include "activiteloi.h"
#include "rendezvous.h"

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QFileDialog>
#include <QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
namespace Ui {
class activiteloisirs;
}

class activiteloisirs : public QDialog
{
    Q_OBJECT

public:
    explicit activiteloisirs(QWidget *parent = nullptr);
    ~activiteloisirs();
    void update();
    void update_rdv();
void update_nom();
private slots:

//void on_tabWidget_currentChanged(int index);

void on_modifier_clicked();

void on_ajout_clicked();

void on_sup_clicked();

void on_Ajout_rdv_clicked();

void on_Supprimer_rdv_clicked();

void on_Modifier_rdv_clicked();

void on_tri_Activite_clicked();


void on_recherche_activite_textChanged(const QString &arg1);

void on_tabactivite_activated(const QModelIndex &index);

void on_tabactivite_clicked(const QModelIndex &index);

void on_tabrdv_activated(const QModelIndex &index);

void on_tabrdv_clicked(const QModelIndex &index);

void on_tri_rdv_clicked();

void on_Recherche_rdv_textChanged(const QString &arg1);

void on_Excel_clicked();

void on_imprimer_clicked();




void on_slidervolume_sliderMoved(int position);

void on_pushButton_4_clicked();

void on_pushButton_5_clicked();

//void on_id_act_comboBox_currentIndexChanged(const QString &arg1);

void on_tri_id_activite_clicked();

void on_tri_activite_nom_clicked();

void on_tri_rdv_id_clicked();

void on_Tri_nom_rdv_clicked();

void on_actionNew_triggered();

   void on_actionOpen_triggered();

   void on_actionSave_as_triggered();

   void on_actionPrint_triggered();

   void on_actionExit_triggered();

   void on_actionSave_triggered();

   void on_actionCopy_triggered();

   void on_actionCut_triggered();

   void on_actionPaste_triggered();

   void on_actionUndo_triggered();

   void on_actionRedo_triggered();
   bool controleNumTel(int test);
   bool controleVide(QString test);
   bool controleVideInt(int test);
   bool controleEmail(QString test);



   void on_pushButton_2_clicked();

   void on_open_clicked();

   void on_save_as_clicked();

   void on_save_clicked();

   void on_copy_clicked();

   void on_cut_clicked();

   void on_paste_clicked();

   void on_undo_clicked();

   void on_redo_clicked();

   void on_print_clicked();

   void on_exit_clicked();


private:
    Ui::activiteloisirs *ui;
    activiteloi tmpactivite;
    RendezVous tmprendezvous;

    QString currentFile = "";
    int id_activite =0;
    int id_rdvs =0;
};

#endif // ACTIVITELOISIRS_H
