#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQueryModel>
class produit
{
public:
    produit();
    produit(int,int,QString,int);
    int getid_produit();
      int getfournisseur();
       QString getnom();
       int getprix();
       void setid_produit(int);
       void setfournisseur(int);
       void setnom(QString);
       void setprix(int);
       bool ajouter_produit();
       QSqlQueryModel* afficher_produit();
       bool supprimer_produit (int);
       bool modifier_produit();
       QSqlQueryModel * AfficherTrieprix();
       QSqlQueryModel * AfficherTrieNom();

       QSqlQueryModel *rechercherNom(QString fournisseur);

   private:
       int id_produit,fournisseur;
       QString nom ;
       int prix ;

};

#endif // PRODUIT_H
