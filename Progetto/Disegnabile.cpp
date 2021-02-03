#include "Disegnabile.h"

Disegnabile::Disegnabile(string nome, string colore) : nome(nome), colore(colore) {}

std::string Disegnabile::getNome() const { return nome; }

string Disegnabile::getColore() const { return colore; }

void Disegnabile::setNome(std::string _nome) { nome = _nome; }

void Disegnabile::setColor(string _colore) { colore = _colore; }
