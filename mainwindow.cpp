#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "personel.h"
#include<QDebug>
#include<QDateTime>
#include<medcin.h>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);



   ui->tableView_2->setModel(tmppersonel.afficher());
timer = new QTimer(this);
connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
timer->start(1000);
}


MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    int cin= ui->lineEdit ->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
   // QString etat= ui->lineEdit_4->text();
    personel p(cin,nom,prenom);
    bool test=p.ajouter(cin);
    if(test)
  {ui->tableView_2->setModel(tmppersonel.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un personel"),
                    QObject::tr("personel ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un personel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  }



void MainWindow::on_pushButton_2_clicked()
{
    int cin = ui->lineEdit_4->text().toInt();
    bool test=tmppersonel.supprimer(cin);
    if(test)
    {ui->tableView_2->setModel(tmppersonel.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un personel"),
                    QObject::tr("personel supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un personel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_pushButton_4_clicked()
{
    int cin = ui->lineEdit_6->text().toInt();
     //int cin = ui->lineEdit_4->text().toInt();
     QString nom=ui->lineEdit_7->text();
     QString prenom=ui->lineEdit_8->text();

     personel e(cin,nom,prenom);

    bool test=tmppersonel.modifier(cin,nom,prenom);

     if(test)
     {
         ui->tableView_2->setModel(tmppersonel.afficher());//refresh
         QMessageBox::information(nullptr, QObject::tr("modifier un personel"),
                     QObject::tr("personel modifier.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("modifier un personel"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


 }








void MainWindow::on_lineRNOM_textChanged()
{
    QString nom = ui->lineRNOM->text();
        QString prenom=ui->lineRNOM->text();
       ui->tabr->setModel(tmppersonel.recherche(nom,prenom));
}


void MainWindow::myfunction()
{
    QTime time =QTime::currentTime();
    QString time_text= time.toString("hh : mm : ss ");
    if ((time.second()% 2)==0 ){
      time_text[3]=' ' ;
      time_text[8]=' ' ;


    }
    ui->label_20->setText(time_text);
}







void MainWindow::on_pushButton_6_clicked()
{
    int cin1 = ui->lineEdit_4 ->text().toInt();
    QString nom1= ui->lineEdit_9->text();
    QString prenom1= ui->lineEdit_10->text();
    QString specialite1= ui->lineEdit_11->text();
   // QString etat= ui->lineEdit_4->text();
   medcin p(nom1,prenom1,specialite1,cin1);
    bool test=p.ajouter1();
    if(test)
  {ui->tableView_5->setModel(tmpmedcin.afficher1());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un medcin"),
                    QObject::tr("medcin ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un medcin"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  }








void MainWindow::on_pushButton_3_clicked()
{
    int cin1 = ui->lineEdit_4->text().toInt();
    bool test=tmpmedcin.supprimer1(cin1);
    if(test)
    {ui->tableView_5->setModel(tmpmedcin.afficher1());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un medcin"),
                    QObject::tr("personel medcin.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un medcin"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_7_clicked()
{
    int cin1 = ui->lineEdit_14->text().toInt();
     //int cin = ui->lineEdit_4->text().toInt();


    bool test=tmpmedcin.modifier1(cin1);

     if(test)
     {
         ui->tableView_4->setModel(tmpmedcin.afficher1());//refresh
         QMessageBox::information(nullptr, QObject::tr("modifier un medcin"),
                     QObject::tr("medcin modifier.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
     else
         QMessageBox::critical(nullptr, QObject::tr("modifier un medcin"),
                     QObject::tr("Erreur !.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_lineEdit_12_textChanged()
{
    QString nom1 = ui->lineEdit_12->text();
        QString prenom1=ui->lineEdit_12->text();
       ui->listView_2->setModel(tmpmedcin.recherche1(nom1,prenom1));
}

