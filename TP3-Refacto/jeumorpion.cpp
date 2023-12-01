#include "jeumorpion.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <limits>
#include "inputconsole.h"

JeuMorpion::JeuMorpion(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage) {}

void JeuMorpion::Jouer()
{
    modeAffichage->AfficherGrille(grille);

    while (!PartieFinie())
    {
        Tour();

        if (AGagne())
        {
            modeAffichage->AfficherGrille(grille);
            modeAffichage->AfficherMessage("Le joueur " + joueurCourant->getNom() + " a gagné !");
                return;
        }

        joueurCourant->getJeton() == joueur1->getJeton() ? joueurCourant = joueur2 : joueurCourant = joueur1;

        modeAffichage->AfficherGrille(grille);
    }
    modeAffichage->AfficherMessage("Match nul !");
}

void JeuMorpion::Tour() {
    auto coupsPossibles = CoupsPossibles();
    if (joueurCourant->estHumain()){
        bool coupValide = false;
        std::pair<int, int> coup;
        while (!coupValide) {
            coup = InputConsole::demanderCoupMorpion(grille->getNbLigne());
            if (std::find(coupsPossibles.begin(), coupsPossibles.end(), coup) != coupsPossibles.end()) {
                    grille->ChangeCellule(coup.first, coup.second, joueurCourant->getJeton());
                    coupValide = true;
            } else {
                    modeAffichage->AfficherErreur("Coups Impossible");
            }
        }
    } else {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(0, coupsPossibles.size() - 1);
            int indiceCoupChoisi = distrib(gen);
            std::pair<int, int> coupChoisi = coupsPossibles[indiceCoupChoisi];
            grille->ChangeCellule(coupChoisi.first, coupChoisi.second, joueurCourant->getJeton());

            modeAffichage->AfficherMessage(joueurCourant->getNom() + " a joué ");

    }
}

std::vector<std::pair<int, int>> JeuMorpion::CoupsPossibles() {
    std::vector<std::pair<int, int>> coups;
    for (int i = 0; i < grille->getNbLigne(); ++i) {
        for (int j = 0; j < grille->getNbColonne(); ++j) {
            if (grille->ACaseVide(i, j)) {
                coups.emplace_back(i, j);
            }
        }
    }
    return coups;
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
