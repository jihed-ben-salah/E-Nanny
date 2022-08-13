#include "activiteloisirs.h"
#include "ui_activiteloisirs.h"
#include "activiteloi.h"
#include "rendezvous.h"
#include <qmessagebox.h>
#include <QIntValidator>
#include <QSqlQuery>
#include <QScrollBar>
#include <qfiledialog.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QComboBox>
activiteloisirs::activiteloisirs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::activiteloisirs)
{
    ui->setupUi(this);
    ui->tabactivite->setModel(tmpactivite.afficher());
    ui->tabrdv->setModel(tmprendezvous.afficher());


    update();
    update_rdv();
    update_nom();
}

activiteloisirs::~activiteloisirs()
{
    delete ui;
}

/*void activiteloisirs::on_tabWidget_currentChanged(int index)
{
   { ui->tabactivite->setModel(tmpactivite.afficher());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID FROM ACTIVITEloi");
    ui->idsup->setModel(model);
    ui->idmodifier->setModel(model);

    }

}*/


void activiteloisirs::update()
{



        QSqlQueryModel *m=new QSqlQueryModel();
            QSqlQuery *querry=new QSqlQuery();
            querry->prepare("SELECT ID FROM ACTIVITEloi ");
            querry->exec();
            m->setQuery(*querry);

            QSqlQueryModel *m1=new QSqlQueryModel();
                QSqlQuery *querry1=new QSqlQuery();
                querry1->prepare("SELECT identifiant FROM personne");
                querry1->exec();
               m1->setQuery(*querry1);

            ui->comboBox->setModel(m);
           // ui->comboBox->setModel(m1);

}
void activiteloisirs::update_nom()
{



        QSqlQueryModel *m=new QSqlQueryModel();
            QSqlQuery *querry=new QSqlQuery();
            querry->prepare("SELECT prenom FROM ACTIVITEloi ");
            querry->exec();
            m->setQuery(*querry);

            QSqlQueryModel *m1=new QSqlQueryModel();
                QSqlQuery *querry1=new QSqlQuery();
                querry1->prepare("SELECT prenom FROM personne");
                querry1->exec();
               m1->setQuery(*querry1);

            ui->comboBox_2->setModel(m);
           //ui->comboBox_2->setModel(m1);

}
void activiteloisirs::update_rdv()
{



        QSqlQueryModel *m=new QSqlQueryModel();
            QSqlQuery *querry=new QSqlQuery();
            querry->prepare("SELECT ID FROM RENDEZVOUS");
            querry->exec();
            m->setQuery(*querry);




}



void activiteloisirs::on_tabactivite_activated(const QModelIndex &index)
{
    QString val=ui->tabactivite->model()->data(index).toString();
              QSqlQuery qry;
              qry.prepare("select * from ACTIVITEloi where" " id='"+val+"' or nom='"+val+"' or prenom='"+val+"'or adresse='"+val+"' or prix='"+val+"' or telephone ='"+val+"' ");
              if(qry.exec())
                {while (qry.next())
               { ui->idmodifier->setText(qry.value(0).toString());
                 ui->nommodifier->setText(qry.value(1).toString());
                 ui->prenommodifier->setText(qry.value(2).toString());
                 ui->adressemodifier->setText(qry.value(3).toString());
                 ui->prixmodifier->setText(qry.value(4).toString());
                 ui->telmodifier->setText(qry.value(5).toString());
                  }
            }
}


void activiteloisirs::on_tabactivite_clicked(const QModelIndex &index)
{
     id_activite=ui->tabactivite->model()->data(index).toInt();
}


