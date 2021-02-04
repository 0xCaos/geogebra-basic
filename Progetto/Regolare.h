#ifndef REGOLARE_H
#define REGOLARE_H

#include "Figura.h"
#include "Vettore.h"

# define M_PIl          3.141592653589793238462643383279502884L /* pi */

Vettore<double> const costantiAree = {0.433, 1, 1.720, 2.598, 3.634, 4.828, 6.182, 7.694, 9.366, 11.196, 13.186, 15.335, 17.642};

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
    Regolare(string, string, std::pair<Punto*, Punto*>, unsigned int);

    Regolare();

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
    void disegna(QPainter*, int) const override;

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

    void read(const QJsonObject&) override;
    void write(QJsonObject&) const override;
};

#endif // REGOLARE_H
