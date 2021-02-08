#include "Model.h"

bool Model::checkNuoviPunti(const Vettore<Punto*>& points) const {
    bool almenoUno = false;
    for(auto point : points)
        if(workspace->puntoNuovo(point)){
            workspace->addDisegno(point);
            almenoUno = true;
           }
    return almenoUno;
}

Model::Model() : workspace(new WorkSpace) {}

Model::~Model() {
    delete workspace;
}

void Model::addNewSegmento(Punto *A, Punto *B, std::string nome, string color) const {
    Creator creator;
    Segmento* s = creator.creaSegmento(nome, color, A, B);
    workspace->addDisegno(s);
    delete s;
}

void Model::addNewRetta(Punto *A, Punto *B, string nome, string color) const {
    Creator creator;
    Retta* r = creator.creaRetta(nome, color, A, B);
    workspace->addDisegno(r);
    delete r;
}

void Model::addNewPoligono(const Vettore<Punto *> &punti, string nome, string color) const {
    Creator creator;
    Poligono* p = creator.creaPoligono(nome, color, punti);
    workspace->addDisegno(p);
    delete p;
}

void Model::addNewRegolare(const std::pair<Punto *, Punto *> &punti, unsigned int numLati, string nome, string color) const {
    Creator creator;
    Regolare* r = creator.creaRegolare(nome, color, punti, numLati);
    workspace->addDisegno(r);
    delete r;
}

void Model::addNewEllisse(Punto *centro, double semiAsse1, double semiAsse2, string nome, string color) const {
    Creator creator;
    Ellisse* e = creator.creaEllisse(nome, color, centro, semiAsse1, semiAsse2);
    workspace->addDisegno(e);
    delete e;
}

void Model::addNewCirconferenza(Punto *centro, double raggio, string nome, string color) const {
    Creator creator;
    Circonferenza* c = creator.creaCirconferenza(nome, color, centro, raggio);
    workspace->addDisegno(c);
    delete c;
}

void Model::addNewPunto(double x, double y, string nome, string color) const {
    Creator creator;
    Punto* p = creator.creaPunto(nome, color, x, y);
    bool nuovo = checkNuoviPunti({p});
    delete p;
    if(!nuovo)
        throw std::runtime_error("Punto già presente");
}

void Model::removeDisegno(unsigned int index) const { workspace->removeDisegno(index); }

void Model::refresh() const {}

void Model::cancellaTutto() { workspace->svuotaWorkspace(); }

std::unordered_map<string, string> Model::getInfoDisegnabile() const {
    return workspace->getInfoDisegnabile();
}

Vettore<std::unordered_map<std::string, std::string> > Model::getTutteInfo() const {
    return workspace->getTutteInfo();
}

unsigned int Model::getNumeroDisegni() const {
    return workspace->getNumeroDisegni();
}

Vettore<Punto *> Model::getTuttiPunti() const {
    return workspace->tuttiPunti();
}

WorkSpace* Model::getWorkspace() const {
    return workspace;
}

const Vettore<DeepPtr<Disegnabile> >& Model::getDisegni() const
{
    return workspace->getDisegni();
}

void Model::addDisegnabile(Disegnabile *d) const
{
    workspace->addDisegno(d);
}

void Model::convertiOggettiJson(QJsonObject disegnabile)
{
    className classe = className(disegnabile["class"].toInt());
    switch (classe) {
    case segmento: {
        Segmento* s = new Segmento;
        s->read(disegnabile);
        addDisegnabile(s);
        delete s;
        break;
    }
    case retta: {
        Retta* r = new Retta;
        r->read(disegnabile);
        addDisegnabile(r);
        delete r;
        break;
    }
    case poligono: {
        Poligono* p = new Poligono;
        p->read(disegnabile);
        addDisegnabile(p);
        delete p;
        break;
    }
    case regolare: {
        Regolare* r = new Regolare;
        r->read(disegnabile);
        addDisegnabile(r);
        delete r;
        break;
    }
    case ellisse: {
        Ellisse* e = new Ellisse;
        e->read(disegnabile);
        addDisegnabile(e);
        delete e;
        break;
    }
    case circonferenza: {
        Circonferenza* c = new Circonferenza;
        c->read(disegnabile);
        addDisegnabile(c);
        delete c;
        break;
    }
    case punto:
        Punto* p = new Punto;
        p->read(disegnabile);
        addNewPunto(p->getX(), p->getY(), p->getNome(), p->getColore()); // addNewPunto effettua il controllo che non ci siano punti duplicati (addDisegnabile fa solo la pushback)
        delete p;
        break;
    }
}
