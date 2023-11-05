#include "jeu.h"

Jeu::Jeu(){ }

void Jeu::InitialiserJcJ()
{
    std::string nomJoueur1, nomJoueur2;
    char jetonJoueur1, jetonJoueur2;
    do
    {
        std::cout << "Saisissez le pseudo du joueur 1 : ";
        std::cin >> nomJoueur1;

        std::cout << "Choisissez le jeton du joueur 1 (O ou X) : ";
        std::cin >> jetonJoueur1;

        std::cout << "Saisissez le pseudo du joueur 2 : ";
        std::cin >> nomJoueur2;

        if (jetonJoueur1 == 'O')
            jetonJoueur2 = 'X';
        else
            jetonJoueur2 = 'O';

    } while((jetonJoueur1 != 'O' && jetonJoueur2 != 'X') &&
             (jetonJoueur1 != 'X' && jetonJoueur2 != 'O'));

    std::cout << std::endl;
    std::cout << "*** JOUEURS ***" << std::endl;
    std::cout << "Joueur 1 : ";
    this->joueur1 = Joueur(nomJoueur1, jetonJoueur1);
    std::cout << "Joueur 2 : ";
    this->joueur2 = Joueur(nomJoueur2, jetonJoueur2);
}

void Jeu::InitialiserJcO()
{
    std::string nomJoueur;
    std::string nomOrdinateur = "Ordinateur";

    char jetonJoueur, jetonOrdinateur;
    do
    {
        std::cout << "Saisissez le pseudo du joueur : ";
        std::cin >> nomJoueur;

        std::cout << "Choisissez le jeton du joueur (O ou X) : ";
        std::cin >> jetonJoueur;

    } while(jetonJoueur != 'O' && jetonJoueur != 'X');

    if (jetonJoueur == 'O')
        jetonOrdinateur = 'X';
    else
        jetonOrdinateur = 'O';

    std::cout << std::endl;
    std::cout << "*** JOUEURS ***" << std::endl;
    std::cout << "Joueur : ";
    this->joueur1 = Joueur(nomJoueur,jetonJoueur);
    std::cout << "Ordinateur : ";
    this->ordinateur = Ordinateur(nomOrdinateur, jetonOrdinateur);
}

void Jeu::Jouer()
{
    int ChoixMode;
    do
    {
        std::cout << "Voulez-vous jouer avec un joueur ou contre ordinateur : " << std::endl;
        std::cout << "1. Joueur" << std::endl;
        std::cout << "2. Ordinateur" << std::endl;
        std::cout << "0. Menu Principal" << std::endl;
        std::cout << "Choix option : ";
        std::cin >> ChoixMode;
    } while (ChoixMode != 1 && ChoixMode != 2 && ChoixMode != 0);

    switch(ChoixMode)
    {
        case 1:
            JoueurContreJoueur();
            break;
        case 2:
            JoueurContreOrdinateur();
            break;
        case 0:
            return;
            break;
        default:
            break;
    }
}

void Jeu::DemanderRejouer()
{
    char rejouer;
    do
    {
        std::cout << "Voulez-vous rejouer (y/N) ? ";
        std::cin >> rejouer;
    } while (rejouer != 'y' &&
             rejouer != 'n' &&
             rejouer != 'Y' &&
             rejouer != 'N');

    if (rejouer == 'y' || rejouer == 'Y')
    {
        Jouer();
    }
    else
    {
        return;
    }
}
