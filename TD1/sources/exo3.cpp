#include <iostream>
#include <string>
#include "headers/exo1.h"
#include "headers/exo3.h"


int Exo3(){
    int choixSousMenu;
    bool retourMenuPrincipal = false;

    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "       INSCRIPTION CONSOLE ET RECUPERATION SAISIE      " << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
    do
    {
        SautLigne();
        std::cout << "Quelle programme voulez-vous lancer : " << std::endl;
        std::cout << "1. Saisie chaine de caractères" << std::endl;
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
            retourMenuPrincipal = true;
            break;
        default:
            std::cout << ">> Erreur : Saisie invalide. Veuillez réessayer." <<std::endl;
            break;
        }
    } while (!retourMenuPrincipal);

    ClearTerminal();
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
    std::cout << "==> Hello, " << nomComplet;
    SautLigne();
}

void JoueurDevineNombre()
{
    srand(time(NULL));
    int nombreGagnant = rand()%1000;

    bool gameOver = false;
    int nombreEssai = 0;
    
    while(!gameOver) {
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
            gameOver = true;
        }
    }
}

void OrdinateurDevineNombre()
{
    int nombreGagnant;
    bool gameOver = false;
    int nombreEssai = 0;
    int nombreMin = 0;
    int nombreOrdinateur = 0;
    int nombreMax = 1000;
    char reponseUtilisateur;

    SautLigne();
    std::cout << "Choisissez un nombre entre 0 et 1000 : ";
    std::cin >> nombreGagnant;

    while(!gameOver) {

        nombreOrdinateur = (nombreMin + nombreMax)/2;    

        std::cout<< "L'ordinateur devine ... " << nombreOrdinateur << std::endl;
        SautLigne();
        std::cout<< "Ai-je deviné le nombre ? (o/N) ==> ";
        std::cin >> reponseUtilisateur;

        if ((reponseUtilisateur == 'o' || reponseUtilisateur == 'O') && (nombreOrdinateur == nombreGagnant))
        {
            nombreEssai++;
            std::cout << "Super! Ordinateur a deviné " << nombreEssai << " fois"<< std::endl;
            gameOver = true;
        }
        else if ((reponseUtilisateur == 'o' || reponseUtilisateur == 'O') && (nombreOrdinateur != nombreGagnant))
        {
            std::cout << "Ne trichez pas s'il vous plait..." <<std::endl;
        }
        else if ((reponseUtilisateur == 'n' || reponseUtilisateur == 'N') && (nombreOrdinateur == nombreGagnant))
        {
            std::cout << "Ne soyez pas mauvais perdant, êtes-vous sur ? " <<std::endl;
        }
        else if ((reponseUtilisateur == 'n' || reponseUtilisateur == 'N'))
        {
            nombreEssai++;
            std::cout << "Zut ! Le nombre est-il plus grand ou plus petit ? (G: grand / p: petit) ==> ";
            std::cin >> reponseUtilisateur;
            if (reponseUtilisateur == 'G' || reponseUtilisateur == 'g')
            {
                std::cout << "D'accord, le nombre est donc plus grand (Calcul en cours ...)" << std::endl;
                nombreMin = nombreOrdinateur + 1;
            }
            else if(reponseUtilisateur == 'p' || reponseUtilisateur == 'P')
            {
                std::cout << "D'accord, le nombre est donc plus petit (Calcul en cours ...)" << std::endl;
                nombreMax = nombreOrdinateur - 1;
            }
            else
            {
                std::cout << "Reponse invalide. Choisissez entre G et p." << std::endl; 
            }
        }
        else{
            std::cout << "Reponse invalide. Choisissez entre o pour Oui et N pour Non" << std::endl;
        }
    }

}

void DevinerNombre()
{
    int optionJeu;

    std::cout << "*** Jeu du nombre GAGNANT ***" << std::endl;
    SautLigne();

    std::cout << "Choisissez le mode de jeu que vous souhaitez : " << std::endl;
    std::cout << "1. Joueur devine" << std::endl;
    std::cout << "2. Ordinateur devine" << std::endl;
    SautLigne();

    std::cout << "Choix option : ";
    std::cin >> optionJeu;

    switch (optionJeu)
    {
    case 1: 
        JoueurDevineNombre();
        break;
    case 2: 
        OrdinateurDevineNombre();
        break;
    default: 
        DevinerNombre();
        break;
    }

}


