#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    QNetworkProxyFactory::setUseSystemConfiguration(true);
    connect(ui->pushButton,SIGNAL(pressed()),this,SLOT(conectar()));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::conectar()
{
    if(!ui->Lurl->text().isEmpty())
    {
        QString dir = "https://";
        dir.append(ui->Lurl->text());
        qDebug()<<dir;
        if(Medidor::getInstancia()->isOk(dir))
        {
            ui->conectividad->setText("hay conexion");
        }
        else
        {
            ui->conectividad->setText("no hay conexion");
        }
    }
}
