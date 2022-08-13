#include "gestionc.h"
#include "ui_gestionc.h"
#include "enfant.h"
#include "compte.h"
#include <qmessagebox.h>
#include <QIntValidator>
#include <QSqlQuery>
#include <QPixmap>
#include <QScrollBar>
#include <qfiledialog.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPrinter>
gestionc::gestionc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionc)
{
    ui->setupUi(this);
    ui->afficher_enfant->setModel(tmpenfant.afficher());
  ui->afficher_compte->setModel(tmpcompte.afficher());
  update();
  refrech();
}

gestionc::~gestionc()
{
    delete ui;
}
void gestionc::on_ajouter_enfant_clicked()
{
    int identifiant=ui->lineEdit_id_a->text().toInt();
      QString nom=ui->lineEdit_nom_a->text();
      QString prenom=ui->lineEdit_pernom_a->text();
      QString adresse=ui->lineEdit_adresse_a->text();
       int age=ui->lineEdit_age_a->text().toInt();
       int poids=ui->lineEdit_poids_a->text().toInt();
       int taille=ui->lineEdit_taille_a->text().toInt();
      QString maladie=ui->lineEdit_maladies_a->text();

      if(identifiant==0)
                  QMessageBox::warning(this,"ERROR","Veillez remplir id de l'enfant");
             else if(nom=="")
                   QMessageBox::warning(this,"ERROR","Veillez remplir nom de l'enfant");
              else if (prenom=="")
                   QMessageBox::warning(this,"ERROR","Veillez remplir le prenom de l'enfant");

              else if(adresse=="")
                   QMessageBox::warning(this,"ERROR","Veillez remplir l'adresse de l'enfant");

               else if(age==0)
                   QMessageBox::warning(this,"ERROR","Veillez remplir l'age de l'enfant");
      else if(poids==0)
           QMessageBox::warning(this,"ERROR","Veillez remplir le poids de l'enfant");
      else if(taille==0)
          QMessageBox::warning(this,"ERROR","Veillez remplir la taille de l'enfant");
      else if(maladie=="")
          QMessageBox::warning(this,"ERROR","Veillez remplir les maladies de l'enfant");

      else {

  Enfant E1(identifiant,nom,prenom,adresse,age,poids,taille,maladie);
  bool test=E1.ajouter();
  QMessageBox msgBox;

  if(test)
     { msgBox.setText("Ajout avec succes.");

       ui->afficher_enfant->setModel(tmpenfant.afficher());
       update();
  }
  else
      msgBox.setText("Echec d'ajout");
  msgBox.exec();
}
}

