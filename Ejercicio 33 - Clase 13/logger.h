#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QVector>
#include <QDebug>
#include <QDateTime>
#include <QMessageBox>
#include "login.h"
#include "formulario.h"
#include "archivador.h"

class Logger : public QObject
{
    Q_OBJECT

private:
    static Logger *instancia;
    explicit Logger(QObject * parent = 0);

public:
    static Logger * getInstancia();
    ~Logger();

    void iniciar();
    void registrarEvento(QString evento);

private:
    Login * login;
    Formulario * formulario;
    Archivador * file;

private slots:
    void slot_ingreso(bool valido, QStringList usuario);
    void slot_AltaFormulario(bool valido, QStringList usuario);

};

#endif // LOGGER_H
