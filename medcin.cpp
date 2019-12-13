#include "medcin.h"
#include <QDebug>
#include<QSqlQueryModel>

medcin::medcin()
{
cin1=0;
nom1="";
prenom1="";
specialite1="";

}
medcin::medcin(QString nom, QString prenom, QString specialite,int cin)
{
  this->nom1 =nom;
  this->prenom1=prenom;
    this->specialite1=specialite;
    this->cin1 = cin;

}
QString medcin::get_nom1(){return  nom1;}
QString medcin::get_prenom1(){return prenom1;}
QString medcin::get_specialite1(){return  specialite1;}
int medcin::get_cin1(){return  cin1;}
bool medcin::ajouter1()
{
QSqlQuery query;
QString res= QString::number(cin1);
query.prepare("INSERT INTO medcin (cin, nom, prenom ,specialite) "
                    "VALUES (:cin, :nom, :prenom, :specialite)");
query.bindValue(":cin", res);
query.bindValue(":nom", nom1);
query.bindValue(":prenom", prenom1);
query.bindValue(":specialite", specialite1);


return    query.exec();

}
QSqlQueryModel * medcin::afficher1()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from medcin");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("specialite"));
    //model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
        return model;
}

QSqlQueryModel *medcin::recherche1(QString nom1,QString prenom1)
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from medcin where nom like '"+nom1+"%' OR prenom like '"+prenom1+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));



    return model;
}
bool medcin::supprimer1(int cin1)
{
QSqlQuery query;
QString res= QString::number(cin1);
query.prepare("Delete from medcin where cin  = :cin1 ");
query.bindValue(":cin1", res);
return    query.exec();
}

bool medcin ::modifier1(int cin1)
{
    QSqlQuery query;
    QString res= QString::number(cin1);
   // QString res1= QString::number(cin);


    query.prepare("UPDATE medcin SET nom='"+nom1+"',prenom='"+prenom1+"' where cin='"+res+"'");
    query.bindValue(":cin", res);
   // query.bindValue(":cin1", res1);
    return query.exec();
}
