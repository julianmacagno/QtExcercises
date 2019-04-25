#include "formulario.h"
#include "ui_formulario.h"

Formulario * Formulario::instancia= NULL;

Formulario::Formulario( QWidget * parent ) : QWidget( parent ),
                                             ui( new Ui::Formulario )
{
    ui->setupUi( this );

    connect( ui->pbAgregar, SIGNAL(clicked(bool)),
             this, SLOT(slot_nuevoUsuario()));
    connect( ui->leClave, SIGNAL(returnPressed()),
             this, SLOT(slot_nuevoUsuario()));

}

void Formulario::slot_nuevoUsuario()
{
    QStringList l;
    l << ui->leNombre->text() << ui->leClave->text();
    emit signal_nuevoUsuario(l);
}

Formulario *Formulario::getInstancia()
{
    if(instancia==NULL){

        instancia= new Formulario;
    }
    return instancia;
}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::iniciar()
{
    ui->leNombre->clear();
    ui->leClave->clear();
    ui->leNombre->setFocus();
    this->show();

}
