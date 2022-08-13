#include "produitalimentaire.h"
#include "ui_produitalimentaire.h"
#include "fournisseur.h"
#include "produit.h"
#include "commande.h"
#include <qmessagebox.h>
#include <QIntValidator>
#include <QSqlQuery>
#include <QDebug>
#include <QDesktopServices>
#include <QPrintDialog>
#include <qfiledialog.h>
#include <QtPrintSupport/QPrinter>
#include <QPixmap>
#include <QScrollBar>
#include <QUrl>
#include <QDate>
using namespace qrcodegen;
produitalimentaire::produitalimentaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::produitalimentaire)
{
    ui->setupUi(this);
    ui->afficher_fournisseur->setModel((tmpfournisseur.afficher()));
    ui->afficher_produit->setModel((tmpproduit.afficher_produit()));
    ui->afficher_commande->setModel((tmpcommande.afficher_commande()));


    update_fournisseur();
    update_produit();
    //update_commande();
}

produitalimentaire::~produitalimentaire()
{
    delete ui;
}
void produitalimentaire::on_ajout_fournisseur_clicked()
{
    int id=ui->lineEdit_idf->text().toInt();
         QString nom=ui->lineEdit_nomf->text();
         QString marque=ui->lineEdit_marquef->text();
         QString adresse=ui->lineEdit_adressef->text();
          int numero=ui->lineEdit_numerof->text().toInt();


         if(id==0)
            QMessageBox::warning(this,"ERROR","Veillez remplir id du fournisseur");
       else if(nom=="")
             QMessageBox::warning(this,"ERROR","Veillez remplir nom du fournisseur");
        else if (marque=="")
             QMessageBox::warning(this,"ERROR","Veillez remplir marque du fournisseur");

        else if(adresse=="")
             QMessageBox::warning(this,"ERROR","Veillez remplir adresse du fournisseur");

         else if(numero==0)
             QMessageBox::warning(this,"ERROR","Veillez remplir numero du fournisseur");

         else {
             fournisseur F1(id,nom,marque,adresse,numero);

     bool test=F1.ajouter();
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Ajout avec succes.");

          ui->afficher_fournisseur->setModel(tmpfournisseur.afficher());
          update_fournisseur();
     }
     else
         msgBox.setText("Echec d'ajout");
     msgBox.exec();}
}

void produitalimentaire::on_afficher_fournisseur_activated(const QModelIndex &index)
{



    QString val=ui->afficher_fournisseur->model()->data(index).toString();
          QSqlQuery qry;
          qry.prepare("select * from fournisseur where"
                      " id='"+val+"' or nom='"+val+"' or marque='"+val+"'or adresse='"+val+"' or numero='"+val+"' ");
          if(qry.exec())
            {while (qry.next())
           { ui->lineEdit_idf_2->setText(qry.value(0).toString());
             ui->lineEdit_nomf_2->setText(qry.value(1).toString());
             ui->lineEdit_marquef_2->setText(qry.value(2).toString());
             ui->lineEdit_adressef_2->setText(qry.value(3).toString());
             ui->lineEdit_numerof_2->setText(qry.value(4).toString());

              }
        }


}


void produitalimentaire::on_supprimer_clicked()
{

    bool test=tmpfournisseur.supprimer(id_fournisseur);
       if(test){
            ui->afficher_fournisseur->setModel(tmpfournisseur.afficher());
           QMessageBox::information(nullptr,"suppression founisseur","fournisseur supprimer avec succés");
           update_fournisseur();

       }
       else
               QMessageBox::warning(nullptr,"Error","fournisseur non supprimer");
   }



