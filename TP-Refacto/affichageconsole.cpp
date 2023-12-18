#include "affichageconsole.h"
#include <iostream>

void AffichageConsole::AfficherGrille(const std::shared_ptr<AGrille> grille) const
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


void AffichageConsole::AfficherMessage(const std::string message, const int nbSautLigne) const
{
    std::cout << message;
    for(int i = 0; i < nbSautLigne; i++)
        std::cout << std::endl;
}

void AffichageConsole::AfficherErreur(const std::string message) const
{
    std::cerr << "Saisie invalide. Veuillez réessayez. " << message;
}

void AffichageConsole::AfficherCoupsPossibles(std::vector<std::pair<int, int>> coupsPossibles) const
{
    std::cout << "Coups possibles : ";
    for (auto &coup : coupsPossibles)
    {
        std::cout << "(" << coup.first + 1 << ", " << coup.second + 1 << ") ";
    }
    std::cout << std::endl;
}