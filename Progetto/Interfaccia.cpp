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

    //qDebug("prima della connect");
    connect(disegnaButton, &QPushButton::clicked, this, &Interfaccia::showSceltaFiguraDialog);
    //qDebug("dopo della connect");

    mainLayout->addLayout(bodyInterface);

    mainLayout->setSpacing(0);
    setLayout(mainLayout);
    resize(QSize(1024, 720));
}

void Interfaccia::setController(Controller *c) {
    controller = c;

    connect(resetButton, SIGNAL(clicked()), controller, SLOT(removeDisegno()));
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

    QPushButton* nuovoPunto = new QPushButton("Nuovo Punto");
    verticalLayout->addWidget(nuovoPunto);
    dialog->setLayout(verticalLayout);
    dialog->resize(QSize(720, 480));

    connect(nuovoPunto, SIGNAL(clicked()), controller, SLOT(addPunto()));

    dialog->exec();
    qDebug("popup chiuso");
}

void Interfaccia::showWarningDialog(const QString &message) {
    QDialog* dialog = new QDialog(this);

    dialog->setLayout(new QHBoxLayout);
    dialog->layout()->addWidget(new QLabel(message, dialog));
    dialog->layout()->setAlignment(Qt::AlignCenter);
    dialog->setMinimumWidth(120);
    dialog->setMaximumWidth(500);

    dialog->exec();
}

Vettore<QString> Interfaccia::showNewPuntoDialog() {
    QDialog* formDialog = new QDialog(this);
    formDialog->setWindowTitle("Nuovo Punto");

    QVBoxLayout* mainLayout     = new QVBoxLayout;/*
    QHBoxLayout* inputLayout    = new QHBoxLayout;
    QVBoxLayout* sxLabelLayout  = new QVBoxLayout;
    QVBoxLayout* dxInputLayout  = new QVBoxLayout;*/
    QHBoxLayout* buttonLayout   = new QHBoxLayout;

    QFormLayout* formLayout = new QFormLayout;

    QPushButton *colorButton = new QPushButton(tr("Colore"));
    connect(colorButton, &QAbstractButton::clicked, this, &Interfaccia::selectColor);

    QLineEdit* inputNome    = new QLineEdit("P");
    QLineEdit* inputX       = new QLineEdit;
    QLineEdit* inputY       = new QLineEdit;
    QDoubleValidator* validator = new QDoubleValidator(-200.0, 200.0, 2, formDialog);
    inputX->setValidator(validator);
    inputY->setValidator(validator);
    colorLabel = new QLabel;

    formLayout->addRow(new QLabel("Nome"), inputNome);
    formLayout->addRow(new QLabel("X"), inputX);
    formLayout->addRow(new QLabel("Y"), inputY);
    formLayout->addRow(colorButton, colorLabel);

    formLayout->setSpacing(10);

    /*
    // SX Label Layout
    QLabel* nome    = new QLabel("Nome");
    QLabel* x       = new QLabel("X");
    QLabel* y       = new QLabel("Y");
    //QLabel* color   = new QLabel("Colore");
    QPushButton *colorButton = new QPushButton(tr("Colore"));
    connect(colorButton, &QAbstractButton::clicked, this, &Interfaccia::selectColor);

    sxLabelLayout->addWidget(nome);
    sxLabelLayout->addWidget(x);
    sxLabelLayout->addWidget(y);
    sxLabelLayout->addWidget(colorButton);
    //sxLabelLayout->addWidget(color);

    QLineEdit* inputNome    = new QLineEdit("P");
    QLineEdit* inputX       = new QLineEdit;
    QLineEdit* inputY       = new QLineEdit;
    QDoubleValidator* validator = new QDoubleValidator(-200.0, 200.0, 2, formDialog);
    inputX->setValidator(validator);
    inputY->setValidator(validator);
    colorLabel = new QLabel;
    //QLineEdit* inputColor   = new QLineEdit();

    dxInputLayout->addWidget(inputNome);
    dxInputLayout->addWidget(inputX);
    dxInputLayout->addWidget(inputY);
    dxInputLayout->addWidget(colorLabel);
*/
    QDialogButtonBox* bottoni = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(bottoni, SIGNAL(accepted()), formDialog, SLOT(accept()));
    connect(bottoni, SIGNAL(rejected()), formDialog, SLOT(reject()));

    buttonLayout->addWidget(bottoni);

    //inputLayout->addLayout(sxLabelLayout);
    //inputLayout->addLayout(dxInputLayout);
    //mainLayout->addLayout(inputLayout);
    mainLayout->addItem(formLayout);
    mainLayout->addLayout(buttonLayout);

    formDialog->setLayout(mainLayout);

    formDialog->resize(QSize(400, 200));

    //formDialog->exec();

    if(formDialog->exec()){
        Vettore<QString> results = {
            inputNome->text(),
            inputX->text(),
            inputY->text(),
            colorLabel->text()
        };
        return results;
    } else
        throw std::runtime_error("Operazione annullata");
        //return Vettore<QString>();

    /*
    double ascissa = QString(inputX->text()).toDouble();
    double ordinata = QString(inputY->text()).toDouble();
    std::cout << ascissa << " " << ordinata << "\n";
    */
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
    for(auto el : info) {
        std::cout << el.first << " | " << el.second << std::endl;
    }
}
