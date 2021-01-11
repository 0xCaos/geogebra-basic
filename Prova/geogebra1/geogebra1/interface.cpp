#include <iostream>

#include <QLayout>
#include <QMenuBar>
#include <QPushButton>
#include <QLabel>

#include "interface.h"
#include "sistemacartesiano.h"

using std::cout, std::endl;

Interface::Interface(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout;

    /***
     * mainLayout
     *  menuBar
     *  interfaccia
     *      sxLayout
     *          buttonLayout
     *          infoLayout
     *      dxLayout
     * */

    // BARRA DEI MENU
    QMenuBar* menuBar = new QMenuBar(this);
    QMenu* file = new QMenu("File", menuBar);
    menuBar->addMenu(file);
    file->addAction(new QAction("Salva", file));
    file->addAction(new QAction("Importa", file));
    QMenu* help = new QMenu("Help", menuBar);
    menuBar->addMenu(help);
    mainLayout->addWidget(menuBar);

    // LAYOUTS
    QHBoxLayout* interaccia = new QHBoxLayout;
    QVBoxLayout* sxLayout = new QVBoxLayout;
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    QVBoxLayout* infoLayout = new QVBoxLayout;
    QVBoxLayout* dxLayout = new QVBoxLayout;

    // SX LAYOUT
    //  buttonLayout
    QPushButton* disegnaButton = new QPushButton("Disegna");
    QPushButton* eliminaButton = new QPushButton("Elimina");
    QPushButton* resetButton = new QPushButton("Reset");
    //disegnaButton->setFixedSize(50,50);
    //eliminaButton->setFixedSize(50,50);
    //resetButton->setFixedSize(50,50);
    buttonLayout->addWidget(disegnaButton);
    buttonLayout->addWidget(eliminaButton);
    buttonLayout->addWidget(resetButton);
    buttonLayout->setContentsMargins(100,20,100,20);
    sxLayout->addLayout(buttonLayout);
    //  infoLayout
    QLabel* infoOggetti = new QLabel("infoOggetti\ninfoOggetti\ninfoOggetti\ninfoOggetti\ninfoOggetti\ninfoOggetti\ninfoOggetti\ninfoOggetti\n");
    infoLayout->addWidget(infoOggetti);
    infoLayout->setContentsMargins(30,20,30,20);
    sxLayout->addLayout(infoLayout);

    interaccia->addLayout(sxLayout);

    // DX LAYOUT
    SistemaCartesiano* sistema = new SistemaCartesiano;
    sistema->setMinimumSize(1100,800);
    QPushButton* zoomIn = new QPushButton("+", sistema);
    QPushButton* zoomOut = new QPushButton("-", sistema);
    int buttonSize = 40;
    zoomIn->setGeometry(sistema->width()-buttonSize*2,sistema->height()-buttonSize*3,buttonSize,buttonSize);
    zoomOut->setGeometry(sistema->width()-buttonSize*2,sistema->height()-buttonSize*2,buttonSize,buttonSize);
    dxLayout->addWidget(sistema);
    interaccia->addLayout(dxLayout);

    mainLayout->addLayout(interaccia);
    setLayout(mainLayout);
}
