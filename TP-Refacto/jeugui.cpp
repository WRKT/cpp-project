#include "jeugui.h"
#include "ui_jeugui.h"
#include "affichagegui.h"
#include "inputgui.h"
#include "joueurfactory.h"
#include "jeufactory.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

JeuGUI::JeuGUI(QWidget *parent, TypesJeu typeDeJeu)
    : QWidget(parent), ui(new Ui::JeuGUI), typeDeJeu(typeDeJeu)
{
    Setup();
}

void JeuGUI::Setup()
{
    ui->setupUi(this);
    ui->gridLayout->setSpacing(0);
    ui->gridLayout->setAlignment(Qt::AlignCenter);

    SetupEspace();
    SetupAffichageEtInput();
    SetupBoutonLayout();
    SetupBoutonTailleMinimale();
    SetupBoutonConnections();

    ui->labelRejouer->hide();
    ui->rejouerBouton->hide();
    ui->labelMessage->setAlignment(Qt::AlignHCenter);
}

void JeuGUI::SetupEspace()
{
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(1);

    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 0, 0);
    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 0, 2);
    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 2, 0);
    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 2, 2);
}

void JeuGUI::SetupAffichageEtInput()
{
    modeAffichage = std::make_shared<AffichageGUI>(this, ui->gridLayout, ui->labelMessage, ui->labelErreur);
    input = std::make_shared<InputGUI>(this);

    auto affichageGUI = std::dynamic_pointer_cast<AffichageGUI>(modeAffichage);
    auto inputGUI = std::dynamic_pointer_cast<InputGUI>(input);

    if (affichageGUI && inputGUI)
    {
        connect(affichageGUI.get(), &AffichageGUI::celluleBoutonClick, inputGUI.get(), &InputGUI::onCelluleClique);
    }
}

void JeuGUI::SetupBoutonLayout()
{
    ui->boutonLayout->setAlignment(Qt::AlignCenter);
    ui->boutonLayout->setSpacing(10);
}

void JeuGUI::SetupBoutonTailleMinimale()
{
    ui->JvsJBouton->setMinimumSize(80, 20);
    ui->JvsOBouton->setMinimumSize(80, 20);
    ui->OvsOBouton->setMinimumSize(80, 20);
    ui->rejouerBouton->setMinimumSize(80, 20);
}

void JeuGUI::SetupBoutonConnections()
{
    connect(ui->rejouerBouton, &QPushButton::clicked, this, &JeuGUI::on_rejouerBouton_clicked);
    connect(ui->retourMenuBouton, &QPushButton::clicked, this, &JeuGUI::on_retourMenuBouton_clicked);
}

JeuGUI::~JeuGUI()
{
    delete ui;
}

void JeuGUI::Reinitialiser() {
    if (jeu != nullptr) {
        jeu.reset();
        joueur1.reset();
        joueur2.reset();

        CacherBoutonsRejouer();
        AfficherBoutonsChoixMode();
        ui->labelMessage->clear();
        ui->labelErreur->clear();
    }
}

