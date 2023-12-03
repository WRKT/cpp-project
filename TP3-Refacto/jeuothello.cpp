#include "jeuothello.h"
#include "inputconsole.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>
#include <limits>

JeuOthello::JeuOthello(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
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

    Jeton gagnant = DetermineGagnant();

    if (gagnant != Jeton::Vide)
    {
        modeAffichage->AfficherMessage ("Le gagnant est " + (gagnant == joueur1->getJeton()? joueur1->getNom() : joueur2->getNom()) + "!");
    }
    else
    {
        modeAffichage->AfficherMessage("La partie se termine par une égalité.");
    }
}

void JeuOthello::Tour()
{
    auto coupsPossibles = CoupsPossibles();
    bool coupValide = false;

    // afficher les coups possibles
    modeAffichage->AfficherMessage("Coups possibles pour " + joueurCourant->getNom() + " :");
    for (auto coup : coupsPossibles)
    {
        modeAffichage->AfficherMessage("(" + std::to_string(coup.first + 1) + "," + std::to_string(coup.second + 1) + ") ");
    }

    if (coupsPossibles.empty())
    {
        modeAffichage->AfficherMessage("Aucun coup possible pour " + joueurCourant->getNom() + ". Passage au joueur suivant.");
        return;
    }

    else if (joueurCourant->estHumain())
    {
        while (!coupValide)
        {
            std::pair<int, int> coup = InputConsole::demanderCoupOthello(grille->getNbLigne());

            if (std::find(coupsPossibles.begin(), coupsPossibles.end(), coup) != coupsPossibles.end())
            {
                grille->ChangeCellule(coup.first, coup.second, joueurCourant->getJeton());
                RetournerJetons(coup.first, coup.second, joueurCourant->getJeton());
                coupValide = true;
            }
            else
            {
                modeAffichage->AfficherErreur("Coup impossible.");
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
        RetournerJetons(coupChoisi.first, coupChoisi.second, joueurCourant->getJeton());

        modeAffichage->AfficherMessage(joueurCourant->getNom() + "(" + static_cast<char>(joueurCourant->getJeton ()) + ") a joué.");
    }
}

bool JeuOthello::PartieFinie() const
{
    return grille->EstRemplie();
}


void JeuOthello::InitialiseJeu() const {
    int centreX = grille->getNbLigne() / 2 - 1;
    int centreY = grille->getNbColonne() / 2 - 1;
    grille->ChangeCellule(centreX, centreY, Jeton::X);
    grille->ChangeCellule(centreX + 1, centreY, Jeton::O);
    grille->ChangeCellule(centreX, centreY + 1, Jeton::O);
    grille->ChangeCellule(centreX + 1, centreY + 1, Jeton::X);
    modeAffichage->AfficherGrille(grille);
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

bool JeuOthello::EstDirectionValide(int x, int y, int dx, int dy, Jeton jeton) const
{
    int l = x + dx;
    int c = y + dy;
    bool trouveAdversaire = false;

    while (l >= 0 && l < grille->getNbLigne() && c >= 0 && c < grille->getNbColonne())
    {
        if (grille->GetCellule(l, c) == Jeton::Vide)
        {
            return false;
        }
        else if (grille->GetCellule(l, c) == jeton)
        {
            return trouveAdversaire;
        }
        else
        {
            trouveAdversaire = true;
        }

        l += dx;
        c += dy;
    }

    return false;
}


bool JeuOthello::AGagne() const {
    return false;
}


void JeuOthello::RetournerJetons(const int x, const int y, Jeton jeton)
{
    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            if (dx == 0 && dy == 0)
                continue;
            if (PeutRetourner(x, y, dx, dy, jeton))
            {
                int l = x + dx;
                int c = y + dy;
                while (grille->GetCellule(l, c) != jeton)
                {
                    grille->ChangeCellule(l, c, jeton);
                    l += dx;
                    c += dy;
                }
            }
        }
    }
}

bool JeuOthello::PeutRetourner(int x, int y, int dx, int dy, Jeton jeton) const
{
    int l = x + dx;
    int c = y + dy;
    bool trouveAdversaire = false;

    while (l >= 0 && l < grille->getNbLigne() && c >= 0 && c < grille->getNbColonne())
    {
        Jeton jetonActuel = grille->GetCellule(l, c);

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

        l += dx;
        c += dy;
    }

    return false;
}

bool JeuOthello::EstCoupValide(int x, int y, Jeton jeton) const
{
    if (x < 0 || x >= grille->getNbLigne() || y < 0 || y >= grille->getNbColonne() || grille->GetCellule(x, y) != Jeton::Vide)
    {
        return false;
    }

    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            if (dx == 0 && dy == 0)
            {
                continue;
            }
            if (EstDirectionValide(x, y, dx, dy, jeton))
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
