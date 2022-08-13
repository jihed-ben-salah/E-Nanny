#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabactivite->setModel(tmpactivite.afficher());
    ui->tabrdv->setModel(tmprendezvous.afficher());


    update();
    update_rdv();



}

MainWindow::~MainWindow()
{
    delete ui;

}


/*void MainWindow::on_tabWidget_currentChanged(int index)
{
   { ui->tabactivite->setModel(tmpactivite.afficher());
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT ID FROM ACTIVITEloi");
    ui->idsup->setModel(model);
    ui->idmodifier->setModel(model);

    }

}*/


void MainWindow::update()
{



        QSqlQueryModel *m=new QSqlQueryModel();
            QSqlQuery *querry=new QSqlQuery();
            querry->prepare("SELECT ID FROM ACTIVITEloi");
            querry->exec();
            m->setQuery(*querry);

            ui->comboBox->setModel(m);


}
void MainWindow::update_rdv()
{



        QSqlQueryModel *m=new QSqlQueryModel();
            QSqlQuery *querry=new QSqlQuery();
            querry->prepare("SELECT ID FROM RENDEZVOUS");
            querry->exec();
            m->setQuery(*querry);




}



void MainWindow::on_tabactivite_activated(const QModelIndex &index)
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


void MainWindow::on_tabactivite_clicked(const QModelIndex &index)
{
     id_activite=ui->tabactivite->model()->data(index).toInt();
}


void MainWindow::on_ajout_clicked()
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
        }
        else
                QMessageBox::warning(nullptr,"Error","activite non ajouté");}
        else
                QMessageBox::warning(nullptr,"Error","Vérifier les champs !");
}
void MainWindow::on_sup_clicked()
{

    bool test=tmpactivite.supprimer(id_activite);
    if(test){
        ui->tabactivite->setModel(tmpactivite.afficher());
        QMessageBox::information(nullptr,"suppression activite","activite supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","activite non supprimer");

}

void MainWindow::on_modifier_clicked()
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
    }
    else
            QMessageBox::warning(nullptr,"Error","activite non modifie");

    }


void MainWindow::on_Ajout_rdv_clicked()
{
    int id_rdv=ui->id_rdv_ajout->text().toInt();
    int id_activite2=ui->id_activite_ajout->text().toInt();
    QString nom=ui->nom_rdv_ajout->text();
    QString prenom=ui->prenom_rdv_ajout->text();
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
        update_rdv();
        QMessageBox::information(nullptr,"Ajout rendezvous","Rendezvous ajouté avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","Rendezvous non ajouté");}
    else
            QMessageBox::warning(nullptr,"Error","Vérifier les champs !");
}

void MainWindow::on_Supprimer_rdv_clicked()
{
    bool test=tmprendezvous.supprimer(id_rdvs);
    if(test){
        ui->tabrdv->setModel(tmprendezvous.afficher());
        update_rdv();
        QMessageBox::information(nullptr,"suppression Rendezvous","Rendezvous supprimer avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","Rendezvous non supprimer");
}

void MainWindow::on_Modifier_rdv_clicked()
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
    }
    else
            QMessageBox::warning(nullptr,"Error","Rendezvous non modifier");

}







void MainWindow::on_recherche_activite_textChanged(const QString &arg1)
{
        activiteloi e;
        ui->tabactivite->setModel(e.recherche_activite(ui->recherche_activite->text()));
}






void MainWindow::on_tabrdv_activated(const QModelIndex &index)
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

void MainWindow::on_tabrdv_clicked(const QModelIndex &index)
{
    id_rdvs=ui->tabrdv->model()->data(index).toInt();

}

void MainWindow::on_tri_rdv_clicked()
{
    ui->tabrdv->setModel(tmprendezvous.tri_rdv());

}

void MainWindow::on_Recherche_rdv_textChanged(const QString &arg1)
{
    RendezVous e;
    ui->tabrdv->setModel(e.rechercherdv(ui->Recherche_rdv->text()));}






void MainWindow::on_Excel_clicked()
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

void MainWindow::on_imprimer_clicked()
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


void MainWindow::on_slidervolume_sliderMoved(int position)
{
    player->setVolume(position);
}

void MainWindow::on_pushButton_4_clicked()
{
    player= new QMediaPlayer;
    player->setMedia(QUrl("C:/Users/user/Downloads/activite.mp3"));
       player->play();
       qDebug()<<player->errorString();
}

void MainWindow::on_pushButton_5_clicked()
{
    player->stop();
}

/*void MainWindow::on_id_act_comboBox_currentIndexChanged(const QString &arg1)
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

void MainWindow::on_tri_id_activite_clicked()
{
    ui->tabactivite->setModel(tmpactivite.tri_activite_id());

}

void MainWindow::on_tri_activite_nom_clicked()
{
    ui->tabactivite->setModel(tmpactivite.tri_activite_nom());
}



void MainWindow::on_tri_rdv_id_clicked()
{
     ui->tabrdv->setModel(tmprendezvous.tri_id_rdv());
}

void MainWindow::on_Tri_nom_rdv_clicked()
{
    ui->tabrdv->setModel(tmprendezvous.tri_nom_rdv());

}



void MainWindow::on_actionNew_triggered()
{
    // Global referencing the current file that we are clearing
        currentFile.clear();

        // Clear the textEdit widget buffer
        ui->textEdit->setText(QString());
}



void MainWindow::on_actionOpen_triggered()
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

void MainWindow::on_actionSave_as_triggered()
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


void MainWindow::on_actionSave_triggered()
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

void MainWindow::on_actionPrint_triggered()
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

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

bool MainWindow::controleNumTel(int test)
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


bool MainWindow::controleVide(QString test)
{
    if(test!="")
        return  true;
    return false;

}

bool MainWindow::controleVideInt(int test)
{
    if(test!=0)
        return  true;
    return false;

}

bool MainWindow::controleEmail(QString test)
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

void MainWindow::on_tri_Activite_clicked()
{
  ui->tabactivite->setModel(tmpactivite.tri());
}
