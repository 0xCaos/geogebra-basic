#ifndef CREATOR_H
#define CREATOR_H

#include "Gerarchia.h"

class Creator {
public:

    Punto* creaPunto() const;
    Punto* creaPunto(string, QColor, double, double) const;


};

#endif // CREATOR_H
