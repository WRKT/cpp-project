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
    emit showMorpion();
}

void Accueil::on_puissance4Button_clicked()
{
    emit showPuissance4();
}

void Accueil::on_othelloButton_clicked()
{
    emit showOthello();
}

void Accueil::on_damesButton_clicked()
{
    emit showDames();
}
