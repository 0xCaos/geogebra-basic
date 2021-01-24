//
// Created by matteo on 19/01/21.
//

#include <math.h>
#include "Punto.h"

Punto::Punto(string nome, QColor colore, double _x, double _y) : Disegnabile(nome, colore), x(_x), y(_y) {}

double Punto::getX() { return x; }

double Punto::getY() { return y; }

double Punto::getDistanza(Punto p)
{
    double d;
    d = sqrt(pow((x - p.getX()),2) + pow((y - p.getY()),2));
    return d;
}

std::unordered_map<string, string> Punto::getInfo() const {
    std::unordered_map<string, string> infoPunto;
    infoPunto["Colore"] = "getColore()";
    infoPunto["Nome"] = getNome();

    return infoPunto;
}

void Punto::disegna(QPainter*) const {

}
