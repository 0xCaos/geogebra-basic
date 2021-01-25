//
// Created by matteo on 19/01/21.
//

#include <math.h>
#include "Punto.h"

Punto::Punto(string nome, QColor colore, double _x, double _y) : Disegnabile(nome, colore), x(_x), y(_y) {}

double Punto::getX() const { return x; }

double Punto::getY() const { return y; }

double Punto::getDistanza(Punto p) const
{
    double d;
    d = sqrt(pow((x - p.getX()),2) + pow((y - p.getY()),2));
    return d;
}

Punto *Punto::clone() const {
    return new Punto(*this);
}

Punto::operator std::string() const {
    return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
}

std::unordered_map<string, string> Punto::getInfo() const {
    std::unordered_map<string, string> infoPunto;
    infoPunto["Coordinate"] = *this;
    infoPunto["Nome"] = getNome();

    return infoPunto;
}

bool Punto::operator==(const Punto &_p) {
    return getX() == _p.getX() && getY() == _p.getY();
}

void Punto::disegna(QPainter*) const {

}
