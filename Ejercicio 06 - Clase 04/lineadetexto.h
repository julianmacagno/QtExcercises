#pragma once
#include <QApplication>
#include <QLineEdit>
#include <QString>

class LineaDeTexto : public QLineEdit  {
     Q_OBJECT

public:
    LineaDeTexto(QWidget *parent=0);
    LineaDeTexto(QString texto, QWidget *parent=0);
    LineaDeTexto(const LineaDeTexto &linea, QWidget *parent=0);

    LineaDeTexto& operator=(const LineaDeTexto &linea);
    LineaDeTexto operator+(const LineaDeTexto &linea);
    LineaDeTexto operator+(QString string);
};
