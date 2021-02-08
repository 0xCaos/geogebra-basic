#ifndef CREATOR_H
#define CREATOR_H

#include "Segmento.h"
#include "Retta.h"
#include "Poligono.h"
#include "Regolare.h"
#include "Circonferenza.h"
#include "Ellisse.h"

class Creator {
public:
    /**
     * La classe Creator è di appoggio al controller.
     * Ogni metodo ritorna un puntatore all'oggetto concreto di "Gerarchia.h"
     * appena allocato nello heap, dopo aver invocato i costruttori presenti
     * nella gerarchia.
     */
    Punto* creaPunto() const;
    Punto* creaPunto(string, string, double, double) const;
    Segmento* creaSegmento(string, string, Punto*, Punto*) const;
    Retta* creaRetta(string, string, Punto*, Punto*) const;
    Poligono* creaPoligono(string, string, Vettore<Punto*>) const;
    Regolare* creaRegolare(string, string, std::pair<Punto*, Punto*>, unsigned int) const;
    Ellisse* creaEllisse(string, string, Punto*, double, double) const;
    Circonferenza* creaCirconferenza(string, string, Punto*, double) const;
};

#endif // CREATOR_H
