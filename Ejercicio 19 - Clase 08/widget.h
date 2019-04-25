#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "lineadetexto.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void suma();

private:
    Ui::Widget *ui;
    LineaDeTexto leSuma;
};

#endif // WIDGET_H