void gestionc::on_supprimer_clicked()
{

    bool test=tmpenfant.supprimer(id_enfant);
    if(test){
         ui->afficher_enfant->setModel(tmpenfant.afficher());
         update();
        QMessageBox::information(nullptr,"suppression enfant","enfant supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","enfant non supprimer");
}

void gestionc::on_afficher_enfant_activated(const QModelIndex &index)
{
    QString val=ui->afficher_enfant->model()->data(index).toString();
          QSqlQuery qry;
          qry.prepare("select * from enfant where"
                      " id='"+val+"' or nom='"+val+"' or prenom='"+val+"'or adresse='"+val+"' or age='"+val+"' or poids ='"+val+"' or taille='"+val+"' or maladie ='"+val+"' ");
          if(qry.exec())
            {while (qry.next())
           { ui->lineEdit_id_a_2->setText(qry.value(0).toString());
             ui->lineEdit_nom_a_2->setText(qry.value(1).toString());
             ui->lineEdit_pernom_a_2->setText(qry.value(2).toString());
             ui->lineEdit_adresse_a_2->setText(qry.value(3).toString());
             ui->lineEdit_age_a_2->setText(qry.value(4).toString());
             ui->lineEdit_poids_a_2->setText(qry.value(5).toString());
             ui->lineEdit_taille_a_2->setText(qry.value(6).toString());
             ui->lineEdit_maladies_a_2->setText(qry.value(7).toString());
              }
        }
}

void gestionc::on_afficher_enfant_clicked(const QModelIndex &index)
{
       id_enfant=ui->afficher_enfant->model()->data(index).toInt();
}

void gestionc::on_modifier_clicked()
{
    int identifiant=ui->lineEdit_id_a_2->text().toInt();
      QString nom=ui->lineEdit_nom_a_2->text();
      QString prenom=ui->lineEdit_pernom_a_2->text();
      QString adresse=ui->lineEdit_adresse_a_2->text();
       int age=ui->lineEdit_age_a_2->text().toInt();
       int poids=ui->lineEdit_poids_a_2->text().toInt();
       int taille=ui->lineEdit_taille_a_2->text().toInt();
      QString maladie=ui->lineEdit_maladies_a_2->text();

  Enfant E1(identifiant,nom,prenom,adresse,age,poids,taille,maladie);
  bool test=E1.modifier();
  QMessageBox msgBox;

  if(test)
     { msgBox.setText(" Modification avec succes.");

       ui->afficher_enfant->setModel(tmpenfant.afficher());
  }
  else
      msgBox.setText("Echec de modifier");
  msgBox.exec();
}

void gestionc::on_tri_clicked()
{
ui->afficher_enfant->setModel(tmpenfant.AfficherTrieAge());
}

void gestionc::on_recherche_textChanged(const QString &arg1)
{
    ui->afficher_enfant->setModel(tmpenfant.rechercherNom(arg1));
}



void gestionc::update()
{



        QSqlQueryModel *m=new QSqlQueryModel();
            QSqlQuery *querry=new QSqlQuery();
            querry->prepare("SELECT prenom FROM enfant");
            querry->exec();
            m->setQuery(*querry);


            ui->comboBox->setModel(m);

}

void gestionc::on_creer_compte_clicked()
{

    int identifiant=ui->lineedit_idc->text().toInt();
      QString login=ui->lineedit_login->text();
      QString mdp=ui->lineedit_mdp->text();
      QString enfant=ui->comboBox->currentText();

      if(identifiant==0)
                  QMessageBox::warning(this,"ERROR","Veillez remplir id de l'enfant");
             else if(login=="")
                   QMessageBox::warning(this,"ERROR","Veillez remplir le login ");
              else if (mdp=="")
                   QMessageBox::warning(this,"ERROR","Veillez remplir le mot de passe ");

              else if(enfant=="")
                   QMessageBox::warning(this,"ERROR","Veillez choisir l'enfant");


      else {


      compte  C1(identifiant,login,mdp,enfant);
      bool test=C1.ajouter();
      QMessageBox msgBox;

      if(test)
         { msgBox.setText("Ajout avec succes.");

           ui->afficher_compte->setModel(tmpcompte.afficher());
      }
      else
          msgBox.setText("Echec d'ajout");
      msgBox.exec();

}
}


void gestionc::on_afficher_compte_activated(const QModelIndex &index)
{

    QString val=ui->afficher_compte->model()->data(index).toString();
           update();

          QSqlQuery qry;
          qry.prepare("select * from compte where"
                      " idc='"+val+"' or login='"+val+"' or mdp='"+val+"' or enfant='"+val+"' ");
          if(qry.exec())
            {while (qry.next())
           { ui->lineedit_idc_2->setText(qry.value(0).toString());
             ui->lineedit_login_2->setText(qry.value(1).toString());
             ui->lineedit_mdp_2->setText(qry.value(2).toString());
             ui->lineedit_enfant_2->setText(qry.value(3).toString());

              }
        }

}





void gestionc::on_supprimer_compte_clicked()
{
    bool test=tmpcompte.supprimer(id_compte);
    if(test){
         ui->afficher_compte->setModel(tmpcompte.afficher());
         update();
        QMessageBox::information(nullptr,"suppression compte","compte supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","compte non supprimer");
}


void gestionc::on_afficher_compte_clicked(const QModelIndex &index)
{
    id_compte=ui->afficher_compte->model()->data(index).toInt();
}

void gestionc::on_modifier_compte_clicked()
{

    int identifiant=ui->lineedit_idc_2->text().toInt();
      QString login=ui->lineedit_login_2->text();
      QString mdp=ui->lineedit_mdp_2->text();
      QString enfant=ui->lineedit_enfant_2->text();


  compte C1(identifiant,login,mdp,enfant);
  bool test=C1.modifier();
  QMessageBox msgBox;

  if(test)
     { msgBox.setText(" Modification avec succes.");

       ui->afficher_compte->setModel(tmpcompte.afficher());


  }
  else
      msgBox.setText("Echec de modifier");
  msgBox.exec();
}


void gestionc::on_imprimer_clicked()
{  compte E;
    QSqlQueryModel * model=new QSqlQueryModel();
    model=E.Find_compte();
    QString textData= "idc ; login ; mdp ; enfant \n";
    int rows=model->rowCount();
    int columns=model->columnCount();
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            textData += model->data(model->index(i,j)).toString();
            textData +=" ; ";
        }
        textData += "\n";
    }
    QString fileName = QFileDialog::getSaveFileName(this, "Export Excel", QString(), "*.csv");
    if (!fileName.isEmpty())
        if (QFileInfo(fileName).suffix().isEmpty())
            fileName.append(".csv");
    QFile csvfile(fileName);
    if(csvfile.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        QTextStream out(&csvfile);
        out<<textData;
    }
    csvfile.close();

}


