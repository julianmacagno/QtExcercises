#pragma once
#include <QDebug>
#include <QWidget>
#include <QCameraInfo>
#include <QCamera>
#include <QTimer>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include "capturador.h"

namespace Ui {
class Principal;
}

class Principal : public QWidget
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();

private:
    Ui::Principal *ui;
    QCamera *camera;
    Capturador *capturador;
    QList<QCameraInfo> camerasList;
    QTimer *timer;
    QImage imagen;
    void paintEvent(QPaintEvent *e);

private slots:
    void slot_iniciarCamara();
    void slot_timeout();
};
