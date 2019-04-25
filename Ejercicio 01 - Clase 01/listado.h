#pragma once
#include<QDebug>

template <class T> class Listado
{
private:
    //n tamaño del arreglo; libre indice de la primera casilla libre
    int n, libre;
    T *v;

public:
    Listado(int n = 10) : n(n), libre(0), v(new T[n]) { }
    bool insert(int i, T nuevo);
    bool erase(int i, bool front_or_Back);
    bool borrar(int i);
    int size() { return libre; }
    void clear() { libre = 0; }
    T get(int i) { return v[i]; }
};

template<class T> bool Listado<T>::insert(int i, T nuevo)
{
    if(libre < n && i > 0)
    {
        //recorre de der a izq dezplazando los elementos hasta la casilla indicada
        for(int j = libre; j != i; j--)
        {
             v[j] = v[j-1];
        }

        v[i] = nuevo;
        libre++;
        return true;
    }

    return false;
}

//true remueve desde el inicio; false desde el final
template<class T> bool Listado<T>::erase(int i, bool front_or_Back)
{
    if(i < libre)
    {
        //si es verdadero, removemos desde el inicio; sino simplemente acortamos el tamaño
        if(front_or_Back)
        {
            for(int j=0; j<libre-i; j++)
            {
                v[j] = v[j+i];
            }
        }

        //esta linea remueve desde el final i casillas. Si se las mavio previamente;
        //implica que "removio las primeras i casillas"
        libre -=i;
        return true;
    }

    return false;
}

template<class T> bool Listado<T>::borrar(int i)
{
    i--;

    if(i<libre)
    {
        for(int j=i; j<libre; j++)
        {
            v[j] = v[j+1];
        }

        libre--;
        return true;
    }

    return false;
}








