#ifndef INTERFACCIA_H
#define INTERFACCIA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QLabel>
//#include <utility>
#include <QInputDialog>
#include <QDialog>
#include <QValidator>
#include <QDialogButtonBox>
#include <QString>
#include <QColorDialog>
#include <QFormLayout>

#include "PianoCartesiano.h"

class Controller;

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

    QLabel *colorLabel;

public:
    explicit Interfaccia(QWidget* parent = nullptr);
    ~Interfaccia() =default;

    void setController(Controller* c);


    void selectColor();

    void showSceltaFiguraDialog();

    void showWarningDialog(const QString& message);

    Vettore<QString> showNewPuntoDialog();
    unsigned int showRemoveDialog();

    void addInfoDisegnabile(std::unordered_map<string,string>);
};

#endif // INTERFACCIA_H
