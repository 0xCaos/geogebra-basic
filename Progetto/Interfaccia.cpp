#include "Interfaccia.h"
#include "Controller.h"

void Interfaccia::addMenu(QVBoxLayout *mainLayout) {
    menuBar             = new QMenuBar(this);
    file                = new QMenu("File", menuBar);
    disegnaMenu         = new QMenu("Disegno", menuBar);
    utility             = new QMenu("Cancellazione", menuBar);
    help                = new QMenu("Aiuto", menuBar);

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
    help->addAction(new QAction("Informazioni e Tutorial", help));

    mainLayout->addWidget(menuBar);
}

void Interfaccia::buildSxLayout(QHBoxLayout *bodyInterface) {
    sxLayout       = new QVBoxLayout;
    buttonLayout   = new QHBoxLayout;
    infoLayout     = new QVBoxLayout;

    // Bottoni
    importaButton  = new QPushButton("Importa");
    disegnaButton  = new QPushButton("Disegna");
    eliminaButton  = new QPushButton("Elimina");
    resetButton    = new QPushButton("Reset");

    // Settaggio dei pulsanti
    setMainButtons();

    buttonLayout->setContentsMargins(20,30,30,30);
    sxLayout->addLayout(buttonLayout);

    //  Info disegni
    infoScroll = new QScrollArea;
    infoBox = new QWidget;
    infoDisegni = new QFormLayout;

    infoScroll->setBackgroundRole(QPalette::Light);
    infoScroll->setWidgetResizable(true);
    infoBox->setLayout(infoDisegni);
    infoScroll->setWidget(infoBox);

    infoLayout->addWidget(new QLabel("Info Oggetti"));
    infoLayout->addWidget(infoScroll);
    infoLayout->setContentsMargins(20, 20, 30, 20);
    sxLayout->addLayout(infoLayout);

    infoScroll->setMaximumSize(400, 16777215); // set della size w=400 MAX, h=MAX_QT

    bodyInterface->addLayout(sxLayout);
}

void Interfaccia::buildDxLayout(QHBoxLayout *bodyInterface) {
    QVBoxLayout* dxLayout   = new QVBoxLayout;
    dxLayout->setMargin(0);

    QScrollArea* pianoScroll = new QScrollArea;

    /*
     * Creazione del piano cartesiano
     */

    pianoCartesiano->setMinimumSize(3000,3000);

    // Pulsanti per lo zoom "+" e "-"
    QPushButton* zoomIn = new QPushButton("+", pianoScroll);
    QPushButton* zoomOut = new QPushButton("-", pianoScroll);

    connect(zoomIn, &QPushButton::clicked, this, &Interfaccia::setZoomIn);
    connect(zoomOut, &QPushButton::clicked, this, &Interfaccia::setZoomOut);

    int buttonSize = 40;
    zoomIn->setGeometry(5, 5, buttonSize, buttonSize);
    zoomOut->setGeometry(5, 50, buttonSize, buttonSize);

    /* ----------------------------------- */

    dxLayout->setContentsMargins(1,30,20,20);

    pianoScroll->setWidgetResizable(true);
    pianoScroll->setWidget(pianoCartesiano);

    pianoScroll->horizontalScrollBar()->setValue(950);
    pianoScroll->verticalScrollBar()->setValue(950);

    dxLayout->addWidget(pianoScroll);

    bodyInterface->addLayout(dxLayout);
}

