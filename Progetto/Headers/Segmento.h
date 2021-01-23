//
// Created by matteo on 23/01/21.
//

#ifndef SEGMENTO_SEGMENTO_H
#define SEGMENTO_SEGMENTO_H

#include <iostream>

#include "Punto.h"
#include "Disegnabile.h"

class Segmento : public Disegnabile {
private:
    std::pair<Punto,Punto> punti;
public:

    /**
     * @brief Costruttore di Segmento
     * @param Punto 1
     * @param Punto 2
     */
    Segmento(string, colori, Punto, Punto);

    /**
     * @brief Lunghezza del Segmento
     * @return Ritorna la lunghezza (double)
     */
    double getLunghezza();

    /**
     * @brief override di Disegnabile::disegna()
     */
    void disegna(QPainter*) override;
};


#endif //SEGMENTO_SEGMENTO_H
