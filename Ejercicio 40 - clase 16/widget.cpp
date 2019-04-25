#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    bool open = Archivador::abrir("../Ejercicio 40 - clase 16/archivo.txt");
    if(!open)
    {
        qDebug() << "no se pudo abrir el archivo...";
    }

//      CODIGO QUE PEGA PALABRAS EN EL ARCHIVO PERO LA VENTANA NO SE MUESTRA HASTA QUE TERMINE....

//    QString pal("pepepeeppe");
//    for(int i = 0; i < 100; ++i)
//    {
//        ui->listWidget->addItem(pal);
//        pal.append("ja");
//        Archivador::almacenar(pal + "\n");
//    }

    // usamos hilo para ejecutar el programa
    mh = new MiHilo(this);
    mh->start(QThread::HighestPriority);

    connect(mh, &MiHilo::EscribirPalabra, [&] (QString pal)
    {
        ui->listWidget->addItem(pal);
        Archivador::almacenar(pal + "\n");
    });
}

Widget::~Widget()
{
    delete ui;
}
