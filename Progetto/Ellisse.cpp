#include "Ellisse.h"

#include "math.h"

Ellisse::Ellisse(std::string nome, string colore, Punto* _centro, double _raggio1, double _raggio2) :
    Curva((_raggio1<=0 || _raggio2<=0) ? throw std::domain_error("I due semiassi devono essere entrambi positivi.") : nome, colore),
    semiAsse1(_raggio1),
    semiAsse2(_raggio2),
    centro(*_centro)
{}

Ellisse::Ellisse() {}

double Ellisse::perimetro() const { return 2*M_PI*sqrt((pow(semiAsse1,2) + pow(semiAsse2,2))/2); }

double Ellisse::area() const { return M_PI*semiAsse1*semiAsse2; }

double Ellisse::getSemidistanzaFocale() const {
    if (semiAsse1 > semiAsse2) return sqrt(pow(semiAsse1,2) - pow(semiAsse2,2));
    return sqrt(pow(semiAsse2,2) - pow(semiAsse1,2));
}

double Ellisse::eccentricita() const
{
    if (semiAsse1 > semiAsse2) return getSemidistanzaFocale()/semiAsse1;
    return getSemidistanzaFocale()/semiAsse2;
}

std::pair<Punto, Punto> Ellisse::getFuochi() const
{
    Punto f1;
    Punto f2;
    double c = sqrt(getSemidistanzaFocale());
    if (semiAsse1 > semiAsse2) {
        f1 = Punto("Fuoco 1", "#000000", centro.getX()-c, centro.getY());
        f2 = Punto("Fuoco 2", "#000000", centro.getX()+c, centro.getY());
    } else {
        f1 = Punto("Fuoco 1", "#000000", centro.getX(), centro.getY()-c);
        f2 = Punto("Fuoco 2", "#000000", centro.getX(), centro.getY()+c);
    }
    return std::pair<Punto, Punto>(f1,f2);
}

void Ellisse::disegna(QPainter * p, int scala) const {
    p->drawEllipse((centro.getX()-semiAsse1)*scala, (-centro.getY()-semiAsse2)*scala, 2*semiAsse1*scala, 2*semiAsse2*scala);
}

std::unordered_map<std::string, std::string> Ellisse::getInfo() const {
    std::unordered_map<string, string> infoEllisse;
    infoEllisse["Eccentricità"] = std::to_string(eccentricita());
    infoEllisse["Area"] = std::to_string(area());
    infoEllisse["Perimetro"] = std::to_string(perimetro());
    infoEllisse["Fuochi"] = string(getFuochi().first) + " " + string(getFuochi().second);
    infoEllisse["Colore"] = getColore();
    infoEllisse["Nome"] = getNome();

    return infoEllisse;
}

Ellisse *Ellisse::clone() const {
    return new Ellisse(*this);
}

void Ellisse::read(const QJsonObject& jObj)
{
    setNome(jObj["nome"].toString().toStdString());
    setColor(jObj["color"].toString().toStdString());
    Punto p;
    QJsonObject jCentro = jObj["centro"].toObject();
    p.read(jCentro);
    centro = p;
    semiAsse1 = jObj["semiAsse1"].toDouble();
    semiAsse2 = jObj["semiAsse2"].toDouble();
}

void Ellisse::write(QJsonObject& jObj) const
{
    jObj["class"] = 4;
    jObj["nome"] = QString::fromStdString(getNome());
    jObj["color"] = QString::fromStdString(getColore());
    QJsonObject jCentro;
    centro.write(jCentro);
    jObj["centro"] = jCentro;
    jObj["semiAsse1"] = semiAsse1;
    jObj["semiAsse2"] = semiAsse2;
}

