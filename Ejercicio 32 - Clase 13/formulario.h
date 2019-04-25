#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>


namespace Ui {
    class Formulario;
}

class Formulario : public QWidget
{
    Q_OBJECT

public:
   static Formulario *getInstancia();
   ~Formulario();
   void iniciar();

private:
    static Formulario *instancia;
    explicit Formulario( QWidget * parent = 0 );
    Ui::Formulario *ui;

private slots:
    void slot_nuevoUsuario();

signals:
    void signal_nuevoUsuario(QStringList);
};

#endif // FORMULARIO_H
