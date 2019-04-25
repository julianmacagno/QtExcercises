#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :    QWidget(parent),
                                     ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(200,200);
    ui->tuLabel->cambiarTexto("Sos un TuLabel?");
}

Widget::~Widget()
{
    delete ui;
}
