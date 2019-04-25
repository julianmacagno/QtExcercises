#include <QCoreApplication>
#include <vector.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Vector <int> vi;
    vi<< 1<< 2 << 3 << 7;
    qDebug() << vi.at(1);
    qDebug() << vi.getPromedio();
    Vector <float> vf;
    vf<< 1.3<< 2.5 << 3.4;
    qDebug() << vf.at(1);
    qDebug() << vf.getPromedio();
    Vector <QString> vs;
    vs<< "pepe"<< "ema" << "pipo";
    qDebug() << vs.at(1);
    qDebug() << vs.getPromedio();
    return a.exec();
}
