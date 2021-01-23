#include "sistemacartesiano.h"
#include <iostream>

#include <QColor>
#include <QPainter>

using namespace std;

SistemaCartesiano::SistemaCartesiano(QWidget *parent) : QWidget(parent) {}

void SistemaCartesiano::paintEvent(QPaintEvent* e) {
    const int PIXEL_SCALE = 10;

    //setFixedSize(1080,800);

    int side = qMin(width(), height());
    cout << width() << "x" << height() << endl;

    QPainter p(this);
    p.setViewport((width()-side)/2, (height()-side)/2, side, side);
    p.setWindow(-100,-100,200,200);

    QPen pen;
    pen.setWidth(0);
    pen.setColor(QColor::fromRgb(217, 217, 217));
    p.setPen(pen);

    //griglia
    for (int i=-side; i<side; ++i) {
        p.drawLine(side, i*PIXEL_SCALE/5, -side, i*PIXEL_SCALE/5);
        p.drawLine(i*PIXEL_SCALE/5, side, i*PIXEL_SCALE/5, -side);
    }

    pen.setColor(QColor::fromRgb(186, 186, 186));
    pen.setWidth(0);
    p.setPen(pen);

    //trattini
    for (int i=-side; i<side; ++i) {
        p.drawLine(i*PIXEL_SCALE, side, i*PIXEL_SCALE, -side);
        p.drawLine(side, i*PIXEL_SCALE, -side, i*PIXEL_SCALE);
    }

    pen.setWidth(0);
    pen.setColor(Qt::black);
    p.setPen(pen);

    //asse x
    p.drawLine(-side,0,side,0);
    //asse y
    p.drawLine(0,side,0,-side);

    //arrows
    int x_arrow = 144;
    p.drawLine(x_arrow-2, 2, x_arrow, 0);
    p.drawLine(x_arrow-2, -2, x_arrow, 0);
    int y_arrow = -100;
    p.drawLine(2, y_arrow+2, 0, y_arrow);
    p.drawLine(-2, y_arrow+2, 0, y_arrow);

    //p.setBrush(Qt::red);

    pen.setWidth(0);
    pen.setColor(Qt::red);
    p.setPen(pen);

    // SET ELLIPSE DIMENSIONS
    int startX = -3;
    int startY = -5;
    int width = 2;
    int height = 4;
    int startXsc = startX * PIXEL_SCALE;
    int startYsc = startY * PIXEL_SCALE;
    int widthScaled = width * PIXEL_SCALE;
    int heightScaled = height * PIXEL_SCALE;

    p.drawEllipse(startXsc,startYsc,widthScaled,heightScaled);

    // SET SQUARE DIMENSIONS
    startX = 1;
    startY = -4;
    int lato = 3;
    startXsc = startX * PIXEL_SCALE;
    startYsc = startY * PIXEL_SCALE;
    int latoScaled = lato * PIXEL_SCALE;

    p.drawRect(startXsc, startYsc, latoScaled, latoScaled);

    // SET RECTANGLE DIMENSIONS
    startX = -2;
    startY = 1;
    int base = 5;
    int altezza = 2;
    startXsc = startX * PIXEL_SCALE;
    startYsc = startY * PIXEL_SCALE;
    int baseScaled = base * PIXEL_SCALE;
    int altezzaScaled = altezza * PIXEL_SCALE;

    p.drawRect(startXsc, startYsc, baseScaled, altezzaScaled);

    // ALTRO


    p.fillRect(5*PIXEL_SCALE,PIXEL_SCALE,2*PIXEL_SCALE,1*PIXEL_SCALE,Qt::black);

    QWidget::paintEvent(e);
}
