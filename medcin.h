#ifndef MEDCIN_H
#define MEDCIN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class medcin
{
public:
    medcin();
    medcin (QString,QString,QString,int);
    QString get_nom1();
    QString get_prenom1() ;
    QString get_specialite1();
    int get_cin1();
    bool ajouter1( );
    QSqlQueryModel * afficher1();
    QSqlQueryModel * recherche1(QString,QString);
    bool supprimer1(int);
    bool modifier1(int);

private:
    QString nom1,prenom1,specialite1;
    int cin1;
};

#endif // MEDCIN_H
