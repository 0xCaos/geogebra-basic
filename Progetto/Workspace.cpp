#include "Workspace.h"

WorkSpace::WorkSpace() : disegni() {}

WorkSpace::~WorkSpace(){
    //for(auto i: disegni) delete i.get();
}

const Vettore<DeepPtr<Disegnabile>> WorkSpace::getDisegni() const {
    return disegni;
}

unsigned int WorkSpace::getNumeroDisegni() const { return disegni.size(); }

void WorkSpace::addDisegno(Disegnabile* disegno) {/*
    std::cout << "pre pushback\n";
    for(auto i : disegno->getInfo()) {
        std::cout << i.first << " " << i.second << "\n";
    }*/
    disegni.push_back(disegno);/*
    std::cout << "post pushback\n";
    for(auto i : disegno->getInfo()) {
        std::cout << i.first << " " << i.second << "\n";
    }*/
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

//SAFE! :)
Vettore<Punto *> WorkSpace::tuttiPunti() const {
    Vettore<Punto*> punti;
    for(auto& disegno : disegni){
        if(dynamic_cast<Punto*>(disegno.get()))
            punti.push_back(static_cast<Punto*>(disegno.get()));
    }
    return punti;
}

Vettore<std::unordered_map<std::string, std::string> > WorkSpace::getTutteInfo() {
    Vettore<std::unordered_map<std::string, std::string> > info;
    for(auto&& d : disegni)
        info.push_back(d->getInfo());
    return info;
}

std::unordered_map<string, string> WorkSpace::getInfoDisegnabile() {
    return disegni[disegni.size()-1]->getInfo();
}


