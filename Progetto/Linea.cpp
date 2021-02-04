#include "Linea.h"

Linea::Linea(std::string nome, string color, Punto* A, Punto* B) :
    Disegnabile((*A==*B) ? throw std::logic_error("Attenzione: le coordinate dei due punti non possono coincidere.") : nome, color),
    punti(*A, *B)
{}

Linea::Linea(std::string nome, std::string color) : Disegnabile(nome, color) {}

const std::pair<Punto, Punto>& Linea::getPunti() const { return punti; }

void Linea::setPunti(Punto A, Punto B) {
    punti = {A,B};
}
