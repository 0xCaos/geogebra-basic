#include <QApplication>
#include <unordered_map>
#include "Gerarchia.h"
#include "Model.h"

#include "iostream"
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    /*
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
    */

    cout << "Inizio \n";
    Model modelloTest;
    cout << "creato modello\n";
    Punto* p2 = new Punto("C",Qt::black, 6, 1);
    Punto* p3 = new Punto("A",Qt::black, 4, 7);
    Punto* p4 = new Punto("B", Qt::black, 3.54, 7.7);
    modelloTest.addNewPoligono({p2,p3,p4});
    cout << "\nPost newPoligono\n";
    Punto p1;
    modelloTest.addNewPunto(p1.getX(), p1.getY(), p1.getNome(), p1.getColore());
    //cout << "\nInserito primo punto\n";
    modelloTest.addNewPunto(p1.getX(), p1.getY(), p1.getNome(), p1.getColore());
    modelloTest.addNewPunto(3, 4, "Lollo", p1.getColore());
    modelloTest.addNewPunto(3, 4, "Yoda", p1.getColore());

    Poligono pol1("Poligono", Qt::black, {p2,p3,p4});

    delete p2, delete p3, delete p4;

    cout << "\nContenuto Modello\n";
    modelloTest.workspace->stampaContenuto();
    modelloTest.workspace->removeDisegno(3);
    cout << "\nPost remove\n";
    modelloTest.workspace->stampaContenuto();

    cout << "\nEnd Main\n";


    /*
    Poligono pol1 ("Poligono", Qt::red);
    pol1.setVertici({
            new Punto("M", Qt::black, 4, 12),
            new Punto("N", Qt::black, 8, 8),
            new Punto("O", Qt::black, 5, 8),
            new Punto("P", Qt::black, 6, 6),
            new Punto("Q", Qt::black, 1, 7),
            new Punto("R", Qt::black, 4, 9)
    });
    std::unordered_map<string, string> irregolare   = pol1.getInfo();

    cout << "\nIrregolare : \n";
    for (itr = irregolare.begin(); itr != irregolare.end(); itr++)
    {

        cout << itr->first << "  " << itr->second << "\n";
     }
     */



}
