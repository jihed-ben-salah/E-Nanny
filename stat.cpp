/*#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>


QChartView * MainWindow::chart ()
{
    QPieSeries * serie= new QPieSeries();

        QSqlQuery querry;

        querry.prepare("SELECT ENFANT FROM TIME  ");
        querry.exec();
     int f=0;

        while(querry.next())
        {
           f++;

        }
 QChart *chart = new QChart();
     QChartView *chartView1 = new QChartView(chart);
    for (int i=0; i<f;i++)
    {


           QString enfant = QString("Enfant").arg(i+1)  ;
        serie->append(enfant,i+1);
        serie->slices().at(i)->setValue(difference());
        serie->slices().at(0)->setBrush(Qt::darkMagenta);

            chart->addSeries(serie);
            chart->setTitle("Horaire par enfant");



            chartView1->setRenderHint(QPainter::Antialiasing);

    }
return chartView1;

}


int MainWindow::difference(QString )
{
    QSqlQuery querry;
    querry.prepare("SELECT HOUREND-HOURSTART FROM TIME WHERE ENFANT like ?  ");
    querry.addBindValue("%"+enfant+"%");
    querry.exec();
}
*/















