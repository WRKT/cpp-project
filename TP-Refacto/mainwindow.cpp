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
    morpionWidget = new MorpionGUI(this);

    connect(accueilWidget, &Accueil::showMorpion, this, [=]() {
        accueilWidget->hide();
        morpionWidget->show();
    });

    connect(morpionWidget, &MorpionGUI::showAccueil, this, [=]() {
        morpionWidget->hide();
        accueilWidget->show();
    });

    accueilWidget->show();
    morpionWidget->hide();
}
