#include "admindb.h"


AdminDB::AdminDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

AdminDB::~AdminDB()
{

}

bool AdminDB::conectar(QString nombreBase)
{
    if(QFile::exists(nombreBase))
    {
        db.setDatabaseName(nombreBase);
        db.open();
        return true;
    }
    return false;
}

bool AdminDB::insertLog(QVector<QString> dato, QVector<QString> columnas)
{
    QSqlQuery query(db);
    QStringList v=db.tables();
    QString comando="INSERT into'"+v.at(0)+"'( ";
    for (int i = 0; i < columnas.size(); ++i)
    {
        if(i<columnas.size()-1)comando.append(columnas.at(i)+",");
        else comando.append(columnas.at(i));
    }
    comando.append(") VALUES(");
    for (int i = 0; i < dato.size(); ++i)
    {
        if(i<dato.size()-1)comando.append("'"+dato.at(i)+"',");
        else comando.append("'"+dato.at(i)+"')");
    }
    qDebug()<< comando;
    return query.exec(comando);

}

QVector<QStringList> AdminDB::select(QString comando)
{
    QVector<QStringList> registros;

    QStringList v= db.tables();
    QSqlRecord rec= db.record(v.at(0));

    QString sel="select "+comando+" from "+ v.at(0);

    QSqlQuery query= db.exec(sel);
    while(query.next())
    {
        QStringList campos;
        for (int i = 0; i < rec.count(); ++i)
        {
            if(!query.value(i).toString().isEmpty())
            {
                if(!registros.contains((QStringList)(query.value(i).toString())))
                campos.append(query.value(i).toString());
            }
        }
        registros.append(campos);

    }
    return registros;
}

QSqlDatabase AdminDB::getDB()
{
    return db;
}
