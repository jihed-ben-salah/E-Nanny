#include "devoirs.h"
#include<QtDebug>
#include <QString>
#include<QSqlQuery>
Devoirs::~Devoirs()
{
    //vide
}
Devoirs::Devoirs()
{
    NOMD="";
    REFDEV=0;
    NOMC="";
    DEADLINE="";

}
Devoirs::Devoirs(QString nomD,int RefDev,QString nomC,QString deadline)
{
 this->NOMD = nomD;
 this->REFDEV = RefDev;
 this->NOMC = nomC;
 this->DEADLINE = deadline;
}
bool Devoirs::ajouter()
{
    QSqlQuery query;
          query.prepare("INSERT INTO DEVOIRS (nomD, refDev,nomC ,deadline) "
                        "VALUES (:NOMD, :REFDEV,:NOMC,:DEADLINE)");
          query.bindValue(":NOMD",NOMD);
          query.bindValue(":REFDEV",REFDEV);
          query.bindValue(":NOMC",NOMC);
          query.bindValue(":DEADLINE",DEADLINE);
         return query.exec();
}
QSqlQueryModel* Devoirs::afficher()
{
    QSqlQueryModel* model =new QSqlQueryModel();

   model->setQuery("SELECT* FROM DEVOIRS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom de Devoir"));//ajouter un nouveau nom au  header de tableau
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom de Cours"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Deadline"));
   return model;
}
QSqlQueryModel* Devoirs::afficher_contact()
{
    QSqlQueryModel* model =new QSqlQueryModel();

   model->setQuery("SELECT NOMC,NOME,EMAIL FROM COURS");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Matiére"));//ajouter un nouveau nom au  header de tableau
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Enseignant"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("EMAIL"));
   return model;
}
bool Devoirs::supprimer(QString NOMD)
{
    QSqlQuery query;
    QString res = NOMD;
    query.prepare("DELETE FROM DEVOIRS WHERE NOMD = :NOMD");
    query.bindValue(":NOMD",res);
    return query.exec();

}
QSqlQueryModel * Devoirs::trier_id()
{
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from DEVOIRS ORDER BY REFDEV");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom de Devoir"));//ajouter un nouveau nom au  header de tableau
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom de Cours"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Deadline"));
        return model ;
}
QSqlQueryModel * Devoirs::trier_nom()
{
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery("SELECT * from DEVOIRS ORDER BY NOMD");
        model->setHeaderData(0,Qt::Horizontal,"Nom De Devoir");
        model->setHeaderData(1,Qt::Horizontal,"Numero ");
        model->setHeaderData(2,Qt::Horizontal,"Nom De Cours");
        model->setHeaderData(3,Qt::Horizontal,"deadline");
        return model ;
}
bool Devoirs::modifier()
{
    QSqlQuery query;
    QString res=QString::number(REFDEV);
    query.prepare("UPDATE DEVOIRS SET NOMD=:NOMD,NOMC=:NOMC ,DEADLINE=:DEADLINE WHERE REFDEV=:REFDEV");
    query.bindValue(":NOMD",NOMD);
    query.bindValue(":REFDEV",REFDEV);
    query.bindValue(":NOMC",NOMC);
    query.bindValue(":DEADLINE",DEADLINE);

    return query.exec();
}
QSqlQueryModel* Devoirs::chercher(QString NOMD)
{
   QSqlQueryModel* model =new QSqlQueryModel();
   model->setQuery("SELECT * FROM DEVOIRS WHERE NOMD='"+NOMD+"'"   );
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom de Devoirs"));//ajouter un nouveau nom au  header de tableau
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom de Cours"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Deadline"));
   return model;
}
