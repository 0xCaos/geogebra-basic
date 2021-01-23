#ifndef RETTA_H
#define RETTA_H

#import "Segmento.h"

class Retta : public Segmento {
private:
    double m;
    double q;
    bool paralleloX;
    bool paralleloY;
public:

    /**
     * @brief Costruttore di Retta --> y = mx + q
     * Calcolo del coefficiente angolare "m" --> m = (y2-y1)/(x2-x1)
     * Calcolo di quota all'origine "q" --> q = y1 - m*x1
     */
    Retta(string, colori, Punto, Punto);

    /**
     * @brief Getter del coefficiente angolare
     */
    double getM();

    /**
     * @brief Getter della quota all'origine
     */
    double getQ();

    /**
     * @brief Generatore della formula della Retta
     */
    std::string getFormula();
};

#endif // RETTA_H
