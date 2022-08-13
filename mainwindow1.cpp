#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include <QSqlQuery>
#include <qfiledialog.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>
mainwindow1::mainwindow1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindow1)
{
    ui->setupUi(this);
    ui->afficher_personne->setModel(P.afficher());
    ui->afficher_rec->setModel(R.afficher_reclamtion());
    update_personne_list();
    update_mail_list();
sound=new QSound("./music.wav");
sound1=new QSound("./M.wav");
 QObject::connect(ui->filebtn, SIGNAL(clicked()), this, SLOT(file()));
ui->comboBo_4->addItem("medecin");
ui->comboBo_4->addItem("babysitters");
ui->comboBo_4->addItem("infirmiere");
ui->comboBo_4->addItem("prof dessin");
ui->comboBo_4->addItem("prof sport");
ui->comboBo_4->addItem("prof musique");


}

mainwindow1::~mainwindow1()
{
    delete ui;
}

bool mainwindow1::controleNumTel(int test)
{
    QString tel= QString::number(test);
    for(int i=0;i<tel.length();i++)
    {
        if (tel.length()==8)
        {
            return true;
        }
    }
    return false;
}


bool mainwindow1::controleVide(QString test)
{
    if(test!="")
        return  true;
    return false;

}

bool mainwindow1::controleVideInt(int test)
{
    if(test!=0)
        return  true;
    return false;

}

bool mainwindow1::controleEmail(QString test)
{
    for(int i=0;i<test.length();i++)
    {
        if (test.at(i)=='@')
        {
            return true;
        }
    }
    return false;
}

