#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "persona.h"
#include <QString>

class Empleado : public Persona
{
public:
    Empleado();
    Empleado(QString nom, int edad, int dni, float sueldo);

    QString get();

private:
    float sueldo;
};

#endif // EMPLEADO_H
