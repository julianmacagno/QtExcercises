#ifndef MEDIDOR_H
#define MEDIDOR_H
#include <QThread>
#include <QObject>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>
#include <QEventLoop>
#include <QTimer>

class Medidor: public QThread
{
    Q_OBJECT
public:
    Medidor();
    ~Medidor();
    static Medidor *getInstancia();
    bool isOk(QString dir);
    bool hayConexion(QString dir);
private slots:
    void cambiar()
    {
        qDebug()<< "timeout";
        seAcabo=true;
    }
private:
    static Medidor *instancia;
    QNetworkAccessManager *manager;
    QTimer *timer;
    bool seAcabo;
};

#endif // MEDIDOR_H
