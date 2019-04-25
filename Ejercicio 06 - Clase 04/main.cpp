#include "alta.h"
#include "lineadetexto.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Alta w;
    w.show();

    return a.exec();
}
