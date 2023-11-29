#include "affichageconsole.h"
#include <iostream>

void AffichageConsole::AfficherGrille(const std::shared_ptr<IGrille> grille) const
{
    AfficherMessage("");
    for (int i = 0; i < grille->getNbLigne(); i++)
    {
        for(int j = 0; j < grille->getNbColonne(); j++)
        {
            if (j == 0)
            {
                std::cout << "| " << static_cast<char>(grille->GetCellule(i,j)) <<  " | ";
            }
            else
            {
                std::cout << static_cast<char>(grille->GetCellule(i,j)) << " | ";
            }
        }
        AfficherMessage("");
    }
    AfficherMessage("");
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
