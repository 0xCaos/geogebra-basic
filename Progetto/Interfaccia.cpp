#include "Interfaccia.h"

#include "Controller.h"

void Interfaccia::addMenu(QVBoxLayout *mainLayout) {
    QMenuBar*   menuBar = new QMenuBar(this);
    file                = new QMenu("File", menuBar);
    help                = new QMenu("Help", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(help);

    // Menu "File"
    file->addAction(new QAction("Salva", file));
    file->addAction(new QAction("Importa", file));
    file->addAction(new QAction("Chiudi", file));

    // Menu "Help"
    help->addAction(new QAction("Tutorial", help));

    connect(file->actions()[2], SIGNAL(triggered()), this, SLOT(close()));

    mainLayout->addWidget(menuBar);
}

void Interfaccia::buildSxLayout(QHBoxLayout *bodyInterface) {
    QVBoxLayout* sxLayout       = new QVBoxLayout;
    QHBoxLayout* buttonLayout   = new QHBoxLayout;
    QVBoxLayout* infoLayout     = new QVBoxLayout;

    // Bottoni
    disegnaButton  = new QPushButton("Disegna");
    eliminaButton  = new QPushButton("Elimina");
    resetButton    = new QPushButton("Reset");
    //disegnaButton->setFixedSize(50,50);
    //eliminaButton->setFixedSize(50,50);
    //resetButton->setFixedSize(50,50);
    buttonLayout->addWidget(disegnaButton);
    buttonLayout->addWidget(eliminaButton);
    buttonLayout->addWidget(resetButton);
    buttonLayout->setContentsMargins(100,20,100,20);
    sxLayout->addLayout(buttonLayout);

    //  Info
    QLabel* infoOggetti = new QLabel("infoOggetti\ninfoOggetti\ninfoOggetti\ninfoOggetti\ninfoOggetti\ninfoOggetti\ninfoOggetti\ninfoOggetti\n");
    infoLayout->addWidget(infoOggetti);
    infoLayout->setContentsMargins(30,20,30,20);
    sxLayout->addLayout(infoLayout);

    bodyInterface->addLayout(sxLayout);
}

void Interfaccia::buildDxLayout(QHBoxLayout *bodyInterface) {
    QVBoxLayout* dxLayout   = new QVBoxLayout;

    PianoCartesiano* piano  = new PianoCartesiano;
    piano->setMinimumSize(1100,800);

    QPushButton* zoomIn = new QPushButton("+", piano);
    QPushButton* zoomOut = new QPushButton("-", piano);
    int buttonSize = 40;
    zoomIn->setGeometry(piano->width()-buttonSize*2,piano->height()-buttonSize*3,buttonSize,buttonSize);
    zoomOut->setGeometry(piano->width()-buttonSize*2,piano->height()-buttonSize*2,buttonSize,buttonSize);
    dxLayout->addWidget(piano);

    bodyInterface->addLayout(dxLayout);
}

Interfaccia::Interfaccia(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout;

    /***
     * mainLayout
     *   menuBar
     *      (interfaccia)
     *      sxLayout
     *          buttonLayout
     *          infoLayout
     *      dxLayout
     * */

    addMenu(mainLayout);

    // Body Interfaccia
    QHBoxLayout* bodyInterface = new QHBoxLayout;

    buildSxLayout(bodyInterface);
    buildDxLayout(bodyInterface);

    mainLayout->addLayout(bodyInterface);

    mainLayout->setSpacing(0);
    setLayout(mainLayout);
    resize(QSize(1024, 720));
}

void Interfaccia::setController(Controller *c) {
    controller = c;

    connect(resetButton, SIGNAL(clicked()), controller, SLOT(removeDisegno()));
}

unsigned int Interfaccia::showRemoveDialog() {
    bool ok = false;
    unsigned int remove =
            QInputDialog::getInt(this, tr("Elimina disegno"),
                         "Indice del disegno da rimuovere: ", 1, 1, 2147483647, 1, &ok);
    if(!ok)
        throw std::runtime_error("Nessun disegno selezionato: rimozione annullata");

    return remove;
}
