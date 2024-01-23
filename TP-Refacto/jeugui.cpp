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

    SetupGridSpacers();
    SetupAffichageAndInput();
    SetupButtonLayout();
    SetupButtonMinimumSize();
    SetupButtonConnections();

    ui->labelRejouer->hide();
    ui->rejouerButton->hide();
    ui->labelMessage->setAlignment(Qt::AlignHCenter);
}

void JeuGUI::SetupGridSpacers()
{
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(1);

    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 0, 0);
    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 0, 2);
    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 2, 0);
    ui->gridLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding), 2, 2);
}

void JeuGUI::SetupAffichageAndInput()
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

void JeuGUI::SetupButtonLayout()
{
    ui->buttonLayout->setAlignment(Qt::AlignCenter);
    ui->buttonLayout->setSpacing(10);
}

void JeuGUI::SetupButtonMinimumSize()
{
    ui->JvsJButton->setMinimumSize(80, 20);
    ui->JvsOButton->setMinimumSize(80, 20);
    ui->OvsOButton->setMinimumSize(80, 20);
    ui->rejouerButton->setMinimumSize(80, 20);
}

void JeuGUI::SetupButtonConnections()
{
    connect(ui->rejouerButton, &QPushButton::clicked, this, &JeuGUI::on_rejouerButton_clicked);
    connect(ui->retourMenuButton, &QPushButton::clicked, this, &JeuGUI::on_retourMenuButton_clicked);
}

JeuGUI::~JeuGUI()
{
    delete ui;
}

void JeuGUI::on_JvsJButton_clicked()
{
    VisibiliteBoutonsChoixMode();

    joueur1 = JoueurFactory::CreerJoueurHumain("Joueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurHumain("Joueur2", Jeton::O, *input);
    jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();

    HideBoutonsChoixMode();

    ShowBoutonsRejouer();
}
void JeuGUI::on_JvsOButton_clicked()
{
    VisibiliteBoutonsChoixMode();

    joueur1 = JoueurFactory::CreerJoueurHumain("Joueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
    jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();

    HideBoutonsChoixMode();

    ShowBoutonsRejouer();
}

void JeuGUI::on_saveButton_clicked()
{
    if (jeu != nullptr) {
        jeu->Sauvegarder();
    } else {
        QMessageBox::warning(this, "Avertissement", "Aucun jeu n'est actuellement en cours.");
    }
}

void JeuGUI::on_OvsOButton_clicked()
{
    VisibiliteBoutonsChoixMode();

    joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
    joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);

    jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();

    HideBoutonsChoixMode();

    ShowBoutonsRejouer();
}

void JeuGUI::on_rejouerButton_clicked()
{
    HideBoutonsRejouer();

    ShowBoutonsChoixMode();
}

void JeuGUI::on_chargerButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Ouvrir fichier de sauvegarde"),
                                                    "",
                                                    tr("Fichiers JSON (*.json)"));
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
        else {
            QJsonArray joueursArray = jsonObj["Joueurs"].toArray();
            QString nomJoueur1 = joueursArray[0].toObject()["NomJoueur1"].toString();
            QString nomJoueur2 = joueursArray[1].toObject()["NomJoueur2"].toString();

            if (nomJoueur1 == "Ordinateur") {
                joueur1 = JoueurFactory::CreerJoueurOrdinateur(Jeton::X);
            } else {
                joueur1 = JoueurFactory::CreerJoueurHumain(nomJoueur1.toStdString(), Jeton::X, *input);
            }

            if (nomJoueur2 == "Ordinateur") {
                joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);
            } else {
                joueur2 = JoueurFactory::CreerJoueurHumain(nomJoueur2.toStdString(), Jeton::O, *input);
            }

            jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
            if (jeu != nullptr) {
                jeu->Charger(jsonObj["Grille"].toArray(), jsonObj["JoueurCourant"].toString());
                jeu->Jouer();
            }

        }
    }
}

void JeuGUI::on_retourMenuButton_clicked()
{
    hide();
    emit showAccueil();
}

void JeuGUI::VisibiliteBoutonsChoixMode()
{
    ui->choixMode->setVisible(false);
    ui->JvsJButton->setVisible(false);
    ui->JvsOButton->setVisible(false);
    ui->OvsOButton->setVisible(false);
}

void JeuGUI::HideBoutonsChoixMode()
{
    ui->choixMode->hide();
    ui->JvsJButton->hide();
    ui->JvsOButton->hide();
    ui->OvsOButton->hide();
}

void JeuGUI::ShowBoutonsChoixMode()
{
    ui->choixMode->show();
    ui->JvsJButton->show();
    ui->JvsOButton->show();
    ui->OvsOButton->show();
}

void JeuGUI::ShowBoutonsRejouer()
{
    ui->labelRejouer->show();
    ui->rejouerButton->show();
}

void JeuGUI::HideBoutonsRejouer()
{
    ui->labelRejouer->hide();
    ui->rejouerButton->hide();
}
