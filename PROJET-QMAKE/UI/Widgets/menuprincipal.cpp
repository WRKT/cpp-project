#include "menuprincipal.h"
#include "ui_menuprincipal.h"

MenuPrincipal::MenuPrincipal(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MenuPrincipal)
{
    setFixedSize(1280,720);
    ui->setupUi(this);
    this->setParent(parent);
    boutonQuitter = new QPushButton("Quitter", this);
    boutonQuitter->setFont(QFont("Roboto", 24));

    int abscisseDepart = 250 - boutonQuitter->width()/2;
    boutonQuitter->move(abscisseDepart, 80);
    QObject::connect(boutonQuitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    boutonMorpion = new QPushButton("Morpion", this);
    boutonMorpion->setFont(QFont("Roboto", 24));
    abscisseDepart = 250 - (boutonMorpion->width()/2);
    boutonMorpion->move(abscisseDepart, 30);

    QObject::connect(boutonMorpion, SIGNAL(clicked()), this->parent(), SLOT(LancerJeu()));
}

void MenuPrincipal::LancerJeu()
{
    this->WidgetActif = TableauMorpion;
    TableauMorpion->show();
}

void MenuPrincipal::RetourMenu()
{


}
MenuPrincipal::~MenuPrincipal()
{
    delete ui;
}
