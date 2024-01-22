#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWidgets();

    disconnect(this, &MainWindow::destroyed, this, &MainWindow::QuitterApplication);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWidgets()
{
    accueilWidget = std::make_unique<Accueil>(this);
    setCentralWidget(accueilWidget.get());

    connect(accueilWidget.get(), &Accueil::selectionTypeJeu, this, &MainWindow::CreerNouveauJeu);

}

void MainWindow::CreerNouveauJeu(TypesJeu typeDeJeu)
{
    typeJeu = typeDeJeu;

    if (jeuWidget) {
        jeuWidget = nullptr;
    }

    jeuWidget = std::make_unique<JeuGUI>(this, typeDeJeu);

    connect(jeuWidget.get(), &JeuGUI::showAccueil, this, [=]() {
        jeuWidget->hide();
        accueilWidget->show();
    });

    jeuWidget->show();
}

void MainWindow::QuitterApplication()
{
    QCoreApplication::quit();
}
