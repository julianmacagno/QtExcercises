#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :    QWidget(parent),    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    for (int i=0 ; i<cameras.size() ; i++)
        qDebug() << cameras.at(i).description();

    QCameraInfo cameraInfo = cameras.at(0);
    camera = new QCamera(cameraInfo);

    camera->setViewfinder(ui->visor);


    connect(ui->pbEncender,SIGNAL(pressed()),this,SLOT(slotPresiono()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotPresiono()
{
     camera->start();
}
