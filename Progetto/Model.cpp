#include "Model.h"

Model::Model() : workspace(new WorkSpace) {}

Model::~Model() {
    delete workspace;
}

void Model::addNewSegmento(Punto *A, Punto *B, std::string nome, QColor color) const {
    Creator creator;
    workspace->addDisegno(creator.creaSegmento(nome, color, A, B));
}




