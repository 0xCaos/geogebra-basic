#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QString>
#include "Model.h"
#include "Interfaccia.h"

class Controller : public QObject {
    Q_OBJECT
private:
    Model* model;
    Interfaccia* view;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller() =default;

    /**
     * @brief setModel              Assegnazione del puntatore del modello che verrà utilizzato durante l'esecuzione del programma
     */
    void setModel(Model* m);

    /**
     * @brief setView               Assegnazione del puntatore della vista che verrà utilizzata durante l'esecuzione del programma
     */
    void setView(Interfaccia* v);

    /**
     * @brief refreshInfoDisegni    Aggiornamento di tutte le informazioni
     */
    void refreshInfoDisegni() const;

    /**
     * @brief showInfoDisegni
     */
    void showInfoDisegni() const;

public slots:

    /**
     *  Gestione dell'inserimento della figura selezionata
     *  (il controller comunica con l'interfaccia, che mostra il dialog corrispondente,
     *  e con il modello, che crea la figura e la inserisce nel contenitore)
     */
    void addPunto() const;
    void addSegmento() const;
    void addRetta() const;
    void addCirconferenza() const;
    void addEllisse() const;
    void addRegolare() const;
    void addPoligono() const;

    /**
     * @brief removeDisegno     Gestione della rimozione di oggetti Disegnabile
     */
    void removeDisegno() const;

    /**
     * @brief cancellaTutto     Rimozione di tutti gli oggetti
     */
    void cancellaTutto() const;

    /**
     * @brief getWorkspace      Getter di Workspace
     * @return                  Puntatore a Workspace
     */
    WorkSpace *getWorkspace() const;

    /**
     * @brief write             Conversione da oggetti Disegnabile a oggetti JSON
     */
    void write(QJsonObject&) const;

    /**
     * @brief read              Conversione da oggetti JSON a oggetti Disegnabile
     */
    void read(const QJsonObject&) const;

    /**
     * @brief saveToFile        Salvataggio della sessione su file JSON
     * @return                  true SSE il salvataggio è andato a buon fine
     */
    bool saveToFile() const;

    /**
     * @brief loadFromFile      Caricamento della sessione da file a
     */
    void loadFromFile() const;
};

#endif // CONTROLLER_H
