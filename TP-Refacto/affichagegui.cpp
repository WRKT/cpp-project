#include "affichagegui.h"
#include <QMessageBox>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QObject>

AffichageGUI::AffichageGUI(QWidget *parentWidget, QGridLayout *gridLayout, QLabel *labelMessage, QLabel *labelErreur) : parentWidget(parentWidget), gridLayout(gridLayout), labelMessage(labelMessage) {}

void AffichageGUI::AfficherGrille(const std::shared_ptr<AGrille>& grille)
{
    const QSize imageSize(50, 50);

    boutonsGrille.resize(grille->getNbLignes());

    for (int x = 0; x < grille->getNbLignes(); ++x)
    {
        boutonsGrille[x].resize(grille->getNbColonnes());
        for (int y = 0; y < grille->getNbColonnes(); ++y)
        {
            QPushButton *button = new QPushButton(parentWidget);

            Jeton jeton = grille->GetCellule(x, y);
            QString imagePath = getImage(jeton);
            QPixmap originalPixmap(imagePath);

            QPixmap scaledPixmap = originalPixmap.scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            QIcon icon(scaledPixmap);
            button->setIcon(icon);
            button->setIconSize(imageSize);

            if ((x + y) % 2 == 0) {
                button->setStyleSheet("QPushButton { background-color : #dcdcdc; border: 1px solid #a0a0a0; }");
            } else {
                button->setStyleSheet("QPushButton { background-color : #808080; border: 1px solid #a0a0a0; }");
            }

            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

            gridLayout->addWidget(button, x, y);
            boutonsGrille[x][y] = button;
            connect(button, &QPushButton::clicked, this, [this, x, y]() {
                emit celluleBoutonClick(x, y);
            });
        }
    }
}


void AffichageGUI::MettreAJourGrille(const std::shared_ptr<AGrille>& grille)
{
    const QSize imageSize(50, 50);

    for (int x = 0; x < grille->getNbLignes(); ++x)
    {
        for (int y = 0; y < grille->getNbColonnes(); ++y)
        {
            Jeton jeton = grille->GetCellule(x, y);
            QString imagePath = getImage(jeton);
            QPixmap originalPixmap(imagePath);

            QPixmap scaledPixmap = originalPixmap.scaled(imageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

            QIcon icon(scaledPixmap);
            boutonsGrille[x][y]->setIcon(icon);
            boutonsGrille[x][y]->setIconSize(imageSize);
        }
    }
}

void AffichageGUI::AfficherMessage(const std::string& message, const int duree) const {
    labelMessage->setText(QString::fromStdString(message));
}

void AffichageGUI::AfficherErreur(const std::string &erreur) const {
    QMessageBox::critical(parentWidget, "Erreur", QString::fromStdString("Saisie invalide. Veuillez réessayer. " + erreur));
}

void AffichageGUI::AfficherCoupsPossibles(const std::vector<Position>& coups, const std::string& message) const {

}

QString AffichageGUI::getImage(Jeton jeton)
{
    QString imagePath;
    switch (jeton)
    {
    case Jeton::X:
        imagePath = ":/Assets/PiecesNoir.png";
        break;
    case Jeton::O:
        imagePath = ":/Assets/PiecesBlanche.png";
        break;
    case Jeton::DameX:
        imagePath = ":/Assets/DamesNoir.png";
        break;
    case Jeton::DameO:
        imagePath = ":/Assets/DamesBlanche.png";
        break;
    default:
        imagePath = ":/Assets/CaseVide.png";
        break;
    }
    return imagePath;
}
