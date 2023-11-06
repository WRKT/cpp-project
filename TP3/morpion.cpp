#include "morpion.h"

JeuMorpion::JeuMorpion() { };

void JeuMorpion::InitialiserGrille()
{
    this->grilleMorpion = Grille(3,3);
}

void JeuMorpion::JoueurContreJoueur()
{
    InitialiserJcJ();
    InitialiserGrille();
    gameOver = false;

    joueurCourant = &joueur1;

    while(!gameOver)
    {
        grilleMorpion.AfficherGrille();
        std::cout << "--> Tour de " << joueurCourant->GetNom() << "(" << joueurCourant->GetJeton() << ")" << std::endl;
        int ligne, colonne;
        do {

            std::cout << "Entrez la ligne (1 - " << grilleMorpion.GetLignes() << ") : ";
            std::cin >> ligne;
            std::cout << "Entrez la colonne (1 - " << grilleMorpion.GetColonnes() << ") : ";
            std::cin >> colonne;

            if(!grilleMorpion.CaseVide(ligne, colonne))
                std::cout << "Ce coup n'est pas valide. Reessayez." << std::endl;

        } while (!grilleMorpion.CaseVide(ligne, colonne));

        grilleMorpion.DeposerMorpion(ligne, colonne, joueurCourant->GetJeton());

        if (grilleMorpion.EstGagnant(joueurCourant->GetJeton()))
        {
            grilleMorpion.AfficherGrille();
            std::cout << std::endl;
            std::cout << "==> Felications ! " << joueurCourant->GetNom() << " a gagne ! Fin de la partie." << std::endl;
            gameOver = true;
        }
        else if (grilleMorpion.EstEgalite())
        {
            grilleMorpion.AfficherGrille();
            std::cout << std::endl;
            std::cout << "==> Fin de la partie. Egalite !" << std::endl;
            gameOver = true;
        }

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
        grilleMorpion.AfficherGrille();
        std::cout << "--> Tour de " << joueurCourant->GetNom() << "(" << joueurCourant->GetJeton() << ")" << std::endl;
        int ligne, colonne;

        if(joueurCourant == &joueur1)
        {
            do {
                std::cout << "Entrez la ligne (1 - " << grilleMorpion.GetLignes() << ") : ";
                std::cin >> ligne;
                std::cout << "Entrez la colonne (1 - " << grilleMorpion.GetColonnes() << ") : ";
                std::cin >> colonne;

                if(!grilleMorpion.CaseVide(ligne, colonne))
                    std::cout << "Ce coup n'est pas valide. Reessayez." << std::endl;

            } while (!grilleMorpion.CaseVide(ligne, colonne));

            grilleMorpion.DeposerMorpion(ligne, colonne, joueurCourant->GetJeton());
        }
        else {
            ordinateur.JouerMorpion(grilleMorpion, joueurCourant->GetJeton());
        }

        if (grilleMorpion.EstGagnant(joueurCourant->GetJeton()))
        {
            grilleMorpion.AfficherGrille();
            std::cout << std::endl;
            std::cout << "Felicitations ! " << joueurCourant->GetNom() << " a gagne !" << std::endl;

            gameOver = true;

        } else if (grilleMorpion.EstEgalite())
        {
            grilleMorpion.AfficherGrille();
            std::cout << std::endl;
            std::cout << "Egalite ! Fin de la partie." << std::endl;

            gameOver = true;
        }

        joueurCourant = (joueurCourant == &joueur1) ? &ordinateur : &joueur1;
    }

    if (gameOver)
    {
        DemanderRejouer();
    }
}
