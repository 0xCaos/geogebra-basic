#include "Retta.h"

using std::string;

Retta::Retta(string nome, colori colore, Punto a, Punto b) :
    Segmento(nome, colore, a, b),
    paralleloX(a.getY() == b.getY()),
    paralleloY(a.getX() == b.getX())
{
    if (paralleloX || paralleloY) m = 0;
    if (paralleloX) q = a.getY();
    if (paralleloY) q = a.getX();
    else {
        m = (b.getY() - a.getY())/(b.getX() - a.getX());
        q = a.getY() - m*a.getX();
    }
}

double Retta::getM() { return m; }

double Retta::getQ() { return q; }

std::string Retta::getFormula()
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