void Interfaccia::setMainButtons() {
    // Creazione dei colori personalizzati
    QColor myRed;
    myRed.setRgb(186,34,4);
    QColor myGreen;
    myGreen.setRgb(13,158,17);
    QColor myBlue;
    myBlue.setRgb(32,97,201);
    QColor myYellow;
    myYellow.setRgb(191,173,4);

    QPalette palette;

    // "Importa"
    importaButton->setAutoFillBackground(true);
    palette = importaButton->palette();
    palette.setColor(QPalette::Button, myBlue);
    palette.setColor(QPalette::ButtonText, QColor(Qt::white));
    importaButton->setPalette(palette);

    // "Disegna"
    disegnaButton->setAutoFillBackground(true);
    palette = disegnaButton->palette();
    palette.setColor(QPalette::Button, myGreen);
    palette.setColor(QPalette::ButtonText, QColor(Qt::white));
    disegnaButton->setPalette(palette);

    // "Elimina"
    eliminaButton->setAutoFillBackground(true);
    palette = eliminaButton->palette();
    palette.setColor(QPalette::Button, myRed);
    palette.setColor(QPalette::ButtonText, QColor(Qt::white));
    eliminaButton->setPalette(palette);

    // "Reset"
    resetButton->setAutoFillBackground(true);
    palette = resetButton->palette();
    palette.setColor(QPalette::Button, myYellow);
    palette.setColor(QPalette::ButtonText, QColor(Qt::white));
    resetButton->setPalette(palette);

    // Set della size dei pulsanti
    importaButton->setFixedSize(100,50);
    disegnaButton->setFixedSize(100,50);
    eliminaButton->setFixedSize(100,50);
    resetButton->setFixedSize(100,50);

    // Aggiunta al rispettivo layout
    buttonLayout->addWidget(importaButton);
    buttonLayout->addWidget(disegnaButton);
    buttonLayout->addWidget(eliminaButton);
    buttonLayout->addWidget(resetButton);
}

void Interfaccia::setStandardDialog() {
    // Creazione dei componenti standard per ogni layout di Input    
    formDialog     = new QDialog(this);
    mainLayout     = new QVBoxLayout;
    dialogButton   = new QHBoxLayout;
    formLayout     = new QFormLayout;

    inputNome      = new QLineEdit;
    colorLabel     = new QLabel;
    colorButton    = new QPushButton(tr("Colore"));
    bottoni        = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(colorButton, &QPushButton::clicked, this, &Interfaccia::selectColor);
    connect(bottoni, SIGNAL(accepted()), formDialog, SLOT(accept()));
    connect(bottoni, SIGNAL(rejected()), formDialog, SLOT(reject()));
}

void Interfaccia::popolaComboBox(const Vettore<Punto *> &punti, const Vettore<QComboBox *> &comboBox) {
    for(auto& cb : comboBox){
        for(auto& p : punti){
            cb->addItem(QString::fromStdString(p->getNome()));
        }
    }
}

Interfaccia::Interfaccia(QWidget *parent) : QWidget(parent), pianoCartesiano(new PianoCartesiano) {
    QVBoxLayout* mainLayout = new QVBoxLayout;

    /***
     * mainLayout
     *   menuBar
     *      (interfaccia)
     *      sxLayout
     *          buttonLayout
     *          infoLayout
     *      dxLayout
     *          pianocartesiano
     *          zoomButtons
     * */

    addMenu(mainLayout);

    // Body Interfaccia
    QHBoxLayout* bodyInterface = new QHBoxLayout;

    buildSxLayout(bodyInterface);
    buildDxLayout(bodyInterface);

    mainLayout->addLayout(bodyInterface);

    mainLayout->setSpacing(0);
    setLayout(mainLayout);
    resize(QSize(1600, 1200)); // resize ottimale alla prima apertura
}

void Interfaccia::setController(Controller *c) {
    // Set del controller
    controller = c;

    // Connessioni SIGNAL => SLOT

    // Menu "File"
    connect(file->actions().at(0), SIGNAL(triggered()), controller, SLOT(saveToFile()));
    connect(file->actions().at(1), SIGNAL(triggered()), controller, SLOT(loadFromFile()));
    connect(file->actions().at(2), SIGNAL(triggered()), this, SLOT(close()));

    // Menu "Disegna"
    connect(disegnaMenu->actions().at(0), SIGNAL(triggered()), controller, SLOT(addPunto()));
    connect(disegnaMenu->actions().at(1), SIGNAL(triggered()), controller, SLOT(addSegmento()));
    connect(disegnaMenu->actions().at(2), SIGNAL(triggered()), controller, SLOT(addRetta()));
    connect(disegnaMenu->actions().at(3), SIGNAL(triggered()), controller, SLOT(addPoligono()));
    connect(disegnaMenu->actions().at(4), SIGNAL(triggered()), controller, SLOT(addRegolare()));
    connect(disegnaMenu->actions().at(5), SIGNAL(triggered()), controller, SLOT(addCirconferenza()));
    connect(disegnaMenu->actions().at(6), SIGNAL(triggered()), controller, SLOT(addEllisse()));
    
    // Menu "Cancellazione"
    connect(utility->actions().at(0), SIGNAL(triggered()), controller, SLOT(removeDisegno()));
    connect(utility->actions().at(1), SIGNAL(triggered()), controller, SLOT(cancellaTutto()));

    // Menu "Tutorial"
    connect(help->actions().at(0), SIGNAL(triggered()), this, SLOT(showTutorialDialog()));

    // Main Buttons
    connect(importaButton, SIGNAL(clicked()), controller, SLOT(loadFromFile()));
    connect(disegnaButton, &QPushButton::clicked, this, &Interfaccia::showSceltaFiguraDialog);
    connect(eliminaButton, SIGNAL(clicked()), controller, SLOT(removeDisegno()));
    connect(resetButton, SIGNAL(clicked()), controller, SLOT(cancellaTutto()));
}

