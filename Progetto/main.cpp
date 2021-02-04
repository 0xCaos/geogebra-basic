#include "Model.h"
#include "Controller.h"
#include "Interfaccia.h"
#include "vector"

#include <QApplication>
#include <unordered_map>
#include "Gerarchia.h"
#include "Model.h"

#include "iostream"
using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model m;
    Controller c;
    c.setModel(&m);
    Interfaccia w;
    c.setView(&w);
    w.setController(&c);
    w.show();
    return a.exec();
}
