#ifndef MIHILO_H
#define MIHILO_H

#include <QThread>

class MiHilo : public QThread
{
    Q_OBJECT
public:
    explicit MiHilo(QObject* parent = 0);

protected:
    void run();

signals:
    void EscribirPalabra(QString);
};

#endif // MIHILO_H
