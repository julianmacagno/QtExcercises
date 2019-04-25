#ifndef VISOR_H
#define VISOR_H

#include <QWidget>
#include <QCameraViewfinder>
#include <QCamera>
#include <QDebug>
#include <QCameraInfo>



namespace Ui {
class Visor;
}

class Visor : public QCameraViewfinder
{
    Q_OBJECT

public:
    explicit Visor(QWidget *parent = 0);
    ~Visor();

private:
    Ui::Visor *ui;
};

#endif // VISOR_H
