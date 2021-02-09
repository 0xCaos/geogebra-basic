#ifndef POLIGONO_H
#define POLIGONO_H

#include "Figura.h"
#include "Vettore.h"
#include "math.h"

class Poligono : public Figura {
private:
    Vettore<Punto> vertici;

    static bool crossProductSign(const Punto&, const Punto&, const Punto&);
public:
    /**
     * @brief Poligono
     * Costruttore di Poligono
     */
    Poligono(string, string, const Vettore<Punto*>&);

    Poligono();

    ~Poligono() = default;

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
    void disegna(QPainter*, int) const override;;

    /**
     * @brief getInfo (override di Disegnabile::getInfo)
     * @return unordered_map con "Nome proprietà" => valore
     */
    std::unordered_map<string, string> getInfo() const override;

    /**
     * @brief clone override di Disegnabile::clone()
     * @return un puntatore al nuovo Punto clonato
     */
    Poligono* clone() const override;

    const Vettore<Punto> &getVettorePunti() const;

    void read(const QJsonObject&) override;
    void write(QJsonObject&) const override;
};

#endif // POLIGONO_H
