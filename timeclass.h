#ifndef TIME_H
#define TIME_H

#include <QString>
#include <QSqlQueryModel>
class timeclass
{
public:
    timeclass();

    timeclass(QString,int,int,int,int);
    int gethourstart();
   int getminutestart();
   int gethourend();
  int getminuteend();
QString getenfant();
    void sethourstart(int);
    void setminutestart(int);
    void sethourend(int);
    void setminuteend(int);
void setenfant(QString);
   bool ajouter();
   QSqlQueryModel* afficher();
  bool supprimer(QString);
  bool modifier ();
private:
    int hourstart,minutestart, hourend,minuteend;
    QString enfant;

};

#endif // TIME_H
