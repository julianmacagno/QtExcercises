#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) : QWidget(parent), ui(new Ui::Ventana) {
    ui->setupUi(this);
    this->installEventFilter(this);
    img = new QImage(":/resources/chrome.png");
    timer = new QTimer;
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_cicles()));
    timer->start();
}

Ventana::~Ventana() {
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *e) {
    QPainter *p = new QPainter(this);
    p->translate(this->width()/2+tx, this->height()/2+ty);
    p->rotate(5*++rot);
    p->drawImage(-this->img->width()/2, -this->img->height()/2, *this->img);
    if (this->rot >= 360) this->rot = 0;
}

bool Ventana::eventFilter(QObject *o, QEvent *e)
{
    if (o == this)
    {
        if (e->type() == QEvent::Move)
        {
            this->move(QApplication::desktop()->screen()->rect().center() - this->rect().center());
        }

        if (e->type() == QEvent::KeyPress)
        {
            int key = static_cast<QKeyEvent*>(e)->key();

            switch(key)
            {
            case Qt::Key_Up:
                ty -= 5;
                break;
            case Qt::Key_Down:
                ty += 5;
                break;
            case Qt::Key_Left:
                tx -= 5;
                break;
            case Qt::Key_Right:
                tx += 5;
                break;
            case Qt::Key_Escape:
                this->close();
                break;
            }

            // stop propagation
            return true;
        }

        if(e->type() == QEvent::MouseButtonDblClick)
        {
            int key = static_cast<QMouseEvent*>(e)->button();

            switch (key)
            {
            case Qt::LeftButton:
                this->close();
                break;

            case Qt::RightButton:
                this->close();
                break;

            default:
                break;
            }

            return true;
        }
    }

    // unhandled events go to base class
    return QWidget::eventFilter(o, e);
}

void Ventana::slot_cicles()
{
    this->repaint();
}