void produitalimentaire::on_modifier_clicked()
{
    int identifiant=ui->lineEdit_idf_2->text().toInt();
         QString nom=ui->lineEdit_nomf_2->text();
         QString marque=ui->lineEdit_marquef_2->text();
         QString adresse=ui->lineEdit_adressef_2->text();
          int numero=ui->lineEdit_numerof_2->text().toInt();


     fournisseur F1(identifiant,nom,marque,adresse,numero);
     bool test=F1.modifier();
     QMessageBox msgBox;

     if(test)
        { msgBox.setText(" Modification avec succes.");

          ui->afficher_fournisseur->setModel(tmpfournisseur.afficher());
          update_fournisseur();
     }
     else
         msgBox.setText("Echec de modifier");
     msgBox.exec();
}
void produitalimentaire::update_fournisseur()
{



        QSqlQueryModel *m=new QSqlQueryModel();
            QSqlQuery *querry=new QSqlQuery();
            querry->prepare("SELECT id FROM fournisseur");
            querry->exec();
            m->setQuery(*querry);


            ui->fournisseur->setModel(m);

}
void produitalimentaire:: update_produit()
{



        QSqlQueryModel *m=new QSqlQueryModel();
            QSqlQuery *querry=new QSqlQuery();
            querry->prepare("SELECT id_produit FROM produit");
            querry->exec();
            m->setQuery(*querry);


            ui->produit->setModel(m);

}

void produitalimentaire::on_trier_clicked()
{
    ui->afficher_fournisseur->setModel((tmpfournisseur.AfficherTrie()));
}
void produitalimentaire::on_trier_marque_clicked()
{
    ui->afficher_fournisseur->setModel((tmpfournisseur.AfficherTrieMarque()));
}
void produitalimentaire::on_afficher_fournisseur_clicked(const QModelIndex &index)
{
    id_fournisseur=ui->afficher_fournisseur->model()->data(index).toInt();
}


void produitalimentaire::on_lineEdit_rechercherf_textChanged(const QString &arg1)
{
    ui->afficher_fournisseur->setModel(tmpfournisseur.rechercherNom(arg1));
}


void produitalimentaire::on_ajout_produit_clicked()
{
    int id_produit=ui->lineEdit_idp->text().toInt();
    int fournisseur=ui->lineEdit_idf_3->currentText().toInt();
    QString nom=ui->lineEdit_nomp->text();
     int prix=ui->lineEdit_prix->text().toInt();
     if(id_produit==0)
        QMessageBox::warning(this,"ERROR","Veillez remplir id du produit");
   else if(fournisseur==0)
         QMessageBox::warning(this,"ERROR","Veillez remplir l id fournisseur du produit");
    else if (nom=="")
         QMessageBox::warning(this,"ERROR","Veillez remplir nom du produit");

     else if(prix==0)
         QMessageBox::warning(this,"ERROR","Veillez remplir prix du produit");
else{
produit P1(id_produit,fournisseur,nom,prix);
bool test=P1.ajouter_produit();
QMessageBox msgBox;

if(test)
   { msgBox.setText("Ajout avec succes.");

     ui->afficher_produit->setModel(tmpproduit.afficher_produit());
     update_produit();
}
else
    msgBox.setText("Echec d'ajout");
msgBox.exec();}

}


void produitalimentaire::on_afficher_produit_activated(const QModelIndex &index)
{


    QString val=ui->afficher_produit->model()->data(index).toString();
          QSqlQuery qry;
          qry.prepare("select * from produit where"
                      " id_produit='"+val+"' or fournisseur='"+val+"' or nom='"+val+"' or prix='"+val+"' ");
          if(qry.exec())
            {while (qry.next())
           { ui->lineEdit_idp_2->setText(qry.value(0).toString());
             ui->lineEdit_fournisseur_2->setText(qry.value(1).toString());
             ui->lineEdit_nomp_2->setText(qry.value(2).toString());
             ui->lineEdit_prix_2->setText(qry.value(3).toString());

              }
        }


}

void produitalimentaire::on_supprimerp_clicked()
{

    bool test=tmpproduit.supprimer_produit(id_prod);
       if(test){
            ui->afficher_produit->setModel(tmpproduit.afficher_produit());

           QMessageBox::information(nullptr,"suppression produit","produit supprimer avec succés");
           update_produit();

       }
       else
               QMessageBox::warning(nullptr,"Error","produit non supprimer");
}


