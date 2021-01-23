#include <iostream>

#include "Segmento.h"

int main() {
    Punto a(2,2);
    Punto b(6,2);
    Segmento ab(a, b);
    std::cout << ab.getLunghezza() << std::endl;
}
