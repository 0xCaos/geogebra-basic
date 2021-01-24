#include "Disegnabile.h"

Disegnabile::Disegnabile(std::string nome, colori colore) : nome(nome), colore(colore) {}

std::string Disegnabile::getNome() const { return nome; }

colori Disegnabile::getColore() const { return colore; }
