#include "visor.h"
#include "ui_visor.h"

Visor::Visor(QWidget *parent) :    QCameraViewfinder(parent),    ui(new Ui::Visor)
{
    ui->setupUi(this);



//    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
//    for (int i=0 ; i<cameras.size() ; i++)
//        qDebug() << cameras.at(i).description();


//    QCameraInfo cameraInfo = cameras.at(0);
//    QCamera * camera = new QCamera(cameraInfo);

//    QCameraViewfinder *visor = new QCameraViewfinder;

//    camera->setViewfinder(visor);
//    camera->start();

//    visor->show();

}

Visor::~Visor()
{
    delete ui;
}
