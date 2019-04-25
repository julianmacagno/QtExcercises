#include "widget.h"
#include "principal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principal w;
    w.showMaximized();

    return a.exec();

/*
 *EJERCICIO:
 *          que la imagen rote sobre su centro
 *          cuando el usuario desplace Ventana, que al soltarlo se centre en la pantalla
 *
*/
}
