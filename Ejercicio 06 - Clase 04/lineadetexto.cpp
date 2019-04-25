#include "lineadetexto.h"

LineaDeTexto::LineaDeTexto(QWidget *parent) : QLineEdit(parent) {

}

LineaDeTexto::LineaDeTexto(QString texto, QWidget *parent) : QLineEdit(texto, parent) {

}

LineaDeTexto::LineaDeTexto(const LineaDeTexto &linea, QWidget *parent) : QLineEdit(parent) {
    this->setText(linea.text());
}

LineaDeTexto& LineaDeTexto::operator=(const LineaDeTexto &linea) {
    this->setText(linea.text());
    return *this;
}

LineaDeTexto LineaDeTexto::operator+(const LineaDeTexto &linea) {
    return LineaDeTexto(this->text() + linea.text());
}

LineaDeTexto LineaDeTexto::operator+(QString string) {
    return LineaDeTexto(this->text() + string);
}
