//
// Created by matteo on 23/01/21.
//

#include "Segmento.h"

Segmento::Segmento(std::string nome, colori colore, Punto a, Punto b) : Disegnabile(nome, colore), punti(a,b) {}

double Segmento::getLunghezza() { return punti.first.getDistanza(punti.second); }
