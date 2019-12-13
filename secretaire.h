#ifndef SECRETAIRE_H
#define SECRETAIRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QDialog>


namespace Ui {
class secretaire;
}

class secretaire : public QDialog
{
    Q_OBJECT

public:
    explicit secretaire(QWidget *parent = nullptr);
    ~secretaire();
    secretaire();
    secretaire(int,QString,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_specialite();
    int get_cin();


private slots:
    void on_pushButton_clicked();

private:
    Ui::secretaire *ui;
    QString nom,prenom,specialite ;
    int cin ;
};

#endif // SECRETAIRE_H
