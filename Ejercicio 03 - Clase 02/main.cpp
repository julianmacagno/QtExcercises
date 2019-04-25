#include <iostream>
#include "listado.h"
#include <QDebug>
using namespace std;

int main()
{
    Listado<int> lista(50);

    for(int i = 0; i< 15; i++)
    {
        lista.insert(i,i+1);
    }

    for(int i=0; i< lista.size(); i++)
    {
        qDebug() << lista.get(i);
    }

    return 0;
}
