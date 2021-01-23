#ifndef DISEGNABILE_H
#define DISEGNABILE_H

#include "Tipi.h"
#include "string"
using std::string;

#include <QPainter>

class Disegnabile {
protected:
    //enum colori {Rosso =1, Nero, Blu, Verde}; // definizione del tipo colori

    Disegnabile(string = "Disegno", colori = Nero);
private:
    string nome;
    //int colore;
    colori colore;
public:
    virtual void disegna(QPainter*) const =0;

    //virtual ~Disegnabile() =0;
};

#endif // DISEGNABILE_H
