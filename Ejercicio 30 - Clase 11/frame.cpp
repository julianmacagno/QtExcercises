#include "frame.h"
#include "ui_frame.h"

Frame::Frame(QWidget *parent) :    QWidget(parent),    ui(new Ui::Frame)
{
    ui->setupUi(this);
}

Frame::~Frame()
{
    delete ui;
}

void Frame::setImage(QImage imagen)
{
    image = imagen;
    repaint();
}

void Frame::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawImage(0,0,image.scaled(this->width(),this->height()));
}
