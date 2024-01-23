#include "accueil.h"
#include "ui_accueil.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>


Accueil::Accueil(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Accueil)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    QVBoxLayout *welcomeLayout = new QVBoxLayout();
    QLabel *welcomeLabel = new QLabel("Bienvenue dans notre interface", this);
    welcomeLabel->setFont(QFont("Segoe UI", 14, QFont::Bold));
    welcomeLabel->setAlignment(Qt::AlignHCenter);
    welcomeLayout->addWidget(welcomeLabel);
    welcomeLayout->setSpacing (50);

    QLabel *menuLabel = new QLabel("Menu Principal", this);
    menuLabel->setFont(QFont("Segoe UI", 12, QFont::Bold));
    menuLabel->setAlignment(Qt::AlignHCenter);
    mainLayout->addWidget(menuLabel);
    mainLayout->setSpacing (100);

    QLabel *choixLabel = new QLabel("Veuillez choisir votre jeu", this);
    choixLabel->setFont(QFont("Segoe UI", 12, QFont::Bold));
    choixLabel->setAlignment(Qt::AlignHCenter);
    welcomeLayout->addWidget(choixLabel);
    welcomeLayout->setSpacing (50);

    mainLayout->addLayout(welcomeLayout);

    QGridLayout *buttonGridLayout = new QGridLayout();

    ui->morpionButton->setMinimumSize(150, 50);
    ui->puissance4Button->setMinimumSize(150, 50);
    ui->othelloButton->setMinimumSize(150, 50);
    ui->damesButton->setMinimumSize(150, 50);
    ui->exitGame->setMinimumSize(150, 50);

    buttonGridLayout->addWidget(ui->morpionButton, 0, 0);
    buttonGridLayout->addWidget(ui->puissance4Button, 0, 1);
    buttonGridLayout->addWidget(ui->othelloButton, 1, 0);
    buttonGridLayout->addWidget(ui->damesButton, 1, 1);
    buttonGridLayout->addWidget(ui->exitGame, 2, 0, 1, 2);

    buttonGridLayout->setAlignment(Qt::AlignCenter);
    buttonGridLayout->setSpacing(20);


    mainLayout->addLayout(buttonGridLayout);
    mainLayout->addStretch();

    mainLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    setLayout(mainLayout);

    connect(ui->exitGame, &QPushButton::clicked, this, &Accueil::on_exitGame_clicked);
}

Accueil::~Accueil()
{
    delete ui;
}

void Accueil::on_morpionButton_clicked()
{
    hide();
    emit selectionTypeJeu(TypesJeu::Morpion);
}

void Accueil::on_puissance4Button_clicked()
{
    hide();
    emit selectionTypeJeu(TypesJeu::Puissance4);
}

void Accueil::on_othelloButton_clicked()
{
    hide();
    emit selectionTypeJeu(TypesJeu::Othello);
}

void Accueil::on_damesButton_clicked()
{
    hide();
    emit selectionTypeJeu(TypesJeu::Dames);
}

void Accueil::on_exitGame_clicked()
{
    QApplication::quit();
}



