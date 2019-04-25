#include "ventana.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ventana w;
//    w.showMaximized();
    w.show();

    return a.exec();
}
