#include "enfant.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
Enfant::Enfant()
{
id=0;
nom="";
prenom="";
adresse="";
age=0;
poids=0;
taille=0;
maladie="";
}

Enfant::Enfant(int id ,QString nom, QString prenom, QString adresse,int age, int poids, int taille, QString maladie )
{this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->age=age;
    this->poids=poids;
    this->taille=taille;
    this->maladie=maladie;
}
int Enfant::getid(){return id;}
QString Enfant:: getnom(){return nom;}
QString Enfant::getprenom() {return prenom;}
QString Enfant::getadresse(){return adresse;}
int Enfant::getage(){return age;}
int Enfant::getpoids(){return poids;}
int Enfant::gettaille(){return taille;}
QString Enfant::getmaladie(){return maladie;}
void Enfant::setid(int id) {this->id=id;}
void Enfant::setnom(QString nom){this->nom=nom;}
void Enfant::setprenom(QString prenom){this->prenom=prenom;}
void Enfant::setadresse(QString adresse){this->adresse=adresse;}
void Enfant::setage(int age){this->age=age;}
void Enfant::setpoids(int poids){this->poids=poids;}
void Enfant::settaille(int taille){this->taille=taille;}
void Enfant::setmaladie(QString maladie){this->maladie=maladie;}
bool Enfant::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO enfant (id,nom,prenom,adresse,age,poids,taille,maladie) VALUES (:id,:nom,:prenom,:adresse,:age,:poids,:taille,:maladie)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":age",age);
    query.bindValue(":poids",poids);
    query.bindValue(":taille",taille);
    query.bindValue(":maladie",maladie);
    return query.exec();
}
bool Enfant::supprimer(int id )
{
    QSqlQuery query;
    query.prepare("delete from enfant where id = :id") ;

    query.bindValue(":id",id);

    return query.exec();
}
QSqlQueryModel* Enfant::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM enfant");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("age"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("poids"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("taille"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("maladie"));
    return model;

}

bool Enfant::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE enfant SET id=:id,nom =:nom,prenom =:prenom,adresse =:adresse,age =:age,poids =:poids ,taille =:taille ,maladie =:maladie  WHERE id=:id ");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":age",age);
    query.bindValue(":poids",poids);
    query.bindValue(":taille",taille);
    query.bindValue(":maladie",maladie);
    return query.exec();
}
QSqlQueryModel * Enfant ::AfficherTrieAge()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM enfant ORDER BY age");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("adresse"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("age"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("poids"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("taille"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("maladie"));
   return model;
}
QSqlQueryModel * Enfant ::rechercherNom(QString search)
{QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from enfant where id like '%"+search+"%' or nom like '%"+search+"%' or prenom like '%"+search+"%' or adresse like '%"+search+"%' or age like '%"+search+"%'or poids like '%"+search+"%'or taille like '%"+search+"%'or maladie like '%"+search+"%'";
    qDebug()<<qry;
    model->setQuery(qry);
    return model;

}
