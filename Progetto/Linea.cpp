#include "Linea.h"

Linea::Linea(std::string nome, QColor color, Punto* A, Punto* B) : Disegnabile(nome, color), punti(A, B) {}

std::pair<Punto*, Punto*> Linea::getPunti() const { return punti; }
