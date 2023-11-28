#include "jeuothello.h"
#include "InterfaceUtilisateur.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <limits>

JeuOthello::JeuOthello(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2,  std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage) {}

void JeuOthello::Jouer()
{
    int centreX = grille->getNbLigne() / 2 - 1;
    int centreY = grille->getNbColonne() / 2 - 1;
    grille->ChangeCellule(centreX, centreY, Jeton::X);
    grille->ChangeCellule(centreX + 1, centreY, Jeton::O);
    grille->ChangeCellule(centreX, centreY + 1, Jeton::O);
    grille->ChangeCellule(centreX + 1, centreY + 1, Jeton::X);
    grille->AfficherGrille();

    while (!PartieFinie())
    {
        Tour();
        joueurCourant->getJeton() == joueur1->getJeton() ? joueurCourant = joueur2 : joueurCourant = joueur1;
        grille->AfficherGrille();
    }

    Jeton gagnant = DetermineGagnant();
    if (gagnant != Jeton::Vide) {
        std::cout << "Le gagnant est " << (gagnant == Jeton::X ? "Noir" : "Blanc") << "!" << std::endl;
    } else {
        std::cout << "La partie se termine par une égalité." << std::endl;
    }
}

void JeuOthello::Tour()
{
    auto coupsPossibles = CoupsPossibles();
    bool coupValide = false;

    if (coupsPossibles.empty()) {
        joueurCourant = (joueurCourant == joueur1) ? joueur2 : joueur1;
        modeAffichage->AfficherMessage("Aucun coup possible pour " + joueurCourant->getNom() + ". Passage au joueur suivant.");
        return;
    }

    if (joueurCourant->estHumain()) {
        while (!coupValide) {
            std::cout << joueurCourant->getNom() << " (" << static_cast<char>(joueurCourant->getJeton()) << "), entrez la ligne (1 - " << grille->getNbLigne() << ") : ";
            std::pair<int, int> coup = InterfaceUtilisateur::demanderCoupOthello(grille->getNbLigne());
            if (std::find(coupsPossibles.begin(), coupsPossibles.end(), coup) != coupsPossibles.end()) {
                grille->ChangeCellule(coup.first, coup.second, joueurCourant->getJeton());
                coupValide = true;
            } else {
                modeAffichage->AfficherErreur("Coup impossible.");
            }
        }
    } else {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, coupsPossibles.size() - 1);
        int indiceCoupChoisi = distrib(gen);
        std::pair<int, int> coupChoisi = coupsPossibles[indiceCoupChoisi];
        grille->ChangeCellule(coupChoisi.first, coupChoisi.second, joueurCourant->getJeton());
        modeAffichage->AfficherMessage(joueurCourant->getNom() + " a joué.");
    }
}


bool JeuOthello::AGagne() const
{
    return VerifiePions();
}

bool JeuOthello::PartieFinie() const
{
    return grille->EstRemplie();
}


std::vector<std::pair<int, int>> JeuOthello::CoupsPossibles() {
    std::vector<std::pair<int, int>> coupsPossibles;

    for (int x = 0; x < grille->getNbLigne(); ++x) {
        for (int y = 0; y < grille->getNbColonne(); ++y) {
            if (EstCoupValide(x, y, joueurCourant->getJeton())) {
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



bool JeuOthello::VerifiePions() const
{
    int countNoir = 0;
    int countBlanc = 0;

    for (int i = 0; i < grille->getNbLigne(); ++i)
    {
        for (int j = 0; j < grille->getNbColonne(); ++j)
        {
            if (grille->GetCellule(i, j) == Jeton::X)
            {
                countNoir++;
            }
            else if (grille->GetCellule(i, j) == Jeton::O)
            {
                countBlanc++;
            }
        }
    }

    if (countNoir > countBlanc)
    {
        return true;
    }
    else if (countBlanc > countNoir)
    {
        return true;
    }
    else
    {
        return false;
    }
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

int JeuOthello::ComptePions(Jeton jeton) const
{
    int count = 0;
    for (int i = 0; i < grille->getNbLigne(); ++i)
    {
        for (int j = 0; j < grille->getNbColonne(); ++j)
        {
            if (grille->GetCellule(i, j) == jeton)
            {
                count++;
            }
        }
    }
    return count;
}

