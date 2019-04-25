#include <QApplication>
#include "tipos.h"
#include "mundo.h"

int main(int argc, char **argv)  {
    QApplication a(argc, argv);

    Mundo<Real> mundo1("Tierra", 10000);
    Mundo<Virtual> *mundo2 = new Mundo<Virtual>("StarCraft", 64);
    Mundo<Persona> mundo3("Hola", 200);

    qDebug() << mundo1.toString();
    qDebug() << mundo2->toString();
    qDebug() << mundo3.toString();

    return a.exec();
}
