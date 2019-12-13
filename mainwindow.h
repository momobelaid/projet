#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "personel.h"
#include <QMainWindow>
#include<QTimer>
#include<QMediaPlayer>
#include<QDebug>
#include"medcin.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

  //  void on_tabWidget_destroyed();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

void myfunction();


 //   void on_tabpersonel_destroyed();


   void on_lineRNOM_textChanged();





   void on_tabpersonel_destroyed();







   void on_pushButton_6_clicked();



  // void on_lineRNOM_textChanged1();

   void on_pushButton_3_clicked();

   void on_pushButton_7_clicked();

   void on_lineEdit_12_textChanged();

private:
    Ui::MainWindow *ui;
    personel tmppersonel;
    QTimer *timer ;
    medcin tmpmedcin ;




};

#endif // MAINWINDOW_H
