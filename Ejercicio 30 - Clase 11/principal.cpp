#include "principal.h"
#include "ui_principal.h"
#include <QDebug>

Principal::Principal(QWidget *parent) :    QWidget(parent),    ui(new Ui::Principal), camera(new QCamera(this))
{
    ui->setupUi(this);    
    capturador = new Capturador;
    timer = new QTimer;

    widgets[0] = ui->frame1;
    widgets[1] = ui->frame2;
    widgets[2] = ui->frame3;
    widgets[3] = ui->frame4;
    widgets[4] = ui->frame5;
    widgets[5] = ui->frame6;


    camerasList = QCameraInfo::availableCameras();
    for (int i=0 ; i<camerasList.size() ; i++)
    {
       ui->cbSeleccionarCamara->addItem(camerasList.at(i).description());
    }

    connect(ui->pbIniciarCamara, SIGNAL(clicked()), this, SLOT(slot_iniciarCamara()));
    connect(timer,SIGNAL(timeout()),this,SLOT(slot_timeout()));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *e)
{

}

void Principal::slot_iniciarCamara()
{
    QCameraInfo cameraInfo = camerasList.at(ui->cbSeleccionarCamara->currentIndex());

    camera = new QCamera(cameraInfo, this);    
    camera->setViewfinder(capturador);

    camera->start();

    timer->setInterval(1000);
    timer->start();
}

void Principal::slot_timeout()
{
    QVideoFrame a = capturador->getFrameActual();
    QImage::Format format = QVideoFrame::imageFormatFromPixelFormat(a.pixelFormat());
    imagen = QImage(a.bits(), a.width(), a.height(), a.bytesPerLine(), format);

    imagen = imagen.mirrored(true,true);

    widgets[i]->setImage(imagen);
    i++;
    if(i>5)
        i=0;
}
