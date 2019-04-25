#pragma once
#include <QString>
#include <typeinfo>

template<class T> class Mundo : public T
{
private:
    QString nombre;

public:
    Mundo(QString nombre, int dato) : T(dato), nombre(nombre) {}
    QString toString();
};

template<class T> QString Mundo<T>::toString()
{
    QString descripcion = "Mundo " + nombre + " de " + QString::number(T::getDato());

    if(typeid(T) == typeid(Real))
    {
        descripcion.append(" colores.");
    }

    else
    {
        if(typeid(T) == typeid(Virtual))
        {
            descripcion.append(" bits.");
        }

        else
        {
            descripcion = "Mundo imposible.";
        }
    }

    return descripcion;
}
