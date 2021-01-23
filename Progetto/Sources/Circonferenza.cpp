#include "Circonferenza.h"

#include "math.h"

Circonferenza::Circonferenza(std::string nome, Disegnabile::colori colore, Punto centro, double _raggio) :
    Curva(nome, colore, centro),
    raggio(_raggio)
{}

double Circonferenza::Diametro() { return raggio*2; }

double Circonferenza::Perimetro() { return Diametro()*M_PI; }

double Circonferenza::Area() { return pow(raggio,2)*M_PI; }

double Circonferenza::Eccentricita() { return 0; }

std::pair<Punto, Punto> Circonferenza::getFuochi() { return std::pair<Punto,Punto>(getPuntoInizio(), getPuntoInizio()); }

double Circonferenza::getRaggio() { return raggio; }


