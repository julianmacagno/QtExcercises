#include <QApplication>
#include <visual.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Visual w;
    w.show();

    return a.exec();
}
