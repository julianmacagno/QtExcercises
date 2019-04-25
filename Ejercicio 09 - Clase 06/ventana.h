#pragma once
#include <QWidget>
#include <QImage>
#include <QTimer>
#include <QPainter>
#include <QKeyEvent>
#include <QDesktopWidget>
#include <QMouseEvent>

class QTimer;
class QImage;

namespace Ui {
    class Ventana;
}

class Ventana : public QWidget {
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = 0);
    ~Ventana();

private:
    Ui::Ventana *ui;
    int rot, tx, ty;
    QTimer *timer;
    QImage *img;

private slots:
    void slot_cicles();

protected:
    void paintEvent(QPaintEvent *e);
    bool eventFilter(QObject *o, QEvent *e);
};