void produitalimentaire::on_modifierp_clicked()
{
    int identifiant=ui->lineEdit_idp_2->text().toInt();
         int fournisseur=ui->lineEdit_fournisseur_2->text().toInt();
         QString nom=ui->lineEdit_nomp_2->text();
          int prix=ui->lineEdit_prix_2->text().toInt();


     produit P1(identifiant,fournisseur,nom,prix);
     bool test=P1.modifier_produit();
     QMessageBox msgBox;

     if(test)
        { msgBox.setText(" Modification avec succes.");

          ui->afficher_produit->setModel(tmpproduit.afficher_produit());
          update_produit();
     }
     else
         msgBox.setText("Echec de modifier");
     msgBox.exec();
}


void produitalimentaire::on_trierp_clicked()
{
    ui->afficher_produit->setModel((tmpproduit.AfficherTrieprix()));

}
void produitalimentaire::on_trierp_nom_clicked()
{
    ui->afficher_produit->setModel((tmpproduit.AfficherTrieNom()));

}


void produitalimentaire::on_afficher_produit_clicked(const QModelIndex &index)
{
    id_prod=ui->afficher_produit->model()->data(index).toInt();

}
void produitalimentaire::on_lineEdit_rechercherp_textChanged(const QString &arg1)
{
    ui->afficher_produit->setModel(tmpproduit.rechercherNom(arg1));

}

/*void produitalimentaire::update_commande()
{



        QSqlQueryModel *m=new QSqlQueryModel();
            QSqlQuery *querry=new QSqlQuery();
            querry->prepare("SELECT id_commande FROM commande");
            querry->exec();
            m->setQuery(*querry);


            ui->afficher_commande->setModel(m);

}*/

void produitalimentaire::on_ajout_commande_clicked()
{
    int id_commande=ui->lineEdit_idc->text().toInt();
         int id_fournisseur=ui->fournisseur->currentText().toInt();
         int id_produit=ui->produit->currentText().toInt();
          int montant=ui->lineEdit_montant->text().toInt();
          QString adresse=ui->lineEdit_adresseC->text();



         if(id_commande==0)
            QMessageBox::warning(this,"ERROR","Veillez remplir id de la commande");
       else if(id_fournisseur==0)
             QMessageBox::warning(this,"ERROR","Veillez remplir id du fournisseur");
        else if (id_produit==0)
             QMessageBox::warning(this,"ERROR","Veillez remplir id du produit");

         else if(montant==0)
             QMessageBox::warning(this,"ERROR","Veillez remplir le montant");
         else if(adresse=="")
             QMessageBox::warning(this,"ERROR","Veillez remplir l adresse");

         else {
             commande C1(id_commande,id_fournisseur,id_produit,montant,adresse);

     bool test=C1.ajouter_commande();
     QMessageBox msgBox;

     if(test)
        { msgBox.setText("Ajout avec succes.");

          ui->afficher_commande->setModel(tmpcommande.afficher_commande());
         // update();
     }
     else
         msgBox.setText("Echec d'ajout");
     msgBox.exec();}

}
void produitalimentaire::on_afficher_commande_activated(const QModelIndex &index)
{
    QString val=ui->afficher_commande->model()->data(index).toString();
          QSqlQuery qry;
          qry.prepare("select * from commande where"
                      " id_commande='"+val+"' or id_fournisseur='"+val+"' or id_produit='"+val+"' or montant='"+val+"' or adresse='"+val+"' ");
          if(qry.exec())
            {while (qry.next())
           { ui->lineEdit_idc_2->setText(qry.value(0).toString());
             ui->lineEdit_fournisseur_3->setText(qry.value(1).toString());
             ui->lineEdit_produit_2->setText(qry.value(2).toString());
             ui->lineEdit_montant_2->setText(qry.value(3).toString());
             ui->lineEdit_adressec_2->setText(qry.value(4).toString());

              }
        }

}

