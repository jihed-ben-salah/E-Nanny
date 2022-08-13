#include "mainwindow1.h"
#include "ui_mainwindow1.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlQueryModel>
#include <QtCharts>
#include "personned_aides.h"
#include "secu.h"
#include "motcle.h"

QChartView* mainwindow1::barchart()
{

QBarSet *set0 = new QBarSet("medecin");
QBarSet *set1 = new QBarSet("babysitters");
QBarSet *set2 = new QBarSet("infirmiere");
QBarSet *set3 = new QBarSet("prof dessin");
QBarSet *set4 = new QBarSet("prof sport");
QBarSet *set5 = new QBarSet("prof musique");


*set0 << R_BCS1()  ;
*set1 << R_BCS2()  ;
*set2 << R_BCS3()  ;
*set3 << R_BCS4()  ;
*set4 << R_BCS5()  ;
*set5 << R_BCS6()  ;

//![1]

//![2]
QBarSeries *series = new QBarSeries();
series->append(set0);
series->append(set1);
series->append(set2);
series->append(set3);
series->append(set4);
series->append(set5);



//![2]

//![3]


QChart *chart = new QChart();
chart->addSeries(series);
chart->setTitle(" Métier des personnes d'aides");
chart->setAnimationOptions(QChart::SeriesAnimations);
chart->resize(50,30);
//![3]

//![4]
QStringList categories;
categories << "Metier"  ;
QBarCategoryAxis *axis = new QBarCategoryAxis();
axis->append(categories);
chart->createDefaultAxes();
chart->setAxisX(axis, series);
//![4]

//![5]
chart->legend()->setVisible(true);
chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
QChartView *chartView = new QChartView(chart);
chartView->setRenderHint(QPainter::Antialiasing);
//chartView->resize(600,400);
return chartView;
}


int mainwindow1::R_BCS1()
{
    QSqlQuery query;
    query.exec("SELECT identifiant FROM personne WHERE metier='medecin'");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}

int mainwindow1::R_BCS2()
{
    QSqlQuery query;
    query.exec("SELECT identifiant FROM personne WHERE metier='babysitters' ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}

int mainwindow1::R_BCS3()
{
    QSqlQuery query;
    query.exec("SELECT identifiant FROM personne WHERE metier='infirmiere' ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}



int mainwindow1::R_BCS4()
{
    QSqlQuery query;
    query.exec("SELECT identifiant FROM personne WHERE metier='prof dessin' ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}

int mainwindow1::R_BCS5()
{
    QSqlQuery query;
    query.exec("SELECT identifiant FROM personne WHERE metier='prof sport' ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}

int mainwindow1::R_BCS6()
{
    QSqlQuery query;
    query.exec("SELECT identifiant FROM personne WHERE metier='prof musique' ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}


QChartView* secu::barchart1()
{

QBarSet *set0 = new QBarSet("Age :3-5");
QBarSet *set1 = new QBarSet("Age :5-8");
QBarSet *set2 = new QBarSet("Age :8-11");
QBarSet *set3 = new QBarSet("Age :11-14");



*set0 << R1_BCS1()  ;
*set1 << R2_BCS2()  ;
*set2 << R3_BCS3()  ;
*set3 << R4_BCS4()  ;


//![1]

//![2]
QBarSeries *series = new QBarSeries();
series->append(set0);
series->append(set1);
series->append(set2);
series->append(set3);




//![2]

//![3]


QChart *chart = new QChart();
chart->addSeries(series);
chart->setTitle(" LES SITES INTERDITS");
chart->setAnimationOptions(QChart::SeriesAnimations);
chart->resize(50,30);
//![3]

//![4]
QStringList categories;
categories << "age"  ;
QBarCategoryAxis *axis = new QBarCategoryAxis();
axis->append(categories);
chart->createDefaultAxes();
chart->setAxisX(axis, series);
//![4]

//![5]
chart->legend()->setVisible(true);
chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
QChartView *chartView = new QChartView(chart);
chartView->setRenderHint(QPainter::Antialiasing);
//chartView->resize(600,400);
return chartView;
}


int secu::R1_BCS1()
{
    QSqlQuery query;
    query.exec("SELECT site FROM motcle WHERE age>=3 and age<=5");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}

int secu::R2_BCS2()
{
    QSqlQuery query;
    query.exec("SELECT site FROM motcle WHERE age>=5 and age<=8 ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}

int secu::R3_BCS3()
{
    QSqlQuery query;
    query.exec("SELECT site FROM motcle WHERE age>=8 and age<=11 ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}



int secu::R4_BCS4()
{
    QSqlQuery query;
    query.exec("SELECT site FROM motcle WHERE age>=11 and age<=13 ");
    int f=0;
    while(query.next())
    {
        f++;
    }
    return f;
}
