#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario( QWidget * parent ) : QWidget( parent ),
                                             ui( new Ui::Formulario )
{
    ui->setupUi( this );

    QStringList usuario1;   usuario1 << "98765" << "carlos" << "vazquez";
    QStringList usuario2;   usuario2 << "45632" << "juan" << "alvarez";
    QStringList usuario3;   usuario3 << "12365" << "pedro" << "perez";

    db << usuario1 << usuario2 << usuario3;

    connect(ui->pbAlta, SIGNAL(pressed()), this, SLOT(slot_validarAlta()));
}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::setDB(QVector<QStringList> db)
{
    this->db = db;
}

void Formulario::slot_validarAlta()
{
    QStringList usuarioIngresado;
    usuarioIngresado << ui->leLegajo->text() << ui->leNombre->text() << ui->leApellido->text();

    if(this->db.contains(usuarioIngresado))
    {
        emit signal_AltaFormulario(true, usuarioIngresado);
    }
    else emit signal_AltaFormulario(false, usuarioIngresado);
}
