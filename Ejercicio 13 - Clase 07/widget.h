#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QCompleter>
#include <QTreeWidget>
#include <QTimer>
#include <QLineEdit>


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
    bool eventFilter(QObject *,QEvent*);
    QStringList list;
    QTimer *timer;
    //-----------------------------
    //QCompleter
    Ui::Widget *ui;
    //-----------------------------
    //QTreeWidget
    QTreeWidget *popup;
    void crearpopup();
    void completarpopup(QVector<QStringList> list);
private slots:
    void sugerencia();
    void completarLineEdit();
    void addCom();

};

#endif // WIDGET_H
