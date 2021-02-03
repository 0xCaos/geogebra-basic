//
// Created by matteo on 23/01/21.
//

#include "Segmento.h"

Segmento::Segmento(std::string nome, QColor colore, Punto* a, Punto* b) : Linea(nome, colore, a, b) {}

double Segmento::getLunghezza() const { return getPunti().first.getDistanza(getPunti().second); }

Segmento *Segmento::clone() const {
    return new Segmento(*this);
}

void Segmento::disegna(QPainter *p, int scala) const {
    p->drawLine(
        getPunti().first.getX()*scala,
        -getPunti().first.getY()*scala,
        getPunti().second.getX()*scala,
        -getPunti().second.getY()*scala
    );
}

std::unordered_map<std::string, std::string> Segmento::getInfo() const {
    std::unordered_map<string, string> infoSegmento;
    infoSegmento["Lunghezza"] = std::to_string(getLunghezza());
    infoSegmento["Secondo Punto"] = getPunti().second;
    infoSegmento["Primo Punto"] = getPunti().first;
    infoSegmento["Colore"] = getColore().name().toStdString();
    infoSegmento["Nome"] = getNome();

    return infoSegmento;
}
