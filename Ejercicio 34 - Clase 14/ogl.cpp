#include "ogl.h"

#include <QTimer>
#include <QKeyEvent>
#include <QDebug>

Ogl::Ogl()
{

}

void Ogl::setTimer(int timerIntervalo)  {
    if(timerIntervalo > 0)  {
        timerIntervalo = qMin(15, timerIntervalo);
        timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(slot_timeout()));
        timer->start(timerIntervalo);
    }
}

void Ogl::keyPressEvent(QKeyEvent *e)  {
    switch( e->key() )  {
        case Qt::Key_Escape:
            close();
    }
}

void Ogl::slot_timeout()  {
    this->timeout();
}

void Ogl::timeout()  {
    this->updateGL();
}


