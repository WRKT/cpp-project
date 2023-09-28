#include <iostream>
#include "headers/exo1.h"
#include "headers/exo2.h"
#include "headers/exo3.h"

int main() {
    ClearTerminal();
    int choixMenu;
    bool arretProgramme = false;
    do {
        std::cout << "---------------------------" << std::endl;
        std::cout << "       MENU PRINCIPAL      " << std::endl;
        std::cout << "---------------------------" << std::endl;
        SautLigne();
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
                ClearTerminal();
                Exo1();
                break;
            case 2:
                ClearTerminal();
                Exo2();
                break;
            case 3:
                ClearTerminal();
                Exo3();
                break;
            case 0:
                arretProgramme = true;
                std::cout << "Merci d'avoir utilisé le programme. Au revoir !" << std::endl;
                break;
            default:
                std::cout << ">> Erreur : Saisie invalide. Veuillez réessayer." << std::endl;
                break;
        }

    } while (!arretProgramme);

    return 0;
}
