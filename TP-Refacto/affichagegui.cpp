#include "affichagegui.h"
#include <QMessageBox>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QObject>

AffichageGUI::AffichageGUI(QWidget *parentWidget) : parentWidget(parentWidget) {
    gridLayout = new QGridLayout(parentWidget);
    gridLayout->setAlignment(Qt::AlignCenter);

    parentWidget->setLayout(gridLayout);
}

void AffichageGUI::AfficherGrille(const std::shared_ptr<AGrille>& grille)
{
    boutonsGrille.resize(grille->getNbLignes());

    for (int x = 0; x < grille->getNbLignes(); ++x)
    {
        boutonsGrille[x].resize(grille->getNbColonnes());
        for (int y = 0; y < grille->getNbColonnes(); ++y)
        {
            QPushButton *button = new QPushButton(parentWidget);
            button->setFixedSize(50, 50);

            Jeton jeton = grille->GetCellule(x, y);
            button->setText(QString(static_cast<char>(jeton)));

            gridLayout->addWidget(button, x, y);
            boutonsGrille[x][y] = button;
            QAction::connect(button, &QPushButton::clicked, [this, x, y](){
                emit celluleBoutonClick(x, y); });
        }
    }
}

void AffichageGUI::MettreAJourGrille(const std::shared_ptr<AGrille>& grille)
{
    for (int x = 0; x < grille->getNbLignes(); ++x)
    {
        for (int y = 0; y < grille->getNbColonnes(); ++y)
        {
            Jeton jeton = grille->GetCellule(x, y);
            boutonsGrille[x][y]->setText(QString(static_cast<char>(jeton)));
        }
    }
}

void AffichageGUI::AfficherMessage(const std::string& message, const int duree) const {
    QMessageBox::information(parentWidget, "Message", QString::fromStdString(message));
}

void AffichageGUI::AfficherErreur(const std::string &erreur) const
{
    QMessageBox::critical(parentWidget, "Erreur", QString::fromStdString("Saisie invalide. Veuillez réessayer. " + erreur));
}

void AffichageGUI::AfficherCoupsPossibles(const std::vector<Position>& coups, const std::string& message) const
{

}
