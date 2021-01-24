#include "Ellisse.h"

#include "math.h"

Ellisse::Ellisse(std::string nome, QColor colore, Punto centro, double _raggio1, double _raggio2) :
    Circonferenza(nome, colore, centro, _raggio1),
    raggio2(_raggio2)
{}

double Ellisse::perimetro() const { return 2*M_PI*sqrt((pow(getRaggio(),2) + pow(raggio2,2))/2); }

double Ellisse::area() const { return M_PI*getRaggio()*raggio2; }

double Ellisse::getSemidistanzaFocale() const {
    if (getRaggio() > raggio2) return sqrt(pow(getRaggio(),2) - pow(raggio2,2));
    return sqrt(pow(raggio2,2) - pow(getRaggio(),2));
}

double Ellisse::eccentricita() const
{
    if (getRaggio() > raggio2) return getSemidistanzaFocale()/sqrt(getRaggio());
    return getSemidistanzaFocale()/sqrt(raggio2);
}

std::pair<Punto, Punto> Ellisse::getFuochi() const
{
    Punto f1;
    Punto f2;
    double c = sqrt(getSemidistanzaFocale());
    if (getRaggio() > raggio2) {
        f1 = Punto("default", Nero, getCentro().getX()-c, getCentro().getY());
        f2 = Punto("default", Nero, getCentro().getX()+c, getCentro().getY());
    } else {
        f1 = Punto("default", Nero, getCentro().getX(), getCentro().getY()-c);
        f2 = Punto("default", Nero, getCentro().getX(), getCentro().getY()+c);
    }
    return std::pair<Punto, Punto>(f1,f2);
}

void Ellisse::disegna(QPainter *) const
{

}

