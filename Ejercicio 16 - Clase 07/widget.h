#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QCompleter>
#include <QTreeWidget>
#include <QTimer>
#include <QLineEdit>
#include <QFile>
#include <QMessageBox>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void setList(QString column);

private:
    bool eventFilter(QObject *,QEvent*);
    QStringList list;
    QString Archivo,columna;
    QTimer *timer;
    Ui::Widget *ui;
    QTreeWidget *popup;
    QString archivo;
    QString linea;

    void crearpopup();
    void completarpopup(QVector<QStringList> list);
    void setDiccionario(QString archivo);

private slots:
    void sugerencia();
    void completarLineEdit();

};

#endif // WIDGET_H
