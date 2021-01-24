#ifndef DISEGNABILE_H
#define DISEGNABILE_H

#include "Tipi.h"
#include "string"
#include <unordered_map>
#include <QColor>

using std::string;

#include <QPainter>

class Disegnabile {
protected:
    //enum colori {Rosso =1, Nero, Blu, Verde}; // definizione del tipo colori

    Disegnabile(string = "Disegno", QColor = Qt::black);
private:
    string nome;
    //int colore;
    QColor colore;
public:
    string getNome() const;
    QColor getColore() const;

    virtual void disegna(QPainter*) const =0;
    virtual std::unordered_map<string,string> getInfo() const =0;
    //virtual ~Disegnabile() =0;
};

#endif // DISEGNABILE_H
