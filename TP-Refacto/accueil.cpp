#include "accueil.h"
#include "ui_accueil.h"

Accueil::Accueil(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Accueil)
{
    ui->setupUi(this);
}

Accueil::~Accueil()
{
    delete ui;
}


void Accueil::on_morpionButton_clicked()
{
    hide();
    emit nouveauJeu();
}

