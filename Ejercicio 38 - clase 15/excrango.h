#ifndef EXCRANGO_H
#define EXCRANGO_H

#include <QString>

class ExcRango
{
public:
    ExcRango(QString msg, int i) : msg(msg), index(i){}
    QString getMensaje()
    {
        msg = msg + " " + QString::number(index);
        return msg;
    }

private:
    int index;
    QString msg;
};

#endif // EXCRANGO_H

/*
 * T get(int i)
 * {
 *      if(!(i>=0 && i<libre))  throw ExcRango("fuera de rango", i);
 *      return v[i];
 * }
 *
 *
 * Listado<QString> listado;
 * try {
 *      QString cadena = listado.get(8);
 * }
 * catch (ExcRango e)
 * {
 *      qDebug()<< "el elemento" << e.getI() << "esta" << e.que();
 * }
 * catch (ExcNoExisteArchivo e) {}
 * catch(...){                      // forma mas generica atrapa todas las excepciones
 *
 * }
*/