void produitalimentaire::on_modif_commande_clicked()
{
    int identifiant=ui->lineEdit_idc_2->text().toInt();
         int id_fournisseur=ui->lineEdit_fournisseur_3->text().toInt();
         int id_produit=ui->lineEdit_produit_2->text().toInt();
         int montant=ui->lineEdit_montant_2->text().toInt();
         QString adresse=ui->lineEdit_adressec_2->text();



     commande C1(identifiant,id_fournisseur,id_produit,montant,adresse);
     bool test=C1.modifier_commande();
     QMessageBox msgBox;

     if(test)
        { msgBox.setText(" Modification avec succes.");

          ui->afficher_commande->setModel(tmpcommande.afficher_commande());
     }
     else
         msgBox.setText("Echec de modifier");
     msgBox.exec();
}

void produitalimentaire::on_supp_commande_clicked()
{
    bool test=tmpcommande.supprimer_commande(id_com);
       if(test){
            ui->afficher_commande->setModel(tmpcommande.afficher_commande());
           QMessageBox::information(nullptr,"suppression commande","commande supprimer avec succés");
       }
       else
               QMessageBox::warning(nullptr,"Error","commande non supprimer");
}
void produitalimentaire::on_afficher_commande_clicked(const QModelIndex &index)
{
    id_com=ui->afficher_commande->model()->data(index).toInt();


}
void produitalimentaire::on_trier_commande_clicked()
{
    ui->afficher_commande->setModel((tmpcommande.AfficherTrieMontant()));


}

void produitalimentaire::on_trier_adresseC_clicked()
{
    ui->afficher_commande->setModel((tmpcommande.AfficherTrieAdresse()));

}

/*int produitalimentaire::creerPdf()
{    commande c;

   QPrinter printer;
   printer.setOutputFormat(QPrinter::PdfFormat);
   printer.setOutputFileName("test123.pdf");
   QPainter painter;
   if(!painter.begin(&printer)){
      qWarning ("failed to opent file , is it writable?");
       return 1;
   }

   painter.setPen(Qt::blue);
   painter.drawText(100,10,"****COMMANDE POUR LA FAMILLE BOUAYED*****");
   painter.drawText(10,50,"id de la commande");


   //painter.draw
   if (!printer.newPage()){
       qWarning("failed");
       return 1;
   }
//painter.drawText(10,10,"test2");
painter.end();


}*/
void produitalimentaire::on_impdos_2_clicked()
{
    commande c;
QString id=ui->lineEdit_idc_2->text();
qDebug () << id;
                QString text=c.apercu_pdf(id);
                ui->imp->setText(text);

                QPrinter printer ;
                printer.setPrinterName("imprim");
                QPrintDialog dialog (&printer,this);
                if(dialog.exec()==QDialog::Rejected) return ;
                ui->imp->print(&printer);
}




