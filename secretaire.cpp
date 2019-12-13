#include "secretaire.h"
#include "ui_secretaire.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "secretaire.h"
#include<QDebug>

secretaire::secretaire(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secretaire)
{
    ui->setupUi(this);
}

secretaire::~secretaire()
{
    delete ui;
}

void secretaire::on_pushButton_clicked()
{
    int cin = ui->lineEdit ->text().toInt();
    QString nom= ui->lineEdit_2->text();
    QString prenom= ui->lineEdit_3->text();
    QString specialete= ui->lineEdit_3->text();
   // QString etat= ui->lineEdit_4->text();
    personel p(nom,prenom);
    bool test=p.ajouter(cin);
    if(test)
  //{ui->secretaire->setModel(tmppersonel.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un personel"),
                    QObject::tr("personel ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    else
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un personel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

