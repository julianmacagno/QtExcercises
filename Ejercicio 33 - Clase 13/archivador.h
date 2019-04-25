#ifndef ARCHIVADOR_H
#define ARCHIVADOR_H

#include <QFile>
#include <QTextStream>
#include <QDebug>

class Archivador
{
private:
    static QFile* file;

public:
    static bool abrir(QString ruta);
    static bool almacenar(QString texto);

};

#endif // ARCHIVADOR_H
