#include "Circonferenza.h"

#include "math.h"

Circonferenza::Circonferenza(std::string nome, colori colore, Punto _centro, double _raggio) :
    Curva(nome, colore),
    raggio(_raggio),
    centro(_centro)
{}

double Circonferenza::diametro() const { return raggio*2; }

double Circonferenza::perimetro() const { return diametro()*M_PI; }

double Circonferenza::area() const { return pow(raggio,2)*M_PI; }

double Circonferenza::eccentricita() const { return 0; }

std::pair<Punto, Punto> Circonferenza::getFuochi() const { return std::pair<Punto,Punto>(centro, centro); }

double Circonferenza::getRaggio() const { return raggio; }

Punto Circonferenza::getCentro() const { return centro; }

void Circonferenza::disegna(QPainter *) const
{

}


