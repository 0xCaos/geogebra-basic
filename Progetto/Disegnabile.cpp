#include "Disegnabile.h"

Disegnabile::Disegnabile(std::string nome, QColor colore) : nome(nome), colore(colore) {}

std::string Disegnabile::getNome() const { return nome; }

QColor Disegnabile::getColore() const { return colore; }

void Disegnabile::setNome(std::string _nome) { nome = _nome; }

void Disegnabile::setColor(QString _colore) { colore = QColor(_colore); }
