#ifndef ELLISSE_H
#define ELLISSE_H

#include "Circonferenza.h"

class Ellisse : public Circonferenza
{
private:
    double raggio2;
public:
    /**
     * @brief Costruttore di Ellisse
     */
    Ellisse(std::string nome, QColor colore, Punto centro, double raggio1, double raggio2);

    /**
     * @brief Calcolo del perimetro dell'ellisse
     * @return 2 * PI_GRECO * radiceQuadrata((raggio1^2 + raggio2^2)/2)
     */
    double perimetro() const override;

    /**
     * @brief Calcolo dell'area dell'ellisse
     * @return PI_GRECO * raggio1 * raggio2;
     */
    double area() const override;

    /**
     * @brief Calcolo della semidistanza fra i due fuochi
     * @return radiceQuadrata( raggioMaggiore^2 - raggioMinore^2)
     */
    double getSemidistanzaFocale() const;

    /**
     * @brief Calcolo dell'eccentricità
     * @return semiDistanzaFocale / radiceQuadrata(raggioMaggiore)
     */
    double eccentricita() const override;

    /**
     * @brief Calcolo del fuochi dell'ellisse
     * @return
     *      se raggio1 > raggio2
     *          fuoco1(xCentro - semiDistanzaFocale, yCentro);
     *          fuoco2(xCentro + semiDistanzaFocale, yCentro);
     *      altrimenti
     *          fuoco1(xCentro, yCentro - semiDistanzaFocale);
     *          fuoco2(xCentro, yCentro + semiDistanzaFocale);
     */
    std::pair<Punto,Punto> getFuochi() const override;

    /**
     * @brief disegna
     */
    void disegna(QPainter*) const override;
};

#endif // ELLISSE_H
