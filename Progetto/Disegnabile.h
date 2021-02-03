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

    virtual Disegnabile* clone() const =0;
    virtual void disegna(QPainter*, int) const =0;
    virtual std::unordered_map<string,string> getInfo() const =0;
    virtual ~Disegnabile() =default;
    
    virtual void read(const QJsonObject&) = 0;
    virtual void write(QJsonObject&) const = 0;

    void setNome(string);
    void setColor(string);
};

#endif // DISEGNABILE_H