void Interfaccia::selectColor()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Seleziona colore");

    if (color.isValid()) {
        colorLabel->setText(color.name());
        colorLabel->setPalette(QPalette(color));
        colorLabel->setAutoFillBackground(true);
    }
}

void Interfaccia::setZoomIn() {
    pianoCartesiano->modificaScala(5);  // +5 e -5 sono i valori ottimali per la modifica della scala
}


void Interfaccia::setZoomOut() {
    pianoCartesiano->modificaScala(-5);  // +5 e -5 sono i valori ottimali per la modifica della scala
}

void Interfaccia::showSceltaFiguraDialog() {
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Disegna");

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
    dialog->setFixedSize(300, 300);

    dialog->exec();
}

int Interfaccia::showWarningDialog(const QString &message) {
    QMessageBox msgBox(QMessageBox::Warning, tr("Attenzione"), message, { }, this);
    msgBox.addButton(tr("&Continua"), QMessageBox::AcceptRole);
    return msgBox.exec();
}

int Interfaccia::showConfermaDialog(const QString &message) {
    QMessageBox msgQBox(QMessageBox::Question, tr("Attenzione"),
                        message,
                        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);

    msgQBox.setButtonText(QMessageBox::Yes, tr("&Si"));
    msgQBox.setButtonText(QMessageBox::No, tr("&No"));
    msgQBox.setButtonText(QMessageBox::Cancel, tr("&Annulla"));

    return msgQBox.exec();
}

void Interfaccia::showTutorialDialog() {
    QString testo (
            "Informazioni: \n\n"
            "GeogebraBasic è un programma che si ispira al più rinomato Geogebra. La versione proposta è una soluzione "
            "semplificata che ha lo scopo di fornire i dati e le propietà più importanti delle principali figure della geometria piana.\n\n"
            "Tutorial: \n\n"
            "Per poter disegnare qualsiasi figura \"complessa\" occorre prima disegnare i punti necessari per poi indicarli nella finestra di input corrispondente.\n\n"
            "Si possono usare i pulsantoni colorati per le principali operazioni oppure usare il menu a tendina completo di tutte le funzioni diviso per il tipo di operazione eseguita.");
    QMessageBox msgQBox(QMessageBox::Information, tr("Informazioni GeogebraBasic"),testo,QMessageBox::Cancel, this);
    msgQBox.setButtonText(QMessageBox::Cancel, tr("&Chiudi"));

    msgQBox.exec();
}

Vettore<QString> Interfaccia::showNewPuntoDialog() {
    setStandardDialog();
    formDialog->setWindowTitle("Nuovo Punto");

    // Set Input section
    inputNome->setText("P");
    inputNome->setMaxLength(1);
    validator               = new QRegularExpressionValidator(QRegularExpression("[A-Z][^A-Z]"), formDialog);
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

    Vettore<QString> results;
    if(formDialog->exec()){ // se role == accepted => ha premuto OK
        results = {
            inputNome->text(),
            inputX->text(),
            inputY->text(),
            colorLabel->text()
        };
    }

    delete inputNome;
    delete colorLabel;
    return results;
}

