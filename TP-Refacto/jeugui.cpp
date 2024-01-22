#include "jeugui.h"
#include "ui_jeugui.h"
#include "affichagegui.h"
#include "inputgui.h"
#include "joueurfactory.h"
#include "jeufactory.h"


JeuGUI::JeuGUI(QWidget *parent, TypesJeu typeDeJeu)
    : QWidget(parent)
    , ui(new Ui::JeuGUI)
    , typeDeJeu(typeDeJeu)
{
    ui->setupUi(this);
    modeAffichage = std::make_shared<AffichageGUI>(this) ;
    input = std::make_shared<InputGUI>(this);

    connect(ui->retourAccueil, &QPushButton::clicked, this, &JeuGUI::on_retourAccueil_clicked);

    std::shared_ptr<AffichageGUI> affichageGUI = std::dynamic_pointer_cast<AffichageGUI>(modeAffichage);
    std::shared_ptr<InputGUI> inputGUI = std::dynamic_pointer_cast<InputGUI>(input);

    if (affichageGUI && inputGUI) {
        connect(affichageGUI.get(), &AffichageGUI::celluleBoutonClick, inputGUI.get(), &InputGUI::onCelluleClique);
    }
    connect(ui->JouerButton, &QPushButton::clicked, this, &JeuGUI::on_JouerButton_clicked);

    ui->buttonLayout->setAlignment(Qt::AlignCenter);
    ui->JouerButton->setMinimumSize(80, 20);
    ui->retourAccueil->setMinimumSize(80, 20);
    ui->buttonLayout->setSpacing(10);
    ui->nomJeu->setAlignment(Qt::AlignHCenter);
}


JeuGUI::~JeuGUI()
{
    delete ui;
}

void JeuGUI::on_retourAccueil_clicked()
{
    hide();
    emit showAccueil();
}

void JeuGUI::on_JouerButton_clicked(){

    joueur1 = JoueurFactory::CreerJoueurHumain("Joueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurHumain("Joueur2", Jeton::O, *input);

    std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();
}
