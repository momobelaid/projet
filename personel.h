#ifndef PERSONEL_H
#define PERSONEL_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class personel
{public:
    personel();
    personel (int,QString,QString);
    QString get_nom();
    QString get_prenom();

    int get_cin();
    bool ajouter (int cin);
    bool modifier(int,QString,QString);
    QSqlQueryModel * afficher();
    bool supprimer(int);

QSqlQueryModel * recherche(QString,QString);

private:
    QString nom,prenom;
   int cin;
   // int presence;

};

#endif // PERSONEL_H
