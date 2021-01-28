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
            if(!dati.empty()){
                string nome = dati[0].toStdString();
                double x = dati[1].toDouble();
                double y = dati[2].toDouble();
                // Qt color mancante !!!!
                model->addNewPunto(x, y, nome);
                displayInfo = model->getInfoDisegnabile();
                view->addInfoDisegnabile(displayInfo);
            }
            //ok = true;
        }  catch (std::runtime_error& exc) {
            //std::cout << exc.what();
            view->showWarningDialog(exc.what());
        }
    //}
}

void Controller::addSegmento() const {
    try {
        Vettore<Punto*> punti = model->getTuttiPunti();
        Vettore<QString> dati = view->showNewLineaDialog(punti, false);
        if(!dati.empty()){
            string nome         = dati[0].toStdString();
            unsigned int indexA = dati[1].toUInt();
            unsigned int indexB = dati[2].toUInt();
            QColor color        = dati[3];
            std::cout << indexA << " " << indexB << "\n";
            model->addNewSegmento(punti[indexA], punti[indexB], nome, color);
        }
    } catch (std::runtime_error& exc) {
        view->showWarningDialog(exc.what());
    } catch (std::logic_error& log){
        view->showWarningDialog(log.what());
    }
}

void Controller::addRetta() const {
    try {
        Vettore<Punto*> punti = model->getTuttiPunti();
        Vettore<QString> dati = view->showNewLineaDialog(punti, true);
        if(!dati.empty()){
            string nome         = dati[0].toStdString();
            unsigned int indexA = dati[1].toUInt();
            unsigned int indexB = dati[2].toUInt();
            QColor color        = dati[3];
            std::cout << indexA << " " << indexB << "\n";
            model->addNewRetta(punti[indexA], punti[indexB], nome, color);
        }
    } catch (std::runtime_error& exc) {
        view->showWarningDialog(exc.what());
    } catch (std::logic_error& log){
        view->showWarningDialog(log.what());
    }
}

void Controller::addCirconferenza() const {
    try {
        Vettore<Punto*> punti = model->getTuttiPunti();
        Vettore<QString> dati = view->showNewCirconferenzaDialog(punti);
        if(!dati.empty()){
            string nome         = dati[0].toStdString();
            unsigned int indexC = dati[1].toUInt();
            unsigned int raggio = dati[2].toUInt();
            QColor color        = dati[3];
            model->addNewCirconferenza(punti[indexC], raggio, nome, color);
        }
    } catch (std::runtime_error& exc) {
        view->showWarningDialog(exc.what());
    } catch (std::logic_error& log){
        view->showWarningDialog(log.what());
    }
}

void Controller::addEllisse() const {
    try {
        Vettore<Punto*> punti = model->getTuttiPunti();
        Vettore<QString> dati = view->showNewEllisseDialog(punti);
        if(!dati.empty()){
            string nome         = dati[0].toStdString();
            unsigned int indexC = dati[1].toUInt();
            double semiA        = dati[2].toDouble();
            double semiB        = dati[3].toDouble();
            QColor color        = dati[4];
            model->addNewEllisse(punti[indexC], semiA, semiB, nome, color);
        }
    } catch (std::runtime_error& exc) {
        view->showWarningDialog(exc.what());
    } catch (std::logic_error& log){
        view->showWarningDialog(log.what());
    }
}

void Controller::addRegolare() const
{
    try {
        Vettore<Punto*> punti = model->getTuttiPunti();
        Vettore<QString> dati = view->showNewRegolareDialog(punti);
        if(!dati.empty()){
            string nome             = dati[0].toStdString();
            unsigned int indexA     = dati[1].toUInt();
            unsigned int indexB     = dati[2].toUInt();
            unsigned int numLati    = dati[3].toUInt();
            QColor color            = dati[4];
            std::cout << "Regolare: " << numLati << "\n";
            model->addNewRegolare(std::pair<Punto*, Punto*>(punti[indexA], punti[indexB]), numLati, nome, color);
        }
    } catch (std::runtime_error& exc) {
        view->showWarningDialog(exc.what());
    } catch (std::logic_error& log){
        view->showWarningDialog(log.what());
    }
}

void Controller::addPoligono() const
{
    try {
        Vettore<Punto*> punti = model->getTuttiPunti();
        Vettore<QString> dati = view->showNewLineaDialog(punti, true);
        string nome         = dati[0].toStdString();
        unsigned int indexA = dati[1].toUInt();
        unsigned int indexB = dati[2].toUInt();
        QColor color        = dati[3];
        std::cout << indexA << " " << indexB << "\n";
        model->addNewRetta(punti[indexA], punti[indexB], nome, color);
    } catch (std::runtime_error& exc) {
        view->showWarningDialog(exc.what());
    } catch (std::logic_error& log){
        view->showWarningDialog(log.what());
    }
}



void Controller::removeDisegno() const {
    try {
        unsigned int index = view->showRemoveDialog();
        model->removeDisegno(index-1);
    } catch (std::runtime_error& exc) {
        //std::cout << exc.what();
        view->showWarningDialog(exc.what()); // controllare se effetivamente può avvenire un runtime error
    } catch (std::out_of_range& exc) {
        view->showWarningDialog(exc.what());
    }
}








