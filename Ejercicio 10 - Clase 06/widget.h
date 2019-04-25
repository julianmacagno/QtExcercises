#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <admindb.h>
#include <QCompleter>
#include <QVector>
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
    AdminDB *db;
    void crearCompleters();
    QStringList toStringList(QVector <QStringList> v);
    QCompleter *setCompleters(QString nombre);
private slots:
    void almacenar();
};

#endif // WIDGET_H
