#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    accueilWidget(nullptr),
    jeuWidget(nullptr)
{
    ui->setupUi(this);
    initWidgets();

    setFixedSize(1024,768);

    connect(this, &QMainWindow::destroyed, this, &MainWindow::QuitterApplication);
}

MainWindow::~MainWindow()
{
    if (accueilWidget) {
        disconnect(accueilWidget.get(), &Accueil::selectionTypeJeu, this, &MainWindow::CreerNouveauJeu);
        accueilWidget.reset();
    }

    if (jeuWidget) {
        jeuWidget.reset();
    }

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

void MainWindow::closeEvent(QCloseEvent *event)
{
    QuitterApplication();
    event->accept();
}

void MainWindow::QuitterApplication()
{
    disconnect(accueilWidget.get(), &Accueil::selectionTypeJeu, this, &MainWindow::CreerNouveauJeu);
    accueilWidget.reset();
    jeuWidget.reset();

    qDebug() << "Quitting application...";
    qApp->quit();
}
