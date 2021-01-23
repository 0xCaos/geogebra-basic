#include <iostream>
#include "Punto.h"

int main() {
    Punto a(-2,2);
    Punto b(1,-1);
    std::cout << a.getDistanza(b);
}
