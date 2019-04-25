#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
    installEventFilter(this);
    installEventFilter(ui->Esc1);
    installEventFilter(ui->Esc2);
    ui->Esc2->setposXY(-5,-5, 164);
    ui->Esc1->setposXY(-5,-5, 205);
    setMouseTracking(true);
}

Ventana::~Ventana()
{
    delete ui;
}

bool Ventana::eventFilter(QObject *obj, QEvent *event)
{
    if(obj==this)
    {
        if(event->type()==QEvent::MouseMove)
        {
            QMouseEvent *e=static_cast<QMouseEvent*>(event);
            ui->Esc1->mouseMove(e->x(),e->y());
            ui->Esc2->mouseMove(e->x(),e->y());
            return true;
        }
    }
    if(obj==ui->Esc1)
    {
        if(event->type()==QEvent::MouseMove)
        {
            QMouseEvent *e=static_cast<QMouseEvent*>(event);
            ui->Esc1->mouseMove(e->x(),e->y());
            ui->Esc2->mouseMove(e->x(),e->y());
            return true;
        }
    }
    if(obj==ui->Esc2)
    {
        if(event->type()==QEvent::MouseMove)
        {
            QMouseEvent *e=static_cast<QMouseEvent*>(event);
            ui->Esc1->mouseMove(e->x(),e->y());
            ui->Esc2->mouseMove(e->x(),e->y());
            return true;
        }
    }
    return false;
}
