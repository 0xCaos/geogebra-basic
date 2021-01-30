#include "Linea.h"

Linea::Linea(std::string nome, QColor color, Punto* A, Punto* B) :
    //Disegnabile((*A==*B) ? throw std::logic_error("Attenzione: le coordinate dei due punti non possono coincidere.") : nome, color),
    Disegnabile(nome, color),
    punti(*A, *B)
{}

const std::pair<Punto, Punto>& Linea::getPunti() const { return punti; }