void activiteloisirs::on_ajout_clicked()
{
        int id=ui->idajout->text().toInt();
        QString nom=ui->nomajout->text();
        QString prenom=ui->prenomajout->text();
        QString adresse=ui->adresseajout->text();
        int prix=ui->prixajout->text().toInt();
        int telephone=ui->telephoneajout->text().toInt();

        activiteloi tmpactivite(id,nom,prenom,adresse,prix,telephone);
        bool test2;
                test2=(controleNumTel(telephone)&&controleVide(nom)&&controleVide(prenom)&&controleVide(adresse)&&controleVideInt(prix)&&controleVideInt(id) );
        if (test2){
        bool test=tmpactivite.ajouter();
        if(test){
            ui->tabactivite->setModel(tmpactivite.afficher());
            QMessageBox::information(nullptr,"Ajout activite","activite ajouté avec succés");
            update();
            update_rdv();
            update_nom();
        }
        else
                QMessageBox::warning(nullptr,"Error","activite non ajouté");}
        else
                QMessageBox::warning(nullptr,"Error","Vérifier les champs !");
}
void activiteloisirs::on_sup_clicked()
{

    bool test=tmpactivite.supprimer(id_activite);
    if(test){
        ui->tabactivite->setModel(tmpactivite.afficher());
        QMessageBox::information(nullptr,"suppression activite","activite supprimer avec succés");
        update();
        update_rdv();
        update_nom();
    }
    else
            QMessageBox::warning(nullptr,"Error","activite non supprimer");

}

void activiteloisirs::on_modifier_clicked()
{
    int id=ui->idmodifier->text().toInt();
    QString nom=ui->nommodifier->text();
    QString prenom=ui->prenommodifier->text();
    QString adresse=ui->adressemodifier->text();
    int prix=ui->prixmodifier->text().toInt();
    int telephone=ui->telmodifier->text().toInt();
    activiteloi tmpactivite(id,nom,prenom,adresse,prix,telephone);
    bool test=tmpactivite.modifier(id);
    if(test){
        ui->tabactivite->setModel(tmpactivite.afficher());

        QMessageBox::information(nullptr,"modification activite","activite modifie avec succés");
        update();
        update_rdv();
        update_nom();
    }
    else
            QMessageBox::warning(nullptr,"Error","activite non modifie");

    }


