#include "Regolare.h"
#include "math.h"

double Regolare::getCostanteArea(unsigned int id) const {
    return costantiAree[id-3];
}

Regolare::Regolare(std::string nome, string color, std::pair<Punto*, Punto*> _punti, unsigned int numVertici) :
    Figura(nome, color)
{
    if (numVertici<3 || numVertici>12)
        throw std::logic_error("Il numero di vertici deve essere compreso tra 3 e 12 (inclusi)");
    if (_punti.first && _punti.second && *_punti.first == *_punti.second)
        throw std::logic_error("Le coordinate dei due punti non possono coincidere");
    punti = {*_punti.first, *_punti.second};
    lato = punti.first.getDistanza(punti.second);
    numLati = numVertici;
}

Regolare::Regolare() {} //invoca Figura::Figura() di default

double Regolare::perimetro() const {
    return lato * numLati;
}

double Regolare::area() const {
    double costante = getCostanteArea(numLati);
    return (lato*lato)*costante;
}

void Regolare::disegna(QPainter *p, int scala) const {
    double xA = punti.first.getX();
    double xB = punti.second.getX();
    double yA = punti.first.getY();
    double yB = punti.second.getY();

    double coseno = cos((180/numLati)*M_PI/180);

    double AB = punti.first.getDistanza(punti.second);
    double apotema = 2*area()/perimetro();
    double raggio = apotema/coseno; // AC - BC

    double f1 = atan2(yB-yA,xB-xA) * 180/M_PI;
    double f2 = acos((pow(AB,2))/(2*raggio*AB)) * 180/M_PI;

    double xC = xA + raggio * (cos((f1+f2)*M_PI/180));
    double yC = yA + raggio * (sin((f1+f2)*M_PI/180));

    double d = punti.first.getDistanza(Punto("P","#000000", xC, yC+raggio));
    double angolo = acos((2*pow(raggio,2)-pow(d,2))/(2*pow(raggio,2))) * 180/M_PIl;

    for (unsigned int i=0; i<numLati; ++i) {
        double xP1 = xC + raggio*sin((2*M_PIl*i/numLati)+angolo*M_PIl/180);
        double yP1 = yC + raggio*cos((2*M_PIl*i/numLati)+angolo*M_PIl/180);
        double xP2 = xC + raggio*sin((2*M_PIl*(i+1)/numLati)+angolo*M_PIl/180);
        double yP2 = yC + raggio*cos((2*M_PIl*(i+1)/numLati)+angolo*M_PIl/180);
        p->drawLine(
            xP1*scala,
            -yP1*scala,
            xP2*scala,
            -yP2*scala
        );
    }
}

std::unordered_map<string, string> Regolare::getInfo() const {
    std::unordered_map<string, string> infoRegolare;
    infoRegolare["Area"] = std::to_string(area());
    infoRegolare["Perimetro"] = std::to_string(perimetro());
    infoRegolare["Vertici"] = std::to_string(numLati);
    infoRegolare["Colore"] = getColore();
    infoRegolare["Nome"] = getNome();

    return infoRegolare;
}

Regolare *Regolare::clone() const {
    return new Regolare(*this);
}

void Regolare::read(const QJsonObject& jObj)
{
    setNome(jObj["nome"].toString().toStdString());
    setColor(jObj["color"].toString().toStdString());
    QJsonArray pairPunti = jObj["pairPunti"].toArray();
    QJsonObject puntoA = pairPunti[0].toObject();
    QJsonObject puntoB = pairPunti[1].toObject();
    Punto A,B;
    A.read(puntoA);
    B.read(puntoB);
    punti.first = A;
    punti.second = B;
    lato = A.getDistanza(B);
    numLati = jObj["numLati"].toInt();
}

void Regolare::write(QJsonObject& jObj) const
{
    jObj["class"] = 3;
    jObj["nome"] = QString::fromStdString(getNome());
    jObj["color"] = QString::fromStdString(getColore());
    QJsonArray pairPunti;
    QJsonObject puntoAobj, puntoBobj;
    punti.first.write(puntoAobj);
    punti.second.write(puntoBobj);
    pairPunti.append(puntoAobj);
    pairPunti.append(puntoBobj);
    jObj["pairPunti"] = pairPunti;
    jObj["lato"] = lato;
    QVariant QVariantNumLati = QVariant::fromValue(numLati);
    jObj["numLati"] = QVariantNumLati.toInt();
}
