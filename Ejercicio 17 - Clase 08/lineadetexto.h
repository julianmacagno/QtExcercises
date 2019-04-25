#ifndef LINEADETEXTO_H
#define LINEADETEXTO_H

#include "lineadetexto_global.h"
#include <QLineEdit>
#include <QString>
#include <QTreeWidget>
#include <QTimer>
#include <QKeyEvent>
#include <QWidget>
#include <QHeaderView>

class LINEADETEXTOSHARED_EXPORT LineaDeTexto:public QLineEdit
{
    Q_OBJECT

public:
   LineaDeTexto(QWidget *parent=0);
   LineaDeTexto(QString texto, QWidget *parent=0);
   LineaDeTexto(const LineaDeTexto &linea, QWidget *parent=0);

   LineaDeTexto& operator=(const LineaDeTexto &linea);
   LineaDeTexto operator+(const LineaDeTexto &linea);
   LineaDeTexto operator+(QString string);
   void setList(QStringList );
private:
   bool eventFilter(QObject *,QEvent*);
   QStringList list;
   QTimer *timer;
   QTreeWidget *popup;
   void crearpopup();
   void completarpopup(QVector<QStringList> list);
private slots:
   void sugerencia();
   void completarLineEdit();
};

#endif // LINEADETEXTO_H
