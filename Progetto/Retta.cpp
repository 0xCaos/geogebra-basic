#include "Retta.h"

Retta::Retta(string nome, QColor colore, Punto* a, Punto* b) :
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
    infoRetta["Passa per"] = string(*getPunti().first) + " e " + string(*getPunti().second);
    infoRetta["Nome"] = getNome();

    return infoRetta;
}

void Retta::disegna(QPainter *p) const {
    double x1 = 100;
    double x2 = -100;
    double y1 = x1*m+q;
    double y2 = x2*m+q;
    p->drawLine(
        x1*10,
        -y1*10,
        x2*10,
        -y2*10
    );
}

Retta *Retta::clone() const {
    return new Retta(*this);
}
