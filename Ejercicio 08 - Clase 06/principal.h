#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>

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

    QTimer* timer;
    int rotacion, transX, transY;
    QImage * image;

protected:
        void paintEvent(QPaintEvent * e);
        bool eventFilter(QObject *, QEvent *);

private slots:
        void slot_ciclos();
};

#endif // PRINCIPAL_H
