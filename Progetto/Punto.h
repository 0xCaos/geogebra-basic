#ifndef PUNTO_PUNTO_H
#define PUNTO_PUNTO_H

#include "Disegnabile.h"

class Punto : public Disegnabile {
private:
    double x;
    double y;
public:

    /**
     * @brief Costruttore di Punto
     */
    Punto(string ="Punto", string ="#000000", double =0, double =0);

    ~Punto() = default;

    /**
     * @brief Getter della coordinata X del Punto
     * @return Ritorna un double (x)
     */
    double getX() const;

    /**
     * @brief Getter della coordinata Y del Punto
     * @return Ritorna un double (Y)
     */
    double getY() const;

    /**
     * @brief Calcolo della distanza tra il Punto di invocazione e il Punto passato come parametro
     * @return Ritorna un double (la distanza)
     */
    double getDistanza(const Punto&) const;

    /**
     * @brief operator std::string
     * overloading del convertitore a string per Punto
     * output => (x, y)
     */
    operator std::string() const;

    /**
     * @brief clone override di Disegnabile::clone()
     * @return un puntatore al nuovo Punto clonato
     */
    Punto* clone() const override;

    /**
     * @brief Override di Disegnabile::disegna()
     */
    void disegna(QPainter*, int) const override;

    /**
     * @brief getInfo override di Disegnabile::getInfo()
     * @return unordered_map con "Nome proprietà" => valore
     */
    std::unordered_map<string,string> getInfo() const override;

    /**
     * @brief operator ==
     * @return true se i due punti hanno le stesse coordinate, altrimenti false
     */
    bool operator==(const Punto& _p);

    void read(const QJsonObject&) override;
    void write(QJsonObject&) const override;
};


#endif //PUNTO_PUNTO_H
