#include "widget.h"
#include "listado.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    Listado <int>l;
    l.add(8);
    l.add(12);

    // encerramos con try y catch el codigo que puede ocasionar corrupcion de memoria...
    try {
    qDebug() << l.get(5);

    }
    catch(ExcRango e) {
        qDebug() << e.getMensaje(); // mostramos el mensaje de excepcion..
    }

    return a.exec();
}
