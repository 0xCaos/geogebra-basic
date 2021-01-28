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
#include <QComboBox>
#include <QMessageBox>

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

    QDialog* formDialog;
    QVBoxLayout* mainLayout;
    QHBoxLayout* buttonLayout;
    QFormLayout* formLayout;
    QLabel *colorLabel;

    QPushButton *colorButton;
    QLineEdit* inputNome;

    QValidator* validator;
    QDialogButtonBox* bottoni;

    void setStandardDialog();

private slots:
    void selectColor();

public:
    explicit Interfaccia(QWidget* parent = nullptr);
    ~Interfaccia() =default;

    /**
     * @brief setController     settaggio del Controller con tutte le varie connect
     * @param c                 Controller da settare
     */
    void setController(Controller* c);

    /**
     * @brief showSceltaFiguraDialog crea il dialog per la scelta del nuovo disegno da fare
     */
    void showSceltaFiguraDialog();

    void showWarningDialog(const QString& message);

    Vettore<QString> showNewPuntoDialog();
    Vettore<QString> showNewLineaDialog(const Vettore<Punto*> punti, bool retta);
    Vettore<QString> showNewRegolareDialog(const Vettore<Punto*> punti);
    Vettore<QString> showNewCirconferenzaDialog(const Vettore<Punto*> punti);
    Vettore<QString> showNewEllisseDialog(const Vettore<Punto*> punti);
    unsigned int showRemoveDialog();

    void addInfoDisegnabile(std::unordered_map<string,string>);
};

#endif // INTERFACCIA_H
