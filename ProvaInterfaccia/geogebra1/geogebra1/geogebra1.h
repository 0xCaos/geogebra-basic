#ifndef GEOGEBRA1_H
#define GEOGEBRA1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Geogebra1; }
QT_END_NAMESPACE

class Geogebra1 : public QMainWindow
{
    Q_OBJECT

public:
    Geogebra1(QWidget *parent = nullptr);
    ~Geogebra1();

private:
    Ui::Geogebra1 *ui;
};
#endif // GEOGEBRA1_H
