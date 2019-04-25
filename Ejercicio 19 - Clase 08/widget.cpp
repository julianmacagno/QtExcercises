#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList lista;
    lista<<"Ricardo"<<"Pepe"<<"Pedro" << "Ramon";
    ui->leTexto1->setList(lista);

}

Widget::~Widget()
{
    delete ui;
}

