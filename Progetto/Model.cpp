#include "Model.h"

bool Model::checkNuoviPunti(const Vettore<Punto*>& points) const {
    bool almenoUno = false;
    for(auto point : points)
        if(workspace->puntoNuovo(point)){
            //std::cout << string(*point) << "\n";
            workspace->addDisegno(point);
            almenoUno = true;
           }
    return almenoUno;
}

Model::Model() : workspace(new WorkSpace) {}

Model::~Model() {
    delete workspace;
}

void Model::addNewSegmento(Punto *A, Punto *B, std::string nome, QColor color) const {
    Creator creator;
    checkNuoviPunti({A, B});
    Segmento* s = creator.creaSegmento(nome, color, A, B);
    workspace->addDisegno(s);
    delete s;
    //workspace->addDisegno(creator.creaSegmento(nome, color, A, B));
}

void Model::addNewRetta(Punto *A, Punto *B, std::string nome, QColor color) const {
    Creator creator;
    checkNuoviPunti({A, B});
    Retta* r = creator.creaRetta(nome, color, A, B);
    workspace->addDisegno(r);
    delete r;
    //workspace->addDisegno(creator.creaRetta(nome, color, A, B));
}

void Model::addNewPoligono(const Vettore<Punto *> &punti, std::string nome, QColor color) const {
    Creator creator;
    checkNuoviPunti(punti);
    Poligono* p = creator.creaPoligono(nome, color, punti);
    workspace->addDisegno(p);
    delete p;
    //workspace->addDisegno(creator.creaPoligono(nome, color, punti));
}

void Model::addNewRegolare(const std::pair<Punto *, Punto *> &punti, unsigned int numLati, std::string nome, QColor color) const {
    Creator creator;
    checkNuoviPunti({punti.first, punti.second});
    Regolare* r = creator.creaRegolare(nome, color, punti, numLati);
    workspace->addDisegno(r);
    delete r;
    //workspace->addDisegno(creator.creaRegolare(nome, color, punti, numLati));
}

void Model::addNewEllisse(Punto *centro, double semiAsse1, double semiAsse2, std::string nome, QColor color) const {
    Creator creator;
    checkNuoviPunti({centro});
    Ellisse* e = creator.creaEllisse(nome, color, centro, semiAsse1, semiAsse2);
    workspace->addDisegno(e);
    delete e;
    //workspace->addDisegno(creator.creaEllisse(nome, color, centro, semiAsse1, semiAsse2));
}

void Model::addNewCirconferenza(Punto *centro, double raggio, std::string nome, QColor color) const {
    Creator creator;
    checkNuoviPunti({centro});
    Circonferenza* c = creator.creaCirconferenza(nome, color, centro, raggio);
    workspace->addDisegno(c);
    delete c;
    //workspace->addDisegno(creator.creaCirconferenza(nome, color, centro, raggio));
}

void Model::addNewPunto(double x, double y, std::string nome, QColor color) const {
    Creator creator;
    Punto* p = creator.creaPunto(nome, color, x, y);
    //std::cout << string(*p) << "\n";
    bool nuovo = checkNuoviPunti({p});
    delete p;
    if(!nuovo) throw std::runtime_error("Punto già presente");
    //checkNuoviPunti({creator.creaPunto(nome, color, x, y)});
}

void Model::removeDisegno(unsigned int index) const { workspace->removeDisegno(index); }

void Model::refresh() const {}

void Model::cancellaTutto() { workspace->svuotaWorkspace(); }

