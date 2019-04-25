#pragma once
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include <QRgb>
#include <QRect>

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
    QImage imagen, original;
    QPixmap pixMap;

    void paintEvent(QPaintEvent *e);

private slots:
    void slot_RGBtoBGR();
};
