#include "affichageconsole.h"
#include <iostream>

void AffichageConsole::AfficherGrille(const std::shared_ptr<IGrille> grille) const
{
    const int nbColonnes = grille->getNbColonne();
    const int nbLignes = grille->getNbLigne();

    std::cout << "    ";
    for (int j = 0; j < nbColonnes; j++)
    {
        std::cout << " " << (j + 1) << "  ";
    }
    std::cout << "\n";

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
        std::cout << "\n";

        std::cout << "   +";
        for(int j = 0; j < nbColonnes; j++)
        {
            std::cout << "---+";
        }
        std::cout << "\n";
    }
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
