#pragma once
#include <QDebug>
#include <QWidget>
#include <QCameraInfo>
#include <QCamera>
#include <QCameraImageCapture>
#include <QTimer>
#include <QDate>
#include <QTime>
#include <QString>
#include <QImageEncoderSettings>
#include <QFileDialog>

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
    QCameraImageCapture *capturador;
    QList<QCameraInfo> camerasList;
    QTimer *timer;
    QFile *fileMaganer;
    QString path;

private slots:
    void slot_iniciarCamara();
    void slot_setIntervalo(int value);
    void slot_timeout();
};

