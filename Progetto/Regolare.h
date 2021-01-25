#ifndef REGOLARE_H
#define REGOLARE_H

#include "Figura.h"
#include "Vettore.h"

Vettore<double> const costantiAree = {0.433, 1, 1.720, 2.598, 3.634, 4.828, 6.182, 7.694, 11.196};

class Regolare : public Figura {
private:
    std::pair<Punto, Punto> punti;
    double lato;
    unsigned int numLati;

    double getCostanteArea(unsigned int) const;

public:
    /**
     * @brief Costruttore di Regolare
     * figura con "numLati" tutti di lunghezza "lato"
     * se numLati > 12, verrà creato al massimo comunque un dodecagono
     */
    Regolare(string, QColor, std::pair<Punto, Punto>, unsigned int);

    ~Regolare() =default;

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

    /**
     * @brief disegna override di Disegnabile::disegna()
     */
    void disegna(QPainter*) const override {}

    /**
     * @brief getInfo override di Disegnabile::getInfo()
     * @return unordered_map con "Nome proprietà" => valore
     */
    std::unordered_map<string, string> getInfo() const override;

    /**
     * @brief clone override di Disegnabile::clone()
     * @return un puntatore al nuovo Segmento clonato
     */
    Regolare* clone() const override;

};

#endif // REGOLARE_H
