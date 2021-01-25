#ifndef WORKSPACE_H
#define WORKSPACE_H

#include "Gerarchia.h"

class WorkSpace {
private:
    Vettore<Disegnabile*> disegni;
public:
    WorkSpace();
    ~WorkSpace();

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

};

#endif // WORKSPACE_H
