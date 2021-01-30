#include "Regolare.h"
#include "math.h"

double Regolare::getCostanteArea(unsigned int id) const {
    return costantiAree[id-3];
}

Regolare::Regolare(std::string nome, QColor color, std::pair<Punto*, Punto*> _punti, unsigned int numVertici) :
    Figura(nome, color)
{
    if (numVertici<3 || numVertici>12)
        throw std::logic_error("Il numero di vertici deve essere compreso tra 3 e 12 (inclusi)");
    if (*_punti.first == *_punti.second)
        throw std::logic_error("Le coordinate dei due punti non possono coincidere");
    punti = _punti;
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

void Regolare::disegna(QPainter *p) const {
    double xA = punti.first->getX();
    double xB = punti.second->getX();
    double yA = punti.first->getY();
    double yB = punti.second->getY();
    double xM = (xA+xB)/2;
    double yM = (yA+yB)/2;

    double tangente = tan(180/numLati);

    double xC = xM+(yA-yB)/2*tangente;
    double yC = yM+(xB-xA)/2*tangente;

    Punto centro("centro",Qt::black,xC,yC);
    double raggio = centro.getDistanza(*punti.first);

    for (unsigned int i=0; i<numLati; ++i) {
        double xP1 = xC + raggio*cos(2*M_PI*i/numLati);
        double yP1 = yC + raggio*sin(2*M_PI*i/numLati);
        double xP2 = xC + raggio*cos(2*M_PI*(i+1)/numLati);
        double yP2 = yC + raggio*sin(2*M_PI*(i+1)/numLati);
        p->drawLine(
            xP1*10,
            -yP1*10,
            xP2*10,
            -yP2*10
        );
    }
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
