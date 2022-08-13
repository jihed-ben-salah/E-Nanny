#include "fournisseur.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>

fournisseur::fournisseur()
{

id=0;
nom="";
marque="";
adresse="";
numero=0;
}

fournisseur::fournisseur(int id,QString nom, QString marque, QString adresse,int numero)
{this->id=id;
    this->nom=nom;
    this->marque=marque;
    this->adresse=adresse;
    this->numero=numero;
}
int fournisseur::getid(){return id;}
QString fournisseur:: getnom(){return nom;}
QString fournisseur::getmarque() {return marque;}
QString fournisseur::getadresse(){return adresse;}
int fournisseur::getnumero(){return numero;}

void fournisseur::setid(int id) {this->id=id;}
void fournisseur::setnom(QString nom){this->nom=nom;}
void fournisseur::setmarque(QString marque){this->marque=marque;}
void fournisseur::setadresse(QString adresse){this->adresse=adresse;}
void fournisseur::setnumero(int numero){this->numero=numero;}


bool fournisseur::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO fournisseur (id,nom,marque,adresse,numero) VALUES (:id,:nom,:marque,:adresse,:numero)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":marque",marque);
    query.bindValue(":adresse",adresse);
    query.bindValue(":numero",numero);

    return query.exec();
}
bool fournisseur::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("delete from fournisseur where id = :id") ;

    query.bindValue(":id",id);

    return query.exec();
}
QSqlQueryModel* fournisseur::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT * FROM fournisseur");

    return model;

}

bool fournisseur::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE fournisseur SET id=:id,nom =:nom,marque =:marque,adresse =:adresse,numero =:numero WHERE id=:id ");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":marque",marque);
    query.bindValue(":adresse",adresse);
    query.bindValue(":numero",numero);

    return query.exec();
}
QSqlQueryModel * fournisseur ::AfficherTrie()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM fournisseur ORDER BY nom");

   return model;
}
QSqlQueryModel * fournisseur ::AfficherTrieMarque()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM fournisseur ORDER BY marque");

   return model;
}
QSqlQueryModel * fournisseur ::rechercherNom(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from fournisseur where nom like ?");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}
