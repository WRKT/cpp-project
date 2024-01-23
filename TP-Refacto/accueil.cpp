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
