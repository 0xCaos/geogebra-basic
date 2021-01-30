//
// Created by matteo on 23/01/21.
//

#include "Segmento.h"

Segmento::Segmento(std::string nome, QColor colore, Punto* a, Punto* b) : Linea(nome, colore, a, b) {}

double Segmento::getLunghezza() const { return getPunti().first->getDistanza(*getPunti().second); }

Segmento *Segmento::clone() const {
    return new Segmento(*this);
}

void Segmento::disegna(QPainter *p) const {
    p->drawLine(
        getPunti().first->getX()*10,
        -getPunti().first->getY()*10,
        getPunti().second->getX()*10,
        -getPunti().second->getY()*10
    );
}

std::unordered_map<std::string, std::string> Segmento::getInfo() const {
    std::unordered_map<string, string> infoSegmento;
    infoSegmento["Lunghezza"] = std::to_string(getLunghezza());
    infoSegmento["Secondo Punto"] = *getPunti().second;
    infoSegmento["Primo Punto"] = *getPunti().first;
    infoSegmento["Nome"] = getNome();

    return infoSegmento;
}
