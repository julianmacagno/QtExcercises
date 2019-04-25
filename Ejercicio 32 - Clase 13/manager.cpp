#include "manager.h"

Manager * Manager::instancia = NULL;

Manager::Manager( QObject * parent ) : QObject( parent )


{

    connect( Login::getInstancia(), SIGNAL( signal_usuarioValidado( bool, QStringList ) ),
             this, SLOT( slot_ingreso( bool, QStringList ) ) );

    connect( Formulario::getInstancia(), SIGNAL(signal_nuevoUsuario(QStringList)),
             this, SLOT(slot_nuevoUsuario(QStringList)));

    QVector< QStringList > nuevosUsuarios;

    QStringList usuario1;  usuario1 << "carlos" << "123";
    QStringList usuario2;  usuario2 << "miguel" << "1234";
    QStringList usuario3;  usuario3 << "julio" << "12345";

    nuevosUsuarios << usuario1 << usuario2 << usuario3;

    Login::getInstancia()->setBaseUsuarios( nuevosUsuarios );
}


Manager * Manager::getInstancia()
{
    if( instancia == NULL )
    {
        instancia = new Manager();
    }
    return instancia;
}

Manager::~Manager()
{
    if( instancia != NULL )
    {
        delete instancia;
    }
}

void Manager::iniciar()
{
    Login::getInstancia()->iniciar();
}

void Manager::slot_ingreso( bool valido, QStringList usuario )
{
    if ( valido )  {
        Login::getInstancia()->terminar();
        Formulario::getInstancia()->iniciar();
        Formulario::getInstancia()->setWindowTitle( "Bienvenido: " + usuario.at( 0 ) );
    }
    else  {
        Login::getInstancia()->terminar();
    }
}

void Manager::slot_nuevoUsuario(QStringList list)
{
    QVector <QStringList> vector;
    vector << list;
    Login::getInstancia()->setBaseUsuarios(vector);
    Formulario::getInstancia()->close();
    Login::getInstancia()->iniciar();
}
