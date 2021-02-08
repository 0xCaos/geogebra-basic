#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "Segmento.h"
#include "Retta.h"
#include "Poligono.h"
#include "Regolare.h"
#include "Circonferenza.h"
#include "Ellisse.h"

#include "DeepPtr.h"

class WorkSpace {
private:
    Vettore<DeepPtr<Disegnabile>> disegni;
public:
    WorkSpace();
    ~WorkSpace() = default; // disegni contiene oggetti non puntatori => non faccio nulla

    /**
     * @brief getDisegni            get del vettore "disegni"
     * @return                      riferimento costante a "disegni"
     */
    const Vettore<DeepPtr<Disegnabile>>& getDisegni() const;

    /**
     * @brief getNumeroDisegni      ritorna il numero di disegni presenti in "disegni"
     * @return                      unsigned int del numero di disegni
     */
    unsigned int getNumeroDisegni() const;

    /**
     * @brief                       inserisce il disegno alla fine di disegni
     * @param                       puntatore al disegno da inserire
     */
    void addDisegno(Disegnabile*);

    /**
     * @brief                       rimuove il disegno in posizione index-esima dal workspace
     * @param                       index : indice del disegno da rimuovere
     * @throw                       out_of_range se index > numero di disegni presenti correntemente nel workspace
     */
    void removeDisegno(unsigned int index);

    /**
     * @brief                       rimuove tutti i disegni dal workspace
     */
    void svuotaWorkspace();

    /**
     * @brief puntoNuovo            controlla se un punto è già presente nel workspace
     * @param point                 punto sul quale si esegue il controllo
     * @return                      true sse point non è presente in disegni
     */
    bool puntoNuovo(const Punto* point) const;

    /**
     * @brief tuttiPunti            get di tutti i punti presenti in "disegni"
     * @return                      vettore di Punto* ai punti presenti in "disegni"
     */
    Vettore<Punto*> tuttiPunti() const;

    /**
     * @brief getTutteInfo          Get di tutte le info dei disegni presenti in "disegni"
     * @return                      vettore di unordered_map contenenti le info di tutti i disegni
     */
    Vettore<std::unordered_map<std::string, std::string>> getTutteInfo();

    /**
     * @brief getInfoDisegnabile    Get delle info dell'ultimo disegno inserito in "disegni"
     * @return                      unordered_map con le info
     */
    std::unordered_map<std::string, std::string> getInfoDisegnabile();

    /**
     * @brief workspaceVuota        controlla se la workspace è vuota
     * @return                      TRUE sse disegni è vuoto
     */
    bool workspaceVuota() const;
};

#endif // WORKSPACE_H
