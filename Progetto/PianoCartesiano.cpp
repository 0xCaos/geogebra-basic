#include "PianoCartesiano.h"

PianoCartesiano::PianoCartesiano(QWidget *parent) : QWidget(parent)
{

}

void PianoCartesiano::paintEvent(QPaintEvent* e)
{
    int side = qMin(width(), height());

    QPainter p(this);
    p.setViewport((width()-side)/2, (height()-side)/2, side, side);
    p.setWindow(-100,-100,200,200);

    QPen pen;
    pen.setWidth(0);
    pen.setColor(QColor::fromRgb(217, 217, 217));
    p.setPen(pen);

    //griglia
    for (int i=-side; i<side; ++i) {
        p.drawLine(side, i*pixelScale/5, -side, i*pixelScale/5);
        p.drawLine(i*pixelScale/5, side, i*pixelScale/5, -side);
    }

    pen.setColor(QColor::fromRgb(186, 186, 186));
    pen.setWidth(0);
    p.setPen(pen);

    //trattini
    for (int i=-side; i<side; ++i) {
        p.drawLine(i*pixelScale, side, i*pixelScale, -side);
        p.drawLine(side, i*pixelScale, -side, i*pixelScale);
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

    QWidget::paintEvent(e);
}
