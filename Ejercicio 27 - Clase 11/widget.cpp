#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :    QWidget(parent),    ui(new Ui::Widget)
{
    ui->setupUi(this);
    original.load(":/mario.jpg");
    imagen = original;

    connect(ui->pbOriginal,SIGNAL(pressed()),this,SLOT(slot_Original()));
    connect(ui->pbRGBaBGR,SIGNAL(pressed()),this,SLOT(slot_RGBtoBGR()));
    connect(ui->pbNegativo,SIGNAL(pressed()),this,SLOT(slot_Negativo()));
    connect(ui->pbEscaladeGrises,SIGNAL(pressed()),this,SLOT(slot_EscalaDeGrises()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawImage(30,30,imagen.scaled(this->width()-30,this->height()-80));
}

void Widget::slot_Original()
{
    imagen = original;
    repaint();
}

//mostrar cada pixel como 255 - valor actual
void Widget::slot_Negativo()
{
    for(int i=0;i<imagen.width();i++)
    {
        for(int j=0;j<imagen.height();j++)
        {
            QRgb rgb = original.pixel(i,j);
            QRgb nuevo = qRgb(255 - qRed(rgb), 255 - qGreen(rgb), 255 - qBlue(rgb));
            imagen.setPixel(i,j,nuevo);
        }
    }

    repaint();
}

//mostrar cada pixel como un YYY=red/3 + green/3 + blue/3
void Widget::slot_EscalaDeGrises()
{
    for(int i=0;i<imagen.width();i++)
    {
        for(int j=0;j<imagen.height();j++)
        {
            QRgb rgb = original.pixel(i,j);
            int yyy = qRed(rgb) / 3 + qGreen(rgb) / 3 + qBlue(rgb) / 3;
            QRgb nuevo = qRgb(yyy,yyy,yyy);
            imagen.setPixel(i,j,nuevo);
        }
    }

    repaint();
}

void Widget::slot_RGBtoBGR()
{
    for(int i=0;i<imagen.width();i++)
    {
        for(int j=0;j<imagen.height();j++)
        {
            QRgb rgb = original.pixel(i,j);
            QRgb nuevo = qRgb(qBlue(rgb), qGreen(rgb), qRed(rgb));
            imagen.setPixel(i,j,nuevo);
        }
    }

    repaint();
}
