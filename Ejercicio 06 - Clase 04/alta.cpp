#include "alta.h"
#include "ui_alta.h"

Alta::Alta(QWidget *parent) : QWidget(parent), ui(new Ui::Alta)
{
    ui->setupUi(this);

    connect(this->ui->pbSumar, SIGNAL(pressed()), this, SLOT(slot_sumar()));
}

Alta::~Alta()
{
    delete ui;
}

void Alta::slot_sumar()
{
    *this->ui->leLinea3 = *this->ui->leLinea1 + " " + *this->ui->leLinea2;
}
