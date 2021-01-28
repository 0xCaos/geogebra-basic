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

void Interfaccia::setStandardDialog() {

    formDialog     = new QDialog(this);
    mainLayout     = new QVBoxLayout;
    buttonLayout   = new QHBoxLayout;
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

    connect(disegnaButton, &QPushButton::clicked, this, &Interfaccia::showSceltaFiguraDialog);
    connect(eliminaButton, SIGNAL(clicked()), controller, SLOT(removeDisegno()));
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

void Interfaccia::showWarningDialog(const QString &message) {
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
    //QLabel* warningLabel = new QLabel;
    msgBox.setDetailedText(message);
    msgBox.addButton(tr("&Continua"), QMessageBox::AcceptRole);
    msgBox.exec();
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
    buttonLayout->addWidget(bottoni);

    mainLayout->addItem(formLayout);
    mainLayout->addLayout(buttonLayout);
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
    buttonLayout->addWidget(bottoni);

    mainLayout->addItem(formLayout);
    mainLayout->addLayout(buttonLayout);
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

    buttonLayout->addWidget(bottoni);
    mainLayout->addItem(formLayout);
    mainLayout->addLayout(buttonLayout);
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
    buttonLayout->addWidget(bottoni);

    mainLayout->addItem(formLayout);
    mainLayout->addLayout(buttonLayout);
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
    buttonLayout->addWidget(bottoni);

    mainLayout->addItem(formLayout);
    mainLayout->addLayout(buttonLayout);
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

void Interfaccia::addInfoDisegnabile(std::unordered_map<std::string, std::string> info) {
    for(auto& el : info) {
        std::cout << el.first << " | " << el.second << std::endl;
    }
}
