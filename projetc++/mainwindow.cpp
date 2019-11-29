#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "personel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // >tableView_2->setModel(tabl.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    int cin = ui->lineEdit ->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
   // QString etat= ui->lineEdit_4->text();
    personel p(cin,nom,prenom);
    bool test=p.ajouter(cin);
    if(test)
  {//ui->tableView_2->setModel(tmppersonel.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un pers"),
                    QObject::tr("Etudiant ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un pers"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


  }



void MainWindow::on_pushButton_2_clicked()
{
    int cin = ui->lineEdit->text().toInt();
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
   int cin1 = ui->lineEdit_6->text().toInt();
    int cin = ui->lineEdit_4->text().toInt();
    QString nom=ui->lineEdit_7->text();
    QString prenom=ui->lineEdit_8->text();

    personel e(cin,nom,prenom);

   bool test=tmppersonel.modifier(cin1,cin,nom,prenom);

    if(test)
    {
        ui->tableView_3->setModel(tmppersonel.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("modifier un personel"),
                    QObject::tr("personel modifier.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("modifier un personel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}





