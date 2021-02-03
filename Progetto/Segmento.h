#ifndef SEGMENTO_SEGMENTO_H
#define SEGMENTO_SEGMENTO_H

#include "Linea.h"

class Segmento : public Linea {
public:

    /**
     * @brief Costruttore di Segmento
     * @param Punto 1
     * @param Punto 2
     */
    Segmento(string ="", string ="#000000", Punto* =new Punto(), Punto* =new Punto());

    ~Segmento() =default;

    /**
     * @brief Lunghezza del Segmento
     * @return Ritorna la lunghezza (double)
     */
    double getLunghezza() const;

    /**
     * @brief clone override di Disegnabile::clone()
     * @return un puntatore al nuovo Segmento clonato
     */
    Segmento* clone() const override;

    /**
     * @brief override di Disegnabile::disegna()
     */
    void disegna(QPainter*, int) const override;;

    /**
     * @brief getInfo override di Disegnabile::getInfo()
     * @return unordered_map con "Nome proprietà" => valore
     */
    std::unordered_map<string,string> getInfo() const override;

    void read(const QJsonObject&) override;
    void write(QJsonObject&) const override;


};


#endif //SEGMENTO_SEGMENTO_H
