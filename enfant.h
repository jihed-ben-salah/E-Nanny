#ifndef ENFANT_H
#define ENFANT_H

#include <QString>
#include <QSqlQueryModel>
class Enfant
{
public:
    Enfant();
    Enfant(int,QString,QString,QString,int,int,int,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getadresse();
    int getage();
    int getpoids();
    int gettaille();
    QString getmaladie();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setadresse(QString);
    void setage(int);
    void setpoids(int);
    void settaille(int);
    void setmaladie(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);
    bool modifier();
    QSqlQueryModel * AfficherTrieAge();
    QSqlQueryModel *rechercherNom(QString search);
private:
    int id;
    QString nom,prenom,adresse,maladie ;
       int age,poids,taille;

   };

   #endif // ENFANT_H
