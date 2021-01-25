#include "Creator.h"

Punto *Creator::creaPunto() const {
    return new Punto();
}

Punto *Creator::creaPunto(std::string nome, QColor color, double x, double y) const {
    return new Punto(nome, color, x, y);
}
