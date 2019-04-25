#include <QApplication>
#include "manager.h"

int main( int argc, char ** argv )
{
    QApplication a( argc, argv );

    Manager::getInstancia()->iniciar();

    return a.exec();
}
