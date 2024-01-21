#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWidgets();
}

MainWindow::~MainWindow()
{
    delete accueilWidget;
    delete morpionWidget;
    delete ui;
}

void MainWindow::initWidgets()
{
    accueilWidget = new Accueil(this);
    setCentralWidget(accueilWidget);

    connect(accueilWidget, &Accueil::selectionTypeJeu, this, &MainWindow::creerNouveauJeu);

}

void MainWindow::creerNouveauJeu(TypesJeu typeDeJeu)
{
    typeJeu = typeDeJeu;

    if (morpionWidget) {
        delete morpionWidget;
        morpionWidget = nullptr;
    }

    morpionWidget = new MorpionGUI(this, typeJeu);

    connect(morpionWidget, &MorpionGUI::showAccueil, this, [=]() {
        morpionWidget->hide();
        accueilWidget->show();
    });

    morpionWidget->show();
}
