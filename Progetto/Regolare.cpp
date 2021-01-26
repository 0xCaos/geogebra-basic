#include "Regolare.h"

double Regolare::getCostanteArea(unsigned int id) const {
    return costantiAree[id-3];
}

Regolare::Regolare(std::string nome, QColor color, std::pair<Punto*, Punto*> punti, unsigned int numVertici) :
    Figura(nome, color)
{
    if (numVertici<3 || numVertici>12)
        throw std::logic_error("Il numero di vertici deve essere compreso tra 3 e 12 (inclusi)");
    if (*punti.first == *punti.second)
        throw std::logic_error("Le coordinate dei due punti non possono coincidere");
    lato = punti.first->getDistanza(*punti.second);
    numLati = numVertici;
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
