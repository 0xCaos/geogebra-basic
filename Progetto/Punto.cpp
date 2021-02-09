//
// Created by matteo on 19/01/21.
//

#include <math.h>
#include "Punto.h"

Punto::Punto(string nome, string colore, double _x, double _y) : Disegnabile(nome, colore), x(_x), y(_y) {}

double Punto::getX() const { return x; }

double Punto::getY() const { return y; }

double Punto::getDistanza(const Punto& p) const
{
    double d;
    d = sqrt(pow((x - p.getX()),2) + pow((y - p.getY()),2));
    return d;
}

Punto *Punto::clone() const {
    return new Punto(*this);
}

Punto::operator std::string() const {
    return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
}

std::unordered_map<string, string> Punto::getInfo() const {
    std::unordered_map<string, string> infoPunto;
    infoPunto["Coordinate"] = *this;
    infoPunto["Nome"] = getNome();

    return infoPunto;
}

bool Punto::operator==(const Punto &_p) {
    return getX() == _p.getX() && getY() == _p.getY();
}

void Punto::disegna(QPainter* p, int scala) const {
    p->drawPoint(x*scala,-y*scala);
    p->setPen(QColor(Qt::black));
    p->setFont(QFont(QString("Verdana"), 3));
    p->drawText((x-0.1)*scala, -((y+0.3)*scala), QString::fromStdString(getNome()));
}

void Punto::read(const QJsonObject& jObj) {
    setNome(jObj["nome"].toString().toStdString());
    setColor(jObj["color"].toString().toStdString());
    x = jObj["x"].toDouble();
    y = jObj["y"].toDouble();
}

void Punto::write(QJsonObject& jObj) const {
    jObj["class"] = 6;
    jObj["nome"] = QString::fromStdString(getNome());
    jObj["color"] = QString::fromStdString(getColore());
    jObj["x"] = x;
    jObj["y"] = y;
}
