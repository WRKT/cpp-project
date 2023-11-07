#include "puissance4.h"

JeuPuissance4::JeuPuissance4(){ };

void JeuPuissance4::InitialiserGrille()
{
    this->grillePuissance4 = GrillePuissance4(4,7);
}

void JeuPuissance4::JouerTour()
{
    grillePuissance4.AfficherGrille();

    std::cout << "--> Tour de " << joueurCourant->GetNom() << "(" << joueurCourant->GetJeton() << ")" << std::endl;

    int colonne;
    bool coupValide;

    if(joueurCourant == &joueur1 || joueurCourant == &joueur2)
    {
        do {
            std::cout << "Entrez la colonne (1 - " << grillePuissance4.GetColonnes() << ") : ";
            std::cin >> colonne;

            if (!(std::cin))
            {
                std::cout << "Saisie invalide. Veuillez reessayer." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            coupValide = this->grillePuissance4.DeposerPuissance4(colonne, joueurCourant->GetJeton ());

            if(!coupValide)
            {
                std::cout << "Colonne pleine, ce coup n'est pas valide. Choisissez une autre colonne." << std::endl;
            }

        } while (!this->grillePuissance4.DeposerPuissance4(colonne, joueurCourant->GetJeton()));
    }

    else {
        ordinateur.JouerPuissance4(grillePuissance4, joueurCourant->GetJeton());
    }

    if (grillePuissance4.EstGagnant(joueurCourant->GetJeton()))
    {
        grillePuissance4.AfficherGrille();
        std::cout << std::endl;
        std::cout << "Felicitations ! " << joueurCourant->GetNom() << " a gagne !" << std::endl;

        gameOver = true;

    } else if (grillePuissance4.EstEgalite())
    {
        grillePuissance4.AfficherGrille();
        std::cout << std::endl;
        std::cout << "Egalite ! Fin de la partie." << std::endl;

        gameOver = true;
    }
}

void JeuPuissance4::JoueurContreJoueur()
{
    InitialiserJcJ();
    InitialiserGrille();
    gameOver = false;

    joueurCourant = &joueur1;

    while(!gameOver)
    {
        JouerTour();
        joueurCourant = (joueurCourant == &joueur1) ? &joueur2 : &joueur1;
    }

    if (gameOver)
    {
        DemanderRejouer();
    }
}

void JeuPuissance4::JoueurContreOrdinateur()
{
    InitialiserJcO();
    InitialiserGrille();

    gameOver = false;
    joueurCourant = &joueur1;

    while(!gameOver)
    {
        JouerTour();
        joueurCourant = (joueurCourant == &joueur1) ? &ordinateur : &joueur1;
    }

    if (gameOver)
    {
        DemanderRejouer();
    }
}
