#ifndef VECTOR_H
#define VECTOR_H
#include <QVector>
#include <typeinfo>

template <class T> class Vector: public QVector<T>
{
public:
    Vector(){ }
    T at(int i) const
    {
        i = i-1;
        Vector v=*this;
        return v[i];
    }
    float getPromedio();
private:
    int size() const
    {

    }
};
#endif // VECTOR_H

template<>float Vector<float>::getPromedio()
{
    float prom = 0;
    Vector v=*this;
    for (int i = 0; i < v.count(); ++i)
    {
        prom += v[i];
    }
    prom = (prom/v.count());
    return prom;
}
template<>float Vector<int>::getPromedio()
{
    float prom = 0;
    Vector v=*this;
    for (int i = 0; i < v.count(); ++i)
    {
        prom += v[i];
    }
    prom = (prom/v.count());
    return prom;
}
template<class T>float Vector<T>::getPromedio()
{
    return -1;
}
