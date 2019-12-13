#include "personel.h"
#include <QDebug>
#include<QSqlQueryModel>

personel::personel()
{
cin=0;
nom="";
prenom="";
//etat="" ;
}
personel::personel(int cin,QString nom,QString prenom)
{
this->cin=cin;
  this->nom=nom;
  this->prenom=prenom;
}
QString personel::get_nom(){return  nom;}
QString personel::get_prenom(){return prenom;}

int personel::get_cin(){return  cin;}

bool personel::ajouter(int cin)
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("INSERT INTO personel (cin, nom, prenom) ""VALUES (:cin, :nom, :prenom)");
query.bindValue(":cin", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);


return    query.exec();
}

QSqlQueryModel * personel::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from personel");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
//model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat"));
    return model;
}

bool personel::supprimer(int cin)
{
QSqlQuery query;
QString res= QString::number(cin);
query.prepare("Delete from personel where cin = :cin ");
query.bindValue(":cin", res);
return    query.exec();
}
bool personel ::modifier(int cin, QString nom,QString prenom)
{
    QSqlQuery query;
    QString res= QString::number(cin);
   // QString res1= QString::number(cin);


    query.prepare("UPDATE PERSONEL SET nom='"+nom+"',prenom='"+prenom+"' where cin='"+res+"'");
    query.bindValue(":cin", res);
   // query.bindValue(":cin1", res1);
    return query.exec();



}

QSqlQueryModel *personel::recherche(QString nom,QString prenom)
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from personel where nom like '"+nom+"%' OR prenom like '"+prenom+"%'");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));



    return model;
}





