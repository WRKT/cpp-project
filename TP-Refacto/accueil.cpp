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

    QLabel *menuLabel = new QLabel("Menu Principal", this);
    menuLabel->setAlignment(Qt::AlignHCenter);
    mainLayout->addWidget(menuLabel);
    mainLayout->setSpacing (100);


    QVBoxLayout *buttonLayout = new QVBoxLayout();

    ui->morpionButton->setMinimumSize(150, 50);
    ui->puissance4Button->setMinimumSize(150, 50);
    ui->othelloButton->setMinimumSize(150, 50);
    ui->damesButton->setMinimumSize(150, 50);

    buttonLayout->addWidget(ui->morpionButton);
    buttonLayout->addWidget(ui->puissance4Button);
    buttonLayout->addWidget(ui->othelloButton);
    buttonLayout->addWidget(ui->damesButton);

    buttonLayout->setAlignment(Qt::AlignCenter);
    buttonLayout->setSpacing(20);


    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();

    mainLayout->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    setLayout(mainLayout);

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
