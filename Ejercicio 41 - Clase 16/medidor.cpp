#include "medidor.h"

Medidor *Medidor::instancia= NULL;

Medidor::Medidor():seAcabo(false)
{
    manager = new QNetworkAccessManager;
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(cambiar()));
}

Medidor::~Medidor()
{
    if(instancia !=NULL)
    {
        delete instancia;
    }
}
Medidor * Medidor::getInstancia()
{
    if( instancia == NULL )
    {
        instancia = new Medidor();
    }
    return instancia;
}

bool Medidor::isOk(QString dir)
{
   if(Medidor::getInstancia()->hayConexion(dir)==false)
   {
       return false;
   }
   else
   {
       return true;
   }
}

bool Medidor::hayConexion(QString dir)
{
    timer->start(500);
    QUrl url = dir;
    QNetworkRequest req(url);
    QNetworkReply *reply = manager->get(req);
    QEventLoop loop;
    connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    if(seAcabo==false)
    {
        timer->stop();
        if(reply->bytesAvailable()){ return true; }
        else { return false; }
    }
    else
    {
        timer->stop();
        seAcabo=false;
        return false;
    }
}

