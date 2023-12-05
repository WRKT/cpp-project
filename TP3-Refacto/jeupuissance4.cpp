#include "jeupuissance4.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "inputconsole.h"

JeuPuissance4::JeuPuissance4(std::shared_ptr<IGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage) {}

void JeuPuissance4::Jouer()
{

    InitialiseJeu();

    while (!PartieFinie())
    {
        Tour();
        if (AGagne()) {
            AfficherResultat();
                return;
        }

        joueurCourant->getJeton() == joueur1->getJeton() ? joueurCourant = joueur2 : joueurCourant = joueur1;

        modeAffichage->AfficherGrille(grille);
    }

    modeAffichage->AfficherMessage("Match nul !");
}

void JeuPuissance4::Tour()
{
    auto coupsPossibles = CoupsPossibles();
    if (joueurCourant->estHumain())
    {
        bool coupValide = false;
        int colonne;
        while (!coupValide)
        {
            modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations());
            colonne = InputConsole::demanderCoupPuissance4(grille->getNbColonne());
            for (auto& coup : coupsPossibles) {
                if (coup.second == colonne) {
                    grille->ChangeCellule(coup.first, colonne, joueurCourant->getJeton());
                    coupValide = true;
                    break;
                }
            }

            if (!coupValide) {
                modeAffichage->AfficherErreur("Coup invalide.");
            }
        }
    }
    else
    {
        if (!coupsPossibles.empty())
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(0, coupsPossibles.size() - 1);

            auto coupChoisi = coupsPossibles[distrib(gen)];
            grille->ChangeCellule(coupChoisi.first, coupChoisi.second, joueurCourant->getJeton());
            modeAffichage->AfficherMessage(joueurCourant->getInformations() + " a joué !");
        }
    }
}

std::vector<std::pair<int, int>> JeuPuissance4::CoupsPossibles()
{
    std::vector<std::pair<int, int>> coupsPossibles;
    for (int colonne = 0; colonne < grille->getNbColonne(); ++colonne)
    {
        for (int ligne = grille->getNbLigne() - 1; ligne >= 0; --ligne)
        {
            if (grille->GetCellule(ligne, colonne) == Jeton::Vide)
            {
                coupsPossibles.emplace_back(ligne, colonne);
                break;
            }
        }
    }
    return coupsPossibles;
}

void JeuPuissance4::AfficherResultat() const
{
    modeAffichage->AfficherGrille(grille);
    modeAffichage->AfficherMessage ("Le joueur " + joueurCourant->getInformations() + " a gagné !");
}

void JeuPuissance4::InitialiseJeu() const {
    modeAffichage->AfficherGrille(grille);
}

bool JeuPuissance4::PartieFinie() const
{
    return AGagne() || grille->EstRemplie();
}

bool JeuPuissance4::AGagne() const
{
    return grille->VerifieLigne(4, joueurCourant->getJeton()) || grille->VerifieColonne(4, joueurCourant->getJeton()) || grille->VerifieDiagonale(4, joueurCourant->getJeton());

}
