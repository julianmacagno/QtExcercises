#include "alta.h"
#include "ui_alta.h"

Alta::Alta(QWidget *parent) : QWidget(parent), ui(new Ui::Alta)
{
    ui->setupUi(this);

    this->ui->leDni->setValidator(new QIntValidator(this));
    this->ui->leDni->setMaxLength(8);

    connect(this->ui->leNombre, SIGNAL(textChanged(QString)), this, SLOT(slot_autocomplete(QString)));
    connect(this->ui->leApellido, SIGNAL(textChanged(QString)), this, SLOT(slot_autocomplete(QString)));
}

Alta::~Alta()
{
    delete ui;
}

void Alta::slot_autocomplete(QString)
{
    *this->ui->leNombreCompleto = *this->ui->leNombre + " " + *this->ui->leApellido;
}
