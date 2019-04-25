#include "principal.h"
#include "ui_principal.h"
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <QImage>



Principal::Principal(QWidget *parent) : QWidget(parent), ui(new Ui::Principal),rotacion(0), transX(0), transY(0)
{
        ui->setupUi(this);
        this->installEventFilter(this);
        image = new QImage(":/imagen/spinner");
        timer = new QTimer;
        timer->setInterval(20);
        connect(timer, SIGNAL(timeout()), SLOT(slot_ciclos()));
        timer->start();
}

Principal::~Principal()
{
        delete ui;
}

void Principal::paintEvent(QPaintEvent * e)
{
        QPainter* p = new QPainter(this);
        p->translate(this->width()/2 + transX, this->height()/2 + transY);
        p->rotate(50*++rotacion);
        p->drawImage(-image->width()/2, -image->height()/2, *image);
        if (rotacion>=360)
                rotacion = 0;
}

void Principal::slot_ciclos()
{
        this->repaint();
}

bool Principal::eventFilter(QObject *obj, QEvent *e)
{
        if (obj == this)
        {
                if (e->type() == QEvent::KeyPress)  // si el evento es el que corresponde a una tecla presionada
                {
                        int key = static_cast<QKeyEvent*>(e)->key();
                        switch(key)
                        {
                        case Qt::Key_Up:
                                transY -= 10;
                                break;
                        case Qt::Key_Down:
                                transY += 10;
                                break;
                        case Qt::Key_Left:
                                transX -= 10;
                                break;
                        case Qt::Key_Right:
                                transX += 10;
                                break;
                        case Qt::Key_Escape:
                                this->close();
                                break;
                        }
                        return true;
                }
        }
        // Esto es para que la clase base decida si necesita controlar los eventos
        // que no estamos capturando nosotros.
        return QWidget::eventFilter(obj, e);
}
