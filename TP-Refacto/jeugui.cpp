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
    , typeDeJeuInitial(typeDeJeu)
{
    ui->setupUi(this);;
    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(0);
    gridLayout->setAlignment(Qt::AlignCenter);

    modeAffichage = std::make_shared<AffichageGUI>(this, gridLayout);
    input = std::make_shared<InputGUI>(this);

    std::shared_ptr<AffichageGUI> affichageGUI = std::dynamic_pointer_cast<AffichageGUI>(modeAffichage);
    std::shared_ptr<InputGUI> inputGUI = std::dynamic_pointer_cast<InputGUI>(input);

    if (affichageGUI && inputGUI) {
        connect(affichageGUI.get(), &AffichageGUI::celluleBoutonClick, inputGUI.get(), &InputGUI::onCelluleClique);
    }
    std::shared_ptr<QPushButton> JvsJButton = std::make_shared<QPushButton>("Joueur vs Joueur");
    connect(JvsJButton.get(), &QPushButton::clicked, this, &JeuGUI::on_JvsJButton_clicked);

    std::shared_ptr<QPushButton> JvsOButton = std::make_shared<QPushButton>("Joueur vs Joueur");
    connect(JvsOButton.get(), &QPushButton::clicked, this, &JeuGUI::on_JvsOButton_clicked);

    std::shared_ptr<QPushButton> OvsOButton = std::make_shared<QPushButton>("Joueur vs Joueur");
    connect(OvsOButton.get(), &QPushButton::clicked, this, &JeuGUI::on_OvsOButton_clicked);

    ui->buttonLayout->setAlignment(Qt::AlignCenter);
    ui->JvsJButton->setMinimumSize(80, 20);
    ui->JvsOButton->setMinimumSize(80, 20);
    ui->OvsOButton->setMinimumSize(80, 20);
    ui->buttonLayout->setSpacing(10);
    ui->nomJeu->setAlignment(Qt::AlignHCenter);

    connect(ui->rejouerButton, &QPushButton::clicked, this, &JeuGUI::on_rejouerButton_clicked);
    connect(ui->retourMenuButton, &QPushButton::clicked, this, &JeuGUI::on_retourMenuButton_clicked);

    ui->buttonLayout->addWidget(JvsJButton.get());
    ui->buttonLayout->addWidget(JvsOButton.get());
    ui->buttonLayout->addWidget(OvsOButton.get());

    ui->labelRejouer->hide();
    ui->rejouerButton->hide();
    ui->retourMenuButton->hide();
}


JeuGUI::~JeuGUI()
{
    delete ui;
}

void JeuGUI::on_JvsJButton_clicked(){

    joueur1 = JoueurFactory::CreerJoueurHumain("Joueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurHumain("Joueur2", Jeton::O, *input);
    std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();

    ui->choixMode->hide();
    ui->JvsJButton->hide();
    ui->JvsOButton->hide();
    ui->OvsOButton->hide();

    ui->labelRejouer->show();
    ui->rejouerButton->show();
    ui->retourMenuButton->show();
}
void JeuGUI::on_JvsOButton_clicked(){

    joueur1 = JoueurFactory::CreerJoueurHumain("prenomJoueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
    std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();

    ui->choixMode->hide();
    ui->JvsJButton->hide();
    ui->JvsOButton->hide();
    ui->OvsOButton->hide();

    ui->labelRejouer->show();
    ui->rejouerButton->show();
    ui->retourMenuButton->show();
}
void JeuGUI::on_OvsOButton_clicked(){

    joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
    joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);

    std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();

    ui->choixMode->hide();
    ui->JvsJButton->hide();
    ui->JvsOButton->hide();
    ui->OvsOButton->hide();

    ui->labelRejouer->show();
    ui->rejouerButton->show();
    ui->retourMenuButton->show();
}

void JeuGUI::on_rejouerButton_clicked()
{
    ui->rejouerButton->hide();
    ui->retourMenuButton->hide();
    ui->labelRejouer->hide();

    ui->choixMode->show();
    ui->JvsJButton->show();
    ui->JvsOButton->show();
    ui->OvsOButton->show();
}

void JeuGUI::on_retourMenuButton_clicked()
{
    hide();
    emit showAccueil();
}
