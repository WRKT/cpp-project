#include <iostream>
#include "headers/exo1.h"
#include "headers/exo2.h"
#include "headers/exo3.h"

int main() {
    int choixMenu;
    
    do {
        std::cout << std::endl;
        std::cout << "Quelle exercice voulez-vous lancer : " << std::endl;
        std::cout << "1. Manipulation des nombres" << std::endl;
        std::cout << "2. Jeu de tennis" << std::endl;
        std::cout << "3. Inscription console et récupération saisie" << std::endl;
        std::cout << "0. Quitter" << std::endl;
        SautLigne();
        std::cout << "Choisissez une option: ";
        std::cin >> choixMenu;

        switch (choixMenu)
        {
            case 1:
                system("clear");
                Exo1();
                break;
            case 2:
                system("clear");
                Exo2();
                break;
            case 3:
                system("clear");
                Exo3();
                break;
            case 0:
                std::cout << "Merci d'avoir utilisé le programme. Au revoir !" << std::endl;
                break;
            default:
                std::cout << ">> Erreur : Saisie invalide. Veuillez réessayer." << std::endl;
                break;
        }

        if (sizeof(choixMenu) != sizeof(int))
        {
            return 0;
        }
    } while (choixMenu != 0);

    return 0;
}