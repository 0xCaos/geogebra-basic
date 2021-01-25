#include "Regolare.h"

double Regolare::getCostanteArea(unsigned int id) const {
    return costantiAree[id-3];
}

Regolare::Regolare(std::string nome, QColor color, std::pair<Punto*, Punto*> punti, unsigned int numVertici) : Figura(nome, color) {
    if(numVertici > 12) numVertici = 12;
    if(numVertici < 3) numVertici = 3;

    numLati = numVertici;
    lato = punti.first->getDistanza(*punti.second);
}

double Regolare::perimetro() const {
    return lato * numLati;
}

double Regolare::area() const {
    double costante = getCostanteArea(numLati);
    return (lato*lato)*costante;
}

std::unordered_map<string, string> Regolare::getInfo() const {
    std::unordered_map<string, string> infoRegolare;
    infoRegolare["Area"] = std::to_string(area());
    infoRegolare["Perimetro"] = std::to_string(perimetro());
    infoRegolare["Vertici"] = std::to_string(numLati);
    infoRegolare["Colore"] = "Nero";
    infoRegolare["Nome"] = getNome();

    return infoRegolare;
}

Regolare *Regolare::clone() const {
    return new Regolare(*this);
}
