#include "Poligono.h"

Poligono::Poligono(std::string nome , colori color, Punto primoPunto) : Figura(nome, color, primoPunto) {}

void Poligono::setVertici(Vettore<Punto> vertici) {
    punti = vertici;
    punti.insert(punti.begin(),getPuntoInizio());
}

double Poligono::perimetro() const {
    int numVertici = punti.size();
    double valore = 0;
    if(numVertici > 2){ // almeno un triangolo
        for(int i=0; i < numVertici-1; i++){
            valore += punti[i].getDistanza(punti[i+1]);
        }
        valore += punti[numVertici-1].getDistanza(punti[0]);
    }

    return valore;
}

double Poligono::area() const {

}