Vettore<QString> Interfaccia::showNewLineaDialog(const Vettore<Punto*> punti, bool retta) {
    setStandardDialog();
    retta ? formDialog->setWindowTitle("Nuova retta") : formDialog->setWindowTitle("Nuovo segmento");

    // Set QComboBox
    boxPunti1 = new QComboBox(formDialog);
    boxPunti2 = new QComboBox(formDialog);

    popolaComboBox(punti, {boxPunti1, boxPunti2});

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

    Vettore<QString> results;
    if(formDialog->exec()){ // se role == accepted => ha premuto OK
        if(boxPunti1->currentText().toStdString().empty() || boxPunti2->currentText().toStdString().empty())
            retta ?
                throw std::runtime_error("Punti insufficienti per identificare una retta sul piano")
              : throw std::runtime_error("Punti insufficienti per identificare un segmento sul piano");
        results = {
            inputNome->text(),
            QString::fromStdString(std::to_string(boxPunti1->currentIndex())),
            QString::fromStdString(std::to_string(boxPunti2->currentIndex())),
            colorLabel->text()
        };
    }

    delete inputNome;
    delete colorLabel;
    return results;
}

Vettore<QString> Interfaccia::showNewRegolareDialog(const Vettore<Punto *> punti) {
    setStandardDialog();
    formDialog->setWindowTitle("Nuovo Poligono Regolare");

    // Set Input section
    QLineEdit* inputLati    = new QLineEdit();
    validator = new QIntValidator(3, 15, formDialog);
    inputLati->setValidator(validator);

    // Set QComboBox
    boxPunti1 = new QComboBox(formDialog);
    boxPunti2 = new QComboBox(formDialog);

    popolaComboBox(punti, {boxPunti1, boxPunti2});

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

    delete inputNome;
    delete colorLabel;
    return results;
}

Vettore<QString> Interfaccia::showNewPoligonoDialog(const Vettore<Punto *> punti) {
    bool ok = false;
    Vettore<QString> results;
    unsigned int n =
            QInputDialog::getInt(this, tr("Numero Vertici Poligono"),
                         "Inserire il numero di vertici (almeno 3): ", 1, 3, 19, 1, &ok);
    if(ok) {

        setStandardDialog();
        formDialog->setWindowTitle("Nuovo Poligono Irregolare");

        formLayout->addRow(new QLabel("Nome"), inputNome);

        // ComboBox da copiare nelle altre CB
        QComboBox* boxPunti = new QComboBox;
        popolaComboBox(punti, {boxPunti});

        for(unsigned int k=0; k<n; ++k) {
            QComboBox* boxPunti1 = new QComboBox(formDialog);
            for(int i = 0; i < boxPunti->count(); i++){
                boxPunti1->addItem(boxPunti->itemText(i));
            }
            formLayout->addRow(boxPunti1);
        }

        formLayout->addRow(colorButton, colorLabel);
        formLayout->setSpacing(10);

        dialogButton->addWidget(bottoni);
        mainLayout->addLayout(formLayout);
        mainLayout->addLayout(dialogButton);
        formDialog->setLayout(mainLayout);

        formDialog->resize(QSize(400, 200));

        if(formDialog->exec()) { // se role == accepted => ha premuto OK          
            results.push_back(inputNome->text());
            /*  Ciclo per prendere i valori da tutte le QComboBox dei punti
             *
             * 1 <= i <= rowCount()
             * perchè:
             *  - in posizione 0 ho il QLineEdit di nome
             *  - in posizione rowCount() ho la color label
             */
            for(int i = 1; i < formLayout->rowCount(); i++){
                QLayoutItem* box = formLayout->itemAt(i);
                QComboBox* b = qobject_cast<QComboBox*>(box->widget()); // tentativo di downcast QWidget* -> QComboBox*
                if(b) {
                    results.push_back(QString::fromStdString(std::to_string(b->currentIndex())));
                }
            }
            results.push_back(colorLabel->text());
        }
        delete inputNome;
        delete colorLabel;
    }

    return results;
}

