#include "Workspace.h"

WorkSpace::WorkSpace() : disegni() {}

WorkSpace::~WorkSpace(){
    for(auto i: disegni) delete i;
}

void WorkSpace::addDisegno(Disegnabile *disegno) {
    disegni.push_back(disegno);
}

void WorkSpace::removeDisegno(unsigned int index) { // Valutare se tornare il puntatore o no
    if(index >= disegni.size())
        throw std::out_of_range("Il disegno selezionato non è presente.");

    //auto disegno = disegni[index];
    disegni.erase(disegni.begin()+index);

    //return disegno;
}

void WorkSpace::svuotaWorkspace() {
    disegni.clear();
}


