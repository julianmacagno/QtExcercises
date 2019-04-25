#include <QApplication>
#include <ventana.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Ventana v;
    v.show();
    return a.exec();
}

//Ejercicio

//Clase Medidor

//-ejecuta un proceso en un hilo
//-es un sigleton
//-bool isok() indica si la conexion es buena o no
//-permite usarlo en otra app y usar:
//    if(medidor::getinstancia->isok())
//    {
//        manager->get(QNetworkrequest(QUrl("http://mi.ubp.edu.ar")))
//    }
//    else
//            QMessageBox::vritical(this,"internet","muy lenta");
