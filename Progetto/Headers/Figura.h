#ifndef FIGURA_H
#define FIGURA_H

#include "Disegnabile.h"
#include "Punto.h"

class Figura : public Disegnabile {
private:
    //Punto puntoInizio;
protected:
    Figura(string, colori);
public:
    virtual double perimetro() const =0;
    virtual double area() const =0;
    //Punto getPuntoInizio();
};

#endif // FIGURA_H
