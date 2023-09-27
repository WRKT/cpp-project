#include <iostream>
#include "headers/exo1.h"
#include "headers/exo2.h"
#include "headers/exo3.h"

int main() {
    int choixMenu;
    
    do {
        std::cout << std::endl;
        std::cout << "Quelle exercice voulez-vous lancer : " << std::endl;
        std::cout << "1. Exercice 1" << std::endl;
        std::cout << "2. Exercice 2" << std::endl;
        std::cout << "3. Exercice 3" << std::endl;
        std::cout << "0. Quitter" << std::endl;
        SautLigne();
        std::cout << "Choisissez une option: ";
        std::cin >> choixMenu;

        switch (choixMenu)
        {
            case 1:
                system("clear");
                exo1();
                break;
            case 2:
                system("clear");
                exo2();
                break;
            case 3:
                system("clear");
                exo3();
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