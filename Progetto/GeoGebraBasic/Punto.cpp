//
// Created by matteo on 19/01/21.
//

#include <math.h>
#include "Punto.h"

double Punto::getX() {
    return x;
}

double Punto::getY() {
    return y;
}

double Punto::getDistanza(Punto p) {
    double d;
    d = sqrt(pow((x - p.getX()),2) + pow((y - p.getY()),2));
    return d;
}

void Punto::Disegna() {

}