void activiteloisirs::on_Ajout_rdv_clicked()
{
    int id_rdv=ui->id_rdv_ajout->text().toInt();
    int id_activite2=ui->id_activite_ajout->text().toInt();
    QString nom=ui->nom_rdv_ajout->text();
    QString prenom=ui->comboBox_2->currentText();
    QString email=ui->email_rdv_ajout->text();
    QString pro_rdv=ui->pro_rdv_ajout->text();
    QString heure=ui->heure_rdv_ajout->text();
    QString date_rdv=ui->date_rdv_ajout->text();
    int telephone_rdv=ui->tel_rdv_ajout->text().toInt();

    RendezVous tmprendezvous(id_rdv,id_activite2,nom,prenom,email,pro_rdv,heure,date_rdv,telephone_rdv);
    bool test2;
            test2=(controleEmail(email)&& controleNumTel(telephone_rdv)&&controleVide(nom)&&controleVide(prenom)&&controleVide(pro_rdv)&&controleVideInt(id_rdv) );
    if (test2){
    bool test=tmprendezvous.ajouter();
    if(test){
        ui->tabrdv->setModel(tmprendezvous.afficher());
        update();
        update_rdv();
        update_nom();
        QMessageBox::information(nullptr,"Ajout rendezvous","Rendezvous ajouté avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","Rendezvous non ajouté");}
    else
            QMessageBox::warning(nullptr,"Error","Vérifier les champs !");
}

void activiteloisirs::on_Supprimer_rdv_clicked()
{
    bool test=tmprendezvous.supprimer(id_rdvs);
    if(test){
        ui->tabrdv->setModel(tmprendezvous.afficher());
        update();
        update_rdv();
        update_nom();
        QMessageBox::information(nullptr,"suppression Rendezvous","Rendezvous supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","Rendezvous non supprimer");
}

void activiteloisirs::on_Modifier_rdv_clicked()
{
    int id_rdv=ui->id_rdv_modifier->text().toInt();
    int id_activite2=ui->id_activite_modifier->text().toInt();
    QString nom=ui->nom_rdv_modifier->text();
    QString prenom=ui->prenom_rdv_modifier->text();
    QString email=ui->email_rdv_modifier->text();
    QString pro_rdv=ui->pro_rdv_modifier->text();
    QString heure=ui->heure_rdv_modifier->text();
    QString date_rdv=ui->date_rdv_modifier->text();
    int telephone_rdv=ui->tel_rdv_modifier->text().toInt();
    RendezVous tmprendezvous(id_rdv,id_activite2,nom,prenom,email,pro_rdv,heure,date_rdv,telephone_rdv);
    bool test=tmprendezvous.modifier(id_rdv);
    if(test){
        ui->tabrdv->setModel(tmprendezvous.afficher());

        QMessageBox::information(nullptr,"modification Rendezvous","Rendezvous modifie avec succés");
        update();
        update_rdv();
        update_nom();
    }
    else
            QMessageBox::warning(nullptr,"Error","Rendezvous non modifier");

}







void activiteloisirs::on_recherche_activite_textChanged(const QString &arg1)
{
        activiteloi e;
        ui->tabactivite->setModel(e.recherche_activite(ui->recherche_activite->text()));
}






void activiteloisirs::on_tabrdv_activated(const QModelIndex &index)
{
    QString val=ui->tabrdv->model()->data(index).toString();
              QSqlQuery qry;
              qry.prepare("select * from RENDEZVOUS where " " id_rdv='"+val+"' or id_activite2='"+val+"' or nom='"+val+"' or prenom='"+val+"'or email='"+val+"' or pro_rdv='"+val+"' or heure='"+val+"' or date_rdv='"+val+"' or telephone_rdv ='"+val+"' ");
              if(qry.exec())
                {while (qry.next())
               { ui->id_rdv_modifier->setText(qry.value(0).toString());
                 ui->id_activite_modifier->setText(qry.value(1).toString());
                 ui->nom_rdv_modifier->setText(qry.value(2).toString());
                 ui->prenom_rdv_modifier->setText(qry.value(3).toString());
                 ui->email_rdv_modifier->setText(qry.value(4).toString());
                 ui->pro_rdv_modifier->setText(qry.value(5).toString());
                 ui->heure_rdv_modifier->setText(qry.value(6).toString());
                 ui->date_rdv_modifier->setText(qry.value(7).toString());
                 ui->tel_rdv_modifier->setText(qry.value(8).toString());
                  }
            }
}

void activiteloisirs::on_tabrdv_clicked(const QModelIndex &index)
{
    id_rdvs=ui->tabrdv->model()->data(index).toInt();

}

void activiteloisirs::on_tri_rdv_clicked()
{
    ui->tabrdv->setModel(tmprendezvous.tri_rdv());

}

void activiteloisirs::on_Recherche_rdv_textChanged(const QString &arg1)
{
    RendezVous e;
    ui->tabrdv->setModel(e.rechercherdv(ui->Recherche_rdv->text()));}






void activiteloisirs::on_Excel_clicked()
{
    activiteloi E;
           QSqlQueryModel * model=new QSqlQueryModel();
           model=E.Find_Activite();
           QString textData= "id ; nom ; prenom ; adresse ; telephone \n";
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

void activiteloisirs::on_imprimer_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tabactivite->model()->rowCount();
                const int columnCount = ui->tabactivite->model()->columnCount();
                QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                out <<"<html>\n"
                      "<head>\n"
                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    << "<title>Activites LIST<title>\n "
                    << "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"
                    "<h1 style=\"text-align: center;\"><strong> ***LISTE DES Activites *** "+TT+"</strong></h1>"
                    "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                      "</br> </br>";
                // headers
                out << "<thead><tr bgcolor=#d6e5ff>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tabactivite->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tabactivite->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++) {
                    out << "<tr>";
                    for (int column = 0; column < columnCount; column++) {
                        if (!ui->tabactivite->isColumnHidden(column)) {
                            QString data =ui->tabactivite->model()->data(ui->tabactivite->model()->index(row, column)).toString().simplified();
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

QMediaPlayer *player;


void activiteloisirs::on_slidervolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void activiteloisirs::on_pushButton_4_clicked()
{
    player= new QMediaPlayer;
    player->setMedia(QUrl("./music.wav"));
       player->play();
       qDebug()<<player->errorString();
}

void activiteloisirs::on_pushButton_5_clicked()
{
    player->stop();
}

/*void activiteloisirs::on_id_act_comboBox_currentIndexChanged(const QString &arg1)
{
    QString id_activite2=ui->id_act_comboBox->currentText();
              QSqlQuery qry;
              qry.prepare("select * from rendezvous where id_activite2='"+id_activite2+"' ");
              if(qry.exec())
                {while (qry.next())
               {
                 ui->id_activite_modifier->setText(qry.value(1).toString());
                 ui->nom_rdv_modifier->setText(qry.value(2).toString());
                 ui->prenom_rdv_modifier->setText(qry.value(3).toString());
                 ui->email_rdv_modifier->setText(qry.value(4).toString());
                 ui->pro_rdv_modifier->setText(qry.value(5).toString());
                 ui->heure_rdv_modifier->setText(qry.value(6).toString());
                 ui->date_rdv_modifier->setText(qry.value(7).toString());
                 ui->tel_rdv_modifier->setText(qry.value(8).toString());
                  }
            }
}*/

void activiteloisirs::on_tri_id_activite_clicked()
{
    ui->tabactivite->setModel(tmpactivite.tri_activite_id());

}

void activiteloisirs::on_tri_activite_nom_clicked()
{
    ui->tabactivite->setModel(tmpactivite.tri_activite_nom());
}



void activiteloisirs::on_tri_rdv_id_clicked()
{
     ui->tabrdv->setModel(tmprendezvous.tri_id_rdv());
}

void activiteloisirs::on_Tri_nom_rdv_clicked()
{
    ui->tabrdv->setModel(tmprendezvous.tri_nom_rdv());

}



void activiteloisirs::on_actionNew_triggered()
{
    // Global referencing the current file that we are clearing
        currentFile.clear();

        // Clear the textEdit widget buffer
        ui->textEdit->setText(QString());
}



void activiteloisirs::on_actionOpen_triggered()
{
    // Opens a dialog that allows you to select a file to open
       QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

       // An object for reading and writing files
       QFile file(fileName);

       // Store the currentFile name
       currentFile = fileName;

       // Try to open the file as a read only file if possible or display a
       // warning dialog box
       if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
           QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
           return;
       }

          // Set the title for the window to the file name
          setWindowTitle(fileName);

          // Interface for reading text
          QTextStream in(&file);

          // Copy text in the string
          QString text = in.readAll();

          // Put the text in the textEdit widget
          ui->textEdit->setText(text);

          // Close the file
          file.close();
}

void activiteloisirs::on_actionSave_as_triggered()
{
    // Opens a dialog for saving a file
       QString fileName = QFileDialog::getSaveFileName(this, "Save as");

       // An object for reading and writing files
       QFile file(fileName);

       // Try to open a file with write only options
       if (!file.open(QFile::WriteOnly | QFile::Text)) {
           QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
           return;
       }

       // Store the currentFile name
       currentFile = fileName;

       // Set the title for the window to the file name
       setWindowTitle(fileName);

       // Interface for writing text
       QTextStream out(&file);

       // Copy text in the textEdit widget and convert to plain text
       QString text = ui->textEdit->toPlainText();

       // Output to file
       out << text;

       // Close the file
       file.close();
}


void activiteloisirs::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save");
       QFile file(fileName);
       if (!file.open(QFile::WriteOnly | QFile::Text)) {
           QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
           return;
       }
       currentFile = fileName;
       setWindowTitle(fileName);
       QTextStream out(&file);
       QString text = ui->textEdit->toPlainText();
       out << text;
       file.close();
}

void activiteloisirs::on_actionPrint_triggered()
{
    // Allows for interacting with printer
        QPrinter printer;

        // You'll put your printer name here
        printer.setPrinterName("Printer Name");

        // Create the print dialog and pass the name and parent
        QPrintDialog pDialog(&printer, this);

        if(pDialog.exec() == QDialog::Rejected){
            QMessageBox::warning(this, "Warning", "Cannot Access Printer");
            return;
        }

        // Send the text to the printer
        ui->textEdit->print(&printer);

}

void activiteloisirs::on_actionExit_triggered()
{
    QApplication::quit();
}

void activiteloisirs::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void activiteloisirs::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void activiteloisirs::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void activiteloisirs::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void activiteloisirs::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

bool activiteloisirs::controleNumTel(int test)
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


bool activiteloisirs::controleVide(QString test)
{
    if(test!="")
        return  true;
    return false;

}

bool activiteloisirs::controleVideInt(int test)
{
    if(test!=0)
        return  true;
    return false;

}

bool activiteloisirs::controleEmail(QString test)
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

void activiteloisirs::on_tri_Activite_clicked()
{
  ui->tabactivite->setModel(tmpactivite.tri());
}

void activiteloisirs::on_pushButton_2_clicked()
{
    // Global referencing the current file that we are clearing
            currentFile.clear();

            // Clear the textEdit widget buffer
            ui->textEdit->setText(QString());
}
void activiteloisirs::on_save_as_clicked()
{
    // Opens a dialog for saving a file
       QString fileName = QFileDialog::getSaveFileName(this, "Save as");

       // An object for reading and writing files
       QFile file(fileName);

       // Try to open a file with write only options
       if (!file.open(QFile::WriteOnly | QFile::Text)) {
           QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
           return;
       }

       // Store the currentFile name
       currentFile = fileName;

       // Set the title for the window to the file name
       setWindowTitle(fileName);

       // Interface for writing text
       QTextStream out(&file);

       // Copy text in the textEdit widget and convert to plain text
       QString text = ui->textEdit->toPlainText();

       // Output to file
       out << text;

       // Close the file
       file.close();
}

void activiteloisirs::on_save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save");
       QFile file(fileName);
       if (!file.open(QFile::WriteOnly | QFile::Text)) {
           QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
           return;
       }
       currentFile = fileName;
       setWindowTitle(fileName);
       QTextStream out(&file);
       QString text = ui->textEdit->toPlainText();
       out << text;
       file.close();
}

void activiteloisirs::on_print_clicked()
{
    // Allows for interacting with printer
        QPrinter printer;

        // You'll put your printer name here
        printer.setPrinterName("Printer Name");

        // Create the print dialog and pass the name and parent
        QPrintDialog pDialog(&printer, this);

        if(pDialog.exec() == QDialog::Rejected){
            QMessageBox::warning(this, "Warning", "Cannot Access Printer");
            return;
        }

        // Send the text to the printer
        ui->textEdit->print(&printer);
}

void activiteloisirs::on_copy_clicked()
{
    ui->textEdit->copy();
}

void activiteloisirs::on_cut_clicked()
{
    ui->textEdit->cut();
}

void activiteloisirs::on_paste_clicked()
{
    ui->textEdit->paste();
}

void activiteloisirs::on_undo_clicked()
{
    ui->textEdit->undo();
}

void activiteloisirs::on_redo_clicked()
{
    ui->textEdit->redo();
}

void activiteloisirs::on_exit_clicked()
{
    QApplication::quit();
}

void activiteloisirs::on_open_clicked()
{
    // Opens a dialog that allows you to select a file to open
           QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

           // An object for reading and writing files
           QFile file(fileName);

           // Store the currentFile name
           currentFile = fileName;

           // Try to open the file as a read only file if possible or display a
           // warning dialog box
           if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
               QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
               return;
           }

              // Set the title for the window to the file name
              setWindowTitle(fileName);

              // Interface for reading text
              QTextStream in(&file);

              // Copy text in the string
              QString text = in.readAll();

              // Put the text in the textEdit widget
              ui->textEdit->setText(text);

              // Close the file
              file.close();

}








