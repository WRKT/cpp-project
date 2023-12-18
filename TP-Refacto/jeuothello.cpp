#include "jeuothello.h"
#include <algorithm>
#include <vector>

JeuOthello::JeuOthello(std::shared_ptr<IGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage) {}

void JeuOthello::Jouer()
{
    InitialiseJeu();

    while (!PartieFinie())
    {
        Tour();
        joueurCourant->getJeton() == joueur1->getJeton() ? joueurCourant = joueur2 : joueurCourant = joueur1;
        modeAffichage->AfficherGrille(grille);
    }

    AfficherResultat();
}

void JeuOthello::Tour()
{
    auto coupsPossibles = CoupsPossibles();
    bool coupValide = false;

    modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations());
    modeAffichage->AfficherCoupsPossibles(coupsPossibles);

    if (coupsPossibles.empty())
    {
        modeAffichage->AfficherMessage("Aucun coup possible pour " + joueurCourant->getInformations() + ". Passage au joueur suivant.");
        bloquer++;
        return;
    }

    while (!coupValide)
    {
        std::pair<int, int> coup = joueurCourant->ChoisirCoupOthello(coupsPossibles);

        if (std::find(coupsPossibles.begin(), coupsPossibles.end(), coup) != coupsPossibles.end())
        {
            grille->ChangeCellule(coup.first, coup.second, joueurCourant->getJeton());
            RetournerJetons(coup.first, coup.second, joueurCourant->getJeton());
            coupValide = true;
            bloquer = 0;
        }
        else
        {
            modeAffichage->AfficherErreur("Coup impossible.");
        }
    }
}

bool JeuOthello::PartieFinie() const
{
    return grille->EstRemplie() || bloquer == 2;
}

void JeuOthello::InitialiseJeu() const
{
    int centreX = grille->getNbLigne() / 2 - 1;
    int centreY = grille->getNbColonne() / 2 - 1;
    grille->ChangeCellule(centreX, centreY, Jeton::X);
    grille->ChangeCellule(centreX + 1, centreY, Jeton::O);
    grille->ChangeCellule(centreX, centreY + 1, Jeton::O);
    grille->ChangeCellule(centreX + 1, centreY + 1, Jeton::X);
    modeAffichage->AfficherGrille(grille);
}

void JeuOthello::AfficherResultat() const
{
    modeAffichage->AfficherMessage("--> Score : ");
    modeAffichage->AfficherMessage(joueur1->getInformations() + ": " + std::to_string(grille->CompteJetons(joueur1->getJeton())));
    modeAffichage->AfficherMessage(joueur2->getInformations() + ": " + std::to_string(grille->CompteJetons(joueur2->getJeton())));

    if (AGagne())
    {
        modeAffichage->AfficherMessage("Le gagnant est " + (DetermineGagnant() == joueur1->getJeton() ? joueur1->getInformations() : joueur2->getInformations()) + " !");
    }
    else
    {
        modeAffichage->AfficherMessage("Match Nul!");
    }
}

std::vector<std::pair<int, int>> JeuOthello::CoupsPossibles()
{
    std::vector<std::pair<int, int>> coupsPossibles;

    for (int x = 0; x < grille->getNbLigne(); ++x)
    {
        for (int y = 0; y < grille->getNbColonne(); ++y)
        {
            if (EstCoupValide(x, y, joueurCourant->getJeton()))
            {
                coupsPossibles.emplace_back(x, y);
            }
        }
    }

    return coupsPossibles;
}

bool JeuOthello::AGagne() const
{
    Jeton gagnant = DetermineGagnant();

    return gagnant == joueur1->getJeton() || gagnant == joueur2->getJeton();
}

void JeuOthello::RetournerJetons(const int x, const int y, Jeton jeton)
{
    for (int directionX = -1; directionX <= 1; ++directionX)
    {
        for (int directionY = -1; directionY <= 1; ++directionY)
        {
            if (directionX == 0 && directionY == 0)
                continue;
            if (PeutRetourner(x, y, directionX, directionY, jeton))
            {
                int ligne = x + directionX;
                int colonne = y + directionY;
                while (grille->GetCellule(ligne, colonne) != jeton)
                {
                    grille->ChangeCellule(ligne, colonne, jeton);
                    ligne += directionX;
                    colonne += directionY;
                }
            }
        }
    }
}

bool JeuOthello::PeutRetourner(int x, int y, int directionX, int directionY, Jeton jeton) const
{
    int ligne = x + directionX;
    int colonne = y + directionY;
    bool trouveAdversaire = false;

    while (ligne >= 0 && ligne < grille->getNbLigne() && colonne >= 0 && colonne < grille->getNbColonne())
    {
        Jeton jetonActuel = grille->GetCellule(ligne, colonne);

        if (jetonActuel == Jeton::Vide)
        {
            return false;
        }
        else if (jetonActuel == jeton)
        {
            return trouveAdversaire;
        }
        else
        {
            trouveAdversaire = true;
        }

        ligne += directionX;
        colonne += directionY;
    }

    return false;
}

bool JeuOthello::EstCoupValide(int x, int y, Jeton jeton) const
{
    if (x < 0 || x >= grille->getNbLigne() || y < 0 || y >= grille->getNbColonne() || grille->GetCellule(x, y) != Jeton::Vide)
    {
        return false;
    }

    for (int directionX = -1; directionX <= 1; ++directionX)
    {
        for (int directionY = -1; directionY <= 1; ++directionY)
        {
            if (directionX == 0 && directionY == 0)
            {
                continue;
            }
            if (PeutRetourner(x, y, directionX, directionY, jeton))
            {
                return true;
            }
        }
    }

    return false;
}

Jeton JeuOthello::DetermineGagnant() const
{
    int countNoir = grille->CompteJetons(Jeton::X);
    int countBlanc = grille->CompteJetons(Jeton::O);

    if (countNoir > countBlanc)
    {
        return Jeton::X;
    }
    else if (countBlanc > countNoir)
    {
        return Jeton::O;
    }
    else
    {
        return Jeton::Vide;
    }
}
