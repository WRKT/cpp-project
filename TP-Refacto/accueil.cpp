#include "accueil.h"
#include "ui_accueil.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>


Accueil::Accueil(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Accueil)
{
    Setup();
    // ui->setupUi(this);

    // QVBoxLayout *mainLayout = new QVBoxLayout(this);
    // mainLayout->setContentsMargins(0, 0, 0, 0);

    // QVBoxLayout *welcomeLayout = new QVBoxLayout();
    // QLabel *welcomeLabel = new QLabel("Bienvenue dans notre interface", this);
    // welcomeLabel->setFont(QFont("Segoe UI", 14, QFont::Bold));
    // welcomeLabel->setAlignment(Qt::AlignHCenter);
    // welcomeLayout->addWidget(welcomeLabel);
    // welcomeLayout->setSpacing (50);

    // QLabel *menuLabel = new QLabel("Menu Principal", this);
    // menuLabel->setFont(QFont("Segoe UI", 12, QFont::Bold));
    // menuLabel->setAlignment(Qt::AlignHCenter);
    // mainLayout->addWidget(menuLabel);
    // mainLayout->setSpacing (100);

    // QLabel *choixLabel = new QLabel("Veuillez choisir votre jeu", this);
    // choixLabel->setFont(QFont("Segoe UI", 12, QFont::Bold));
    // choixLabel->setAlignment(Qt::AlignHCenter);
    // welcomeLayout->addWidget(choixLabel);
    // welcomeLayout->setSpacing (50);

    // mainLayout->addLayout(welcomeLayout);

    // QGridLayout *buttonGridLayout = new QGridLayout();

    // ui->morpionButton->setMinimumSize(150, 50);
    // ui->puissance4Button->setMinimumSize(150, 50);
    // ui->othelloButton->setMinimumSize(150, 50);
    // ui->damesButton->setMinimumSize(150, 50);
    // ui->exitGame->setMinimumSize(150, 50);

    // buttonGridLayout->addWidget(ui->morpionButton, 0, 0);
    // buttonGridLayout->addWidget(ui->puissance4Button, 0, 1);
    // buttonGridLayout->addWidget(ui->othelloButton, 1, 0);
    // buttonGridLayout->addWidget(ui->damesButton, 1, 1);
    // buttonGridLayout->addWidget(ui->exitGame, 2, 0, 1, 2);

    // buttonGridLayout->setAlignment(Qt::AlignCenter);
    // buttonGridLayout->setSpacing(20);


    // mainLayout->addLayout(buttonGridLayout);
    // mainLayout->addStretch();

    // mainLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    // setLayout(mainLayout);

    // connect(ui->exitGame, &QPushButton::clicked, this, &Accueil::on_exitGame_clicked);
}

void Accueil::Setup()
{
    ui->setupUi(this);
    SetupLayoutPrincipale();
    SetupLayoutBienvenue();
    SetupMenuLabels();
    SetupBoutons();
    SetupBoutonConnections();
}

void Accueil::SetupLayoutPrincipale()
{
    layoutPrincipale = new QVBoxLayout(this);
    layoutPrincipale->setContentsMargins(0, 0, 0, 0);
    layoutPrincipale->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    setLayout(layoutPrincipale);
}

void Accueil::SetupLayoutBienvenue()
{
    QVBoxLayout *layoutBienvenue = new QVBoxLayout();
    layoutBienvenue->setSpacing(50);

    QLabel *labelBienvenue = CreationDuLabelEnGras("Bienvenue dans notre interface", 14);
    labelBienvenue->setAlignment(Qt::AlignHCenter);

    QLabel *choixLabel = CreationDuLabelEnGras("Veuillez choisir votre jeu", 12);
    choixLabel->setAlignment(Qt::AlignHCenter);

    layoutBienvenue->addWidget(labelBienvenue);
    layoutBienvenue->addWidget(choixLabel);

    ui->morpionBouton->setMinimumSize(150, 50);
    ui->puissance4Bouton->setMinimumSize(150, 50);
    ui->othelloBouton->setMinimumSize(150, 50);
    ui->damesBouton->setMinimumSize(150, 50);
    ui->exitGame->setMinimumSize(150, 50);

    layoutPrincipale->addLayout(layoutBienvenue);
}

void Accueil::SetupMenuLabels()
{
    QLabel *menuLabel = CreationDuLabelEnGras("Menu Principal", 12);
    menuLabel->setAlignment(Qt::AlignHCenter);
    layoutPrincipale->addWidget(menuLabel);
    layoutPrincipale->setSpacing(100);
}

void Accueil::SetupBoutons()
{
    QGridLayout *boutonLayout = new QGridLayout();
    boutonLayout->setAlignment(Qt::AlignCenter);
    boutonLayout->setSpacing(20);

    boutonLayout->addWidget(ui->morpionBouton, 0, 0);
    boutonLayout->addWidget(ui->puissance4Bouton, 0, 1);
    boutonLayout->addWidget(ui->othelloBouton, 1, 0);
    boutonLayout->addWidget(ui->damesBouton, 1, 1);
    boutonLayout->addWidget(ui->exitGame, 2, 0, 1, 2);

    layoutPrincipale->addLayout(boutonLayout);
    layoutPrincipale->addStretch();
}

void Accueil::SetupBoutonConnections()
{
    connect(ui->exitGame, &QPushButton::clicked, this, &Accueil::on_exitGame_clicked);
}

QLabel* Accueil::CreationDuLabelEnGras(const QString &text, int fontSize)
{
    QLabel *label = new QLabel(text, this);
    label->setFont(QFont("Segoe UI", fontSize, QFont::Bold));
    return label;
}

Accueil::~Accueil()
{
    delete ui;
}

void Accueil::on_morpionBouton_clicked()
{
    hide();
    emit selectionTypeJeu(TypesJeu::Morpion);
}

void Accueil::on_puissance4Bouton_clicked()
{
    hide();
    emit selectionTypeJeu(TypesJeu::Puissance4);
}

void Accueil::on_othelloBouton_clicked()
{
    hide();
    emit selectionTypeJeu(TypesJeu::Othello);
}

void Accueil::on_damesBouton_clicked()
{
    hide();
    emit selectionTypeJeu(TypesJeu::Dames);
}

void Accueil::on_exitGame_clicked()
{
    QApplication::quit();
}
