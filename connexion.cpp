#include "connexion.h"
#include <QSqlError>
Connexion::Connexion(){


                      }
bool Connexion::ouvrirConnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
                           db.setDatabaseName("tfg");
                           db.setUserName("marouadh");//inserer nom de l'utilisateur
                           db.setPassword("maroua");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;

else throw QString ("Erreur Paramétres"+db.lastError().text());
return  test;
}
void Connexion::fermerConnexion()
{db.close();}
