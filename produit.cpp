#include "produit.h"
#include "fournisseur.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
produit::produit()
{
id_produit=0;
fournisseur=0;
nom="";
prix=0;
}

produit::produit(int id_produit, int fournisseur,QString nom,int prix)
{this->id_produit=id_produit;
    this->fournisseur=fournisseur;
    this->nom=nom;
    this->prix=prix;
}
int produit::getid_produit(){return id_produit;}
int produit::getfournisseur() {return fournisseur;}
QString produit:: getnom(){return nom;}
int produit::getprix(){return prix;}

void produit::setid_produit(int id_produit) {this->id_produit=id_produit;}
void produit::setfournisseur(int fournisseur){this->fournisseur=fournisseur;}
void produit::setnom(QString nom){this->nom=nom;}
void produit::setprix(int prix){this->prix=prix;}


bool produit::ajouter_produit()
{
    QSqlQuery query;
    query.prepare("INSERT INTO produit (id_produit,fournisseur,nom,prix) VALUES (:id_produit,:fournisseur,:nom,:prix)");
    query.bindValue(":id_produit",id_produit);
    query.bindValue(":fournisseur",fournisseur);
    query.bindValue(":nom",nom);
    query.bindValue(":prix",prix);

    return query.exec();
}
bool produit::supprimer_produit(int id_produit)
{
    QSqlQuery query;
    query.prepare("delete from produit where id_produit = :id_produit") ;

    query.bindValue(":id_produit",id_produit);

    return query.exec();
}
QSqlQueryModel* produit::afficher_produit()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM produit");
    return model;

}

bool produit::modifier_produit()
{
    QSqlQuery query;
    query.prepare("UPDATE produit SET id_produit=:id_produit,fournisseur =:fournisseur,nom =:nom,prix =:prix WHERE id_produit=:id_produit");
    query.bindValue(":id_produit",id_produit);
    query.bindValue(":fournisseur",fournisseur);
    query.bindValue(":nom",nom);
    query.bindValue(":prix",prix);

    return query.exec();
}
QSqlQueryModel * produit ::AfficherTrieprix()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM produit ORDER BY prix");

   return model;
}
QSqlQueryModel * produit ::AfficherTrieNom()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM produit ORDER BY nom");

   return model;
}
QSqlQueryModel * produit ::rechercherNom(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from produit where nom like ?");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}
