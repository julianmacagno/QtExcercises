#include <QString>
#include <QDebug>


class Real {
private:
    int colores;

public:
    Real(int colores) : colores(colores)  {  }
    int getDato()  {  return colores;  }
};


class Virtual {
private:
    int bits;

public:
    Virtual(int bits) : bits(bits)  {  }
    int getDato()  {  return bits;  }
};


class Persona {
private:
    int edad;

public:
    Persona(int edad) : edad(edad)  {  }
    int getDato()  {  return edad;  }
};
