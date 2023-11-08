#include "morpion.h"
#include <limits>

JeuMorpion::JeuMorpion() { };

void JeuMorpion::InitialiserGrille()
{
    this->grilleMorpion = Grille(3,3);
}

void JeuMorpion::JouerTour()
{
    grilleMorpion.AfficherGrille();

    std::cout << "--> Tour de " << joueurCourant->GetNom() << "(" << joueurCourant->GetJeton() << ")" << std::endl;

    int ligne, colonne;

    if (joueurCourant == &joueur1 || joueurCourant == &joueur2)
    {
        do
        {
            std::cout << "Entrez la ligne (1 - " << grilleMorpion.GetLignes() << ") : ";
            std::cin >> ligne;
            std::cout << "Entrez la colonne (1 - " << grilleMorpion.GetColonnes() << ") : ";
            std::cin >> colonne;

            if (!(std::cin))
            {
                std::cout << "Saisie invalide. Veuillez reessayer." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            if (!grilleMorpion.CaseVide(ligne, colonne))
            {
                std::cout << "Ce coup n'est pas valide. Réessayez." << std::endl;
            }

        } while (!grilleMorpion.CaseVide(ligne, colonne));

        grilleMorpion.DeposerMorpion(ligne, colonne, joueurCourant->GetJeton());
    }
    else
    {
        ordinateur.JouerMorpion(grilleMorpion, joueurCourant->GetJeton());
    }

    if (grilleMorpion.EstGagnant(joueurCourant->GetJeton()))
    {
        grilleMorpion.AfficherGrille();
        std::cout << std::endl;
        std::cout << "Félicitations ! " << joueurCourant->GetNom() << " a gagné !" << std::endl;
        gameOver = true;
    }
    else if (grilleMorpion.EstEgalite())
    {
        grilleMorpion.AfficherGrille();
        std::cout << std::endl;
        std::cout << "Fin de la partie. Égalité !" << std::endl;
        gameOver = true;
    }
}

void JeuMorpion::JoueurContreJoueur()
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

void JeuMorpion::JoueurContreOrdinateur()
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

