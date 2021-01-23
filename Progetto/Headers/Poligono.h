#ifndef POLIGONO_H
#define POLIGONO_H

#include "Figura.h"
#include "Vettore.h"

class Poligono : public Figura {
private:
    Vettore<Punto> punti;
public:
    /**
     * @brief Poligono
     * Costruttore di Poligono
     */
    Poligono(string, colori, Punto);

    /**
     * @brief setVertici
     * metodo per il settaggio di tutti i vertici del poligono
     */
    void setVertici(Vettore<Punto>);

    /**
     * @brief perimetro (override di Figura::perimetro)
     * @return perimetro del poligono
     */
    double perimetro() const override;

    /**
     * @brief area (override di Figura::area)
     * @return area del poligono
     */
    double area() const override;

    /**
     * @brief disegna (override di Disegnabile::disegna)
     */
    void disegna(QPainter*) const override;
};

#endif // POLIGONO_H
