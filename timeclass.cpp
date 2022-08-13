#include "timeclass.h"


#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

timeclass::timeclass()
{
enfant="";hourstart=0; minutestart=0;hourend=0;minuteend=0;
}

timeclass::timeclass(QString enfant,int hourstart,int minutestart,int hourend,int minuteend)
{
     this->enfant=enfant;
  this->hourstart=hourstart;
    this->minutestart=minutestart;
    this->hourend=hourend;
      this->minuteend=minuteend;

}
int timeclass::gethourstart()
{
    return hourstart;
}
int timeclass::getminutestart()
{
    return minutestart;
}
int timeclass::gethourend()
{
    return hourend;
}
int timeclass::getminuteend()
{
    return minuteend;
}
QString timeclass::getenfant()
{
    return enfant;
}
void timeclass::sethourstart(int hourstart)
{
    this->hourstart=hourstart;
}
void timeclass::setminutestart(int minutestart)
{
    this->minutestart=minutestart;
}
void timeclass::sethourend(int hourend)
{
    this->hourend=hourend;
}
void timeclass::setminuteend(int minuteend)
{
    this->minuteend=minuteend;
}
void timeclass::setenfant(QString enfant)
{
    this->enfant=enfant;
}
bool timeclass::ajouter()
{

    QSqlQuery query;

         query.prepare("INSERT INTO time (enfant,hourstart, minutestart,hourend,minuteend) "
                      "VALUES (:enfant,:hourstart, :minutestart, :hourend, :minuteend)");
          query.bindValue(":enfant", enfant);
         query.bindValue(":hourstart", hourstart);
         query.bindValue(":minutestart", minutestart);
         query.bindValue(":hourend", hourend);
         query.bindValue(":minuteend", minuteend);

         return  query.exec();


}
QSqlQueryModel* timeclass::afficher(){
    QSqlQueryModel* model = new QSqlQueryModel();


         model->setQuery("SELECT* FROM time");

model->setHeaderData(1, Qt::Horizontal, QObject::tr("Heure Debut"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Minute Debut"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Heure Fin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Minute Fin"));


return model;
}

bool timeclass::supprimer(QString enfant)
{


    QSqlQuery query;

         query.prepare("Delete from time where enfant=:enfant ");
         query.bindValue(0,enfant);

         return  query.exec();
}

bool timeclass::modifier()
{
QSqlQuery query;
    //QString id_string=QString::number(identifiant);
    // QString personne_aide_string=QString::number(personne_aide);
  query.prepare("Update time set enfant=:enfant, hourstart=:hourstart, minutestart=:minutestart, hourend=:hourend ,minuteend=:minuteend where enfant=:enfant");
  query.bindValue(":enfant", enfant);
 query.bindValue(":hourstart", hourstart);
 query.bindValue(":minutestart", minutestart);
 query.bindValue(":hourend", hourend);
 query.bindValue(":minuteend", minuteend);

  return query.exec();

}