void JeuGUI::on_JvsJBouton_clicked()
{
    VisibiliteBoutonsChoixMode();

    joueur1 = JoueurFactory::CreerJoueurHumain("Joueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurHumain("Joueur2", Jeton::O, *input);
    jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();

    CacherBoutonsChoixMode();

    AfficherBoutonsRejouer();
}
void JeuGUI::on_JvsOBouton_clicked()
{
    VisibiliteBoutonsChoixMode();

    joueur1 = JoueurFactory::CreerJoueurHumain("Joueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
    jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();

    CacherBoutonsChoixMode();

    AfficherBoutonsRejouer();
}

void JeuGUI::on_sauvegardeBouton_clicked()
{
    if (jeu != nullptr)
    {
        jeu->Sauvegarder();
    }
    else
    {
        QMessageBox::warning(this, "Avertissement", "Aucun jeu n'est actuellement en cours.");
    }
}

void JeuGUI::on_OvsOBouton_clicked()
{
    VisibiliteBoutonsChoixMode();

    joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
    joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);

    jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();

    CacherBoutonsChoixMode();

    AfficherBoutonsRejouer();
}

void JeuGUI::on_rejouerBouton_clicked()
{
    CacherBoutonsRejouer();

    AfficherBoutonsChoixMode();
}

void JeuGUI::on_chargerBouton_clicked()
{
    jeu.reset();
    CacherBoutonsRejouer();

    if (jeu != nullptr)
    {
        QMessageBox::warning(this, "Avertissement", "Un jeu est actuellement en cours. Veuillez le terminer avant de charger une partie.");
        Reinitialiser();
    }

    QString fileName = QFileDialog::getOpenFileName(this,tr("Ouvrir fichier de sauvegarde"),"",tr("Fichiers JSON (*.json)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, "Erreur", "Impossible d'ouvrir le fichier");
            return;
        }

        QByteArray fileData = file.readAll();
        file.close();

        QJsonDocument doc = QJsonDocument::fromJson(fileData);
        QJsonObject jsonObj = doc.object();

        std::map<TypesJeu, std::string> nomsDesJeux = {
            {TypesJeu::Morpion, "Morpion"},
            {TypesJeu::Puissance4, "Puissance4"},
            {TypesJeu::Othello, "Othello"},
            {TypesJeu::Dames, "Dames"}};

        if (jsonObj["TypesJeu"].toString().toStdString() != nomsDesJeux[typeDeJeu])
        {
            QMessageBox::warning(this, "Erreur", "Le fichier de sauvegarde ne correspond pas au type de jeu choisi.");
            return;
        }
        else
        {
            QJsonArray joueursArray = jsonObj["Joueurs"].toArray();
            QString nomJoueur1 = joueursArray[0].toObject()["NomJoueur1"].toString();
            QString nomJoueur2 = joueursArray[1].toObject()["NomJoueur2"].toString();

            if (nomJoueur1 == "Ordinateur")
            {
                joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
            }
            else
            {
                joueur1 = JoueurFactory::CreerJoueurHumain(nomJoueur1.toStdString(), Jeton::X, *input);
            }

            if (nomJoueur2 == "Ordinateur")
            {
                joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
            }
            else
            {
                joueur2 = JoueurFactory::CreerJoueurHumain(nomJoueur2.toStdString(), Jeton::O, *input);
            }

            jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
            if (jeu != nullptr)
            {
                jeu->Charger(jsonObj["Grille"].toArray(), jsonObj["JoueurCourant"].toString());
                jeu->Jouer();
                jeu.reset();
                joueur1.reset();
                joueur2.reset();
                ui->labelErreur->clear();
            }
        }
    }
}

void JeuGUI::on_retourMenuBouton_clicked()
{
    Reinitialiser();
    hide(); 
    emit showAccueil();
}

void JeuGUI::VisibiliteBoutonsChoixMode()
{
    ui->choixMode->setVisible(false);
    ui->JvsJBouton->setVisible(false);
    ui->JvsOBouton->setVisible(false);
    ui->OvsOBouton->setVisible(false);
}

void JeuGUI::CacherBoutonsChoixMode()
{
    ui->choixMode->hide();
    ui->JvsJBouton->hide();
    ui->JvsOBouton->hide();
    ui->OvsOBouton->hide();
}

void JeuGUI::AfficherBoutonsChoixMode()
{
    ui->choixMode->show();
    ui->JvsJBouton->show();
    ui->JvsOBouton->show();
    ui->OvsOBouton->show();
}

void JeuGUI::AfficherBoutonsRejouer()
{
    ui->labelRejouer->show();
    ui->rejouerBouton->show();
}

void JeuGUI::CacherBoutonsRejouer()
{
    ui->labelRejouer->hide();
    ui->rejouerBouton->hide();
}
