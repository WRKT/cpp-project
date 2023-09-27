#include <iostream>
#include <string>
#include "headers/exo1.h"
#include "headers/exo3.h"


int exo3(){
    int choixSousMenu;
    std::cout << "-----------------------" << std::endl;
    std::cout << "       EXERCICE 3      " << std::endl;
    std::cout << "-----------------------" << std::endl;
    do
    {
        SautLigne();
        std::cout << "Quelle programme voulez-vous lancer : " << std::endl;
        std::cout << "1. Salutations" << std::endl;
        std::cout << "2. Jeu du nombre gagnant" << std::endl;
        std::cout << "0. Menu Principal" << std::endl;
        SautLigne();
        std::cout << "Choisissez une option: ";
        std::cin >> choixSousMenu;

        switch (choixSousMenu)
        {
        case 1:
            SautLigne();
            Salutations();
            break;
        case 2:
            SautLigne();
            DevinerNombre();
            break;
        case 0:
            SautLigne();
            std::cout << "<< Retour au menu principal" <<std::endl;
            break;
        default:
            std::cout << ">> Erreur : Saisie invalide. Veuillez réessayer." <<std::endl;
            break;
        }
    } while (choixSousMenu != 0);

    system("clear");
    return 0;
    
}

void Salutations()
{
    std::cout << "*** Programme salutation ***" << std::endl;

    std::string prenom, nom, nomComplet;
    std::cout << "Saisissez votre prénom et NOM: ";
    std::cin >> prenom;
    std::cin >> nom;

    nomComplet = prenom + " " + nom;
    std::cout << std::endl;
    std::cout << "Hello, " << nomComplet;
    SautLigne();
}

void DevinerNombre()
{
    std::cout << "*** Jeu du nombre GAGNANT ***" << std::endl;

    srand(time(NULL));
    int nombreGagnant = rand()%1000;

    bool deviner = true;
    int nombreEssai = 0;
    
    while(deviner) {
        int nombreUser;
        std::cout << std::endl;
        std::cout << "Saisissez votre nombre: ";
        std::cin >> nombreUser;
        
        nombreEssai++;
        if (nombreGagnant < nombreUser)
        {
            std::cout << "Votre nombre est trop haut." << std::endl;
        }
        else if (nombreGagnant > nombreUser)
        {
            std::cout << "Votre nombre est trop bas." << std::endl;
        }
        else 
        {
            std::cout << std::endl;
            std::cout << "Félicitations ! Vous avez deviné le nombre ! Vous avez effectué " << nombreEssai;
            std::cout << " essais." << std::endl;
            deviner = false;
        }
    }
}
