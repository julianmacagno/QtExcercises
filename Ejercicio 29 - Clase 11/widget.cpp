#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :    QWidget(parent),    ui(new Ui::Widget)
{
    ui->setupUi(this);
    original.load(":/mario.jpg");
    imagen = original;

    connect(ui->pbRGBaBGR,SIGNAL(pressed()),this,SLOT(slot_RGBtoBGR()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawImage(0,0,imagen.scaled(this->width(),this->height()));
}

void Widget::slot_RGBtoBGR()
{
    imagen = grab(QRect(0,0,this->width(),this->height())).toImage();

    for(int i=0;i<imagen.width();i++)
    {
        for(int j=0;j<imagen.height();j++)
        {
            QRgb rgb = imagen.pixel(i,j);
            QRgb nuevo = qRgb(qBlue(rgb), qGreen(rgb), qRed(rgb));
            imagen.setPixel(i,j,nuevo);
        }
    }

    repaint();
}
