#ifndef ELLISSE_H
#define ELLISSE_H

#include "Circonferenza.h"

class Ellisse : public Curva
{
private:
    double semiAsse1;
    double semiAsse2;
    Punto centro;
public:
    /**
     * @brief Costruttore di Ellisse
     * @default         costruisco una circonferenza goniometrica
     */
    Ellisse(std::string, string, Punto*, double, double);

    Ellisse();

    ~Ellisse() =default;

    /**
     * @brief Calcolo del perimetro dell'ellisse
     * @return 2 * PI_GRECO * radiceQuadrata((raggio1^2 + raggio2^2)/2)
     */
    double perimetro() const override;

    /**
     * @brief Calcolo dell'area dell'ellisse
     * @return PI_GRECO * raggio1 * raggio2;
     */
    double area() const override;

    /**
     * @brief Calcolo della semidistanza fra i due fuochi
     * @return radiceQuadrata( raggioMaggiore^2 - raggioMinore^2)
     */
    double getSemidistanzaFocale() const;

    /**
     * @brief Calcolo dell'eccentricità
     * @return semiDistanzaFocale / radiceQuadrata(semi asse maggiore)
     */
    double eccentricita() const override;

    /**
     * @brief Calcolo del fuochi dell'ellisse
     * @return
     *      se raggio1 > raggio2
     *          fuoco1(xCentro - semiDistanzaFocale, yCentro);
     *          fuoco2(xCentro + semiDistanzaFocale, yCentro);
     *      altrimenti
     *          fuoco1(xCentro, yCentro - semiDistanzaFocale);
     *          fuoco2(xCentro, yCentro + semiDistanzaFocale);
     */
    std::pair<Punto,Punto> getFuochi() const override;

    /**
     * @brief disegna (Override di Disegnabile::disegna())
     */
    void disegna(QPainter*, int) const override;

    /**
     * @brief getInfo (override di Disegnabile::getInfo)
     * @return unordered_map con "Nome proprietà" => valore
     */
    std::unordered_map<string, string> getInfo() const override;

    /**
     * @brief clone override di Disegnabile::clone()
     * @return un puntatore alla nuova Ellisse clonata
     */
    Ellisse* clone() const override;

    void read(const QJsonObject&) override;
    void write(QJsonObject&) const override;
};

#endif // ELLISSE_H
