#ifndef COMPTE_H
#define COMPTE_H
#include<QString>
#include<QSqlQueryModel>
#include "QMessageBox"



class compte
{
public:
    compte();
    compte(int,QString,QString,QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);
    bool modifier();
    QSqlQueryModel * Find_compte();
    QString  apercu_pdf();
    QSqlQueryModel* recherche_avance(QString text,QString choix);
      bool supprimerc(int idc,QString log,QString m,QString enf);
      bool restoration(int idc,QString log,QString m,QString enf);
      QSqlQueryModel * archive();
private:
    int idc;
    QString login,mdp,enfant;
};

#endif // COMPTE_H
