#include "mihilo.h"

MiHilo::MiHilo(QObject *parent) : QThread(parent)
{

}

void MiHilo::run()
{
    QString pal("abcdefghijklmnopqrstuvwxyz");
    for(int i = 0; i < 100; ++i)
    {
        emit EscribirPalabra(pal);
        this->msleep(100);
        pal.append("ja");
    }
}
