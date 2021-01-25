#ifndef CREATOR_H
#define CREATOR_H

#include "Gerarchia.h"

class Creator {
public:

    Punto* creaPunto() const;
    Punto* creaPunto(string, QColor, double, double) const;

    Segmento* creaSegmento(string, QColor, Punto*, Punto*) const;
    Retta* creaRetta(string, QColor, Punto*, Punto*) const;
    Poligono* creaPoligono(string, QColor, Vettore<Punto*>) const;
    Regolare* creaRegolare(string, QColor, std::pair<Punto*, Punto*>, unsigned int) const;
    Ellisse* creaEllisse(string, QColor, Punto*, double, double) const;
    Circonferenza* creaCirconferenza(string, QColor, Punto*, double) const;

};

#endif // CREATOR_H
