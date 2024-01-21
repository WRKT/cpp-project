#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "accueil.h"
#include "morpiongui.h"

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
    TypesJeu typeJeu;

    void initWidgets();

public slots:
    void creerNouveauJeu(TypesJeu typedeJeu);
};
#endif // MAINWINDOW_H
