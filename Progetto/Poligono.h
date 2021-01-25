#ifndef POLIGONO_H
#define POLIGONO_H

#include "Figura.h"
#include "Vettore.h"
#include "math.h"

class Poligono : public Figura {
private:
    Vettore<Punto> vertici;

    static bool crossProductSign(Punto, Punto, Punto);
public:
    /**
     * @brief Poligono
     * Costruttore di Poligono
     */
    Poligono(string, QColor, Vettore<Punto> = Vettore<Punto>());

    //~Poligono() = default;

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
     * @return area del poligono (sia concavo che convesso)
     */
    double area() const override;

    /**
     * @brief concavo
     * @return true sse il poligono è concavo altrimenti è convesso
     */
    bool concavo() const;

    /**
     * @brief disegna (override di Disegnabile::disegna)
     */
    void disegna(QPainter*) const override {};

    /**
     * @brief getInfo (override di Disegnabile::getInfo)
     * @return unordered_map con "Nome proprietà" => valore
     */
    std::unordered_map<string, string> getInfo() const override;
};

#endif // POLIGONO_H
