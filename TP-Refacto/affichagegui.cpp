#include "affichagegui.h"
#include <QMessageBox>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QObject>

AffichageGUI::AffichageGUI(QWidget *parentWidget, QGridLayout *gridLayout, QLabel *labelMessage, QLabel *labelErreur) : parentWidget(parentWidget), gridLayout(gridLayout), labelMessage(labelMessage) {}

void AffichageGUI::AfficherGrille(const std::shared_ptr<AGrille>& grille)
{
    boutonsGrille.resize(grille->getNbLignes());

    gridLayout->setSpacing(0);

    for (int x = 0; x < grille->getNbLignes(); ++x)
    {
        boutonsGrille[x].resize(grille->getNbColonnes());
        for (int y = 0; y < grille->getNbColonnes(); ++y)
        {
            QPushButton *button = new QPushButton(parentWidget);
            button->setFixedSize(50, 50);

            Jeton jeton = grille->GetCellule(x, y);
            button->setText(QString(static_cast<char>(jeton)));
            QFont font = button->font();
            font.setPointSize(button->height() / 3);
            button->setFont(font);

            QString style = "QPushButton { background-color : #dcdcdc; border: 1px solid #a0a0a0; }";
            style += "QPushButton:hover { background-color : #f0f0f0; }";
            style += "QPushButton:pressed { background-color : #c0c0c0; }";
            style += "QLabel { background-color : #f0f0f0; border: 1px solid #a0a0a0; }";
            button->setStyleSheet(style);

            gridLayout->addWidget(button, x, y);
            boutonsGrille[x][y] = button;
            connect(button, &QPushButton::clicked, this, [this, x, y](){
                emit celluleBoutonClick(x, y);
            });
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
    labelMessage->setText(QString::fromStdString(message));
}

void AffichageGUI::AfficherErreur(const std::string &erreur) const
{
    QMessageBox::critical(parentWidget, "Erreur", QString::fromStdString("Saisie invalide. Veuillez réessayer. " + erreur));
}

void AffichageGUI::AfficherCoupsPossibles(const std::vector<Position>& coups, const std::string& message) const
{

}
