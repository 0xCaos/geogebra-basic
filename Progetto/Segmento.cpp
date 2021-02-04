#include "Segmento.h"

Segmento::Segmento(std::string _nome, string _colore, Punto* a, Punto* b) : Linea(_nome, _colore, a, b) {}

Segmento::Segmento() {}

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
    infoSegmento["Colore"] = getColore();
    infoSegmento["Nome"] = getNome();

    return infoSegmento;
}

void Segmento::read(const QJsonObject& jObj)
{
    setNome(jObj["nome"].toString().toStdString());
    setColor(jObj["color"].toString().toStdString());
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
    jObj["color"] = QString::fromStdString(getColore());
    QJsonArray pairPunti;
    QJsonObject puntoAobj, puntoBobj;
    getPunti().first.write(puntoAobj);
    getPunti().second.write(puntoBobj);
    pairPunti.append(puntoAobj);
    pairPunti.append(puntoBobj);
    jObj["pairPunti"] = pairPunti;
}
