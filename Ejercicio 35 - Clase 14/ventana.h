#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();
    bool eventFilter(QObject *obj, QEvent *event);
private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H
