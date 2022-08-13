#include "commande.h"
#include "produit.h"
#include"fournisseur.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QDate>
#include <QObject>
commande::commande()
{

id_commande=0;
id_fournisseur=0;
id_produit=0;
montant=0;
adresse="";

}

commande::commande(int id_commande,int id_fournisseur, int id_produit,int montant, QString adresse)
{this->id_commande=id_commande;
    this->id_fournisseur=id_fournisseur;
    this->id_produit=id_produit;
    this->montant=montant;
    this->adresse=adresse;

}
int commande::getid_commande(){return id_commande;}
int commande:: getid_fournisseur(){return id_fournisseur;}
int commande::getid_produit() {return id_produit;}
int commande::getmontant(){return montant;}
QString commande::getadresse(){return adresse;}


void commande::setid_commande(int id_commande) {this->id_commande=id_commande;}
void commande::setid_fournisseur(int id_fournisseur){this->id_fournisseur=id_fournisseur;}
void commande::setid_produit(int id_produit){this->id_produit=id_produit;}
void commande::setmontant(int montant){this->montant=montant;}
void commande::setadresse(QString adresse){this->adresse=adresse;}


bool commande::ajouter_commande()
{
    QSqlQuery query;
    query.prepare("INSERT INTO commande (id_commande,id_fournisseur,id_produit,montant,adresse) VALUES (:id_commande,:id_fournisseur,:id_produit,:montant,:adresse)");
    query.bindValue(":id_commande",id_commande);
    query.bindValue(":id_fournisseur",id_fournisseur);
    query.bindValue(":id_produit",id_produit);
    query.bindValue(":montant",montant);
    query.bindValue(":adresse",adresse);


    return query.exec();
}
bool commande::supprimer_commande(int id_commande)
{
    QSqlQuery query;
    query.prepare("delete from commande where id_commande = :id_commande") ;

    query.bindValue(":id_commande",id_commande);

    return query.exec();
}
QSqlQueryModel* commande::afficher_commande()
{
    QSqlQueryModel* model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM commande");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_fournisseur"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_produit"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("montant"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

    return model;

}

bool commande::modifier_commande()
{
    QSqlQuery query;
    query.prepare("UPDATE commande SET id_commande=:id_commande,id_fournisseur =:id_fournisseur,id_produit =:id_produit,montant =:montant ,adresse =:adresse WHERE id_commande=:id_commande ");
    query.bindValue(":id_commande",id_commande);
    query.bindValue(":id_fournisseur",id_fournisseur);
    query.bindValue(":id_produit",id_produit);
    query.bindValue(":montant",montant);
    query.bindValue(":adresse",adresse);


    return query.exec();
}
QSqlQueryModel * commande ::AfficherTrieMontant()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM commande ORDER BY montant");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_fournisseur"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_produit"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("montant"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

   return model;
}
QSqlQueryModel * commande ::AfficherTrieAdresse()
{
    QSqlQueryModel *model = new QSqlQueryModel;
         model->setQuery("SELECT * FROM commande ORDER BY adresse");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_fournisseur"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_produit"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("montant"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));

   return model;
}
QSqlQueryModel * commande ::rechercherAdresse(QString adresse)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from commande where adresse like ?");
    q.addBindValue("%"+ adresse +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}
QString commande:: apercu_pdf(QString id)
 {



    QString text="********COMMANDE POUR LA FAMILLE BOUAYED****** \n\n\n" ;
         QSqlQuery query ;
         QString i,x,z,a,b,c;

             c = QDate::currentDate().toString("yyyy/MM/dd");

          query.exec("select * from commande ");
          while (query.next())
          {
             i=query.value(0).toString();
             x=query.value(1).toString();
             z=query.value(2).toString();
             a=query.value(3).toString();
             b=query.value(4).toString();

    if(id==i){
            text += "\nCommande Id : "+i+"                                    Tunis , le "+c+"\n\n - Id fournisseur : "+ x+"\n - Id produit : "+ z+"\n - Adresse:"+a+"\n - Montant :"+b+"\n\n\n ";
    return text ;

    }
         }
 }

QSqlQueryModel * commande::Find_commande()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT id_commande,id_fournisseur,id_produit,adresse,montant FROM commande");

    query.exec();
    model->setQuery(query);
    return model;
}
