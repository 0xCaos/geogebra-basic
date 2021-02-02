#include "Poligono.h"

bool Poligono::crossProductSign(const Punto& A, const Punto& B, const Punto& C){
    return signbit((B.getX() - A.getX()) * (C.getY() - B.getY()) - (B.getY() - A.getY()) * (C.getX() - B.getX()));
}

bool Poligono::concavo() const {
    int numVertici = vertici.size();
    if(numVertici < 4) return false;

    bool check = crossProductSign(vertici[0], vertici[1], vertici[2]);
    bool isConcavo = check;
    for(int i=1; i < numVertici && check==isConcavo; i++){
        check = crossProductSign(vertici[i], vertici[(i+1)%numVertici], vertici[(i+2)%numVertici]);
    }
    if(check == isConcavo) return false; // convesso
    else return true; // concavo
}

void Poligono::disegna(QPainter *p, int scala) const {
    int n = vertici.size();
    for(u_int i=0; i < vertici.size(); ++i) {
        Punto A = vertici[i];
        Punto B = vertici[(i+1)%n];
        p->drawLine(
            A.getX()*scala,
            -A.getY()*scala,
            B.getX()*scala,
            -B.getY()*scala
        );
    }
}

std::unordered_map<std::string, std::string> Poligono::getInfo() const {
    std::unordered_map<string, string> infoPoligono;
    infoPoligono["Concavità"] = concavo()?"Concavo":"Convesso";
    infoPoligono["Area"] = std::to_string(area());
    infoPoligono["Perimetro"] = std::to_string(perimetro());
    infoPoligono["Vertici"] = std::to_string(vertici.size());
    infoPoligono["Colore"] = "Nero";
    infoPoligono["Nome"] = getNome();

    return infoPoligono;
}

Poligono::Poligono(std::string nome , QColor color, const Vettore<Punto*>& vettVertici) :
    Figura(nome,color)
{
    bool duplicati = false;
    for(auto i = vettVertici.begin(); i != vettVertici.end() && !duplicati; ++i)
        for(auto j = i+1; j != vettVertici.end() && !duplicati; ++j)
            if (**i == **j) duplicati = true;
    if(duplicati)
        throw std::logic_error("Attenzione: non puoi inserire più volte lo stesso punto.");
    for(auto p : vettVertici){
        vertici.push_back(*p);
    }
}

void Poligono::setVertici(const Vettore<Punto*>& newVertici) {
    for(auto p : newVertici){
        vertici.push_back(*p);
    }
}

double Poligono::perimetro() const {
    int numVertici = vertici.size();
    double valore = 0;
    if(numVertici > 2){ // almeno un triangolo
        for(int i=0; i < numVertici-1; i++){
            valore += vertici[i].getDistanza(vertici[i+1]);
        }
        valore += vertici[numVertici-1].getDistanza(vertici[0]);
    }

    return valore;
}

double Poligono::area() const {
    double a = 0;
    int numVertici = vertici.size();

    for(int i = 0; i < numVertici-1; i++)
        a += vertici[i].getX() * vertici[i+1].getY() - vertici[i+1].getX() * vertici[i].getY();

    a += vertici[numVertici-1].getX() * vertici[0].getY() - vertici[0].getX()* vertici[numVertici-1].getY();

    return std::abs(a)/2;
}

Poligono *Poligono::clone() const {
    return new Poligono(*this);
}


