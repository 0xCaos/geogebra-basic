#ifndef REGOLARE_H
#define REGOLARE_H

#include "Figura.h"
#include "Vettore.h"

class Regolare : public Figura {
private:
    std::pair<Punto, Punto> punti;
    double lato;
    unsigned int numLati;

    Vettore<double> const costantiAree = {0.433, 1, 1.720, 2.598, 3.634, 4.828, 6.182, 7.694, 11.196};

    double getCostanteArea(unsigned int) const;

public:
    /**
     * @brief Costruttore di Regolare
     * figura con "numLati" tutti di lunghezza "lato"
     * se numLati > 12, verrà creato al massimo comunque un dodecagono
     */
    Regolare(string, colori, std::pair<Punto, Punto>, unsigned int);

    /**
     * @brief perimetro
     * @return il perimetro di una figura regolare
     */
    double perimetro() const override;

    /**
     * @brief area
     * @return l'area della figura regolare
     */
    double area() const override;

    void disegna(QPainter*) const override {}

};

#endif // REGOLARE_H
