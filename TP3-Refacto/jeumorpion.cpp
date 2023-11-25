#include "jeumorpion.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <limits>

JeuMorpion::JeuMorpion(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage) {}

void JeuMorpion::Jouer()
{
    modeAffichage->AfficherGrille(grille);

    while (!PartieFinie())
    {
        if (joueurCourant->estHumain())
        {
            TourHumain();
        }
        else
        {
            TourOrdi();
        }

        if (AGagne())
        {
            modeAffichage->AfficherGrille(grille);
            modeAffichage->AfficherMessage("Le joueur " + joueurCourant->getNom() + " a gagné !");
                return;
        }

        if (joueurCourant->getJeton() == joueur1->getJeton())
        {
            joueurCourant = joueur2;
        }
        else
        {
            joueurCourant = joueur1;
        }

        modeAffichage->AfficherGrille(grille);
    }
    modeAffichage->AfficherMessage("Match nul !");
}

void JeuMorpion::TourHumain()
{
    int x, y;
    bool coupValide = false;

    while (!coupValide) // coupValide sera une methode
    {
        modeAffichage->AfficherMessage(joueurCourant->getNom() + " (" + static_cast<char>(joueurCourant->getJeton()) + "), entrez la ligne (1 - " + std::to_string (grille->getNbLigne()) + ") : ", 0);

        while (!(std::cin >> x) || x < 1 || x > grille->getNbLigne())
        {
            modeAffichage->AfficherErreur("Entrer un nombre entre 1 et " + std::to_string(grille->getNbLigne()) + ": ");

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        modeAffichage->AfficherMessage(joueurCourant->getNom() + " (" + static_cast<char>(joueurCourant->getJeton()) + "), entrez la colonne (1 - " + std::to_string(grille->getNbColonne()) + ") : ", 0);

        while (!(std::cin >> y) || y < 1 || y > grille->getNbColonne())
        {
            modeAffichage->AfficherErreur("Entrer un nombre entre 1 et " + std::to_string(grille->getNbColonne()) + ": ");
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
            std::cerr << "Coup invalide, réessayez.\n";
        }
    }
}

void JeuMorpion::TourOrdi()
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

        modeAffichage->AfficherMessage(joueurCourant->getNom() + " (" + static_cast<char>(joueurCourant->getJeton()) + ") a joué ! ");

        PlacerJeton(x, y, joueurCourant->getJeton());
    }
}

bool JeuMorpion::AGagne() const
{
    return VerifieLignes() || VerifieColonnes() || VerifieDiagonales();
}

bool JeuMorpion::VerifieLignes() const
{
    for (int i = 0; i < grille->getNbLigne(); ++i)
    {
        Jeton premierJeton = grille->GetCellule(i, 0);
        if (premierJeton != Jeton::Vide)
        {
            bool ligneGagnante = true;
            for (int j = 1; j < grille->getNbColonne(); ++j)
            {
                if (grille->GetCellule(i, j) != premierJeton)
                {
                    ligneGagnante = false;
                    break;
                }
            }
            if (ligneGagnante)
                return true;
        }
    }
    return false;
}

bool JeuMorpion::VerifieColonnes() const
{
    for (int j = 0; j < grille->getNbColonne(); ++j)
    {
        Jeton premierJeton = grille->GetCellule(0, j);
        if (premierJeton != Jeton::Vide)
        {
            bool colonneGagnante = true;
            for (int i = 1; i < grille->getNbLigne(); ++i)
            {
                if (grille->GetCellule(i, j) != premierJeton)
                {
                    colonneGagnante = false;
                    break;
                }
            }
            if (colonneGagnante)
                return true;
        }
    }
    return false;
}

bool JeuMorpion::VerifieDiagonales() const
{
    Jeton premierJeton = grille->GetCellule(0, 0);
    bool diagonaleGagnante = (premierJeton != Jeton::Vide);
    for (int i = 1; i < grille->getNbLigne() && diagonaleGagnante; ++i)
    {
        if (grille->GetCellule(i, i) != premierJeton)
        {
            diagonaleGagnante = false;
        }
    }

    if (diagonaleGagnante)
        return true;

    premierJeton = grille->GetCellule(0, grille->getNbColonne() - 1);
    diagonaleGagnante = (premierJeton != Jeton::Vide);
    for (int i = 1; i < grille->getNbLigne() && diagonaleGagnante; ++i)
    {
        if (grille->GetCellule(i, grille->getNbColonne() - 1 - i) != premierJeton)
        {
            diagonaleGagnante = false;
        }
    }

    return diagonaleGagnante;
}

bool JeuMorpion::PartieFinie() const
{
    return AGagne() || grille->EstRemplie();
}

void JeuMorpion::PlacerJeton(int x, int y, Jeton jeton)
{
    grille->ChangeCellule(x - 1, y - 1, jeton);
}

