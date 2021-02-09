#include "Model.h"
#include "Controller.h"
#include "Interfaccia.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Model m;
    Controller c;
    Interfaccia w;

    c.setModel(&m);
    c.setView(&w);
    w.setController(&c);
    w.show();

    return a.exec();
}
