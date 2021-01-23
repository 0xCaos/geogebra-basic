#ifndef CIRCONFERENZA_H
#define CIRCONFERENZA_H

#include "Curva.h"

class Circonferenza : public Curva
{
private:
    double raggio;
public:
    Circonferenza(string, colori, Punto, double);
    double diametro() const;
    double perimetro() const override;
    double area() const override;
    double Eccentricita() override;
    std::pair<Punto,Punto> getFuochi() override;
    double getRaggio() const;
    void disegna(QPainter*) const override;
};

#endif // CIRCONFERENZA_H
