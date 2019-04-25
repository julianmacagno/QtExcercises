#pragma once
#include<QLabel>
#include<QString>

class TuLabel : public QLabel
{
public:
    TuLabel(QWidget *parent = 0);

    void cambiarTexto(QString nuevoTexto);
};
