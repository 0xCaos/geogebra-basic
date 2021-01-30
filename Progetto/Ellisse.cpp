#include "Ellisse.h"

#include "math.h"

Ellisse::Ellisse(std::string nome, QColor colore, Punto* _centro, double _raggio1, double _raggio2) :
    Curva((_raggio1<=0 || _raggio2<=0) ? throw std::domain_error("I due semiassi devono essere entrambi positivi.") : nome, colore),
    semiAsse1(_raggio1),
    semiAsse2(_raggio2),
    centro(*_centro)
{}

double Ellisse::perimetro() const { return 2*M_PI*sqrt((pow(semiAsse1,2) + pow(semiAsse2,2))/2); }

double Ellisse::area() const { return M_PI*semiAsse1*semiAsse2; }

double Ellisse::getSemidistanzaFocale() const {
    if (semiAsse1 > semiAsse2) return sqrt(pow(semiAsse1,2) - pow(semiAsse2,2));
    return sqrt(pow(semiAsse2,2) - pow(semiAsse1,2));
}

double Ellisse::eccentricita() const
{
    if (semiAsse1 > semiAsse2) return getSemidistanzaFocale()/semiAsse1;
    return getSemidistanzaFocale()/semiAsse2;
}

std::pair<Punto, Punto> Ellisse::getFuochi() const
{
    Punto f1;
    Punto f2;
    double c = sqrt(getSemidistanzaFocale());
    if (semiAsse1 > semiAsse2) {
        f1 = Punto("Fuoco 1", Qt::black, centro.getX()-c, centro.getY());
        f2 = Punto("Fuoco 2", Qt::black, centro.getX()+c, centro.getY());
    } else {
        f1 = Punto("Fuoco 1", Qt::black, centro.getX(), centro.getY()-c);
        f2 = Punto("Fuoco 2", Qt::black, centro.getX(), centro.getY()+c);
    }
    return std::pair<Punto, Punto>(f1,f2);
}

void Ellisse::disegna(QPainter * p) const {
    p->drawEllipse((centro.getX()-semiAsse1)*10, (-centro.getY()-semiAsse2)*10, 2*semiAsse1*10, 2*semiAsse2*10);
}

std::unordered_map<std::string, std::string> Ellisse::getInfo() const {
    std::unordered_map<string, string> infoEllisse;
    infoEllisse["Eccentricità"] = std::to_string(eccentricita());
    infoEllisse["Area"] = std::to_string(area());
    infoEllisse["Perimetro"] = std::to_string(perimetro());
    infoEllisse["Fuochi"] = string(getFuochi().first) + " " + string(getFuochi().second);
    infoEllisse["Nome"] = getNome();

    return infoEllisse;
}

Ellisse *Ellisse::clone() const {
    return new Ellisse(*this);
}

