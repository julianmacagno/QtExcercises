#ifndef VENTANA_H
#define VENTANA_H
#include <medidor.h>
#include <QWidget>
#include <QNetworkProxyFactory>

namespace Ui {
class Ventana;
}

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();
private slots:
    void conectar();
private:
    Ui::Ventana *ui;
};

#endif // VENTANA_H
