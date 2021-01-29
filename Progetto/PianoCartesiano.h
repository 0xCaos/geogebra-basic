#ifndef PIANOCARTESIANO_H
#define PIANOCARTESIANO_H

#include "Gerarchia.h"
#include "Workspace.h"

#include <QWidget>

class PianoCartesiano : public QWidget
{
    Q_OBJECT
private:
    double scalaZoom;
    static const int pixelScale = 10;
    WorkSpace* workspace;
public:
    explicit PianoCartesiano(WorkSpace* =nullptr, QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* e);
    void disegnaFigura(Disegnabile*);
    void modificaScala(double);
    void refresh();
    void setWorkspace(WorkSpace*);
signals:

};

#endif // PIANOCARTESIANO_H
