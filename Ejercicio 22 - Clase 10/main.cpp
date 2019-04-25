#include "widget.h"
#include <QApplication>
#include <QCameraInfo>
#include <QCamera>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QCameraInfo cameraInfo = cameras.at(0);
//    QCamera * camera = new QCamera(cameraInfo);

//    QCameraViewfinder *visor = new QCameraViewfinder;

//    camera->setViewfinder(visor);
//    camera->start();

//    visor->show();
    Widget w;
    w.show();

    return a.exec();
}
