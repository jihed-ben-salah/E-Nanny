#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQueryModel>
#include "QMessageBox"

class fournisseur
{
public:
    fournisseur();
    fournisseur(int,QString,QString,QString,int);
    int getid();
       QString getnom();
       QString getmarque();
       QString getadresse();
       int getnumero();
       void setid(int);
       void setnom(QString);
       void setmarque(QString);
       void setadresse(QString);
       void setnumero(int);
       bool ajouter();
       QSqlQueryModel* afficher();
       bool supprimer (int);
       bool modifier();
       QSqlQueryModel * AfficherTrie();
       QSqlQueryModel * AfficherTrieMarque();

       QSqlQueryModel *rechercherNom(QString nom);
   private:
       int id;
       QString nom,marque,adresse ;
       int numero ;

};

#endif // FOURNISSEUR_H
