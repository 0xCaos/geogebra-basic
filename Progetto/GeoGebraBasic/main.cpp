#include "mainwindow.h"

#include "Punto.h"
#include "Segmento.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    */
    Punto a(2,2);
    Punto b(6,2);
    Segmento ab(a,b);
    std::cout << ab.getLunghezza();
}
