#ifndef RENDEZVOUS_H
#define RENDEZVOUS_H

#include <QString>
#include <QSqlQueryModel>
class RendezVous
{
public:
    RendezVous();
    RendezVous(int,int,QString,QString,QString,QString,QString,QString,int);
    int getid_rdv();
    int getid_activite2();
    QString getnom();
    QString getprenom();
    QString getemail();
    QString getpro_rdv();
    QString getheure();
    QString getdate_rdv();
    int gettelephone_rdv();
    void setid_rdv(int);
    void setid_activite2(int);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    void setpro_rdv(QString);
    void setheure(QString);
    void setdate_rdv(QString);
    void settelephone_rdv(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int id_rdv);
    bool modifier(int id_rdv);
    QSqlQueryModel* tri_rdv();
    QSqlQueryModel *tri_id_rdv();
    QSqlQueryModel *tri_nom_rdv();
    //QSqlQueryModel *rechercheNom(QString nom);
    QSqlQueryModel *rechercherdv(QString search);
private:
    int id_rdv, id_activite2;
    QString nom , prenom,email,pro_rdv,heure,date_rdv ;
       int telephone_rdv;

   };

   #endif //
