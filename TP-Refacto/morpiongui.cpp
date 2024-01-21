#include "morpiongui.h"
#include "ui_morpiongui.h"
#include "affichagegui.h"
#include "inputgui.h"
#include "joueurfactory.h"
#include "jeufactory.h"


MorpionGUI::MorpionGUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MorpionGUI)
{
    ui->setupUi(this);
    modeAffichage = std::make_shared<AffichageGUI>(this) ;
    input = new InputGUI(this);

    connect(ui->retourAccueil, &QPushButton::clicked, this, &MorpionGUI::on_retourAccueil_clicked);
    std::shared_ptr<AffichageGUI> affichageGUI = std::dynamic_pointer_cast<AffichageGUI>(modeAffichage);

    if (affichageGUI) {
        connect(affichageGUI.get(), &AffichageGUI::celluleBoutonClick, input, &InputGUI::onCelluleClique);
    }
    connect(ui->JouerButton, &QPushButton::clicked, this, &MorpionGUI::on_JouerButton_clicked);
}


MorpionGUI::~MorpionGUI()
{
    delete ui;
}

void MorpionGUI::on_retourAccueil_clicked()
{
    hide();
    emit showAccueil();

}

void MorpionGUI::ReinitialiserJeu()
{
    delete input;
    input = new InputGUI(this);
}

void MorpionGUI::on_JouerButton_clicked(){

    joueur1 = JoueurFactory::CreerJoueurHumain("prenomJoueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurHumain("prenomJoueur2", Jeton::O, *input);

    std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();
}
