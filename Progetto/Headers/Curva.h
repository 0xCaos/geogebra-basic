#ifndef CURVA_H
#define CURVA_H

#include "Figura.h"
//#include "Punto.h"

class Curva : public Figura
{
public:

    /**
     * @brief Costruttore di Curva
     */
    Curva(std::string nome, colori colore);

    /**
     * @brief Calcolo dell'eccentricità (rapporto costante tra le distanze di un qualsiasi
     * punto di una curva da un fuoco e dalla corrispondente direttrice.
     *      e==0 --> la curva è una circonferenza
     *      0<e<1 --> la curva è un'ellisse
     */
    virtual double eccentricita() const = 0;

    /**
     * @brief Calcolo dei Fuochi della Curva.
     *      L'ellisse ha 2 fuochi, mentre nella circonferenza i due fuochi collassano nel
     *      centro di essa.
     */
    virtual std::pair<Punto,Punto> getFuochi() const = 0;
};

#endif // CURVA_H
