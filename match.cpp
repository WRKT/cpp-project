#include "match.h"
#include <iostream>
#include <limits>

Match::Match()
{

}

void Match::StartJeu()
{
    if(system("clear"))
    {
        system("cls");
    }

    std::cout << "*********************************" << std::endl;
    std::cout << "*  PROGRAMME DE JEU DE PLATEAU  *" << std::endl;
    std::cout << "*********************************" << std::endl;
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
        // boucle for pour recupérée chaque jeux dans la liste
        std::cout << "1. Morpion" << std::endl;
        std::cout << "2. Puissance4" << std::endl;
        std::cout << "99. Quittez le programme." << std::endl;
        std::cout << std::endl;
        std::cout << "Choix option : ";
        std::cin >> choixUser;

        if (!(std::cin))
        {
            std::cout << "Saisie invalide. Veuillez reessayer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while ((choixUser != 1) &&
             (choixUser != 2) &&
             (choixUser != 99));

    return choixUser;
}
void Match::Rejouer()
{
    StartJeu();
}
