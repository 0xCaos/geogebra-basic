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
    // Collegamento al controller e al Piano Cartesiano
    Controller* controller;
    PianoCartesiano* pianoCartesiano;

    // QMenu
    QMenuBar*   menuBar;
    QMenu* file;
    QMenu* disegnaMenu;
    QMenu* utility;
    QMenu* help;

    // QLayouts per l'interfaccia
    QVBoxLayout* infoLayout;
    QHBoxLayout* buttonLayout;
    QVBoxLayout* sxLayout;

    // QPushButton con le principali funzioni
    QPushButton* disegnaButton;
    QPushButton* eliminaButton;
    QPushButton* resetButton;
    QPushButton* importa;

    // QDialog personalizzati per l'input dei dati da parte dell'utente
    QDialog* formDialog;
    QVBoxLayout* mainLayout;
    QHBoxLayout* dialogButton;
    QFormLayout* formLayout;
    QLabel *colorLabel;
    QPushButton *colorButton;
    QLineEdit* inputNome;
    QComboBox* boxPunti1;
    QComboBox* boxPunti2;

    QValidator* validator;      // Validator per i campi numerici
    QDialogButtonBox* bottoni;  // Bottoni "Cancel" e "OK"

    // Area delle Info
    QScrollArea* infoScroll;
    QWidget* infoBox;
    QFormLayout* infoDisegni;

    QPushButton* addPuntiBox;
    QPushButton* removePuntiBox;

    // Funzioni di creazione dell'interfaccia
    void addMenu(QVBoxLayout* mainLayout);
    void buildSxLayout(QHBoxLayout* bodyInterface);
    void buildDxLayout(QHBoxLayout* bodyInterface);
    void setMainButtons();

    /**
     * @brief setStandardDialog     setta le impostazioni e i QWidget presenti in ogni QDialog
     */
    void setStandardDialog();

    /**
     * @brief popolaComboBox        funzione che popola le ComboBox con tutti i punti creati
     * @param punti                 vettore contenente i puntatori ai punti presenti nel piano
     * @param comboBox              vettore delle ComboBox da popolare
     */
    void popolaComboBox(const Vettore<Punto*>& punti, const Vettore<QComboBox*>& comboBox);

private slots:
    /**
     * @brief selectColor           slot che gestisce il Dialog per la scelta del colore
     */
    void selectColor();

    /**
     * @brief setZoomIn             slot che aumenta la scala del piano cartesiano
     */
    void setZoomIn();

    /**
     * @brief setZoomOut            slot che diminuisce la scala del piano cartesiano
     */
    void setZoomOut();

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

    /**
     * @brief showWarningDialog     gestione della MessageBox per la visualizzazione degli errori/warning
     * @param message               messaggio da mostrare sulla box
     * @return                      ritorna un intero in base all'esito di chiusura della messageBox
     */
    int showWarningDialog(const QString& message);

    /**
     * @brief showConfermaDialog    gestione della MessageBox per la visualizzazione di una question di conferma
     * @param message               messaggio da mostrare sulla box
     * @return                      ritorna un intero in base alla scelta fatta prima della chiusura della messageBox
     */
    int showConfermaDialog(const QString& message);

    // Dialog per l'inserimento di nuove figure
    Vettore<QString> showNewPuntoDialog();
    Vettore<QString> showNewLineaDialog(const Vettore<Punto*> punti, bool retta); // Unico dialog per Retta e Segmento (stessi valori)
    Vettore<QString> showNewRegolareDialog(const Vettore<Punto*> punti);
    Vettore<QString> showNewPoligonoDialog(const Vettore<Punto*> punti);
    Vettore<QString> showNewCirconferenzaDialog(const Vettore<Punto*> punti);
    Vettore<QString> showNewEllisseDialog(const Vettore<Punto*> punti);

    /**
     * @brief showRemoveDialog      dialog per la rimozione di un disegno dal piano
     * @return                      intero in base all'esito di chiusura della messageBox
     * @throws std::runtime_error   nel caso in cui non venga selezionato nulla
     */
    unsigned int showRemoveDialog();

    /**
     * @brief pulisciInfoDisegni    funzione per la cancellazione delle info dalla QScrollArea a Sx
     */
    void pulisciInfoDisegni();

    /**
     * @brief addInfoDisegnabile    funzione che si occupa di stampare sul pannello di sx le info del
     *                              disegno scelto
     */
    void addInfoDisegnabile(std::unordered_map<string,string>, unsigned int);

    /**
     * @brief refreshPiano          aggiorna il workspace con i disegni inseriti e invoca la refresh sul
     *                              piano cartesiano
     */
    void refreshPiano();
};

#endif // INTERFACCIA_H
