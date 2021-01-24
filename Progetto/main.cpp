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

    Poligono pol1 ("Poligono", Rosso, Punto("D", Nero, -4, -1));
    pol1.setVertici({
            Punto("E", Nero, -6, 1),
            Punto("F", Nero, -8, -2),
            Punto("G", Nero, -5, -3)
    });

    Poligono pol2 ("Poligono", Rosso, Punto("M",Nero,4,12));
    pol2.setVertici({
            Punto("N", Nero, 8, 8),
            Punto("O", Nero, 5, 8),
            Punto("P", Nero, 6, 6),
            Punto("Q", Nero, 1, 7),
            Punto("R", Nero, 4, 9)
    });

    cout << pol1.perimetro() << " " << pol1.area() << "\n";
    cout << pol2.perimetro() << " " << pol2.area() << "\n";
}
