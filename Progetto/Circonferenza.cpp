#include "Circonferenza.h"

#include "math.h"

Circonferenza::Circonferenza(std::string _nome, string _colore, Punto* _centro, double _raggio) :
    Curva((_raggio <= 0) ? throw std::domain_error("Il raggio deve essere positivo.") : _nome, _colore),
    raggio(_raggio),
    centro(*_centro)
{}

Circonferenza::Circonferenza() {}

double Circonferenza::diametro() const { return raggio*2; }

double Circonferenza::perimetro() const { return diametro()*M_PI; }

double Circonferenza::area() const { return pow(raggio,2)*M_PI; }

double Circonferenza::eccentricita() const { return 0; }

std::pair<Punto, Punto> Circonferenza::getFuochi() const { return std::pair<Punto,Punto>(centro, centro); }

double Circonferenza::getRaggio() const { return raggio; }

const Punto* Circonferenza::getCentro() const { return &centro; }

void Circonferenza::disegna(QPainter * p, int scala) const {
    p->drawEllipse((centro.getX()-raggio)*scala, (-centro.getY()-raggio)*scala, 2*raggio*scala, 2*raggio*scala);
}

std::unordered_map<std::string, std::string> Circonferenza::getInfo() const {
    std::unordered_map<string, string> infoCirconferenza;
    infoCirconferenza["Area"] = std::to_string(area());
    infoCirconferenza["Perimeter"] = std::to_string(perimetro());
    infoCirconferenza["Diameter"] = std::to_string(diametro());
    infoCirconferenza["Center"] = *getCentro();
    infoCirconferenza["Color"] = getColore();
    infoCirconferenza["Name"] = getNome();

    return infoCirconferenza;
}

Circonferenza *Circonferenza::clone() const {
    return new Circonferenza(*this);
}

void Circonferenza::read(const QJsonObject& jObj)
{
    setNome(jObj["nome"].toString().toStdString());
    setColor(jObj["color"].toString().toStdString());
    Punto p;
    QJsonObject jCentro = jObj["centro"].toObject();
    p.read(jCentro);
    centro = p;
    raggio = jObj["raggio"].toDouble();
}

void Circonferenza::write(QJsonObject& jObj) const
{
    jObj["class"] = 5;
    jObj["nome"] = QString::fromStdString(getNome());
    jObj["color"] = QString::fromStdString(getColore());
    QJsonObject jCentro;
    centro.write(jCentro);
    jObj["centro"] = jCentro;
    jObj["raggio"] = raggio;
}
