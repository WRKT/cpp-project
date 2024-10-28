#include "affichagegui.h"
#include <QMessageBox>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QObject>

AffichageGUI::AffichageGUI(QWidget *parentWidget, QGridLayout *gridLayout, QLabel *labelMessage, QLabel *labelErreur)
    : parentWidget(parentWidget), gridLayout(gridLayout), labelMessage(labelMessage) {}

void AffichageGUI::configurerBouton(QPushButton *bouton, const QString &cheminImage, const QSize &tailleImage, bool estPair)
{
    QPixmap pixmapOriginal(cheminImage);
    QPixmap pixmapRedimensionne = pixmapOriginal.scaled(tailleImage, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QIcon icone(pixmapRedimensionne);
    bouton->setIcon(icone);
    bouton->setIconSize(tailleImage);

    QString couleurFond = estPair ? "#dcdcdc" : "#808080";

    bouton->setStyleSheet("QPushButton { background-color: " + couleurFond + "; border: 1px solid #a0a0a0; }"
                          "QPushButton:hover { background-color: #d3d3d3; border: 1px solid #a0a0a0; }"
                          "QPushButton:pressed { background-color: #c0c0c0; border: 1px solid #a0a0a0; }");

    bouton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void AffichageGUI::AfficherGrille(const std::shared_ptr<AGrille> &grille)
{
    const QSize tailleImage(50, 50);

    boutonsGrille.resize(grille->getNbLignes());

    for (int x = 0; x < grille->getNbLignes(); ++x)
    {
        boutonsGrille[x].resize(grille->getNbColonnes());
        for (int y = 0; y < grille->getNbColonnes(); ++y)
        {
            QPushButton *bouton = new QPushButton(parentWidget);
            Jeton jeton = grille->GetCellule(x, y);
            QString cheminImage = getImage(jeton);
            configurerBouton(bouton, cheminImage, tailleImage, (x + y) % 2 == 0);

            gridLayout->addWidget(bouton, x, y);
            boutonsGrille[x][y] = bouton;
            connect(bouton, &QPushButton::clicked, this, [this, x, y]() {
                emit celluleBoutonClick(x, y);
            });
        }
    }
}

void AffichageGUI::MettreAJourGrille(const std::shared_ptr<AGrille> &grille)
{
    const QSize tailleImage(50, 50);

    for (int x = 0; x < grille->getNbLignes(); ++x)
    {
        for (int y = 0; y < grille->getNbColonnes(); ++y)
        {
            Jeton jeton = grille->GetCellule(x, y);
            QString cheminImage = getImage(jeton);
            configurerBouton(boutonsGrille[x][y], cheminImage, tailleImage, (x + y) % 2 == 0);
        }
    }
}

void AffichageGUI::AfficherMessage(const std::string &message, const int duree) const
{
    labelMessage->setText(QString::fromStdString(message));
}

void AffichageGUI::AfficherErreur(const std::string &erreur) const
{
    QMessageBox::critical(parentWidget, "Erreur", QString::fromStdString("Saisie invalide. Veuillez réessayer. " + erreur));
}

void AffichageGUI::AfficherCoupsPossibles(const std::vector<Position> &coups, const std::string &message) const
{
}

QString AffichageGUI::getImage(Jeton jeton)
{
    QString cheminImage;
    switch (jeton)
    {
    case Jeton::X:
        cheminImage = ":/Assets/PiecesNoir.png";
        break;
    case Jeton::O:
        cheminImage = ":/Assets/PiecesBlanche.png";
        break;
    case Jeton::DameX:
        cheminImage = ":/Assets/DamesNoir.png";
        break;
    case Jeton::DameO:
        cheminImage = ":/Assets/DamesBlanche.png";
        break;
    default:
        cheminImage = ":/Assets/CaseVide.png";
        break;
    }
    return cheminImage;
}
