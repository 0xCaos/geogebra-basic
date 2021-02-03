#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "Gerarchia.h"

class WorkSpace {
private:
    Vettore<DeepPtr<Disegnabile>> disegni;
public:
    WorkSpace();
    ~WorkSpace();

    /* Only for Debug
    void stampaContenuto() const {
        for(auto el : disegni)
            std::cout << el->getNome() << " ";
    }
    */
    const Vettore<DeepPtr<Disegnabile>> getDisegni() const;

    unsigned int getNumeroDisegni() const;

    /**
     * @brief inserisce il disegno alla fine di disegni
     * @param puntatore al disegno da inserire
     */
    void addDisegno(Disegnabile*);

    /**
     * @brief rimuove il disegno in posizione index-esima dal workspace
     * @param index : indice del disegno da rimuovere
     * @throw out_of_range se index > numero di disegni presenti correntemente nel workspace
     */
    void removeDisegno(unsigned int index);

    /**
     * @brief rimuove tutti i disegni dal workspace
     */
    void svuotaWorkspace();

    /**
     * @brief puntoNuovo        controlla se un punto è già presente nel workspace
     * @param point             punto sul quale si esegue il controllo
     * @return                  true sse point non è presente in disegni
     */
    bool puntoNuovo(const Punto* point) const;

    Vettore<Punto*> tuttiPunti() const;

    Vettore<std::unordered_map<std::string, std::string>> getTutteInfo();
    std::unordered_map<std::string, std::string> getInfoDisegnabile();

    bool workspaceVuota() const;
};

#endif // WORKSPACE_H
