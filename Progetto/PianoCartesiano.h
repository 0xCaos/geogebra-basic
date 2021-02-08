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
    int pixelScale;
    WorkSpace* workspace;
public:
    /**
     * @brief PianoCartesiano       costruttore di PianoCartesiano
     * @param w                     puntatore al workspace
     * @param parent                puntatore al parent a cui appartiene
     */
    explicit PianoCartesiano(WorkSpace* w=new WorkSpace, QWidget *parent = nullptr);

    /**
     * @brief paintEvent            override di QWidget::paintEvent(QPaintEvent*)
     */
    void paintEvent(QPaintEvent* e);

    /**
     * @brief disegnaFigura         disegna il disegnabile passatogli
     */
    void disegnaFigura(Disegnabile*);

    /**
     * @brief modificaScala         modifica "pixelScale" e invoca la refresh()
     */
    void modificaScala(int);

    /**
     * @brief refresh               ridisegna il piano cartesiano con i relativi oggetti presenti in workspace*
     */
    void refresh();

    /**
     * @brief setWorkspace          settaggio del workspace da cui prendere i disegni
     */
    void setWorkspace(WorkSpace*);

    /**
     * @brief pianocartesianoVuoto  dice se il piano cartesiano ha disegni
     * @return                      TRUE sse workspace punta a un WorkSpace vuoto
     */
    bool pianocartesianoVuoto() const;
signals:

};

#endif // PIANOCARTESIANO_H
