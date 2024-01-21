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
    // delete puissance4Widget;
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

    // connect(accueilWidget, &Accueil::showPuissance4, this, [=]() {
    //     accueilWidget->hide();
    //     puissance4Widget->show();
    // });

    connect(morpionWidget, &MorpionGUI::showAccueil, this, [=]() {
        morpionWidget->hide();
        accueilWidget->show();
    });

    // connect(puissance4Widget, &Puissance4GUI::showAccueil, this, [=]() {
    //     puissance4Widget->hide();
    //     accueilWidget->show();
    // });

    accueilWidget->show();
    morpionWidget->hide();
    // puissance4Widget->hide();
}
