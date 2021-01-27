#include "Controller.h"

#include <iostream>

Controller::Controller(QObject *parent) : QObject(parent) {
    // connessione di eventiali signals
}

void Controller::setModel(Model *m) { model = m; }

void Controller::setView(Interfaccia *v) { view = v; }

void Controller::addPunto() const {
    //bool ok = false;
    //while(!ok){
        try {
            Vettore<QString> dati = view->showNewPuntoDialog();
            std::unordered_map<string, string> displayInfo;
            //for(auto el : dati)
            //    std::cout << el.toStdString() << " ";
            string nome = dati[0].toStdString();
            double x = dati[1].toDouble();
            double y = dati[2].toDouble();
            // Qt color mancante !!!!
            model->addNewPunto(x, y, nome);
            displayInfo = model->getInfoDisegnabile();
            view->addInfoDisegnabile(displayInfo);
            //ok = true;
        }  catch (std::runtime_error exc) {
            //std::cout << exc.what();
            view->showWarningDialog(exc.what());
        }
    //}
}

void Controller::removeDisegno() const {
    try {
        unsigned int index = view->showRemoveDialog();
        model->removeDisegno(index);
    }  catch (std::runtime_error exc) {
        std::cout << exc.what();
        //view->showWarning(exc.what()); // warning della vista per mostrare il messaggio di errore
    }
}








