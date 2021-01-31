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
#include <QScrollArea>

#include "PianoCartesiano.h"

class Controller;

class Interfaccia : public QWidget {
    Q_OBJECT
private:
    Controller* controller;
    PianoCartesiano* pianoCartesiano;

    QMenuBar*   menuBar;
    QMenu* file;
    QMenu* disegnaMenu;
    QMenu* utility;
    QMenu* help;

    QVBoxLayout* infoLayout;
    QHBoxLayout* buttonLayout;
    QVBoxLayout* sxLayout;

    QPushButton* disegnaButton;
    QPushButton* eliminaButton;
    QPushButton* resetButton;

    void addMenu(QVBoxLayout* mainLayout);

    void buildSxLayout(QHBoxLayout* bodyInterface);
    void buildDxLayout(QHBoxLayout* bodyInterface);

    QDialog* formDialog;
    QVBoxLayout* mainLayout;
    QHBoxLayout* dialogButton;
    QFormLayout* formLayout;
    QLabel *colorLabel;

    QPushButton *colorButton;
    QLineEdit* inputNome;

    QValidator* validator;
    QDialogButtonBox* bottoni;

    QScrollArea* infoScroll;
    QWidget* infoBox;
    QFormLayout* infoDisegni;

    QPushButton* addPuntiBox;
    QPushButton* removePuntiBox;

    QComboBox* boxPunti1;
    QComboBox* boxPunti2;
    QWidget* comboboxLayout;

    void setStandardDialog();
    void popolaComboBox(const Vettore<Punto*>& punti, const Vettore<QComboBox*>& comboBox);

private slots:
    void selectColor();
    void addRowPuntiBox();
    void removeRowPuntiBox();

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

    int showWarningDialog(const QString& message);
    int showConfermaDialog(const QString& message);

    Vettore<QString> showNewPuntoDialog();
    Vettore<QString> showNewLineaDialog(const Vettore<Punto*> punti, bool retta);
    Vettore<QString> showNewRegolareDialog(const Vettore<Punto*> punti);
    Vettore<QString> showNewPoligonoDialog(const Vettore<Punto*> punti);
    Vettore<QString> showNewCirconferenzaDialog(const Vettore<Punto*> punti);
    Vettore<QString> showNewEllisseDialog(const Vettore<Punto*> punti);
    unsigned int showRemoveDialog();

    void pulisciInfoDisegni();
    void addInfoDisegnabile(std::unordered_map<string,string>, unsigned int);
    void refreshPiano();
};

#endif // INTERFACCIA_H
