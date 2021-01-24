#include "mainwindow.h"

#include <QApplication>
#include "Gerarchia.h"

#include "iostream"
using std::cout;

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    */


    //colori nero = Nero;


    //Punto("Punto 1", 1, 1, 2) punto1;
    Punto punto1 ("Punto 1");
    Regolare regolare ("Regolare 1", Nero, punto1, 3, 4);

    cout << regolare.perimetro() << " " << regolare.area() << "\n";

    Poligono pol1 ("Poligono", Rosso, punto1);
    pol1.setVertici({Punto("Punto", Nero, 1, 2), Punto("Punto", Nero, 1, 4)});

    cout << pol1.perimetro() << " " << pol1.area() << "\n";
}
