//
// Created by matteo on 19/01/21.
//

#ifndef PUNTO_PUNTO_H
#define PUNTO_PUNTO_H


class Punto {
private:
    double x;
    double y;
public:
    Punto(double _x=0, double _y=0) : x(_x), y(_y) {}
    double getX();
    double getY();
    double getDistanza(Punto);
    void Disegna();
};


#endif //PUNTO_PUNTO_H
