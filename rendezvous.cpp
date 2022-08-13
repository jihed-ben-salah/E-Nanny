#include "rendezvous.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
RendezVous::RendezVous()
{
id_rdv=0;
id_activite2=0;
nom="";
prenom="";
email="";
pro_rdv="";
heure="";
date_rdv="";
telephone_rdv=0;
}

RendezVous::RendezVous(int id_rdv ,int id_activite2 ,QString nom, QString prenom, QString email,QString pro_rdv,QString heure,QString date_rdv, int telephone_rdv)
{this->id_rdv=id_rdv;
    this->id_activite2=id_activite2;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->pro_rdv=pro_rdv;
    this->heure=heure;
    this->date_rdv=date_rdv;
    this->telephone_rdv=telephone_rdv;}
int RendezVous::getid_rdv(){return id_rdv;}
int RendezVous::getid_activite2(){return id_activite2;}
QString RendezVous:: getnom(){return nom;}
QString RendezVous::getprenom() {return prenom;}
QString RendezVous::getemail(){return email;}
QString RendezVous::getpro_rdv(){return pro_rdv;}
QString RendezVous::getheure(){return heure;}
QString RendezVous::getdate_rdv(){return date_rdv;}
int RendezVous::gettelephone_rdv(){return telephone_rdv;}
void RendezVous::setid_rdv(int id_rdv) {this->id_rdv=id_rdv;}
void RendezVous::setid_activite2(int id_activite2) {this->id_activite2=id_activite2;}
void RendezVous::setnom(QString nom){this->nom=nom;}
void RendezVous::setprenom(QString prenom){this->prenom=prenom;}
void RendezVous::setemail(QString email){this->email=email;}
void RendezVous::setpro_rdv(QString pro_rdv){this->pro_rdv=pro_rdv;}
void RendezVous::setheure(QString heure) {this->heure=heure;}
void RendezVous::setdate_rdv(QString date_rdv) {this->date_rdv=date_rdv;}
void RendezVous::settelephone_rdv(int telephone_rdv){this->telephone_rdv=telephone_rdv;}

bool RendezVous::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO RENDEZVOUS (id_rdv,id_activite2,nom,prenom,email,heure,date_rdv,telephone_rdv) VALUES (:id_rdv,:id_activite2,:nom,:prenom,:email,:heure,:date_rdv,:telephone_rdv)");
    query.bindValue(":id_rdv",id_rdv);
    query.bindValue(":id_activite2",id_activite2);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email",email);
    query.bindValue(":pro_rdv",pro_rdv);
    query.bindValue(":heure",heure);
    query.bindValue(":date_rdv",date_rdv);
    query.bindValue(":telephone_rdv",telephone_rdv);
    return query.exec();
}
bool RendezVous::supprimer(int id_rdv )
{
    QSqlQuery query;
    query.prepare("delete from RENDEZVOUS where id_rdv = :id_rdv") ;

    query.bindValue(":id_rdv",id_rdv);

    return query.exec();
}
QSqlQueryModel* RendezVous::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM RENDEZVOUS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("identifiant_activite"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("pro_rdv"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("heure"));
          model->setHeaderData(7, Qt::Horizontal, QObject::tr("date_rdv"));
          model->setHeaderData(8, Qt::Horizontal, QObject::tr("telephone_rdv"));
    return model;
}

bool RendezVous::modifier(int id_rdv)
{
    QSqlQuery query;
    query.prepare("UPDATE RENDEZVOUS SET id_activite2 =:id_activite2, nom =:nom,prenom =:prenom,email =:email,heure =:heure,date_rdv =:date_rdv, telephone_rdv =:telephone_rdv  WHERE id_rdv=:id_rdv ");
    query.bindValue(":id_rdv",id_rdv);
    query.bindValue(":id_activite2",id_activite2);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email",email);
    query.bindValue(":pro_rdv",pro_rdv);
    query.bindValue(":heure",heure);
    query.bindValue(":date_rdv",date_rdv);
    query.bindValue(":telephone_rdv",telephone_rdv);
    return query.exec();
}

QSqlQueryModel * RendezVous::tri_rdv()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM RENDEZVOUS ORDER BY date_rdv");
    return model;

}

QSqlQueryModel * RendezVous::tri_id_rdv()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM RENDEZVOUS ORDER BY id_rdv");
    return model;

}

QSqlQueryModel * RendezVous::tri_nom_rdv()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM RENDEZVOUS ORDER BY nom");
    return model;

}


/*QSqlQueryModel * RendezVous ::rechercheNom(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from RENDEZVOUS where nom like ?");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}*/

QSqlQueryModel * RendezVous::rechercherdv(QString search)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from rendezvous where id_rdv like '%"+search+"%' or id_activite2 like '%"+search+"%' or nom like '%"+search+"%' or prenom like '%"+search+"%' or email like '%"+search+"%' or pro_rdv like '%"+search+"%' or heure like '%"+search+"%' or date_rdv like '%"+search+"%' or telephone_rdv like '%"+search+"%'";
    qDebug()<<qry;
    model->setQuery(qry);
    return model;
}

