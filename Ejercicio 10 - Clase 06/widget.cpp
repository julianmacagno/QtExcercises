#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    db = new AdminDB;
    qDebug() << db->conectar("../Ejercicio 10 - Clase 06/DataEntry");// cuidado la Direccion
    crearCompleters();
    connect(ui->Almacenar,SIGNAL(pressed()),this,SLOT(almacenar()));

}
Widget::~Widget()
{
    delete ui;
}

void Widget::crearCompleters()
{
    ui->LNombre->setCompleter(setCompleters("Nombre"));
    ui->LApellido->setCompleter(setCompleters("Apellido"));
    ui->LCarrera->setCompleter(setCompleters("Carrera"));
}

QStringList Widget::toStringList(QVector<QStringList> v)
{
    QStringList list;
    for (int i = 0; i < v.count(); ++i)
    {
        list.append(v.at(i));
    }
    return list;
}

QCompleter *Widget::setCompleters(QString nombre)
{
    QStringList list;
    list = toStringList(db->select(nombre));
    QCompleter *Completer = new QCompleter(list,this);
    return Completer;
}

void Widget::almacenar()
{
    if(!ui->LNombre->text().isEmpty() && !ui->LApellido->text().isEmpty()
            && !ui->LLegajo->text().isEmpty() && !ui->LCarrera->text().isEmpty())
    {
        QVector<QString>dato;
        dato<<ui->LNombre->text()<<ui->LApellido->text()<<ui->LLegajo->text()<<ui->LCarrera->text();
        QVector<QString>columnas;
        columnas<<"Nombre"<<"Apellido"<<"Legajo"<<"Carrera";
        db->insertLog(dato,columnas);
        crearCompleters();
        ui->LNombre->clear();
        ui->LApellido->clear();
        ui->LLegajo->clear();
        ui->LCarrera->clear();
    }
}
