#include "poste.h"
#include <QDebug>
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);

    Poste poste1(20);
    Poste poste2(30);
    Poste poste3(10);

    Poste poste4 = poste1 + poste2;

    qDebug() << poste4.getAltura();

    poste4++;

    qDebug() << poste4.getAltura();

    poste4 = poste4 + 100;

    qDebug() << poste4.getAltura();

    return a.exec();
}
