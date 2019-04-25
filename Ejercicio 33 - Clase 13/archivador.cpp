#include "archivador.h"

QFile * Archivador::file = new QFile("../ejercicio33-clase13/registros.txt"); // no anda...

bool Archivador::abrir(QString ruta)
{
    file->setFileName(ruta);
    if(!file->exists())
    {
        return false;
    }
    return file->open(QIODevice::Append | QIODevice::Text);
}

bool Archivador::almacenar(QString texto)
{
    if(!file->isOpen())
    {
        return false;
    }
    //qDebug() << "entra a registrar";
    QTextStream salida(file);
    salida << texto;

    return true;
}
