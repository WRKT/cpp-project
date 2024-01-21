#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "accueil.h"
#include "morpiongui.h"
#include "puissance4gui.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Accueil *accueilWidget;
    MorpionGUI *morpionWidget;
    // Puissance4GUI *puissance4Widget;

    void initWidgets();
};
#endif // MAINWINDOW_H
