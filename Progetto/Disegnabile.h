#ifndef DISEGNABILE_H
#define DISEGNABILE_H

#include "string"
#include <unordered_map>
#include <QJsonObject>
#include <QJsonArray>

using std::string;

#include <QPainter>

class Disegnabile {
protected:
    Disegnabile(string = "Disegno", string = "#000000");

private:
    string nome;
    string colore;

public:
    string getNome() const;
    string getColore() const;

    /**
     * @brief clone         metodo per la clonazione polimorfa
     * @return              puntatore all'oggetto di una delle classi concrete derivate
     */
    virtual Disegnabile* clone() const =0;

    /**
     * @brief disegna       utilizza un metodo QT per la stampa a video dell'oggetto
     */
    virtual void disegna(QPainter*, int) const =0;

    /**
     * @brief getInfo       Getter di tutte le informazioni relative all'oggetto
     * @return              Unordered Map che associa i parametri alle relative descrizioni
     */
    virtual std::unordered_map<string,string> getInfo() const =0;

    virtual ~Disegnabile() =default;
    
    /**
     * @brief read          Scrittura dei parametri dall'oggetto JSON all'oggetto della gerarchia
     */
    virtual void read(const QJsonObject&) = 0;

    /**
     * @brief write         Scrittura dei parametri dall'oggetto della gerarchia all'oggetto JSON
     */
    virtual void write(QJsonObject&) const = 0;

    void setNome(string);
    void setColor(string);
};

#endif // DISEGNABILE_H
