#include "widget.h"
#include "admindb.h"
#include <QApplication>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    AdminDB admindb;
    if(admindb.conectar("../Ejercicio 26 - Clase 10/DataEntry"))
    {
        qDebug() << "conexion exitosa...";
    }
    else qDebug() << "no se pudo conectar a la base";

    return a.exec();
}
