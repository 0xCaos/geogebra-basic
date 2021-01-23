#ifndef DISEGNABILE_H
#define DISEGNABILE_H

#include "string"
using std::string;

#include <QPainter>

class Disegnabile {
protected:
    enum colori {Rosso =1, Nero, Blu, Verde}; // definizione del tipo colori
    Disegnabile(string = "Disegno", colori = Nero);
private:
    string nome;
    colori colore;
public:
    virtual void disegna(QPainter*) =0;
};

#endif // DISEGNABILE_H
