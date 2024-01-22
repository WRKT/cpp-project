#include "jeupuissance4.h"
#include <vector>
#include <algorithm>


void JeuPuissance4::Tour()
{
    std::vector<Position> coupsPossibles = CoupsPossibles();
    bool coupValide = false;

    while (!coupValide)
    {
        modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations());
        const Position& coup = joueurCourant->ChoisirColonne(coupsPossibles);

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

std::vector<Position> JeuPuissance4::CoupsPossibles()
{
    std::vector<Position> coupsPossibles;

    for (int colonne = 0; colonne < grille->getNbColonnes(); ++colonne)
    {
        for (int ligne = grille->getNbLignes() - 1; ligne >= 0; --ligne)
        {
            if (grille->ACaseVide(ligne, colonne))
            {
                Position position = {ligne, colonne};
                coupsPossibles.emplace_back(position);
                break;
            }
        }
    }
    return coupsPossibles;
}

void JeuPuissance4::AfficherResultat() const
{
    modeAffichage->MettreAJourGrille(grille);
    modeAffichage->AfficherMessage("Le joueur " + joueurCourant->getInformations() + " a gagné !");
}

bool JeuPuissance4::PartieFinie() const
{
    return AGagne() || grille->EstRemplie();
}

bool JeuPuissance4::AGagne() const
{
    return grille->VerifieLigne(sequenceGagnante, joueurCourant->getJeton())
           || grille->VerifieColonne(sequenceGagnante, joueurCourant->getJeton())
           || grille->VerifieDiagonaleASC(sequenceGagnante, joueurCourant->getJeton())
           || grille->VerifieDiagonaleDESC(sequenceGagnante, joueurCourant->getJeton());
}
