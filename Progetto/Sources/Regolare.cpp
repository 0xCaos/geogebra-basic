#include "Regolare.h"

double Regolare::getCostanteArea(unsigned int id) const {
    return costantiAree[id-3];
}

Regolare::Regolare(std::string nome, colori color, std::pair<Punto, Punto> punti, unsigned int numVertici) : Figura(nome, color) {
    if(numVertici > 12) numVertici = 12;
    if(numVertici < 3) numVertici = 3;

    numLati = numVertici;
    lato = punti.first.getDistanza(punti.second);
}

double Regolare::perimetro() const {
    return lato * numLati;
}

double Regolare::area() const {
    double numeroFisso = getCostanteArea(numLati);
    return (lato*lato)*numeroFisso;
}
