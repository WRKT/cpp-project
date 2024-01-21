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

        modeAffichage->MettreAJourGrille(grille);
    }
    modeAffichage->AfficherMessage("Match nul !");
}

void JeuMorpion::Tour()
{
    std::vector<Position> coupsPossibles = CoupsPossibles();

    bool coupValide = false;

    while (!coupValide)
    {
        modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations());
        const Position& coup = joueurCourant->ChoisirCoupMorpion(coupsPossibles);

        if (std::find(coupsPossibles.begin(), coupsPossibles.end(), coup) != coupsPossibles.end())
        {
            grille->ChangeCellule(coup.x, coup.y, joueurCourant->getJeton());
            coupValide = true;
        }
        else
        {
            modeAffichage->AfficherErreur("Coups Impossible");
        }
    }
}

std::vector<Position> JeuMorpion::CoupsPossibles()
{
    std::vector<Position> coups;

    for (int ligne = 0; ligne < grille->getNbLignes(); ligne++)
    {
        for (int colonne = 0; colonne < grille->getNbColonnes(); colonne++)
        {
            if (grille->ACaseVide(ligne, colonne))
            {
                Position position = {ligne, colonne};
                coups.emplace_back(position);
            }
        }
    }
    return coups;
}

void JeuMorpion::AfficherResultat() const
{
    modeAffichage->MettreAJourGrille(grille);
    modeAffichage->AfficherMessage("Le joueur " + joueurCourant->getInformations() + " a gagné !");
}

bool JeuMorpion::AGagne() const
{
    return grille->VerifieLigne(sequenceGagnante, joueurCourant->getJeton())
           || grille->VerifieColonne(sequenceGagnante, joueurCourant->getJeton())
           || grille->VerifieDiagonaleASC(sequenceGagnante, joueurCourant->getJeton())
           || grille->VerifieDiagonaleDESC(sequenceGagnante, joueurCourant->getJeton());
}

bool JeuMorpion::PartieFinie() const
{
    return AGagne() || grille->EstRemplie();
}
