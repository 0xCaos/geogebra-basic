//
// Created by matteo on 23/01/21.
//

#include "Segmento.h"

double Segmento::getLunghezza() {
    return punti.first.getDistanza(punti.second);
}
