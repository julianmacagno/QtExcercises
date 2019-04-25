#ifndef PERSONA_H
#define PERSONA_H

#include<QString>
#include <QDebug>

class Persona
{
public:
    Persona();
    explicit Persona(QString nom, int ed, int dni);

    virtual ~Persona(){ qDebug() << "destr. P"; }

    virtual QString get() { return "persona";}
    virtual QString toString();

private:
    QString nombre;
    int edad, dni;
};

#endif // PERSONA_H
