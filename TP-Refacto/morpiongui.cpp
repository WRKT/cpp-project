#include "morpiongui.h"
#include "ui_morpiongui.h"
#include "affichagegui.h"
#include "inputgui.h"
#include "joueurfactory.h"
#include "jeufactory.h"


MorpionGUI::MorpionGUI(QWidget *parent, TypesJeu typeDeJeu)
    : QWidget(parent)
    , ui(new Ui::MorpionGUI)
    , typeDeJeu(typeDeJeu)
{
    ui->setupUi(this);
    modeAffichage = std::make_shared<AffichageGUI>(this) ;
    input = std::make_shared<InputGUI>(this);

    connect(ui->retourAccueil, &QPushButton::clicked, this, &MorpionGUI::on_retourAccueil_clicked);

    std::shared_ptr<AffichageGUI> affichageGUI = std::dynamic_pointer_cast<AffichageGUI>(modeAffichage);
    std::shared_ptr<InputGUI> inputGUI = std::dynamic_pointer_cast<InputGUI>(input);

    if (affichageGUI && inputGUI) {
        connect(affichageGUI.get(), &AffichageGUI::celluleBoutonClick, inputGUI.get(), &InputGUI::onCelluleClique);
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

void MorpionGUI::on_JouerButton_clicked(){

    joueur1 = JoueurFactory::CreerJoueurHumain("prenomJoueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurHumain("prenomJoueur2", Jeton::O, *input);

    std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();
}
