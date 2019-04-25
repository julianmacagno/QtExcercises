#include "alta.h"
#include "ui_alta.h"

Alta::Alta(QWidget *parent) : QWidget(parent), ui(new Ui::Alta)
{
    ui->setupUi(this);

    ui->leDni->setValidator(new QIntValidator(this));
    ui->leDni->setMaxLength(8);

    listN<<"pepe"<<"Antonio"<<"Diego";
    ui->leNombre->setList(listN);
    listP<<"Lopez"<<"Roberts"<<"Macagno"<<"Filipi";
    ui->leApellido->setList(listP);
    connect(this->ui->leNombre, SIGNAL(textChanged(QString)), this, SLOT(slot_autocomplete(QString)));
    connect(this->ui->leApellido, SIGNAL(textChanged(QString)), this, SLOT(slot_autocomplete(QString)));
    connect(this->ui->pbAlta,SIGNAL(pressed()),this,SLOT(slot_alta()));
}

Alta::~Alta()
{
    delete ui;
}

void Alta::slot_autocomplete(QString)
{
    *this->ui->leNombreCompleto = *this->ui->leNombre + " " + *this->ui->leApellido;
}

void Alta::slot_alta()
{
    if(!ui->leNombre->text().isEmpty()&&!ui->leDni->text().isEmpty()&&!ui->leApellido->text().isEmpty())
    {
       if(!listN.contains(ui->leNombre->text()))
       {
           listN<<ui->leNombre->text();
           ui->leNombre->setList(listN);
       }
       if(!listP.contains(ui->leApellido->text()))
       {
           listP<<ui->leApellido->text();
           ui->leApellido->setList(listP);
       }
    }
    ui->leApellido->clear();
    ui->leDni->clear();
    ui->leNombre->clear();
    ui->leNombreCompleto->clear();
}
