#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QVector>
#include <QStringList>

namespace Ui {
    class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    static Login *getInstancia();
    void iniciar();
    void terminar();
    ~Login();

    /**
     * @brief setBaseUsuarios Permite agregar usuarios permitidos para
              este login. Siempre estara el usuario admin:nimda
     * @param usuarios Son los nuevos usuarios que se agregan a
              este login sin borrar los anteriores.
     */
    void setBaseUsuarios( QVector< QStringList > usuarios );

private:
    explicit Login( QWidget * parent = 0 );
    static Login *instancia;
    Ui::Login *ui;

    /**
     * @brief usuarios Se mantienen todos los usuarios validos para este login.
              El QStringList almacena las credenciales usuario:clave
     */
    QVector< QStringList > usuarios;

private slots:
    void slot_validarUsuario();

signals:

    /**
     * @brief signal_usuarioValidado Se emite cuando un usuario intenta ingresar.
     * @param valido Si es true entonces el usuario es valido, sino devuelve false.
     * @param usuario Son las credenciales que el usuario ingresa.
     */
    void signal_usuarioValidado( bool valido, QStringList usuario );
};

#endif // LOGIN_H
