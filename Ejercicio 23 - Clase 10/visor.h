#pragma once
#include <QCameraViewfinder>

class Visor : public QCameraViewfinder  {
    Q_OBJECT
public:
    explicit Visor(QWidget *parent = 0 ) : QCameraViewfinder(parent)  {   }
};
