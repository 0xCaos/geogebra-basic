#ifndef ELLISSE_H
#define ELLISSE_H

#include "Circonferenza.h"

class Ellisse : public Circonferenza
{
private:
    double raggio2;
public:
    Ellisse(std::string, colori, Punto, double, double);
    double perimetro() const override;
    double area() const override;
    double Eccentricita() override;
    double getSemidistanzaFocale();
    std::pair<Punto,Punto> getFuochi() override;
    void disegna(QPainter*) const override;
};

#endif // ELLISSE_H
