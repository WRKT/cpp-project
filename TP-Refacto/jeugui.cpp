#include "jeugui.h"
#include "ui_jeugui.h"
#include "affichagegui.h"
#include "inputgui.h"
#include "joueurfactory.h"
#include "jeufactory.h"
#include <QMessageBox>

JeuGUI::JeuGUI(QWidget *parent, TypesJeu typeDeJeu)
    : QWidget(parent)
    , ui(new Ui::JeuGUI)
    , typeDeJeu(typeDeJeu)
    , typeDeJeuInitial(typeDeJeu)
{
    ui->setupUi(this);;
    ui->gridLayout->setSpacing(0);
    ui->gridLayout->setAlignment(Qt::AlignCenter);

    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(1);
    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 0, 0);
    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 0, 2);
    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 2, 0);
    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 2, 2);

    modeAffichage = std::make_shared<AffichageGUI>(this, ui->gridLayout, ui->labelMessage, ui->labelErreur);
    input = std::make_shared<InputGUI>(this);

    std::shared_ptr<AffichageGUI> affichageGUI = std::dynamic_pointer_cast<AffichageGUI>(modeAffichage);
    std::shared_ptr<InputGUI> inputGUI = std::dynamic_pointer_cast<InputGUI>(input);

    if (affichageGUI && inputGUI) {
        connect(affichageGUI.get(), &AffichageGUI::celluleBoutonClick, inputGUI.get(), &InputGUI::onCelluleClique);
    }

    ui->buttonLayout->setAlignment(Qt::AlignCenter);
    ui->JvsJButton->setMinimumSize(80, 20);
    ui->JvsOButton->setMinimumSize(80, 20);
    ui->OvsOButton->setMinimumSize(80, 20);
    ui->rejouerButton->setMinimumSize(80,20);
    ui->buttonLayout->setSpacing(10);

    connect(ui->rejouerButton, &QPushButton::clicked, this, &JeuGUI::on_rejouerButton_clicked);
    connect(ui->retourMenuButton, &QPushButton::clicked, this, &JeuGUI::on_retourMenuButton_clicked);

    ui->labelRejouer->hide();
    ui->rejouerButton->hide();

    ui->labelMessage->setAlignment(Qt::AlignHCenter);
}


JeuGUI::~JeuGUI()
{
    delete ui;
}

void JeuGUI::on_JvsJButton_clicked(){

    joueur1 = JoueurFactory::CreerJoueurHumain("Joueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurHumain("Joueur2", Jeton::O, *input);
    jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
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
    std::shared_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();

    ui->choixMode->hide();
    ui->JvsJButton->hide();
    ui->JvsOButton->hide();
    ui->OvsOButton->hide();

    ui->labelRejouer->show();
    ui->rejouerButton->show();
    ui->retourMenuButton->show();
}

void JeuGUI::on_saveButton_clicked() {
    if (jeu == nullptr) {
        // Affiche une boîte de dialogue indiquant que le jeu n'est pas choisi
        QMessageBox::warning(this, "Avertissement", "Aucun jeu n'est choisi pour la sauvegarde.");
    } else {
        // Lance la sauvegarde du jeu
        jeu->Sauvegarder();
    }
}

void JeuGUI::on_OvsOButton_clicked(){

    joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
    joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);

    jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
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


