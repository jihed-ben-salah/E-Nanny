#ifndef ACTIVITELOI_H
#define ACTIVITELOI_H
#include <QString>
#include <QSqlQueryModel>

class activiteloi
{
public:
    activiteloi();
    activiteloi(int ,QString,QString,QString,int,int);
    int getid();
    QString getnom();
    QString getprenom();
    QString getadresse();
    int getprix();
    int gettelephone();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setadresse(QString);
    void setprix(int);
    void settelephone(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int id);
    bool modifier(int id);
    QSqlQueryModel* tri();
    QSqlQueryModel *tri_activite_id();
    QSqlQueryModel *tri_activite_nom();
    QSqlQueryModel* recherche_activite(QString prenom);
    QSqlQueryModel * Find_Activite();
private:
    int id;
    QString nom , prenom,adresse ;
       int prix, telephone;
       int selected_activite=0;

   };

#endif // ACTIVITELOI_H
