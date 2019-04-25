#ifndef ADMINDB_H
#define ADMINDB_H
#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVector>
#include <QString>
#include <QFile>
#include <QDebug>

class AdminDB: public QObject
{
    Q_OBJECT
public:
    AdminDB();
    ~AdminDB();
    bool conectar(QString nombreBase);
    bool insertLog(QVector<QString> dato, QVector<QString> columnas);
    QVector<QStringList> select(QString comando);
    QSqlDatabase getDB();
private:
    QSqlDatabase db;

};

#endif // ADMINDB_H
