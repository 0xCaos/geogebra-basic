#include "Creator.h"

Punto* Creator::creaPunto() const {
    return new Punto();
}

Punto* Creator::creaPunto(std::string nome, string color, double x, double y) const {
    return new Punto(nome, color, x, y);
}

Segmento* Creator::creaSegmento(std::string nome, string color, Punto * A, Punto *B) const {
    return new Segmento(nome, color, A, B);
}

Retta* Creator::creaRetta(std::string nome, string color, Punto *A, Punto *B) const {
    return new Retta(nome, color, A, B);
}

Poligono* Creator::creaPoligono(std::string nome, string color, const Vettore<Punto *>& punti) const {
    return new Poligono(nome, color, punti);
}

Regolare* Creator::creaRegolare(std::string nome, string color, std::pair<Punto *, Punto *> punti, unsigned int numVertici) const {
    return new Regolare(nome, color, punti, numVertici);
}

Ellisse* Creator::creaEllisse(std::string nome, string color, Punto * centro, double semiAsse1, double semiAsse2) const {
    return new Ellisse(nome, color, centro, semiAsse1, semiAsse2);
}

Circonferenza* Creator::creaCirconferenza(std::string nome, string color, Punto *centro, double raggio) const {
    return new Circonferenza(nome, color, centro, raggio);
}
