#include "jeuothello.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <limits>

JeuOthello::JeuOthello(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1) {}

void JeuOthello::Jouer()
{
    grille->AfficherGrille();

    while (!PartieFinie()) {
        if (joueurCourant->estHumain()) {
            TourHumain();
        } else {
            TourOrdi();
        }

        if (AGagne()) {
            grille->AfficherGrille();
            std::cout << "Le joueur " << joueurCourant->getNom() << " a gagné !" << std::endl;
                return;
        }

        if (joueurCourant->getJeton() == joueur1->getJeton()) {
            joueurCourant = joueur2;
        } else {
            joueurCourant = joueur1;
        }

        grille->AfficherGrille();
    }
    std::cout << "Match nul !" << std::endl;
}

void JeuOthello::TourHumain()
{
    int x, y;
    bool coupValide = false;
    while (!coupValide)
    {
        std::cout << joueurCourant->getNom() << " (" << static_cast<char>(joueurCourant->getJeton()) << "), entrez la ligne (1 - " << grille->getNbLigne() << ") : ";
        while (!(std::cin >> x) || x < 1 || x > grille->getNbLigne())
        {
            std::cout << "Entrée invalide. Veuillez entrer un nombre entre 1 et " << grille->getNbLigne() << ": ";
                                                                                                             std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << joueurCourant->getNom() << " (" << static_cast<char>(joueurCourant->getJeton()) << "), entrez la colonne (1 - " << grille->getNbColonne() << ") : ";
        while (!(std::cin >> y) || y < 1 || y > grille->getNbColonne())
        {
            std::cout << "Entrée invalide. Veuillez entrer un nombre entre 1 et " << grille->getNbColonne() << ": ";
                                                                                                               std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (grille->ACaseVide(x - 1, y - 1))
        {
            PlacerJeton(x, y, joueurCourant->getJeton());
            coupValide = true;
        }
        else
        {
            std::cout << "Coup invalide, réessayez.\n";
        }
    }
}

void JeuOthello::TourOrdi()
{
    std::vector<std::pair<int, int>> coupsPossibles;

    for (int i = 0; i < grille->getNbLigne(); ++i)
    {
        for (int j = 0; j < grille->getNbColonne(); ++j)
        {
            if (grille->ACaseVide(i, j))
            {
                coupsPossibles.emplace_back(i + 1, j + 1);
            }
        }
    }
    if (!coupsPossibles.empty())
    {
        std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
        std::uniform_int_distribution<int> dist(0, coupsPossibles.size() - 1);
        auto [x, y] = coupsPossibles[dist(rng)];
        std::cout << joueurCourant->getNom() << " (" << static_cast<char>(joueurCourant->getJeton()) << ") a joué ! " << std::endl;

                    PlacerJeton(x, y, joueurCourant->getJeton());
    }
}

bool JeuOthello::AGagne() const
{

}

bool JeuOthello::PartieFinie() const
{

}

void JeuOthello::PlacerJeton(int x, int y, Jeton jeton)
{

}

Jeton JeuOthello::VerifiePions() const
{
    int countNoir = 0;
    int countBlanc = 0;

    for (int i = 0; i < grille->getNbLigne(); ++i) {
        for (int j = 0; j < grille->getNbColonne(); ++j) {
            if (grille->GetCellule(i, j) == Jeton::X) {
                countNoir++;
            } else if (grille->GetCellule(i, j) == Jeton::O) {
                countBlanc++;
            }
        }
    }

    if (countNoir > countBlanc) {
        return Jeton::X;
    } else if (countBlanc > countNoir) {
        return Jeton::O;
    } else {
        return Jeton::Vide;
    }
}

int JeuOthello::ComptePions(Jeton jeton) const
{
    int count = 0;
    for (int i = 0; i < grille->getNbLigne(); ++i) {
        for (int j = 0; j < grille->getNbColonne(); ++j) {
            if (grille->GetCellule(i, j) == jeton) {
                count++;
            }
        }
    }
    return count;
}

void JeuOthello::VoirCoupPossibles()
{

}
