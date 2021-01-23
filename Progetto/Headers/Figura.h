#ifndef FIGURA_H
#define FIGURA_H

#include "Disegnabile.h"

class Punto {};

class Figura : public Disegnabile {
private:
    Punto puntoInizio;
protected:
    Figura(string, colori, Punto);
public:
    virtual double Perimetro() =0;
    virtual double Area() =0;
};

#endif // FIGURA_H
