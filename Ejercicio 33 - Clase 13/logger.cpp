#include "logger.h"

Logger * Logger::instancia = NULL;

Logger::Logger(QObject *parent) : QObject(parent), login(new Login), formulario(new Formulario), file(new Archivador)
{
    file->abrir("../Ejercicio 33 - Clase 13/registros.txt");

    QVector< QStringList > nuevosUsuarios;

    QStringList usuario1;   usuario1 << "carlos" << "123";
    QStringList usuario2;   usuario2 << "miguel" << "1234";
    QStringList usuario3;   usuario3 << "julio" << "12345";

    nuevosUsuarios << usuario1 << usuario2 << usuario3;

    login->setBaseUsuarios(nuevosUsuarios);

    connect(login, SIGNAL(signal_usuarioValidado(bool,QStringList)), this, SLOT(slot_ingreso(bool, QStringList)));
    connect(formulario, SIGNAL(signal_AltaFormulario(bool,QStringList)), this, SLOT(slot_AltaFormulario(bool,QStringList)));
}

Logger *Logger::getInstancia()
{
    if(instancia == NULL)
    {
        instancia = new Logger();
    }
    return instancia;
}

Logger::~Logger()
{
    if(instancia != NULL)
    {
        delete instancia;
    }
}

void Logger::iniciar()
{
    login->show();
}

void Logger::registrarEvento(QString evento)
{
    QString date = QDate::currentDate().toString();
    QString time = QTime::currentTime().toString();

    QString total = evento + "\t" + date + "\t\t" + time;
    file->almacenar(total + "\n");
}

void Logger::slot_ingreso(bool valido, QStringList usuario)
{
    if ( valido )
    {
        login->hide();
        formulario->show();
        this->registrarEvento("APERTURA DE FORMULARIO");
        formulario->setWindowTitle( "Bienvenido: " + usuario.at( 0 ) );
    }
    else
    {
        login->close();
        this->registrarEvento("DATOS INCORRECTOS DE USUARIO");
        this->registrarEvento("CIERRE DE LA APP");
    }
}

void Logger::slot_AltaFormulario(bool valido, QStringList usuario)
{
    if( valido )
    {
        // llamamos a registrarEvento para que lo pegue en txt (valido)

        this->registrarEvento("ALTA DE FORMULARIO");
        QMessageBox::information(this->formulario,"info","bienvenido: " + usuario.at(1));
    }
    else
    {
        // llamamos a registrarEvento para que lo guarde como incorrecto

        this->registrarEvento("ERROR DE FORMULARIO");
        QMessageBox::information(this->formulario, "info", "error de carga...");
    }
    if(formulario->close()) this->registrarEvento("CIERRE DE APP");
}

