#include "Controller.h"

#include <iostream>

Controller::Controller(QObject *parent) : QObject(parent) {
    // connessione di eventiali signals
}

void Controller::setModel(Model *m) { model = m; }

void Controller::setView(Interfaccia *v) { view = v; }

void Controller::removeDisegno() const {
    try {
        unsigned int index = view->showRemoveDialog();
        model->removeDisegno(index);
    }  catch (std::runtime_error exc) {
        std::cout << exc.what();
        //view->showWarning(exc.what()); // warning della vista per mostrare il messaggio di errore
    }
}








