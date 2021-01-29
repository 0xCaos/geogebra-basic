#include "Interfaccia.h"

#include "Controller.h"


void Interfaccia::addMenu(QVBoxLayout *mainLayout) {
    menuBar             = new QMenuBar(this);
    file                = new QMenu("File", menuBar);
    disegnaMenu         = new QMenu("Disegna", menuBar);
    utility             = new QMenu("Utility", menuBar);
    help                = new QMenu("Help", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(disegnaMenu);
    menuBar->addMenu(utility);
    menuBar->addMenu(help);

    // Menu "File"
    file->addAction(new QAction("Salva", file));
    file->addAction(new QAction("Importa", file));
    file->addAction(new QAction("Chiudi", file));

    // Menu "Disegna"
    disegnaMenu->addAction(new QAction("Punto", disegnaMenu));
    disegnaMenu->addAction(new QAction("Segmento", disegnaMenu));
    disegnaMenu->addAction(new QAction("Retta", disegnaMenu));
    disegnaMenu->addAction(new QAction("Poligono", disegnaMenu));
    disegnaMenu->addAction(new QAction("Regolare", disegnaMenu));
    disegnaMenu->addAction(new QAction("Circonferenza", disegnaMenu));
    disegnaMenu->addAction(new QAction("Ellisse", disegnaMenu));

    // Menu "Utility"
    utility->addAction(new QAction("Elimina disegno", utility));
    utility->addAction(new QAction("Cancella tutto", utility));

    // Menu "Help"
    help->addAction(new QAction("Tutorial", help));

    connect(file->actions()[2], SIGNAL(triggered()), this, SLOT(close()));

    mainLayout->addWidget(menuBar);
}

void Interfaccia::buildSxLayout(QHBoxLayout *bodyInterface) {
    sxLayout       = new QVBoxLayout;
    buttonLayout   = new QHBoxLayout;
    infoLayout     = new QVBoxLayout;

    // Bottoni
    QPushButton* importa = new QPushButton("Importa");
    disegnaButton  = new QPushButton("Disegna");
    eliminaButton  = new QPushButton("Elimina");
    resetButton    = new QPushButton("Reset");

    QColor myRed;
    myRed.setRgb(217,36,0);
    QColor myGreen;
    myGreen.setRgb(21,194,27);

    disegnaButton->setAutoFillBackground(true);
    QPalette palette = disegnaButton->palette();
    palette.setColor(QPalette::Button, myGreen);
    palette.setColor(QPalette::ButtonText, QColor(Qt::white));
    disegnaButton->setPalette(palette);

    eliminaButton->setAutoFillBackground(true);
    palette = eliminaButton->palette();
    palette.setColor(QPalette::Button, myRed);
    palette.setColor(QPalette::ButtonText, QColor(Qt::white));
    eliminaButton->setPalette(palette);

    importa->setFixedSize(100,50);
    disegnaButton->setFixedSize(100,50);
    eliminaButton->setFixedSize(100,50);
    resetButton->setFixedSize(100,50);

    buttonLayout->addWidget(importa);
    buttonLayout->addWidget(disegnaButton);
    buttonLayout->addWidget(eliminaButton);
    buttonLayout->addWidget(resetButton);
    buttonLayout->setContentsMargins(20,30,30,30);
    sxLayout->addLayout(buttonLayout);

    //  Info
    infoScroll = new QScrollArea;
    infoBox = new QWidget;
    //scrollLayout = new QVBoxLayout(infoBox);
    infoDisegni = new QFormLayout;

    infoScroll->setBackgroundRole(QPalette::Light);
    infoScroll->setWidgetResizable(true);
    infoBox->setLayout(infoDisegni);
    infoScroll->setWidget(infoBox);

    infoLayout->addWidget(new QLabel("Info Oggetti"));
    infoLayout->addWidget(infoScroll);
    infoLayout->setContentsMargins(20, 20, 30, 20);
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

void Interfaccia::setStandardDialog() {

    formDialog     = new QDialog(this);
    mainLayout     = new QVBoxLayout;
    dialogButton   = new QHBoxLayout;
    formLayout     = new QFormLayout;

    inputNome      = new QLineEdit();
    colorLabel     = new QLabel;
    colorButton    = new QPushButton(tr("Colore"));
    bottoni        = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(colorButton, &QAbstractButton::clicked, this, &Interfaccia::selectColor);
    connect(bottoni, SIGNAL(accepted()), formDialog, SLOT(accept()));
    connect(bottoni, SIGNAL(rejected()), formDialog, SLOT(reject()));
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

    //qDebug("prima della connect");
    //connect(disegnaButton, &QPushButton::clicked, this, &Interfaccia::showSceltaFiguraDialog);
    //qDebug("dopo della connect");

    mainLayout->addLayout(bodyInterface);

    mainLayout->setSpacing(0);
    setLayout(mainLayout);
    resize(QSize(1024, 720));
}

void Interfaccia::setController(Controller *c) {
    controller = c;

    connect(disegnaMenu->actions()[0], SIGNAL(triggered()), controller, SLOT(addPunto()));
    connect(disegnaMenu->actions()[1], SIGNAL(triggered()), controller, SLOT(addSegmento()));
    connect(disegnaMenu->actions()[2], SIGNAL(triggered()), controller, SLOT(addRetta()));
    connect(disegnaMenu->actions()[3], SIGNAL(triggered()), controller, SLOT(addPoligono()));
    connect(disegnaMenu->actions()[4], SIGNAL(triggered()), controller, SLOT(addRegolare()));
    connect(disegnaMenu->actions()[5], SIGNAL(triggered()), controller, SLOT(addCirconferenza()));
    connect(disegnaMenu->actions()[6], SIGNAL(triggered()), controller, SLOT(addEllisse()));

    connect(utility->actions()[0], SIGNAL(triggered()), controller, SLOT(removeDisegno()));
    connect(utility->actions()[1], SIGNAL(triggered()), controller, SLOT(cancellaTutto()));

    connect(disegnaButton, &QPushButton::clicked, this, &Interfaccia::showSceltaFiguraDialog);
    connect(eliminaButton, SIGNAL(clicked()), controller, SLOT(removeDisegno()));
    connect(resetButton, SIGNAL(clicked()), controller, SLOT(cancellaTutto()));
}

void Interfaccia::selectColor()
{
    //QColorDialog::ColorDialogOptions options;
    QColor color = QColorDialog::getColor(Qt::black, this, "Seleziona colore");

    if (color.isValid()) {
        colorLabel->setText(color.name());
        colorLabel->setPalette(QPalette(color));
        colorLabel->setAutoFillBackground(true);
    }
}

void Interfaccia::showSceltaFiguraDialog() {
    QDialog* dialog = new QDialog(this);

    QVBoxLayout *verticalLayout = new QVBoxLayout;

    QPushButton* nuovoPunto         = new QPushButton("Punto");
    QPushButton* nuovoSegmento      = new QPushButton("Segmento");
    QPushButton* nuovaRetta         = new QPushButton("Retta");
    QPushButton* nuovoPoligono      = new QPushButton("Poligono");
    QPushButton* nuovoRegolare      = new QPushButton("Regolare");
    QPushButton* nuovaEllisse       = new QPushButton("Ellisse");
    QPushButton* nuovaCirconferenza = new QPushButton("Circonferenza");


    connect(nuovoPunto, SIGNAL(clicked()), controller, SLOT(addPunto()));
    connect(nuovoSegmento, SIGNAL(clicked()), controller, SLOT(addSegmento()));
    connect(nuovaRetta, SIGNAL(clicked()), controller, SLOT(addRetta()));
    connect(nuovoPoligono, SIGNAL(clicked()), controller, SLOT(addPoligono()));
    connect(nuovoRegolare, SIGNAL(clicked()), controller, SLOT(addRegolare()));
    connect(nuovaEllisse, SIGNAL(clicked()), controller, SLOT(addEllisse()));
    connect(nuovaCirconferenza, SIGNAL(clicked()), controller, SLOT(addCirconferenza()));

    verticalLayout->addWidget(nuovoPunto);
    verticalLayout->addWidget(nuovoSegmento);
    verticalLayout->addWidget(nuovaRetta);
    verticalLayout->addWidget(nuovoPoligono);
    verticalLayout->addWidget(nuovoRegolare);
    verticalLayout->addWidget(nuovaEllisse);
    verticalLayout->addWidget(nuovaCirconferenza);

    dialog->setLayout(verticalLayout);
    dialog->resize(QSize(720, 480));

    dialog->exec();
}

int Interfaccia::showWarningDialog(const QString &message) {
    /*
    QDialog* dialog = new QDialog(this);

    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(new QLabel(message, dialog));
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setMinimumWidth(120);
    dialog->setMaximumWidth(500);
    dialog->resize(QSize(320,120));

    dialog->exec();
    */
    QMessageBox msgBox(QMessageBox::Warning, tr("Attenzione"), message, { }, this);
    msgBox.setDetailedText(message);
    msgBox.addButton(tr("&Continua"), QMessageBox::AcceptRole);
    return msgBox.exec();
    //QMessageBox::ButtonRole
}

int Interfaccia::showConfermaDialog(const QString &message) {
    /*QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Attenzione!"),
                                    message,
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);*/
    QMessageBox msgQBox(QMessageBox::Question, tr("Attenzione"),
                        message,
                        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    return msgQBox.exec();
}

Vettore<QString> Interfaccia::showNewPuntoDialog() {
    setStandardDialog();
    formDialog->setWindowTitle("Nuovo Punto");

    // Set Input section
    inputNome               = new QLineEdit("P");
    QLineEdit* inputX       = new QLineEdit;
    QLineEdit* inputY       = new QLineEdit;
    validator               = new QDoubleValidator(-200.0, 200.0, 2, formDialog); // setto un validator per i double
    inputX->setValidator(validator);
    inputY->setValidator(validator);

    formLayout->addRow(new QLabel("Nome"), inputNome);
    formLayout->addRow(new QLabel("X"), inputX);
    formLayout->addRow(new QLabel("Y"), inputY);
    formLayout->addRow(colorButton, colorLabel);

    formLayout->setSpacing(10);

    // Set Button section
    dialogButton->addWidget(bottoni);

    mainLayout->addItem(formLayout);
    mainLayout->addLayout(dialogButton);
    formDialog->setLayout(mainLayout);

    formDialog->resize(QSize(400, 200));

    if(formDialog->exec()){ // se role == accepted => ha premuto OK
        Vettore<QString> results = {
            inputNome->text(),
            inputX->text(),
            inputY->text(),
            colorLabel->text()
        };
        return results;
    } else
        throw std::runtime_error("Operazione annullata");
}

Vettore<QString> Interfaccia::showNewLineaDialog(const Vettore<Punto*> punti, bool retta) {
    setStandardDialog();
    retta ? formDialog->setWindowTitle("Nuova retta") : formDialog->setWindowTitle("Nuovo segmento");

    // Set QComboBox
    QComboBox* boxPunti1 = new QComboBox(formDialog);
    QComboBox* boxPunti2 = new QComboBox(formDialog);
    for(auto point : punti){
        boxPunti1->addItem(QString::fromStdString(point->getNome()));
        boxPunti2->addItem(QString::fromStdString(point->getNome()));
    }

    formLayout->addRow(new QLabel("Nome"), inputNome);
    formLayout->addRow(new QLabel("Punto 1"), boxPunti1);
    formLayout->addRow(new QLabel("Punto 2"), boxPunti2);
    formLayout->addRow(colorButton, colorLabel);

    formLayout->setSpacing(10);

    // Set Button section
    dialogButton->addWidget(bottoni);

    mainLayout->addItem(formLayout);
    mainLayout->addLayout(dialogButton);
    formDialog->setLayout(mainLayout);

    formDialog->resize(QSize(400, 200));

    if(formDialog->exec()){ // se role == accepted => ha premuto OK
        if(boxPunti1->currentText().toStdString().empty() || boxPunti2->currentText().toStdString().empty())
            retta ?
                throw std::runtime_error("Punti insufficienti per identificare una retta sul piano")
              : throw std::runtime_error("Punti insufficienti per identificare un segmento sul piano");
        Vettore<QString> results = {
            inputNome->text(),
            QString::fromStdString(std::to_string(boxPunti1->currentIndex())),
            QString::fromStdString(std::to_string(boxPunti2->currentIndex())),
            colorLabel->text()
        };
        return results;
    } else
        throw std::runtime_error("Operazione annullata");
}

Vettore<QString> Interfaccia::showNewRegolareDialog(const Vettore<Punto *> punti) {
    setStandardDialog();
    formDialog->setWindowTitle("Nuovo Poligono Regolare");

    // Set Input section
    QLineEdit* inputLati    = new QLineEdit();
    validator = new QIntValidator(3, 12, formDialog);
    inputLati->setValidator(validator);

    // Set QComboBox
    QComboBox* boxPunti1 = new QComboBox(formDialog);
    QComboBox* boxPunti2 = new QComboBox(formDialog);
    for(auto point : punti){
        boxPunti1->addItem(QString::fromStdString(point->getNome()));
        boxPunti2->addItem(QString::fromStdString(point->getNome()));
    }

    formLayout->addRow(new QLabel("Nome"), inputNome);
    formLayout->addRow(new QLabel("Primo punto"), boxPunti1);
    formLayout->addRow(new QLabel("Secondo punto"), boxPunti2);
    formLayout->addRow(new QLabel("Numero vertici"), inputLati);
    formLayout->addRow(colorButton, colorLabel);

    formLayout->setSpacing(10);

    dialogButton->addWidget(bottoni);
    mainLayout->addItem(formLayout);
    mainLayout->addLayout(dialogButton);
    formDialog->setLayout(mainLayout);

    formDialog->resize(QSize(400, 200));

    Vettore<QString> results;
    if(formDialog->exec()){ // se role == accepted => ha premuto OK
        if(boxPunti1->currentText().toStdString().empty() || boxPunti2->currentText().toStdString().empty())
            throw std::runtime_error("Punti insufficienti per creare il poligono");
        results = {
            inputNome->text(),
            QString::fromStdString(std::to_string(boxPunti1->currentIndex())),
            QString::fromStdString(std::to_string(boxPunti2->currentIndex())),
            inputLati->text(),
            colorLabel->text()
        };
    }
    return results;
}

Vettore<QString> Interfaccia::showNewCirconferenzaDialog(const Vettore<Punto *> punti) {
    setStandardDialog();
    formDialog->setWindowTitle("Nuova Circonferenza");

    QLineEdit* inputRaggio  = new QLineEdit();
    validator = new QDoubleValidator(formDialog);
    inputRaggio->setValidator(validator);

    // Set QComboBox
    QComboBox* boxPunti = new QComboBox(formDialog);
    for(auto point : punti){
        boxPunti->addItem(QString::fromStdString(point->getNome()));
    }

    colorLabel = new QLabel;

    formLayout->addRow(new QLabel("Nome"), inputNome);
    formLayout->addRow(new QLabel("Centro"), boxPunti);
    formLayout->addRow(new QLabel("Raggio"), inputRaggio);
    formLayout->addRow(colorButton, colorLabel);

    formLayout->setSpacing(10);

    // Set Button section
    dialogButton->addWidget(bottoni);

    mainLayout->addItem(formLayout);
    mainLayout->addLayout(dialogButton);
    formDialog->setLayout(mainLayout);

    formDialog->resize(QSize(400, 200));

    Vettore<QString> results;
    if(formDialog->exec()){ // se role == accepted => ha premuto OK
        if(boxPunti->currentText().toStdString().empty())
            throw std::runtime_error("Impossibile identificare una circonferenza nel piano senza un centro");
        results = {
            inputNome->text(),
            QString::fromStdString(std::to_string(boxPunti->currentIndex())),
            inputRaggio->text(),
            colorLabel->text()
        };
    } //else
        //throw std::runtime_error("Operazione annullata");
    return results;
}

Vettore<QString> Interfaccia::showNewEllisseDialog(const Vettore<Punto *> punti) {
    setStandardDialog();
    formDialog->setWindowTitle("Nuova Ellisse");

    // Set Input section
    inputNome               = new QLineEdit();
    QLineEdit* inputRaggio  = new QLineEdit();
    QLineEdit* inputRaggio2 = new QLineEdit();
    validator = new QDoubleValidator(formDialog);
    inputRaggio->setValidator(validator);
    inputRaggio2->setValidator(validator);

    // Set QComboBox
    QComboBox* boxPunti = new QComboBox(formDialog);
    for(auto point : punti){
        boxPunti->addItem(QString::fromStdString(point->getNome()));
    }

    formLayout->addRow(new QLabel("Nome"), inputNome);
    formLayout->addRow(new QLabel("Centro"), boxPunti);
    formLayout->addRow(new QLabel("Semiasse 1"), inputRaggio);
    formLayout->addRow(new QLabel("Semiasse 2"), inputRaggio2);

    formLayout->addRow(colorButton, colorLabel);

    formLayout->setSpacing(10);

    // Set Button section
    dialogButton->addWidget(bottoni);

    mainLayout->addItem(formLayout);
    mainLayout->addLayout(dialogButton);
    formDialog->setLayout(mainLayout);

    formDialog->resize(QSize(400, 200));

    Vettore<QString> results;
    if(formDialog->exec()){ // se role == accepted => ha premuto OK
        if(boxPunti->currentText().toStdString().empty())
            throw std::runtime_error("Impossibile identificare un'ellisse nel piano senza un centro");
        results = {
            inputNome->text(),
            QString::fromStdString(std::to_string(boxPunti->currentIndex())),
            inputRaggio->text(),
            inputRaggio2->text(),
            colorLabel->text()
        };
    }
    return results;
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

void Interfaccia::pulisciInfoDisegni() {
    if(infoScroll->widget())
        infoScroll->deleteLater();

    //delete infoScroll;
    //delete infoBox;
    //delete infoDisegni;

    // Riassegno un nuovo Layout pulito
    /*
    infoScroll = new QScrollArea;
    infoBox = new QWidget;
    infoDisegni = new QFormLayout;

    infoScroll->setWidgetResizable(true);
    infoBox->setLayout(infoDisegni);
    infoScroll->setWidget(infoBox);
    infoLayout->addWidget(new QLabel("Info Oggetti"));
    infoLayout->addWidget(infoScroll);
    infoLayout->setContentsMargins(30,20,30,20);
    sxLayout->addLayout(infoLayout);

    infoLayout->addWidget(infoScroll);
    */
    infoScroll  = new QScrollArea;
    infoBox     = new QWidget;
    infoDisegni = new QFormLayout;

    infoScroll->setBackgroundRole(QPalette::Light);

    infoScroll->setWidgetResizable(true);
    infoBox->setLayout(infoDisegni);
    infoScroll->setWidget(infoBox);

    //infoLayout->addWidget(new QLabel("Info Oggetti"));
    infoLayout->addWidget(infoScroll);
    //infoLayout->setContentsMargins(30,20,30,20);
    //sxLayout->addLayout(infoLayout);
}

void Interfaccia::addInfoDisegnabile(std::unordered_map<std::string, std::string> info, unsigned int index) {
    for(auto&& el : info) {
        if(el.first == "Nome") infoDisegni->addRow(new QLabel("Numero"), new QLabel(QString::fromStdString(std::to_string(index))));
        infoDisegni->addRow(new QLabel(QString::fromStdString(el.first)), new QLabel(QString::fromStdString(el.second)));
    }
    infoBox->setLayout(infoDisegni);
    infoScroll->setWidget(infoBox);
}
