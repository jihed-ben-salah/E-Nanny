#include "activiteloi.h"
#include <QSqlQuery>
#include<QtDebug>
#include <QObject>
activiteloi::activiteloi()
{
id=0;
nom="";
prenom="";
adresse="";
prix=0;
telephone=0;
}

activiteloi::activiteloi(int id ,QString nom, QString prenom, QString adresse,int prix, int telephone)
{this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->prix=prix;
    this->telephone=telephone;}
int activiteloi::getid(){return id;}
QString activiteloi:: getnom(){return nom;}
QString activiteloi::getprenom() {return prenom;}
QString activiteloi::getadresse(){return adresse;}
int activiteloi::getprix(){return prix;}
int activiteloi::gettelephone(){return telephone;}
void activiteloi::setid(int id) {this->id=id;}
void activiteloi::setnom(QString nom){this->nom=nom;}
void activiteloi::setprenom(QString prenom){this->prenom=prenom;}
void activiteloi::setadresse(QString adresse){this->adresse=adresse;}
void activiteloi::setprix(int prix) {this->prix=prix;}
void activiteloi::settelephone(int telephone){this->telephone=telephone;}

bool activiteloi::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO activiteloi (id,nom,prenom,adresse,prix,telephone) VALUES (:id,:nom,:prenom,:adresse,:prix,:telephone)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":prix",prix);
    query.bindValue(":telephone",telephone);
    return query.exec();
}
bool activiteloi::supprimer(int id )
{
    QSqlQuery query;
    query.prepare("delete from activiteloi where id = :id") ;

    query.bindValue(":id",id);

    return query.exec();
}
QSqlQueryModel* activiteloi::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();





          model->setQuery("SELECT * FROM activiteloi");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
    return model;
}

bool activiteloi::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE activiteloi SET nom =:nom,prenom =:prenom,adresse =:adresse,prix =:prix, telephone =:telephone  WHERE id=:id ");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":prix",prix);
    query.bindValue(":telephone",telephone);
    return query.exec();
}

QSqlQueryModel * activiteloi::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM activiteloi ORDER BY prix");
    return model;

}

/*QSqlQueryModel * activiteloi::recherche_activiteloi(QString prenom)
{

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from activiteloi where prenom like ?");
    q.addBindValue("%"+ prenom +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}*/

QSqlQueryModel * activiteloi::recherche_activite(QString search)
{

    QSqlQueryModel * model= new QSqlQueryModel();
    QString qry="select * from activiteloi where id like '%"+search+"%' or nom like '%"+search+"%' or prenom like '%"+search+"%' or adresse like '%"+search+"%' or prix like '%"+search+"%' or telephone like '%"+search+"%'";
    qDebug()<<qry;
    model->setQuery(qry);
    return model;
}

QSqlQueryModel * activiteloi::Find_Activite()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT id,nom,prenom,adresse,telephone FROM activiteloi");

    query.exec();
    model->setQuery(query);
    return model;
}

QSqlQueryModel * activiteloi::tri_activite_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM activiteloi ORDER BY id");
    return model;

}

QSqlQueryModel * activiteloi::tri_activite_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM activiteloi ORDER BY nom");
    return model;

}

