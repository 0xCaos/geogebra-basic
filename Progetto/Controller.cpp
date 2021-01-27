#include "Controller.h"

Controller::Controller(QObject *parent) : QObject(parent) {
    // connessione di eventiali signals
}

Controller::~Controller() {} // default per il momento

void Controller::setModel(Model *m) { model = m; }

void Controller::setView(Interfaccia *v) { view = v; }

void Controller::addPunto() const {

}

void Controller::remove() const {
    try {
        unsigned int index = 1; // showRemoveDialog
        model->removeDisegno(index);
    }  catch (std::runtime_error exc) {
        // showWarning(exc.what()); // warning della vista per mostrare il messaggio di errore
    }
}








