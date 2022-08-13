/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *widget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTabWidget *tabWidget_3;
    QWidget *tab_5;
    QLabel *label_4;
    QPushButton *ajouter_3;
    QLabel *label_8;
    QLineEdit *lineEdit_3;
    QLabel *label_9;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *tab_6;
    QLineEdit *lineEdit_5;
    QTableView *tableView_2;
    QPushButton *pb_supp_2;
    QLabel *label_11;
    QPushButton *ajouter_4;
    QLabel *label_12;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLabel *label_13;
    QPushButton *trie;
    QLineEdit *lineEdit_8;
    QLabel *label_14;
    QWidget *tab_2;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QTimeEdit *timeEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *ajouter;
    QComboBox *comboBox;
    QLabel *label_3;
    QTimeEdit *timeEdit_2;
    QWidget *tab_4;
    QTableView *tableView;
    QTimeEdit *timeEdit_3;
    QLabel *label_5;
    QTimeEdit *timeEdit_4;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *ajouter_2;
    QPushButton *pb_supp;
    QLineEdit *lineEdit;
    QWidget *tab_7;
    QPushButton *pushButton_3;
    QLabel *label_10;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1028, 518);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(MainWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1011, 471));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"background-image: url(:/img/image.jpg);\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: black;"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget_3 = new QTabWidget(tab);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        tabWidget_3->setGeometry(QRect(0, 0, 1001, 431));
        tabWidget_3->setAutoFillBackground(false);
        tabWidget_3->setStyleSheet(QString::fromUtf8("background-image: url(:/img/image.jpg);"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        label_4 = new QLabel(tab_5);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 181, 31));
        label_4->setAutoFillBackground(false);
        label_4->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: white;"));
        ajouter_3 = new QPushButton(tab_5);
        ajouter_3->setObjectName(QString::fromUtf8("ajouter_3"));
        ajouter_3->setGeometry(QRect(290, 270, 181, 25));
        ajouter_3->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        label_8 = new QLabel(tab_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 110, 231, 31));
        label_8->setAutoFillBackground(false);
        label_8->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: white;"));
        lineEdit_3 = new QLineEdit(tab_5);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(240, 120, 201, 24));
        lineEdit_3->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        lineEdit_3->setReadOnly(false);
        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 30, 181, 31));
        label_9->setAutoFillBackground(false);
        label_9->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: white;"));
        lineEdit_2 = new QLineEdit(tab_5);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(240, 70, 201, 24));
        lineEdit_2->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        lineEdit_2->setReadOnly(false);
        lineEdit_4 = new QLineEdit(tab_5);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(280, 30, 121, 24));
        lineEdit_4->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        lineEdit_4->setReadOnly(false);
        pushButton = new QPushButton(tab_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 40, 161, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        pushButton_2 = new QPushButton(tab_5);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(660, 120, 161, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        tabWidget_3->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        lineEdit_5 = new QLineEdit(tab_6);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(700, 130, 113, 24));
        lineEdit_5->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        lineEdit_5->setReadOnly(false);
        tableView_2 = new QTableView(tab_6);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setGeometry(QRect(5, 11, 591, 271));
        tableView_2->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        pb_supp_2 = new QPushButton(tab_6);
        pb_supp_2->setObjectName(QString::fromUtf8("pb_supp_2"));
        pb_supp_2->setGeometry(QRect(650, 230, 221, 51));
        pb_supp_2->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        label_11 = new QLabel(tab_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(710, 100, 131, 31));
        label_11->setAutoFillBackground(false);
        label_11->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: white;"));
        ajouter_4 = new QPushButton(tab_6);
        ajouter_4->setObjectName(QString::fromUtf8("ajouter_4"));
        ajouter_4->setGeometry(QRect(650, 170, 221, 51));
        ajouter_4->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        label_12 = new QLabel(tab_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(820, 20, 131, 31));
        label_12->setAutoFillBackground(false);
        label_12->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: white;"));
        lineEdit_6 = new QLineEdit(tab_6);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(820, 60, 113, 24));
        lineEdit_6->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        lineEdit_6->setReadOnly(false);
        lineEdit_7 = new QLineEdit(tab_6);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(620, 60, 113, 24));
        lineEdit_7->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        lineEdit_7->setReadOnly(false);
        label_13 = new QLabel(tab_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(620, 20, 131, 31));
        label_13->setAutoFillBackground(false);
        label_13->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: white;"));
        trie = new QPushButton(tab_6);
        trie->setObjectName(QString::fromUtf8("trie"));
        trie->setGeometry(QRect(90, 300, 221, 31));
        trie->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        lineEdit_8 = new QLineEdit(tab_6);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(380, 330, 151, 24));
        lineEdit_8->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        lineEdit_8->setReadOnly(false);
        label_14 = new QLabel(tab_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(380, 290, 181, 31));
        label_14->setAutoFillBackground(false);
        label_14->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: white;"));
        tabWidget_3->addTab(tab_6, QString());
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget_2 = new QTabWidget(tab_2);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(-10, 0, 1051, 491));
        tabWidget_2->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"background-image: url(:/img/image.jpg);\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: black;"));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        timeEdit = new QTimeEdit(tab_3);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(50, 90, 171, 61));
        timeEdit->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 30, 131, 31));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: white;"));
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 160, 131, 31));
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8("font: 75 8pt \"MS Shell Dlg 2\" b;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"font: bold, \"Comic Sans MS\" ;\n"
"text-align:center;\n"
"color: white;"));
        ajouter = new QPushButton(tab_3);
        ajouter->setObjectName(QString::fromUtf8("ajouter"));
        ajouter->setGeometry(QRect(340, 230, 181, 25));
        ajouter->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        comboBox = new QComboBox(tab_3);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(270, 90, 171, 51));
        comboBox->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 30, 131, 31));
        label_3->setAutoFillBackground(false);
        label_3->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: white;"));
        timeEdit_2 = new QTimeEdit(tab_3);
        timeEdit_2->setObjectName(QString::fromUtf8("timeEdit_2"));
        timeEdit_2->setGeometry(QRect(50, 190, 171, 61));
        timeEdit_2->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tableView = new QTableView(tab_4);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(15, 11, 591, 271));
        tableView->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        timeEdit_3 = new QTimeEdit(tab_4);
        timeEdit_3->setObjectName(QString::fromUtf8("timeEdit_3"));
        timeEdit_3->setGeometry(QRect(610, 180, 171, 61));
        timeEdit_3->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(830, 20, 131, 31));
        label_5->setAutoFillBackground(false);
        label_5->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: white;"));
        timeEdit_4 = new QTimeEdit(tab_4);
        timeEdit_4->setObjectName(QString::fromUtf8("timeEdit_4"));
        timeEdit_4->setGeometry(QRect(610, 80, 171, 61));
        timeEdit_4->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(620, 20, 131, 31));
        label_6->setAutoFillBackground(false);
        label_6->setStyleSheet(QString::fromUtf8("/*border: 2px solid ;*/\n"
"/*font: 75 8pt \"MS Shell Dlg 2\" ;*/\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"/*background: #AFEEEE;*/\n"
"font: bold, \"Comic Sans MS\"  ;\n"
"text-align:center;\n"
"color: white;"));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(630, 150, 131, 31));
        label_7->setAutoFillBackground(false);
        label_7->setStyleSheet(QString::fromUtf8("font: 75 8pt \"MS Shell Dlg 2\" b;\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"font: bold, \"Comic Sans MS\" ;\n"
"text-align:center;\n"
"color: white;"));
        ajouter_2 = new QPushButton(tab_4);
        ajouter_2->setObjectName(QString::fromUtf8("ajouter_2"));
        ajouter_2->setGeometry(QRect(800, 220, 181, 25));
        ajouter_2->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        pb_supp = new QPushButton(tab_4);
        pb_supp->setObjectName(QString::fromUtf8("pb_supp"));
        pb_supp->setGeometry(QRect(800, 260, 181, 25));
        pb_supp->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        lineEdit = new QLineEdit(tab_4);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(820, 90, 113, 24));
        lineEdit->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        lineEdit->setReadOnly(true);
        tabWidget_2->addTab(tab_4, QString());
        tabWidget->addTab(tab_2, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        pushButton_3 = new QPushButton(tab_7);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 60, 151, 51));
        pushButton_3->setStyleSheet(QString::fromUtf8("border: 2px solid black;\n"
"font: 75 8pt \"MS Shell Dlg 2\";\n"
"border-radius: 10px;\n"
"padding: 0 8px;\n"
"background: #AFEEEE;\n"
"font: bold, \"Comic Sans MS\";;\n"
"color: black;\n"
"text-align:center;"));
        label_10 = new QLabel(tab_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(300, 60, 331, 221));
        label_10->setStyleSheet(QString::fromUtf8("background-image: url(:/numero.png);"));
        tabWidget->addTab(tab_7, QString());
        MainWindow->setCentralWidget(widget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1028, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);
        tabWidget_3->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Nom du site \303\240 interdire", nullptr));
        ajouter_3->setText(QApplication::translate("MainWindow", "Interdire le site", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\303\202ge limite pour acc\303\251der au site", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Identifiant", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Play", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Stop", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_5), QApplication::translate("MainWindow", "Ajouter", nullptr));
        pb_supp_2->setText(QApplication::translate("MainWindow", "Supprimer", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "\303\202ge Limite", nullptr));
        ajouter_4->setText(QApplication::translate("MainWindow", "Modifier ", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Nom du site", nullptr));
        lineEdit_7->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Id du site", nullptr));
        trie->setText(QApplication::translate("MainWindow", "Trier par age", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Rechercher un site", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("MainWindow", "Afficher", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Site \303\240 interdire", nullptr));
        label->setText(QApplication::translate("MainWindow", "Heure debut", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Heure fin", nullptr));
        ajouter->setText(QApplication::translate("MainWindow", "Ajouter plage horaire", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Enfant", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Ajouter", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Enfant", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Heure debut", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "Heure fin", nullptr));
        ajouter_2->setText(QApplication::translate("MainWindow", "Modifier plage horaire", nullptr));
        pb_supp->setText(QApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Afficher", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Plage horaires", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Telephone", nullptr));
        label_10->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("MainWindow", "Urgence", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
