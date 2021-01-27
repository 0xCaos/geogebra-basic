#ifndef INTERFACCIA_H
#define INTERFACCIA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QLabel>

class Controller;

class PianoCartesiano;

class Interfaccia : public QWidget {
    Q_OBJECT
private:
    Controller* controller;
    PianoCartesiano* pianoCartesiano;

    QMenu* file;
    QMenu* help;

    QPushButton* disegnaButton;
    QPushButton* eliminaButton;
    QPushButton* resetButton;


    void addMenu(QVBoxLayout* mainLayout);

    void buildSxLayout(QHBoxLayout* bodyInterface);
    void buildDxLayout(QHBoxLayout* bodyInterface);

public:
    explicit Interfaccia(QWidget* parent = nullptr);

    void setController(Controller* c);

    ~Interfaccia() =default;
};

#endif // INTERFACCIA_H
