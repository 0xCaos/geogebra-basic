#include "Disegnabile.h"

Disegnabile::Disegnabile(std::string nome, QColor colore) : nome(nome), colore(colore) {}

std::string Disegnabile::getNome() const { return nome; }

QColor Disegnabile::getColore() const { return colore; }
