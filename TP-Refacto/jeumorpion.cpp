#include "jeumorpion.h"
#include <algorithm>
#include <vector>


void JeuMorpion::Tour()
{
    std::vector<Position> coupsPossibles = CoupsPossibles();

    bool coupValide = false;

    while (!coupValide)
    {
        modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations());
        const Position& coup = joueurCourant->ChoisirCoordonnees(coupsPossibles);

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
