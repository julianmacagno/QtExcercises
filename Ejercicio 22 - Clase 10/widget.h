#pragma once
#include <QWidget>
#include "visor.h"

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
    QCamera *camera;

public slots:
   void slotPresiono();
};
