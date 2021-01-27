#ifndef PIANOCARTESIANO_H
#define PIANOCARTESIANO_H

#include "Gerarchia.h"

#include <QWidget>

class PianoCartesiano : public QWidget
{
    Q_OBJECT
private:
    double scalaZoom;
    static const int pixelScale = 10;
public:
    explicit PianoCartesiano(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* e);
    void disegnaFigura(Disegnabile*);
    void modificaScala(double);
    void refresh();
signals:

};

#endif // PIANOCARTESIANO_H
