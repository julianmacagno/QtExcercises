#pragma once
#include <QWidget>
#include <QImage>
#include <QPaintEvent>
#include <QPainter>

namespace Ui {
class Frame;
}

class Frame : public QWidget
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = 0);
    ~Frame();
    void setImage(QImage imagen);

private:
    Ui::Frame *ui;
    QImage image;
    void paintEvent(QPaintEvent *e);
};

