#ifndef SISTEMACARTESIANO_H
#define SISTEMACARTESIANO_H

#include <QWidget>

class SistemaCartesiano : public QWidget
{
    Q_OBJECT
public:
    explicit SistemaCartesiano(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent* e);
signals:

};

#endif // SISTEMACARTESIANO_H
