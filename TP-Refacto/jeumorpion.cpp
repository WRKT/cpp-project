#include "jeumorpion.h"
#include <algorithm>
#include <vector>

JeuMorpion::JeuMorpion(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage) {}

void JeuMorpion::Jouer()
{
    modeAffichage->AfficherGrille(grille);
    while (!PartieFinie())
    {
        Tour();
        if (AGagne())
        {
            AfficherResultat();
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

    bool coupValide = false;
    std::pair<int, int> coup;

    while (!coupValide)
    {
        modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations());
        coup = joueurCourant->ChoisirCoupMorpion(coupsPossibles);
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
std::vector<std::pair<int, int>> JeuMorpion::CoupsPossibles()
{
    std::vector<std::pair<int, int>> coups;
    for (int i = 0; i < grille->getNbLignes(); ++i)
    {
        for (int j = 0; j < grille->getNbColonnes(); ++j)
        {
            if (grille->ACaseVide(i, j))
            {
                coups.emplace_back(i, j);
            }
        }
    }
    return coups;
}

void JeuMorpion::AfficherResultat() const
{
    modeAffichage->AfficherGrille(grille);
    modeAffichage->AfficherMessage("Le joueur " + joueurCourant->getInformations() + " a gagné !");
}

bool JeuMorpion::AGagne() const
{
    return grille->VerifieLigne(sequenceGagnante, joueurCourant->getJeton()) || grille->VerifieColonne(sequenceGagnante, joueurCourant->getJeton()) || grille->VerifieDiagonale(sequenceGagnante, joueurCourant->getJeton());
}

bool JeuMorpion::PartieFinie() const
{
    return AGagne() || grille->EstRemplie();
}
