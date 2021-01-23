#include "Circonferenza.h"

#include "math.h"

Circonferenza::Circonferenza(std::string nome, colori colore, Punto centro, double _raggio) :
    Curva(nome, colore, centro),
    raggio(_raggio)
{}

double Circonferenza::diametro() const { return raggio*2; }

double Circonferenza::perimetro() const { return diametro()*M_PI; }

double Circonferenza::area() const { return pow(raggio,2)*M_PI; }

double Circonferenza::Eccentricita() { return 0; }

std::pair<Punto, Punto> Circonferenza::getFuochi() { return std::pair<Punto,Punto>(getPuntoInizio(), getPuntoInizio()); }

double Circonferenza::getRaggio() const { return raggio; }

void Circonferenza::disegna(QPainter *) const
{

}


