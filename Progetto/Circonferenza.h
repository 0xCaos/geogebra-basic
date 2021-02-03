#ifndef CIRCONFERENZA_H
#define CIRCONFERENZA_H

#include "Curva.h"

class Circonferenza : public Curva {
private:
    double raggio;
    Punto centro;

public:

    /**
     * @brief Costruttore di Circonferenza
     */
    Circonferenza(string nome="", QColor colore=Qt::black, Punto* centro=new Punto, double raggio=1);

    ~Circonferenza() =default;

    /**
     * @brief Calcolo del diametro
     *      --> Raggio * 2
     */
    double diametro() const;

    /**
     * @brief Calcolo del perimetro del cerchio (o circonferenza)
     *      --> Diametro * PI_GRECO
     */
    double perimetro() const override;

    /**
     * @brief Calcolo dell'area del cerchio
     *      --> Raggio^2 * PI_Greco
     */
    double area() const override;

    /**
     * @brief Nella circonferenza, eccentricità e == 0
     *      --> ritorna sempre 0
     */
    double eccentricita() const override;

    /**
     * @brief Nella circonferenza, i due fuochi collassano al centro
     * @return pair<p1,p2> dove p1 == p2 == centro
     */
    std::pair<Punto,Punto> getFuochi() const override;

    /**
     * @brief Getter del raggio della circonferenza
     */
    double getRaggio() const;

    /**
     * @brief Getter del centro della circonferenza
     */
    const Punto* getCentro() const;

    /**
     * @brief override di Disegnabile::disegna()
     */
    void disegna(QPainter*, int) const override;

    /**
     * @brief getInfo (override di Disegnabile::getInfo)
     * @return unordered_map con "Nome proprietà" => valore
     */
    std::unordered_map<string, string> getInfo() const override;

    /**
     * @brief clone override di Disegnabile::clone()
     * @return un puntatore alla nuova Circonferenza clonata
     */
    Circonferenza* clone() const override;

    void read(const QJsonObject&) override;
    void write(QJsonObject&) const override;
};

#endif // CIRCONFERENZA_H
