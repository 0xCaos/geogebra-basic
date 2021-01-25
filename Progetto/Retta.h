#ifndef RETTA_H
#define RETTA_H

#include "Segmento.h"

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
    Retta(string, QColor, Punto, Punto);

    /**
     * @brief Getter del coefficiente angolare
     */
    double getM() const;

    /**
     * @brief Getter della quota all'origine
     */
    double getQ() const;

    double getLunghezza() const =delete; // per una retta non ha senso chiedere la lunghezza

    /**
     * @brief Generatore della formula della Retta
     */
    std::string getFormula() const;

    /**
     * @brief getInfo override di Disegnabile::getInfo()
     * @return unordered_map con "Nome proprietà" => valore
     */
    std::unordered_map<string,string> getInfo() const override;
};

#endif // RETTA_H
