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

void Segmento::read(const QJsonObject& jObj)
{
    setNome(jObj["nome"].toString().toStdString());
    setColor(jObj["color"].toString());
    QJsonArray pairPunti = jObj["pairPunti"].toArray();
    QJsonObject puntoA = pairPunti[0].toObject();
    QJsonObject puntoB = pairPunti[1].toObject();
    Punto A,B;
    A.read(puntoA);
    B.read(puntoB);
    setPunti(A,B);
}

void Segmento::write(QJsonObject& jObj) const {
    jObj["class"] = 0;
    jObj["nome"] = QString::fromStdString(getNome());
    jObj["color"] = getColore().name();
    QJsonArray pairPunti;
    QJsonObject puntoAobj, puntoBobj;
    getPunti().first.write(puntoAobj);
    getPunti().second.write(puntoBobj);
    pairPunti.append(puntoAobj);
    pairPunti.append(puntoBobj);
    jObj["pairPunti"] = pairPunti;
}
