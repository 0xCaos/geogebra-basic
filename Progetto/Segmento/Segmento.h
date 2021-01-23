//
// Created by matteo on 23/01/21.
//

#ifndef SEGMENTO_SEGMENTO_H
#define SEGMENTO_SEGMENTO_H

#include <iostream>

#include "../Punto/Punto.h"

class Segmento {
private:
    std::pair<Punto,Punto> punti;
public:
    Segmento(Punto a, Punto b) : punti(a,b) {}
    void Disegna();
    double getLunghezza();
};


#endif //SEGMENTO_SEGMENTO_H
