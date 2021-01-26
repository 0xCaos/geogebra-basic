#include "Workspace.h"

WorkSpace::WorkSpace() : disegni() {}

WorkSpace::~WorkSpace(){
    //for(auto i: disegni) delete i.get();
}

void WorkSpace::addDisegno(Disegnabile *disegno) {
    disegni.push_back(disegno);
}

void WorkSpace::removeDisegno(unsigned int index) { // Valutare se tornare il puntatore o no
    if(index >= disegni.size())
        throw std::out_of_range("Il disegno selezionato non è presente.");

    disegni.erase(disegni.begin()+index);
}

void WorkSpace::svuotaWorkspace() {
    disegni.clear();
}

bool WorkSpace::puntoNuovo(const Punto *point) const {
    for(auto i = disegni.begin(); i != disegni.end(); i++)
        if(dynamic_cast<Punto*>((*i).get()) && *(static_cast<Punto*>((*i).get())) == *point)
            return false;

    return true;
}


