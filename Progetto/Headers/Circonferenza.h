#ifndef CIRCONFERENZA_H
#define CIRCONFERENZA_H

#include "Curva.h"

class Circonferenza : public Curva
{
private:
    double raggio;
public:
    Circonferenza(string, colori, Punto, double);
    double Diametro();
    double Perimetro() override;
    double Area() override;
    double Eccentricita() override;
    std::pair<Punto,Punto> getFuochi() override;
    double getRaggio();
    void disegna(QPainter*) override;
};

#endif // CIRCONFERENZA_H
