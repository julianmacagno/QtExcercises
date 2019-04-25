#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QVector>
#include <QDebug>
#include <QStringList>

namespace Ui {
    class Formulario;
}

class Formulario : public QWidget
{
    Q_OBJECT

public:
    explicit Formulario( QWidget * parent = 0 );
    ~Formulario();

    void setDB(QVector <QStringList> db);

private:
    Ui::Formulario *ui;
    QVector< QStringList > db;

private slots:
    void slot_validarAlta();

signals:
    void signal_AltaFormulario(bool valido, QStringList usuario);
};

#endif // FORMULARIO_H
