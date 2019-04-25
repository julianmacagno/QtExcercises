#pragma once
#include <QWidget>
#include <lineadetexto.h>

namespace Ui {
    class Alta;
}

class Alta : public QWidget {
    Q_OBJECT

public:
    explicit Alta(QWidget *parent = 0);
    ~Alta();

private:
    Ui::Alta *ui;
    QStringList listN,listP;

private slots:
    void slot_autocomplete(QString);
    void slot_alta();
};
