#include "modifier1.h"
#include "ui_modifier1.h"

modifier1::modifier1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifier1)
{
    ui->setupUi(this);
}

modifier1::~modifier1()
{
    delete ui;
}
