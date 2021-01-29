#include "Controller.h"

#include <iostream>

Controller::Controller(QObject *parent) : QObject(parent) {
    // connessione di eventiali signals
}

void Controller::setModel(Model *m) { model = m; }

void Controller::setView(Interfaccia *v) { view = v; }

void Controller::refreshInfoDisegni() const {
    view->pulisciInfoDisegni();
    unsigned int cont = 1;
    for(auto&& i : model->getTutteInfo()){
        view->addInfoDisegnabile(i, cont);
        cont++;
    }
}

void Controller::showInfoDisegni() const {
    std::unordered_map<string, string> displayInfo;
    displayInfo = model->getInfoDisegnabile();
    view->addInfoDisegnabile(displayInfo, model->getNumeroDisegni());
}

void Controller::addPunto() const {
    //bool ok = false;
    //while(!ok){
        try {
            Vettore<QString> dati = view->showNewPuntoDialog();
            //std::unordered_map<string, string> displayInfo;
            //for(auto el : dati)
            //    std::cout << el.toStdString() << " ";
            if(!dati.empty()){
                string nome = dati[0].toStdString();
                double x = dati[1].toDouble();
                double y = dati[2].toDouble();
                QColor c = QColor(dati[3]);
                // Qt color mancante !!!!
                model->addNewPunto(x, y, nome, c);
                showInfoDisegni();
                view->refreshPiano();
                //displayInfo = model->getInfoDisegnabile();
                //view->addInfoDisegnabile(displayInfo);
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
        Vettore<QString> dati = view->showNewLineaDialog(punti, false);/*
        SAAAAAAAAAAAAAFE
        std::cout << "vettore punti\n";
        for(auto i: punti) {
            std::cout << string(*i) << "\n";
        }
        std::cout << "finepausa\n";*/
        if(!dati.empty()){
            string nome         = dati[0].toStdString();/*
            std::cout << "SEG: "<< punti[dati[1].toUInt()]->getX() << std::endl;
            unsigned int indexA = dati[1].toUInt();
            unsigned int indexB = dati[2].toUInt();
            QColor color        = QColor(dati[3]);
            std::cout << indexA << " " << indexB << "\n";
            model->addNewSegmento(punti[indexA], punti[indexB], nome, color);*/
            model->addNewSegmento(punti[dati[1].toUInt()], punti[dati[2].toUInt()], nome, QColor(dati[3]));
            for(auto i:punti) {
                std::cout << string(*i) << std::endl;
            }
            std::cout << "SEG2X: "<< punti[dati[1].toUInt()]->getX() << std::endl;
            std::cout << "SEG2Y: "<< punti[dati[1].toUInt()]->getY() << std::endl;
            showInfoDisegni();
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
            showInfoDisegni();
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
            showInfoDisegni();
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
            showInfoDisegni();
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
            showInfoDisegni();
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
        showInfoDisegni();
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
        refreshInfoDisegni();
        view->refreshPiano();
    } catch (std::runtime_error& exc) {
        //std::cout << exc.what();
        view->showWarningDialog(exc.what()); // controllare se effetivamente può avvenire un runtime error
    } catch (std::out_of_range& exc) {
        view->showWarningDialog(exc.what());
    }
}

void Controller::cancellaTutto() const {
    int d = view->showConfermaDialog("Attenzione stai per eliminare tutti i disegni inseriti. L'operazione non è annullabile.");
    if(d == 16384)
    {
        model->cancellaTutto();
        refreshInfoDisegni();
        view->refreshPiano();
    }
    std::cout << d << " ";
}

WorkSpace* Controller::getWorkspace() const {
    return model->getWorkspace();
}

