#pragma once
#include <QWidget>
#include <QCompleter>

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

private slots:
    void slot_sumar();
};
