//
// Created by matteo on 19/01/21.
//

#ifndef PUNTO_PUNTO_H
#define PUNTO_PUNTO_H

#include "Disegnabile.h"

class Punto : public Disegnabile {
private:
    double x;
    double y;
public:

    /**
     * @brief Costruttore di Punto
     */
    Punto(string ="Punto", colori =Nero, double =0, double =0);

    //~Punto() = default;

    /**
     * @brief Getter della coordinata X del Punto
     * @return Ritorna un double (x)
     */
    double getX();

    /**
     * @brief Getter della coordinata Y del Punto
     * @return Ritorna un double (Y)
     */
    double getY();

    /**
     * @brief Calcolo della distanza tra il Punto di invocazione e il Punto passato come parametro
     * @return Ritorna un double (la distanza)
     */
    double getDistanza(Punto);

    /**
     * @brief Override di Disegnabile::disegna()
     */
    void disegna(QPainter*) const override;

    /**
     * @brief getInfo override di Disegnabile::getInfo()
     * @return una map con tutte le info relative al punto
     */
    std::unordered_map<string,string> getInfo() const override;
};


#endif //PUNTO_PUNTO_H
