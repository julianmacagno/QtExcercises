#include "form.h"
#include "ui_form.h"

Form::Form(QString ruta, QWidget *parent) :    QWidget(parent),    ui(new Ui::Form)
{
    ui->setupUi(this);
    path = ruta;
    dir.setPath(path);

    namefilters << "*.jpg" << "*.jpeg" << "*.png" << "*.gif";
    files = dir.entryList(namefilters);

    imagen.load(path + files.first());
    i++;

    timer = new QTimer;
    timer->start(100);
    connect(timer,SIGNAL(timeout()),this,SLOT(slot_mostrar()));
}

Form::~Form()
{
    delete ui;
}

void Form::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawImage(0,0,imagen.scaled(this->width(),this->height()));
}

void Form::slot_mostrar()
{
    imagen.load(path + files.at(i));
    i++;

    if(i>=files.size())
    {
        i=0;
    }

    repaint();
}
