#include "Regolare.h"

double Regolare::getCostanteArea(unsigned int id) const {
    return costantiAree[id-3];
}

Regolare::Regolare(std::string nome, colori color, Punto primoPunto, double lato, unsigned int numVertici) : Figura(nome, color, primoPunto), lato(lato) {
    if(numVertici > 12) numVertici = 12;
    if(numVertici < 3) numVertici = 3;

    numLati = numVertici;
}

double Regolare::perimetro() const {
    return lato * numLati;
}

double Regolare::area() const {
    double numeroFisso = getCostanteArea(numLati);
    return (lato*lato)*numeroFisso;
}
