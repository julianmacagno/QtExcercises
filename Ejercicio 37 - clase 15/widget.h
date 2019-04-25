#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
#include <QMessageBox>
#include "cliente.h"
#include "empleado.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    QVector < Persona* > v;

private slots:
    void slot_agregar();
};

#endif // WIDGET_H
