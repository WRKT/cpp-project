#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "accueil.h"
#include "jeugui.h"

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
    std::unique_ptr<Accueil> accueilWidget;
    std::unique_ptr<JeuGUI> jeuWidget;
    TypesJeu typeJeu;

    void initWidgets();

public slots:
    void CreerNouveauJeu(TypesJeu typedeJeu);
    void QuitterApplication();
};

#endif // MAINWINDOW_H
