#ifndef CLIENTE_H
#define CLIENTE_H

#include "persona.h"
#include <QString>

class Cliente : public Persona
{
public:
    Cliente();
    Cliente(QString nom, int edad, int dni, int cuenta);

    ~Cliente(){ qDebug() << "destr. C"; }

    QString get() { return "cliente";}

private:
    int cuenta;
};

#endif // CLIENTE_H