void produitalimentaire::on_excel_clicked()
{
    commande E;
        QSqlQueryModel * model=new QSqlQueryModel();
        model=E.Find_commande();
        QString textData= "id_commande ; id_fournisseur; id_produit ; montant ;adresse \n";
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

void produitalimentaire::on_test_clicked()
{ //int s=0;
   // s=ui->lineEdit_montant_2->text().toInt();


    QString strStream;
    QTextStream out(&strStream);




                    const int rowCount = ui->afficher_commande->model()->rowCount();
                    const int columnCount = ui->afficher_commande->model()->columnCount();
                    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                    out <<"<html>\n"
                          "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        << "<title>Activites LIST<title>\n "
                        << "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"
                        "<h1 style=\"text-align: center;\"><strong> **LISTE DES COMMANDES ** "+TT+"</strong></h1>"
                        "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                          "</br> </br>";
                    // headers
                    out << "<thead><tr bgcolor=#d6e5ff>";
                    for (int column = 0; column < columnCount; column++)

                        if (!ui->afficher_commande->isColumnHidden(column))

                            out << QString("<th>%1</th>").arg(ui->afficher_commande->model()->headerData(column, Qt::Horizontal).toString());

                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->afficher_commande->isColumnHidden(column)) {
                                 //qDebug () << s;

                                QString data =ui->afficher_commande->model()->data(ui->afficher_commande->model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table>\n"
                            //"<h2 style=\"text-align: center;\"><strong> la somme est  "+TT+"</strong></h1>"
                            "<?php echo  $s ?>"


                        "</body>\n"
                        "</html>\n";

                    QTextDocument *document = new QTextDocument();
                    document->setHtml(strStream);

                    QPrinter printer;

                    QPrintDialog *test = new QPrintDialog(&printer, NULL);
                    if (test->exec() == QDialog::Accepted) {
                        document->print(&printer);
                    }

                    delete document;
}


void produitalimentaire::on_QRcode_clicked()
{

    int tabprod=ui->afficher_produit->currentIndex().row();
    QVariant idd=ui->afficher_produit->model()->data(ui->afficher_produit->model()->index(tabprod,0));
    int id= idd.toInt();
    QSqlQuery qry;
    qry.prepare("select * from produit where id_produit=:id");
    qry.bindValue(":id_produit",id);
    qry.exec();
    QString fournisseur , nom, prix,ids;

    while(qry.next()){
        ids=qry.value(0).toString();
        fournisseur=qry.value(1).toString();
        nom=qry.value(2).toString();
        prix=qry.value(3).toString();
    }
    ids=QString::number(id);
    ids="ID: '"+ids+"' fournisseur: '"+fournisseur+"' nom: '"+nom+"' Prix: '"+prix+"'";
    QrCode qr = QrCode::encodeText(ids.toUtf8().constData(), QrCode::Ecc::HIGH);


    QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);

    for (int y = 0; y < qr.getSize(); y++) {
        for (int x = 0; x < qr.getSize(); x++) {
            int color = qr.getModule(x, y);  // 0 for white, 1 for black

            // You need to modify this part
            if(color==0)
                im.setPixel(x, y,qRgb(254, 254, 254));
            else
                im.setPixel(x, y,qRgb(0, 0, 0));
        }
    }
    im=im.scaled(200,200);
    ui->qrlabel->setPixmap(QPixmap::fromImage(im));

}

void produitalimentaire::on_im_clicked()
{//int s=0;
    // s=ui->lineEdit_montant_2->text().toInt();


     QString strStream;
     QTextStream out(&strStream);




                     const int rowCount = ui->afficher_produit->model()->rowCount();
                     const int columnCount = ui->afficher_produit->model()->columnCount();
                     QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                     out <<"<html>\n"
                           "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         << "<title>Activites LIST<title>\n "
                         << "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                         "<h1 style=\"text-align: center;\"><strong> **LISTE DES PRODUITS ** "+TT+"</strong></h1>"
                         "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                           "</br> </br>";
                     // headers
                     out << "<thead><tr bgcolor=#d6e5ff>";
                     for (int column = 0; column < columnCount; column++)

                         if (!ui->afficher_produit->isColumnHidden(column))

                             out << QString("<th>%1</th>").arg(ui->afficher_produit->model()->headerData(column, Qt::Horizontal).toString());

                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->afficher_produit->isColumnHidden(column)) {
                                  //qDebug () << s;

                                 QString data =ui->afficher_produit->model()->data(ui->afficher_produit->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"



                         "</body>\n"
                         "</html>\n";

                     QTextDocument *document = new QTextDocument();
                     document->setHtml(strStream);

                     QPrinter printer;

                     QPrintDialog *test = new QPrintDialog(&printer, NULL);
                     if (test->exec() == QDialog::Accepted) {
                         document->print(&printer);
                     }

                     delete document;

}
