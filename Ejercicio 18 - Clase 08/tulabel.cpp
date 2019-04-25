#include "tulabel.h"

TuLabel::TuLabel(QWidget *parent): QLabel(parent)
{

}

void TuLabel::cambiarTexto(QString nuevoTexto)
{
    this->setText(nuevoTexto);
}