void mainwindow1::on_ajouter_clicked()
{
sound1->play();
    int identifiant=ui->lineEdit_id_a->text().toInt();
    QString nom=ui->lineEdit_nom_a->text();
    QString prenom=ui->lineEdit_pernom_a->text();
    QString adresse=ui->lineEdit_adresse_a->text();
     QString email=ui->lineEdit_email_a->text();
      QString metier=ui->comboBo_4->currentText();
      int prix_heure =ui->lineEdit_prix_heure_a->text().toInt();
      int num_tel =ui->lineEdit_num_tel_a->text().toInt();

      bool test2;
         test2=(controleEmail(email)&& controleNumTel(num_tel)&&controleVide(nom)&&controleVide(prenom)&&controleVide(adresse)&&controleVideInt(prix_heure)&&controleVideInt(identifiant) );

Personned_aides P1(identifiant,nom,prenom,adresse,email,metier,num_tel,prix_heure);

QMessageBox msgBox;
if(test2)
 {
bool test=P1.ajouter();
if(test)
   { msgBox.setText("Ajout avec succes.");
ui->afficher_personne->setModel(P.afficher());
update_personne_list();
update_mail_list();
msgBox.exec();
}
else
   { msgBox.setText("Echec d'ajout");
msgBox.exec();}
}
else

  {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel "),
                                 QObject::tr("personne d'aides non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


  }




}



void mainwindow1::on_modifier_clicked()
{sound1->play();
    int id =ui->lineEdit_id_a_2->text().toInt();
    QString nom=ui->lineEdit_nom_a_2->text();
    QString prenom=ui->lineEdit_pernom_a_2->text();
    QString adresse=ui->lineEdit_adresse_a_2->text();
    QString email=ui->lineEdit_email_a_2->text();
    QString metier=ui->lineEdit_metier_a_2->text();
    int num=ui->lineEdit_num_tel_a_2->text().toInt();
    int prix=ui->lineEdit_prix_heure_a_2->text().toInt();
    Personned_aides P1(id,nom,prenom,adresse,email,metier,num,prix);
    bool test=P1.modifier();
    if (test)
    {
       ui->afficher_personne->setModel(P.afficher());
       update_personne_list();
       update_mail_list();
    QMessageBox::information(nullptr,QObject::tr("Modification Personnes"),
                             QObject::tr("personne modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void mainwindow1::on_supprimer_clicked()
{sound1->play();

    bool test=P.supprimer(id_personne);
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("Suppresion avec succes.");
    ui->afficher_personne->setModel(P.afficher());}
    else
        msgBox.setText("Echec de suppresion");
    msgBox.exec();
    update_personne_list();
    update_mail_list();
}
void mainwindow1::update_mail_list(){
    QSqlQueryModel *m=new QSqlQueryModel();
    QSqlQuery *querry=new QSqlQuery();
    querry->prepare("SELECT email FROM personne");
    querry->exec();
    m->setQuery(*querry);


    ui->comboBo_3->setModel(m);

}
void mainwindow1::update_personne_list(){
    QSqlQueryModel *m=new QSqlQueryModel();
    QSqlQuery *querry=new QSqlQuery();
    querry->prepare("SELECT identifiant FROM personne");
    querry->exec();
    m->setQuery(*querry);


    ui->comboBo_2->setModel(m);

}



void mainwindow1::on_recherche_textChanged(const QString &arg1)
{
     ui->afficher_personne->setModel(P.rechercherNom(arg1));
}

void mainwindow1::on_tri_clicked()
{sound1->play();
    ui->afficher_personne->setModel(P.AfficherTrieNom());

}

void mainwindow1::on_afficher_personne_activated(const QModelIndex &index)
{
    QString val=ui->afficher_personne->model()->data(index).toString();
      QSqlQuery qry;
      qry.prepare("select * from personne where"
                  " identifiant='"+val+"' or nom='"+val+"' or prenom='"+val+"' or adresse='"+val+"' or email ='"+val+"' or metier='"+val+"' or num_tel ='"+val+"' or prix_heure='"+val+"'");
      if(qry.exec())
        {while (qry.next())
       { ui->lineEdit_id_a_2->setText(qry.value(0).toString());
         ui->lineEdit_nom_a_2->setText(qry.value(1).toString());
         ui->lineEdit_pernom_a_2->setText(qry.value(2).toString());
         ui->lineEdit_adresse_a_2->setText(qry.value(3).toString());
         ui->lineEdit_email_a_2->setText(qry.value(4).toString());
         ui->lineEdit_metier_a_2->setText(qry.value(5).toString());
         ui->lineEdit_num_tel_a_2->setText(qry.value(6).toString());
         ui->lineEdit_prix_heure_a_2->setText(qry.value(7).toString());
          }
    }
}

void mainwindow1::on_afficher_personne_clicked(const QModelIndex &index)
{
    id_personne=ui->afficher_personne->model()->data(index).toInt();
}

void mainwindow1::on_envoyer_clicked()
{sound1->play();
    int identifiant=ui->lineedit_ref->text().toInt();
    QString mail_destinataire=ui->comboBo_3->currentText();
    QString sujet=ui->lineedit_sujet->text();
    QString message=ui->lineedit_msg->text();
      int personne_aide =ui->comboBo_2->currentText().toInt();
reclamation R1(identifiant,mail_destinataire,sujet,message,personne_aide);

QMessageBox msgBox;
bool test2;
   test2=(controleVide(sujet)&&controleVide(message)&&controleVide(mail_destinataire)&controleVideInt(personne_aide)&&controleVideInt(identifiant) );
if(test2)
{bool test=R1.ajouter_reclamtion();
if(test)
   {
    msgBox.setText("Ajout de la reclamation avec succes.");
ui->afficher_rec->setModel(R.afficher_reclamtion());
Smtp* smtp = new Smtp("soumaya99.bensassi@gmail.com","Sb50607010", "smtp.gmail.com");


if( !files.isEmpty() )

     smtp->sendMail("soumaya99.bensassi@gmail.com",ui->comboBo_3->currentText(),ui->lineedit_sujet->text(),ui->lineedit_msg->text(),files);
  else
     smtp->sendMail("soumaya99.bensassi@gmail.com",ui->comboBo_3->currentText(),ui->lineedit_sujet->text(),ui->lineedit_msg->text());


ui->comboBo_3->clear();
 ui->lineedit_sujet->clear();
 ui->lineedit_msg->clear();
 ui->file->clear();
  msgBox.exec();
}
else
    msgBox.setText("Echec d'ajout");
    msgBox.exec();
}
else
{


    QMessageBox::information(nullptr, QObject::tr("Ajouter un personnel "),
                               QObject::tr("Reclamation  non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);
}
}

void mainwindow1::on_modifier_rec_clicked()
{sound1->play();
    int id =ui->lineedit_ref_2->text().toInt();
    QString mail=ui->comboBo_3->currentText();
    QString sujet=ui->lineedit_sujet_2->text();
    QString msg=ui->lineedit_msg_2->text();
    int personne=ui->comboBo_2->currentText().toInt();
    reclamation R1(id,mail,sujet,msg,personne);
    bool test=R1.modifier_reclamtion();
    if (test)
    {
       ui->afficher_rec->setModel(R.afficher_reclamtion());
    QMessageBox::information(nullptr,QObject::tr("Modification Reclamation "),
                             QObject::tr("Reclamatin modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void mainwindow1::on_supprimer_rec_clicked()
{sound1->play();
    bool test=R.supprimer_reclamtion(ref_reclamation);
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("Suppresion avec succes.");
    ui->afficher_rec->setModel(R.afficher_reclamtion());}
    else
        msgBox.setText("Echec de suppresion");
    msgBox.exec();
}

void mainwindow1::on_afficher_rec_activated(const QModelIndex &index)
{
    QString val=ui->afficher_rec->model()->data(index).toString();
      QSqlQuery qry;
      qry.prepare("select * from reclamation where"
                  " identifiant='"+val+"' or mail_destinataire='"+val+"' or sujet='"+val+"' or message='"+val+"' or personne_aide ='"+val+"'");
      if(qry.exec())
        {while (qry.next())
       { ui->lineedit_ref_2->setText(qry.value(0).toString());
         ui->lineedit_mail_2->setText(qry.value(1).toString());
         ui->lineedit_sujet_2->setText(qry.value(2).toString());
         ui->lineedit_msg_2->setText(qry.value(3).toString());
         ui->lineedit_personne_2->setText(qry.value(4).toString());

          }
    }
}

void mainwindow1::on_afficher_rec_clicked(const QModelIndex &index)
{
    ref_reclamation=ui->afficher_rec->model()->data(index).toInt();
}

void mainwindow1::on_stop_2_clicked()
{
   sound->play();
}

void mainwindow1::on_stop_clicked()
{
sound->stop();
}

void mainwindow1::file()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );
}

void mainwindow1::on_tabWidget_2_tabBarClicked(int index)
{

    qDeleteAll(ui->tabWidget_2->widget(0)->children());
    QWidget* barstats = new QWidget(this);
    barstats = barchart();
    QGridLayout* layout = new QGridLayout(this);
    layout->addWidget(barstats, 0, 0); // Top-Left
    layout->addWidget(NULL, 0, 1); // Top-Right
    layout->addWidget(NULL, 1, 0); // Bottom-Left
    layout->addWidget(NULL, 1, 1); // Bottom-Right
    ui->tab_4->setLayout(layout);
}



void mainwindow1::on_pdf_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->afficher_rec->model()->rowCount();
                    const int columnCount = ui->afficher_rec->model()->columnCount();
                    QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                    out <<"<html>\n"
                          "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        << "<title>LISTE DES RECLAMATION <title>\n "
                        << "</head>\n"
                        "<body  bgcolor=#ffffff  link=#5000A0  >\n"
                           "<h3 style=\"text-align:left ;\"><strong> E-Nanny </strong></h3>"
                            "<h3 style=\"text-align:right ;\"><strong>  "+TT+"</strong></h3>"
                            "<FONT color=#fade02 face=Times New Roman> <U  color=black><h1 style=\"text-align: center; \"><strong> LISTE DES RECLAMATION  </strong></h1> </U> </FONT>"

                        "<table style=\"text-align: center; font-size: 25px;\" border=1>\n "
                          "</br> </br>";
                    // headers
                    out << "<thead><tr bgcolor=#085394>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->afficher_rec->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->afficher_rec->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->afficher_rec->isColumnHidden(column)) {
                                QString data =ui->afficher_rec->model()->data(ui->afficher_rec->model()->index(row, column)).toString().simplified();
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
void mainwindow1::on_Excel_clicked()
{
     Personned_aides E;
           QSqlQueryModel * model=new QSqlQueryModel();
           model=E.Find_personne_d_aides();
       QString textData= "identifiant ; nom ; prenom ; adresse ; email ; metier ; num_tel ;prix_heure \n";
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
