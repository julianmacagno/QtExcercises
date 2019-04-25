#pragma once
#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QDir>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QTimer>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QString ruta, QWidget *parent = 0);
    ~Form();

private:
    Ui::Form *ui;
    QImage imagen;
    QDir dir;
    QString path;
    int i=0;
    QStringList namefilters, files;
    QTimer *timer;

    void paintEvent(QPaintEvent *e);

private slots:
    void slot_mostrar();
};
