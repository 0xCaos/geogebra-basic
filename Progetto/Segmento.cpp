//
// Created by matteo on 23/01/21.
//

#include "Segmento.h"

Segmento::Segmento(std::string nome, QColor colore, Punto a, Punto b) : Disegnabile(nome, colore), punti(a,b) {}

std::pair<Punto, Punto> Segmento::getPunti() const { return punti; }

double Segmento::getLunghezza() const { return punti.first.getDistanza(punti.second); }

std::unordered_map<std::string, std::string> Segmento::getInfo() const {
    std::unordered_map<string, string> infoSegmento;
    infoSegmento["Lunghezza"] = std::to_string(getLunghezza());
    infoSegmento["Secondo Punto"] = punti.second;
    infoSegmento["Primo Punto"] = punti.first;
    infoSegmento["Nome"] = getNome();

    return infoSegmento;
}
