#include <QCoreApplication>
#include <QDebug>

void funcion(std::type_info info)
{
    qDebug() << info.name();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << typeid(char).name();
    int x = 10;
    qDebug() << typeid(x).name();
    const std::type_info & ref = typeid(int);
    qDebug() << ref.name();

    funcion(ref);   // no compila porque el constructor copia de type_info es privado...

    return a.exec();
}
