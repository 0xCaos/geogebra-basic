#include "Circonferenza.h"

#include "math.h"

Circonferenza::Circonferenza(std::string nome, QColor colore, Punto* _centro, double _raggio) :
    Curva((_raggio<=0) ? throw std::domain_error("Il raggio deve essere positivo.") : nome, colore),
    raggio(_raggio),
    centro(_centro)
{}

double Circonferenza::diametro() const { return raggio*2; }

double Circonferenza::perimetro() const { return diametro()*M_PI; }

double Circonferenza::area() const { return pow(raggio,2)*M_PI; }

double Circonferenza::eccentricita() const { return 0; }

std::pair<Punto, Punto> Circonferenza::getFuochi() const { return std::pair<Punto,Punto>(*centro, *centro); }

double Circonferenza::getRaggio() const { return raggio; }

Punto* Circonferenza::getCentro() const { return centro; }

void Circonferenza::disegna(QPainter *) const
{

}

std::unordered_map<std::string, std::string> Circonferenza::getInfo() const {
    std::unordered_map<string, string> infoCirconferenza;
    infoCirconferenza["Area"] = std::to_string(area());
    infoCirconferenza["Perimetro"] = std::to_string(perimetro());
    infoCirconferenza["Diametro"] = std::to_string(diametro());
    infoCirconferenza["Centro"] = *getCentro();
    infoCirconferenza["Nome"] = getNome();

    return infoCirconferenza;
}

Circonferenza *Circonferenza::clone() const {
    return new Circonferenza(*this);
}


