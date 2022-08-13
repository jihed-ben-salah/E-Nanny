#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSqlQueryModel>
#include "QMessageBox"


class commande
{
public:
    commande();
    commande(int,int,int,int,QString);
    int getid_commande();
       int getid_fournisseur();
       int getid_produit();
       int getmontant();
       QString getadresse();

       void setid_commande(int);
       void setid_fournisseur(int);
       void setid_produit(int);
       void setmontant(int);
        void setadresse(QString);
       bool ajouter_commande();
       QSqlQueryModel* afficher_commande();
       bool supprimer_commande (int);
       bool modifier_commande();
       QSqlQueryModel * AfficherTrieMontant();
       QSqlQueryModel * AfficherTrieAdresse();

       QSqlQueryModel *rechercherAdresse(QString adresse);
       QString  apercu_pdf(QString);
       QString  apercu_pdf2();

       QSqlQueryModel * Find_commande();
   private:
       int id_commande,id_fournisseur,id_produit;
       int montant ;
       QString adresse ;


};

#endif // COMMANDE_H
