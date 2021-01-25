#ifndef LINEA_H
#define LINEA_H

#include "Disegnabile.h"
#include "Punto.h"

class Linea : public Disegnabile {
private:
    std::pair<Punto,Punto> punti;

protected:
    Linea(string, QColor, Punto, Punto);

public:
    /**
     * @brief getPunti
     * @return ritorna i punti per cui passa una linea e che la identificano
     */
    std::pair<Punto, Punto> getPunti() const;

    ~Linea() =default;
};

#endif // LINEA_H
