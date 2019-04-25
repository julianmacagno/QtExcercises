#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent) :    QWidget(parent),    ui(new Ui::Principal), camera(new QCamera(this))
{
    ui->setupUi(this);    
    capturador = new Capturador;
    timer = new QTimer;

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
    QPainter painter(this);
    imagen = imagen.mirrored(true,true);

    if(!imagen.isNull())
    {    
        //mostrar cada pixel como un YYY=red/3 + green/3 + blue/3
        for(int i=0; i<imagen.width(); i++)
        {
            for(int j=0; j<imagen.height(); j++)
            {
                QRgb rgb = imagen.pixel(i,j);
                int yyy = qRed(rgb) / 3 + qGreen(rgb) / 3 + qBlue(rgb) / 3;
                QRgb nuevo = qRgb(yyy,yyy,yyy);
                imagen.setPixel(i,j,nuevo);
            }
        }
        painter.drawImage((this->width()-imagen.width())/2, (this->height()-imagen.height())/2, imagen);
    }
}

void Principal::slot_iniciarCamara()
{
    QCameraInfo cameraInfo = camerasList.at(ui->cbSeleccionarCamara->currentIndex());

    camera = new QCamera(cameraInfo, this);    
    camera->setViewfinder(capturador);

    camera->start();

    timer->setInterval(30);
    timer->start();
}

void Principal::slot_timeout()
{
    QVideoFrame a = capturador->getFrameActual();
    QImage::Format format = QVideoFrame::imageFormatFromPixelFormat(a.pixelFormat());
    imagen = QImage(a.bits(), a.width(), a.height(), a.bytesPerLine(), format);
    repaint();
}
