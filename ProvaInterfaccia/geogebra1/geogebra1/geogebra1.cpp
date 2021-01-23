#include "geogebra1.h"
#include "ui_geogebra1.h"

Geogebra1::Geogebra1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Geogebra1)
{
    ui->setupUi(this);
}

Geogebra1::~Geogebra1()
{
    delete ui;
}

