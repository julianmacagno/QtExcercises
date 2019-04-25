#include "widget.h"
#include "ui_widget.h"
#include "QDebug"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    list<<"Carlos"<<"Pepe"<<"hernesto";
    this->crearpopup();

}

void Widget::addCom()
{
    if(!list.contains(ui->LineTreeWidget->text()))
    {
        list.append(ui->LineTreeWidget->text());
    }
}

void Widget::crearpopup()
{
    popup=new QTreeWidget();
    popup->setColumnCount(2);
    popup->setRootIsDecorated(false);
    popup->header()->hide();
    popup->installEventFilter(this);
    popup->setWindowFlags(Qt::Popup);

    connect(popup,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(completarLineEdit()));

    timer=new QTimer(this);
    timer->setSingleShot(true);
    timer->setInterval(200);
    connect(timer,SIGNAL(timeout()),SLOT(sugerencia()));
    connect(ui->LineTreeWidget,SIGNAL(textEdited(QString)),timer,SLOT(start()));
}



void Widget::sugerencia()
{
    QVector<QStringList> coincidencias;
    QString line=ui->LineTreeWidget->text();
    for (int i = 0, contador= 0; i < list.size()&& contador< 5; i++)
    {
        QString sugerencia=list.at(i);
        if(sugerencia.contains(line))
        {
            QStringList parecidos;
            parecidos<<sugerencia<<"campo";
            coincidencias.push_back(parecidos);
            contador++;
        }

    }
    this->completarpopup(coincidencias);
}
void Widget::completarpopup(QVector<QStringList> list)
{
    popup->clear();
    for (int i = 0; i < list.size(); ++i)
    {
        QTreeWidgetItem *items;
        items=new QTreeWidgetItem(popup);
        items->setText(0,list.at(i).at(0));
        items->setText(1,list.at(i).at(1));
        items->setTextAlignment(1,Qt::AlignRight);
    }
    popup->setCurrentItem(popup->topLevelItem(0));
    int h = popup->sizeHintForRow(0) * qMin(20, list.size()) + 3;
    popup->resize(ui->LineTreeWidget->width(), h);
    popup->move(ui->LineTreeWidget->mapToGlobal(QPoint(0, ui->LineTreeWidget->height())));
    popup->setFocus();
    popup->show();
}
void Widget::completarLineEdit()
{
    if(!list.contains(ui->LineTreeWidget->text()))
    {
        addCom();
    }
    timer->stop();
    popup->hide();
    ui->LineTreeWidget->setFocus();

    QTreeWidgetItem *items= popup->currentItem();
    if(items)
    {
        ui->LineTreeWidget->setText(items->text(0));
    }
}
bool Widget::eventFilter(QObject *obj, QEvent *e)
{
        if(obj==popup)
        {

            if(e->type()==QEvent::MouseButtonPress)
            {
                popup->hide();
                ui->LineTreeWidget->setFocus();
                return true;
            }
            if (e->type() == QEvent::KeyPress)  // si el evento es el que corresponde a una tecla presionada
            {
                bool reconocido = false;
                int key = static_cast<QKeyEvent*>(e)->key();
                switch (key) {
                case Qt::Key_Return:
                    this->completarLineEdit();
                    reconocido = true;
                    break;
                case Qt::Key_Up:
                case Qt::Key_Down:
                case Qt::Key_Home:
                case Qt::Key_End:
                case Qt::Key_PageUp:
                case Qt::Key_PageDown:
                    break;

                default:
                    // Hace que permanezca el cursor en el QLineEdit y poder seguir escribiendo
                    ui->LineTreeWidget->event(e);
                    popup->hide();
                    break;
                }
                return reconocido;
            }
        }
//     Esto es para que la clase base decida si necesita controlar los eventos
//     que no estamos capturando nosotros.
    return QWidget::eventFilter(obj, e);
}

Widget::~Widget()
{
    delete ui;
}
