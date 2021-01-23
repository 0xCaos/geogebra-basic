#include "Figura.h"

Figura::Figura(std::string nome, colori colore, Punto puntoInizio) : Disegnabile(nome, colore), puntoInizio(puntoInizio){}

Punto Figura::getPuntoInizio() { return puntoInizio; }
