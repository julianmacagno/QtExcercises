#include "empleado.h"

Empleado::Empleado()
{

}

Empleado::Empleado(QString nom, int edad, int dni, float sueldo) : Persona(nom, edad, dni), sueldo(sueldo)
{

}

QString Empleado::get()
{
    return "empleado";
}
