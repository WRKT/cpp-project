#include "match.h"
#include <iostream>

Match::Match()
{

}

void Match::StartJeu()
{
    std::cout << "*** Bienvenue sur le programme des jeux sur PLATEAU ***" << std::endl;
    std::cout << std::endl;

    switch(ChoixJeu())
    {
    case 1:
        morpion.Jouer();
        break;
    case 2:
        puissance4.Jouer();
        break;
    case 99:
        std::cout << "Merci d'avoir utiliser le programme. Au revoir." << std::endl;
        return;
        break;
    default:
        break;
    }

    Rejouer();
}

int Match::ChoixJeu()
{
    int choixUser = 0;

    do
    {
        std::cout << "Quelle jeu voulez-vous jouer : " << std::endl;
        std::cout << "1. Morpion" << std::endl;
        std::cout << "2. Puissance4" << std::endl;
        std::cout << "99. Quittez le programme." << std::endl;
        std::cout << std::endl;
        std::cout << "Choix option : ";
        std::cin >> choixUser;

    } while ((choixUser != 1) &&
             (choixUser != 2) &&
             (choixUser != 99));

    return choixUser;
}
void Match::Rejouer()
{
    StartJeu();
}
