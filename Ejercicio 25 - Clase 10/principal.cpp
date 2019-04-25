#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent) :    QWidget(parent),    ui(new Ui::Principal), camera(new QCamera(this))
{
    ui->setupUi(this);    

    ui->slider->setValue(3000);
    timer = new QTimer;
    timer->setInterval(ui->slider->value());
    ui->lSlider->setText(QString::number(ui->slider->value()));

    path = QFileDialog::getExistingDirectory(this, "Seleccione la ruta para guardar", "/");
    if(path == "")
        return;

    path += "/";

    camerasList = QCameraInfo::availableCameras();
    for (int i=0 ; i<camerasList.size() ; i++)
    {
       ui->cbSeleccionarCamara->addItem(camerasList.at(i).description());
    }

    connect(ui->pbIniciarCamara, SIGNAL(clicked()), this, SLOT(slot_iniciarCamara()));
    connect(ui->slider,SIGNAL(valueChanged(int)),this,SLOT(slot_setIntervalo(int)));
    connect(timer,SIGNAL(timeout()),this,SLOT(slot_timeout()));
    connect(ui->pbMostrar,SIGNAL(pressed()),this,SLOT(slot_mostrar()));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::slot_iniciarCamara()
{
    QCameraInfo cameraInfo = camerasList.at(ui->cbSeleccionarCamara->currentIndex());

    camera = new QCamera(cameraInfo, this);    
    camera->setViewfinder(ui->visor);

    capturador = new QCameraImageCapture(camera);

    camera->start();
    timer->start();
}

void Principal::slot_setIntervalo(int value)
{
    timer->setInterval(value);
    ui->lSlider->setText(QString::number(ui->slider->value()));
}

void Principal::slot_timeout()
{
    QDate fecha = QDate::currentDate();
    QTime hora = QTime::currentTime();

    QString filename = path + QString::number(fecha.day()) + "-" + QString::number(fecha.month())
            + "-" + QString::number(fecha.year()) + " " + QString::number(hora.hour()) +
            "h-" + QString::number(hora.minute()) + "m-" + QString::number(hora.second()) + "s";

    capturador->setCaptureDestination(QCameraImageCapture::CaptureToFile);
    QImageEncoderSettings imgEncoderStgs;
    imgEncoderStgs.setCodec("image/jpeg");
    imgEncoderStgs.setResolution(800,600);
    capturador->setEncodingSettings(imgEncoderStgs);
    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->searchAndLock();
    capturador->capture(filename);
    camera->unlock();
}

void Principal::slot_mostrar()
{
    timer->stop();
    Form *form = new Form(path);
    form->show();
    //this->hide();
}
