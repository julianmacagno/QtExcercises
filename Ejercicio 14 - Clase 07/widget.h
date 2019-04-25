#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QCompleter>
#include <QTreeWidget>
#include <QTimer>
#include <QLineEdit>
#include <admindb.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    bool setdb(QString arc,QString column);
    void setList(QString column);
private:
    bool eventFilter(QObject *,QEvent*);
    QStringList list;
    QString Archivo,columna;
    AdminDB db;
    QTimer *timer;
    Ui::Widget *ui;
    QTreeWidget *popup;

    void crearpopup();
    void completarpopup(QVector<QStringList> list);
private slots:
    void sugerencia();
    void completarLineEdit();

};

#endif // WIDGET_H
