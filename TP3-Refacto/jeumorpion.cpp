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
    InitialiseJeu();

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

void JeuMorpion::Tour()
{
    auto coupsPossibles = CoupsPossibles();
    if (joueurCourant->estHumain())
    {
        bool coupValide = false;
        std::pair<int, int> coup;
        while (!coupValide)
        {
            coup = InputConsole::demanderCoupMorpion(grille->getNbLigne());
            if (std::find(coupsPossibles.begin(), coupsPossibles.end(), coup) != coupsPossibles.end())
            {
                grille->ChangeCellule(coup.first, coup.second, joueurCourant->getJeton());
                coupValide = true;
            }
            else
            {
                modeAffichage->AfficherErreur("Coups Impossible");
            }
        }
    }
    else
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, coupsPossibles.size() - 1);
        int indiceCoupChoisi = distrib(gen);
        std::pair<int, int> coupChoisi = coupsPossibles[indiceCoupChoisi];
        grille->ChangeCellule(coupChoisi.first, coupChoisi.second, joueurCourant->getJeton());

        modeAffichage->AfficherMessage(joueurCourant->getNom() + " a joué ");
    }
}

void JeuMorpion::InitialiseJeu() const
{
    modeAffichage->AfficherGrille(grille);
}

std::vector<std::pair<int, int>> JeuMorpion::CoupsPossibles()
{
    std::vector<std::pair<int, int>> coups;
    for (int i = 0; i < grille->getNbLigne(); ++i)
    {
        for (int j = 0; j < grille->getNbColonne(); ++j)
        {
            if (grille->ACaseVide(i, j))
            {
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
    std::vector<Jeton> Ligne1 = grille->GetLigne(0);
    std::vector<Jeton> Ligne2 = grille->GetLigne(1);
    std::vector<Jeton> Ligne3 = grille->GetLigne(2);

    if (std::all_of(Ligne1.begin(), Ligne1.end(), [this](Jeton jeton)
                    { return jeton == joueurCourant->getJeton(); }))
        return true;
    if (std::all_of(Ligne2.begin(), Ligne2.end(), [this](Jeton jeton)
                    { return jeton == joueurCourant->getJeton(); }))
        return true;
    if (std::all_of(Ligne3.begin(), Ligne3.end(), [this](Jeton jeton)
                    { return jeton == joueurCourant->getJeton(); }))
        return true;
    else
        return false;
}

bool JeuMorpion::VerifieColonnes() const
{
    std::vector<Jeton> Colonne1 = grille->GetColonne(0);
    std::vector<Jeton> Colonne2 = grille->GetColonne(1);
    std::vector<Jeton> Colonne3 = grille->GetColonne(2);

    if (std::all_of(Colonne1.begin(), Colonne1.end(), [this](Jeton jeton)
                    { return jeton == joueurCourant->getJeton(); }))
        return true;
    if (std::all_of(Colonne2.begin(), Colonne2.end(), [this](Jeton jeton)
                    { return jeton == joueurCourant->getJeton(); }))
        return true;
    if (std::all_of(Colonne3.begin(), Colonne3.end(), [this](Jeton jeton)
                    { return jeton == joueurCourant->getJeton(); }))
        return true;
    else
        return false;
}

bool JeuMorpion::VerifieDiagonales() const
{
    std::vector<Jeton> Diagonale1 = grille->GetDiagonale(1);
    std::vector<Jeton> Diagonale2 = grille->GetDiagonale(0);

    if (std::all_of(Diagonale1.begin(), Diagonale1.end(), [this](Jeton jeton)
                    { return jeton == joueurCourant->getJeton(); }))
        return true;
    if (std::all_of(Diagonale2.begin(), Diagonale2.end(), [this](Jeton jeton)
                    { return jeton == joueurCourant->getJeton(); }))
        return true;
    else
        return false;
}

bool JeuMorpion::PartieFinie() const
{
    return AGagne() || grille->EstRemplie();
}
