#include "affichageconsole.h"
#include <iostream>

void AffichageConsole::AfficherGrille(const std::shared_ptr<AGrille> &grille)
{
    const int nbColonnes = grille->getNbColonnes();
    const int nbLignes = grille->getNbLignes();

    std::cout << std::endl;
    std::cout << "    ";
    for (int j = 0; j < nbColonnes; j++)
    {
        std::cout << " " << (j + 1) << "  ";
    }
    std::cout << std::endl;

    std::cout << "   +";
    for (int j = 0; j < nbColonnes; j++)
    {
        std::cout << "---+";
    }
    std::cout << "\n";

    for (int i = 0; i < nbLignes; i++)
    {
        std::cout << (i < 9 ? " " : "") << (i + 1) << " | ";

        for(int j = 0; j < nbColonnes; j++)
        {
            std::cout << static_cast<char>(grille->GetCellule(i, j)) << " | ";
        }
        std::cout << std::endl;

        std::cout << "   +";
        for(int j = 0; j < nbColonnes; j++)
        {
            std::cout << "---+";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void AffichageConsole::AfficherMessage(const std::string& message, const int nbSautLigne) const
{
    std::cout << message;
    for(int i = 0; i < nbSautLigne; i++)
        std::cout << std::endl;
}

void AffichageConsole::AfficherErreur(const std::string& message) const
{
    std::cerr << "Saisie invalide. Veuillez réessayez. " << message << std::endl;
    std::cout << std::endl;

}

void AffichageConsole::AfficherCoupsPossibles(const std::vector<Position> &coupsPossibles, const std::string& message) const
{
    std::cout << message;
    for (auto &coup : coupsPossibles)
    {
        std::cout << "(" << coup.x + 1 << ", " << coup.y + 1 << ") ";
    }
    std::cout << std::endl;
}

void AffichageConsole::MettreAJourGrille(const std::shared_ptr<AGrille> &grille)
{
    AfficherGrille(grille);
}

