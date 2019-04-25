#include "persona.h"

Persona::Persona()
{

}

Persona::Persona(QString nom, int edad, int dni) : nombre(nom), edad(edad), dni(dni)
{

}

QString Persona::toString()
{
    QString pers = "nombre: " + nombre + " edad: " + edad + " dni: " + dni;
    return pers;
}
