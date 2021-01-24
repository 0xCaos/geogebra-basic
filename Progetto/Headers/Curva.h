#ifndef CURVA_H
#define CURVA_H

#include "Figura.h"

class Curva : public Figura
{
public:
    Curva(std::string, colori);
    virtual double Eccentricita() = 0;
    virtual std::pair<Punto,Punto> getFuochi() = 0;
};

#endif // CURVA_H
