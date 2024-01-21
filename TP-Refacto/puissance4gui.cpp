#include "puissance4gui.h"
#include "ui_puissance4gui.h"
#include "affichagegui.h"
#include "inputgui.h"
#include "joueurfactory.h"
#include "jeufactory.h"


Puissance4GUI::Puissance4GUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Puissance4GUI)
{
    ui->setupUi(this);
    modeAffichage = std::make_shared<AffichageGUI>(this) ;
    input = new InputGUI(this);

    connect(ui->retourAccueil, &QPushButton::clicked, this, &Puissance4GUI::on_retourAccueil_clicked);
    std::shared_ptr<AffichageGUI> affichageGUI = std::dynamic_pointer_cast<AffichageGUI>(modeAffichage);

    if (affichageGUI) {
        connect(affichageGUI.get(), &AffichageGUI::celluleBoutonClick, input, &InputGUI::onCelluleClique);
    }
    connect(ui->JouerButton, &QPushButton::clicked, this, &Puissance4GUI::on_JouerButton_clicked);
}


Puissance4GUI::~Puissance4GUI()
{
    delete ui;
}

void Puissance4GUI::on_retourAccueil_clicked()
{
    hide();
    emit showAccueil();

}

void Puissance4GUI::ReinitialiserJeu()
{
    delete input;
    input = new InputGUI(this);
}

void Puissance4GUI::on_JouerButton_clicked(){

    joueur1 = JoueurFactory::CreerJoueurHumain("Test", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurHumain("Test", Jeton::O, *input);

    std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();
}
