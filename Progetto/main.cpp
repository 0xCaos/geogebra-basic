#include "mainwindow.h"

#include <QApplication>
#include <unordered_map>
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

    Segmento s ("a", Qt::black, Punto("A",Qt::black, 1, 2), Punto("A",Qt::black, 5, 7));
    Retta r ("r", Qt::black, Punto("A",Qt::black, 1, 2), Punto("A",Qt::black, 5, 7));
    Regolare quadrato ("Quadrato", Qt::black, std::pair<Punto, Punto>(Punto("A",Qt::black, 1, 2), Punto("A",Qt::black, 5, 7)), 4);
    Poligono pol1 ("Poligono", Rosso);
    pol1.setVertici({
            Punto("M", Qt::black, 4, 12),
            Punto("N", Qt::black, 8, 8),
            Punto("O", Qt::black, 5, 8),
            Punto("P", Qt::black, 6, 6),
            Punto("Q", Qt::black, 1, 7),
            Punto("R", Qt::black, 4, 9)
    });

    Circonferenza cerchio("Circonferenza", Qt::black, Punto(), 2);
    Ellisse ell("Ellisse", Qt::black, Punto(), 2, 5);

    std::unordered_map<string, string> segmento     = s.getInfo();
    std::unordered_map<string, string> retta        = r.getInfo();
    std::unordered_map<string, string> quad         = quadrato.getInfo();
    std::unordered_map<string, string> irregolare   = pol1.getInfo();
    std::unordered_map<string, string> punto        = Punto().getInfo();
    std::unordered_map<string, string> circ         = cerchio.getInfo();
    std::unordered_map<string, string> ellisse      = ell.getInfo();

    std::unordered_map<string, string>:: iterator itr;
    cout << "\nSegmento : \n";
    for (itr = segmento.begin(); itr != segmento.end(); itr++)
    {

        cout << itr->first << "  " << itr->second << "\n";
     }

    cout << "\nRetta : \n";
    for (itr = retta.begin(); itr != retta.end(); itr++)
    {

        cout << itr->first << "  " << itr->second << "\n";
     }

    cout << "\nQuadrato : \n";
    for (itr = quad.begin(); itr != quad.end(); itr++)
    {

        cout << itr->first << "  " << itr->second << "\n";
     }

    cout << "\nIrregolare : \n";
    for (itr = irregolare.begin(); itr != irregolare.end(); itr++)
    {

        cout << itr->first << "  " << itr->second << "\n";
     }

    cout << "\nPunto : \n";
    for (itr = punto.begin(); itr != punto.end(); itr++)
    {

        cout << itr->first << "  " << itr->second << "\n";
     }

    cout << "\nCirconferenza : \n";
    for (itr = circ.begin(); itr != circ.end(); itr++)
    {

        cout << itr->first << "  " << itr->second << "\n";
     }

    cout << "\nEllisse : \n";
    for (itr = ellisse.begin(); itr != ellisse.end(); itr++)
    {

        cout << itr->first << "  " << itr->second << "\n";
     }

    //Punto("Punto 1", 1, 1, 2) punto1;
    /*
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
    */
}