Vettore<QString> Interfaccia::showNewCirconferenzaDialog(const Vettore<Punto *> punti) {
    setStandardDialog();
    formDialog->setWindowTitle("Nuova Circonferenza");

    QLineEdit* inputRaggio  = new QLineEdit();
    validator = new QDoubleValidator(0.1,50,4,formDialog);
    inputRaggio->setValidator(validator);

    // Set QComboBox
    boxPunti1   = new QComboBox(formDialog);

    popolaComboBox(punti, {boxPunti1});

    colorLabel = new QLabel;

    formLayout->addRow(new QLabel("Nome"), inputNome);
    formLayout->addRow(new QLabel("Centro"), boxPunti1);
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
        if(boxPunti1->currentText().toStdString().empty())
            throw std::runtime_error("Impossibile identificare una circonferenza nel piano senza un centro");
        results = {
            inputNome->text(),
            QString::fromStdString(std::to_string(boxPunti1->currentIndex())),
            inputRaggio->text(),
            colorLabel->text()
        };
    }

    delete inputNome;
    delete colorLabel;
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
    boxPunti1 = new QComboBox(formDialog);

    popolaComboBox(punti, {boxPunti1});

    formLayout->addRow(new QLabel("Nome"), inputNome);
    formLayout->addRow(new QLabel("Centro"), boxPunti1);
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
        if(boxPunti1->currentText().toStdString().empty())
            throw std::runtime_error("Impossibile identificare un'ellisse nel piano senza un centro");
        results = {
            inputNome->text(),
            QString::fromStdString(std::to_string(boxPunti1->currentIndex())),
            inputRaggio->text(),
            inputRaggio2->text(),
            colorLabel->text()
        };
    }

    delete inputNome;
    delete colorLabel;
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

    infoScroll  = new QScrollArea;
    infoBox     = new QWidget;
    infoDisegni = new QFormLayout;

    infoScroll->setBackgroundRole(QPalette::Light);

    infoScroll->setWidgetResizable(true);
    infoBox->setLayout(infoDisegni);
    infoScroll->setWidget(infoBox);

    infoLayout->addWidget(infoScroll);

    infoScroll->setMaximumSize(400, 16777215);
}

void Interfaccia::addInfoDisegnabile(std::unordered_map<std::string, std::string> info, unsigned int index) {
    QFrame* frame = new QFrame;
    QFormLayout* box = new QFormLayout(frame);
    for(auto&& el : info) {
        if(el.first == "Nome")
            box->addRow(new QLabel("N#"), new QLabel(QString::fromStdString(std::to_string(index))));

        if((el.first == "Colore")){
            QColor color = QString::fromStdString(el.second);
            QLabel* colorLabel = new QLabel;
            //if (color.isValid()) {
                colorLabel->setPalette(QPalette(color));
                colorLabel->setAutoFillBackground(true);
            //}
            colorLabel->setFixedSize(20,20);
            box->addRow(new QLabel(QString::fromStdString(el.first)), colorLabel);
        }
        else {
            box->addRow(new QLabel(QString::fromStdString(el.first)), new QLabel(QString::fromStdString(el.second)));
        }
    }

    frame->setLayout(box);
    frame->setFrameStyle(QFrame::StyledPanel | QFrame::Raised);
    frame->setLineWidth(1);

    infoDisegni->addRow(frame);
    infoBox->setLayout(infoDisegni);
    infoScroll->setWidget(infoBox);
}

void Interfaccia::refreshPiano() {
    pianoCartesiano->setWorkspace(controller->getWorkspace());
    pianoCartesiano->refresh();
}

QString Interfaccia::showSaveFile()
{
    QFileDialog saveDialog(this);
    QString fileName = saveDialog.getSaveFileName(
        this,
        tr("Salva disegni"), "",
        tr(".json (*.json)")
    );
    if (fileName == "")
       throw std::runtime_error("Nessun file selezionato: operazione annullata.");
    if (!fileName.endsWith(".json"))
        fileName += ".json";
    return fileName;
}

QString Interfaccia::showLoadFile()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Apri il file"), "",
        tr(".json (*.json)")
    );
    if (fileName == "")
        throw std::runtime_error("Nessun file selezionato: operazione annullata.");
    return fileName;
}

void Interfaccia::closeEvent(QCloseEvent *event) {
    if (!pianoCartesiano->pianocartesianoVuoto()) {
        event->ignore();

        int risposta = showConfermaDialog("Vuoi salvare prima di chiudere?");

        if (risposta == QMessageBox::Cancel)
            return;
        if (risposta == QMessageBox::Yes) {
            if (controller->saveToFile())
                event->accept();
        }
        if (risposta == QMessageBox::No)
            event->accept();
    }
}
