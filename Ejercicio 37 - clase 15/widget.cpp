#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pbCliente, SIGNAL(pressed()), this, SLOT(slot_agregar()));
    connect(ui->pbEmpleado, SIGNAL(pressed()), this, SLOT(slot_agregar()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slot_agregar()
{
    QObject* obj = this->sender(); // funcion que devuelve el objeto que lo llamo
    if(obj == ui->pbCliente)
    {
        if(v.size() == 0)
        {
            //Persona *p = new Cliente;
            v.append( new Cliente );
            qDebug() << "se agrega un cliente como primer elemento";
        }
        else
        {
            Cliente *c = dynamic_cast <Cliente*>(v.at(0));

            if( typeid(c) == typeid(Cliente*) && c != NULL)
            {
                 //Persona *p = new Cliente;
                 v.append( new Cliente );
                 qDebug() << "se agrega otro cliente numero" << v.size();
            }
            // si el casteo no se logra (osea v[0] es Empleado...) el puntero es NULL
            else { QMessageBox::critical(this,"ERROR", "v[0] es Empleado"); }
        }
    }
    else
    {
        if (v.size() == 0)
        {
            //Persona *p = new Empleado;
            v.append( new Empleado );
            qDebug() << "Se agrega como primer elemento un Empleado";
        }
        else
        {
            Empleado * pd = dynamic_cast<Empleado*>( v.at( 0 ) );

            if ( typeid(pd) == typeid(Empleado*) && pd != NULL )
            {
                //Persona *p = new Empleado;
                v.append( new Empleado );
                qDebug() << "Se agrega otro empleado numero" << v.size();
            }
            // si el casteo no se logra (osea v[0] es Cliente...) el puntero es NULL
            else { QMessageBox::critical(this,"ERROR", "v[0] es Cliente"); }
        }
    }
}
