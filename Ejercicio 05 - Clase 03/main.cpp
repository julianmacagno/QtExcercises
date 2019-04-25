#include <iostream>
#include "listado.h"
#include <QDebug>
#include <QWidget>
#include <QApplication>
#include <QString>

using namespace std;

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    Listado<QWidget*> lista(10);

    for(int i = 0; i< 10; i++)
    {
        lista.insert(i,new QWidget);
    }

    for(int i=0; i<lista.size(); i++)
    {
        lista.get(i)->setWindowTitle("Ventana " + QString::number(i+1));
        lista.get(i)->show();
    }

    return a.exec();
}
