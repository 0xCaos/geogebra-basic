#include "Retta.h"

Retta::Retta(string nome, string colore, Punto* a, Punto* b) :
    Linea(nome, colore, a, b),
    paralleloX(a->getY() == b->getY()),
    paralleloY(a->getX() == b->getX())
{
    if (paralleloX || paralleloY) m = 0;
    if (paralleloX) q = a->getY();
    if (paralleloY) q = a->getX();
    else {
        m = (b->getY() - a->getY())/(b->getX() - a->getX());
        q = a->getY() - m*a->getX();
    }
}

Retta::Retta() {}

double Retta::getM() const { return m; }

double Retta::getQ() const { return q; }

std::string Retta::getFormula() const
{
    if (m) {
        string sign = "+";
        double q = getQ();
        if (getQ() < 0) {
            sign = "-";
            q *= -1;
        }
        return "y = " + std::to_string(getM()) + "x " + sign + " " + std::to_string(q);
    } else {
        if (paralleloX) return "y = " + std::to_string(getQ());
        else return "x = " + std::to_string(getQ());
    }
}

std::unordered_map<std::string, std::string> Retta::getInfo() const {
    std::unordered_map<string, string> infoRetta;
    infoRetta["Formula"] = getFormula();
    infoRetta["Passa per"] = string(getPunti().first) + " e " + string(getPunti().second);
    infoRetta["Colore"] = getColore();
    infoRetta["Nome"] = getNome();

    return infoRetta;
}

void Retta::disegna(QPainter *p, int scala) const {
    double x1 = 100;
    double x2 = -100;
    double y1 = x1*m+q;
    double y2 = x2*m+q;
    p->drawLine(
        x1*scala,
        -y1*scala,
        x2*scala,
        -y2*scala
    );
}

Retta *Retta::clone() const {
    return new Retta(*this);
}

void Retta::read(const QJsonObject& jObj)
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
    m = jObj["m"].toDouble();
    q = jObj["q"].toDouble();
    paralleloX = jObj["paralleloX"].toBool();
    paralleloY = jObj["paralleloY"].toBool();
}

void Retta::write(QJsonObject& jObj) const {
    jObj["class"] = 1;
    jObj["nome"] = QString::fromStdString(getNome());
    jObj["color"] = QString::fromStdString(getColore());
    QJsonArray pairPunti;
    QJsonObject puntoAobj, puntoBobj;
    getPunti().first.write(puntoAobj);
    getPunti().second.write(puntoBobj);
    pairPunti.append(puntoAobj);
    pairPunti.append(puntoBobj);
    jObj["pairPunti"] = pairPunti;
    jObj["m"] = m;
    jObj["q"] = q;
    jObj["paralleloX"] = paralleloX;
    jObj["paralleloY"] = paralleloY;
}
