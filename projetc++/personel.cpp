#include "personel.h"
#include <QDebug>
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
int o=0;
QString res= QString::number(cin);
QString res1= QString::number(o);
query.prepare("INSERT INTO personel (cin, nom, prenom,presence) "
                    "VALUES (:cin, :nom, :prenom,:o)");
query.bindValue(":cin", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":o", res1);


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
bool personel ::modifier(int cin1,int cin, QString nom,QString prenom)
{
    QSqlQuery query;
    QString res= QString::number(cin1);
    QString res1= QString::number(cin);


    query.prepare("UPDATE PERSONEL SET cin='"+res1+"',nom='"+nom+"',prenom='"+prenom+"' where cin='"+res+"'");
    query.bindValue(":cin", res);
    query.bindValue(":cin1", res1);
    return query.exec();



}



