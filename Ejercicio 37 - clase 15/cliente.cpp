#include "cliente.h"

Cliente::Cliente()
{

}

Cliente::Cliente(QString nom, int edad, int dni, int cuenta) : Persona(nom, edad, dni), cuenta(cuenta)
{

}
