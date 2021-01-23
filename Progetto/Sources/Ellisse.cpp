#include "Ellisse.h"

#include "math.h"

Ellisse::Ellisse(std::string nome, colori colore, Punto centro, double _raggio1, double _raggio2) :
    Circonferenza(nome, colore, centro, _raggio1),
    raggio2(_raggio2)
{}

double Ellisse::perimetro() const { return 2*M_PI*sqrt((pow(getRaggio(),2) + pow(raggio2,2))/2); }

double Ellisse::area() const { return M_PI*getRaggio()*raggio2; }

double Ellisse::getSemidistanzaFocale() {
    if ( getRaggio() > raggio2) return pow(getRaggio(),2) - pow(raggio2,2);
    return pow(raggio2,2) - pow(getRaggio(),2);
}

double Ellisse::Eccentricita()
{
    double c = sqrt(getSemidistanzaFocale());
    return c/sqrt(raggio2);
}

std::pair<Punto, Punto> Ellisse::getFuochi()
{
    // Se si vuole mettere solo un return finale, bisogna crearsi per forza all'inizio i 2 Punto (fuochi) e poi usare la new
    // dentro all'if e all'else... ci sta?
    double c = sqrt(getSemidistanzaFocale());
    if (getRaggio() > raggio2) {
        Punto f1("default", Nero, getPuntoInizio().getX()-c, getPuntoInizio().getY());
        Punto f2("default", Nero, getPuntoInizio().getX()+c, getPuntoInizio().getY());
        return std::pair<Punto, Punto>(f1,f2);
    } else {
        Punto f1("default", Nero, getPuntoInizio().getX(), getPuntoInizio().getY()-c);
        Punto f2("default", Nero, getPuntoInizio().getX(), getPuntoInizio().getY()+c);
        return std::pair<Punto, Punto>(f1,f2);
    }
}

void Ellisse::disegna(QPainter *) const
{

}