void gestionc::on_impdos_2_clicked()
{

    compte e;

                  QString text=e.apercu_pdf();
                  ui->imp->setText(text);

                  QPrinter printer ;
                  printer.setPrinterName("imprim");
                  QPrintDialog dialog (&printer,this);
                  if(dialog.exec()==QDialog::Rejected) return ;
                  ui->imp->print(&printer);
}

void gestionc::refrech() {
    ui->afficher_compte->setModel(tmpcompte.afficher());
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT idc FROM compte");
        ui->idsup->setModel(model);


        QSqlQueryModel * model2= new QSqlQueryModel();
        model2->setQuery("SELECT idc FROM ARCHIVE");
        ui->idRestoration->setModel(model2);
}





void gestionc::on_sup_clicked()
{
        ui->idsup->currentText().toInt();
        QString login=ui->lineedit_login_2->text();
        QString mdp=ui->lineedit_mdp_2->text();
        QString enfant=ui->lineedit_enfant_2->text();
        bool test=tmpcompte.supprimerc(id_compte,login,mdp,enfant);
        if(test){
            ui->afficher_compte->setModel(tmpcompte.afficher());


            QMessageBox::information(nullptr,"Archivage ","compte archiver avec succés");
        refrech();

        }
        else
                QMessageBox::warning(nullptr,"Error","compte non archiver");
}
void gestionc::on_Archive_clicked()
{
    ui->afficher_compte->setModel(tmpcompte.archive());

}
void gestionc::on_restoration_clicked()
{QString login=ui->lineedit_login_2->text();
    QString mdp=ui->lineedit_mdp_2->text();
    QString enfant=ui->lineedit_enfant_2->text();
    int id =ui->idRestoration->currentText().toInt();
        bool test=tmpcompte.restoration(id,login,mdp,enfant);
        if(test){
            QSqlQueryModel *s=new QSqlQueryModel();
                QSqlQuery *querry=new QSqlQuery();
                querry->prepare("SELECT idc FROM archive");
                querry->exec();
                s->setQuery(*querry);


                ui->idsup->setModel(s);
            ui->afficher_compte->setModel(tmpcompte.afficher());
            QMessageBox::information(nullptr,"restauration compte","compte restaurer avec succés");
            refrech();
        }
        else
                QMessageBox::warning(nullptr,"Error","compte non restaurer");





}
