#include "login.h"
#include "ui_login.h"

Login::Login( QWidget * parent ) : QWidget( parent ),
                                   ui( new Ui::Login )
{
    ui->setupUi( this );

    QStringList usuarioAdmin;
    usuarioAdmin << "admin" << "nimda";

    usuarios << usuarioAdmin;

    connect( ui->pbIngresar, SIGNAL( pressed() ), this, SLOT( slot_validarUsuario() ) );
    connect( ui->leClave, SIGNAL( returnPressed() ), this, SLOT( slot_validarUsuario() ) );
}

Login::~Login()
{
    delete ui;
}

void Login::setBaseUsuarios( QVector< QStringList > usuarios )
{
    this->usuarios << usuarios;
}

void Login::slot_validarUsuario()
{
    QStringList usuarioIngresado;
    usuarioIngresado << ui->leUsuario->text() << ui->leClave->text();

    if ( this->usuarios.contains( usuarioIngresado ) )
        emit signal_usuarioValidado( true, usuarioIngresado );
    else
        emit signal_usuarioValidado( false, usuarioIngresado );
}
