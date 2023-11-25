#include "jeupuissance4.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

JeuPuissance4::JeuPuissance4(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage) {}

void JeuPuissance4::Jouer() {

    modeAffichage->AfficherGrille(grille);

    while (!PartieFinie()) {
        if (joueurCourant->estHumain()) {
            TourHumain();
        } else {
            TourOrdi();
        }

        if (AGagne()) {
            modeAffichage->AfficherGrille(grille);
            modeAffichage->AfficherMessage ("Le joueur " + joueurCourant->getNom() + " a gagné !");
                return;
        }

        if (joueurCourant->getJeton() == joueur1->getJeton()) {
            joueurCourant = joueur2;
        } else {
            joueurCourant = joueur1;
        }

        modeAffichage->AfficherGrille(grille);
    }

    modeAffichage->AfficherMessage("Match nul !");
}

void JeuPuissance4::TourHumain()
{
    int colonne;
    bool coupValide = false;

    while (!coupValide) {
        modeAffichage->AfficherMessage (joueurCourant->getNom() + " (" + static_cast<char>(joueurCourant->getJeton()) + "), choisissez une colonne (1 - " + std::to_string(grille->getNbColonne()) + ") : ", 0);
        std::cin >> colonne;

        while (std::cin.fail() || colonne < 1 || colonne > grille->getNbColonne()) {
            modeAffichage->AfficherErreur ("Entrer un nombre entre 1 et " + std::to_string(grille->getNbColonne()) + ": ");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> colonne;
        }

        if (colonne > 0 && colonne <= grille->getNbColonne() && grille->GetCellule(0, colonne - 1) == Jeton::Vide) {
            PlacerJeton(colonne - 1, joueurCourant->getJeton());
            coupValide = true;
        } else {
            modeAffichage->AfficherErreur("\n");
        }
    }
}

void JeuPuissance4::TourOrdi()
{
    std::vector<int> colonnesPossibles;
    for (int i = 0; i < grille->getNbColonne(); ++i) {
        if (grille->GetCellule(0, i) == Jeton::Vide) {
            colonnesPossibles.push_back(i);
        }
    }

    if (!colonnesPossibles.empty()) {
        std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
        std::uniform_int_distribution<int> dist(0, colonnesPossibles.size() - 1);
        int colonneChoisie = colonnesPossibles[dist(rng)];

        modeAffichage->AfficherMessage(joueurCourant->getNom() + " (" + static_cast<char>(joueurCourant->getJeton()) + ") a joué ! ");

        PlacerJeton(colonneChoisie, joueurCourant->getJeton());
    }
}

bool JeuPuissance4::PartieFinie() const {
    return AGagne() || grille->EstRemplie();
}

bool JeuPuissance4::AGagne() const {
    return VerifieLignes() || VerifieColonnes() || VerifieDiagonales();
}

void JeuPuissance4::PlacerJeton(int colonne, Jeton jeton)
{
    int ligneDisponible = grille->getNbLigne() - 1;

    while (ligneDisponible >= 0 && grille->GetCellule(ligneDisponible, colonne) != Jeton::Vide)
    {
        ligneDisponible--;
    }

    if (ligneDisponible >= 0)
    {
        grille->ChangeCellule(ligneDisponible, colonne, jeton);
    }

}

bool JeuPuissance4::VerifieLignes() const {
    for (int i = 0; i < grille->getNbLigne(); ++i) {
            for (int j = 0; j < 4; ++j) {
            Jeton premierJeton = grille->GetCellule(i, j);
            if (premierJeton != Jeton::Vide &&
                premierJeton == grille->GetCellule(i, j + 1) &&
                premierJeton == grille->GetCellule(i, j + 2) &&
                premierJeton == grille->GetCellule(i, j + 3)) {
                return true;
            }
            }
    }
    return false;
}

bool JeuPuissance4::VerifieColonnes() const {
    for (int j = 0; j < grille->getNbColonne(); ++j) {
            for (int i = 0; i < grille->getNbLigne() - 3; ++i) {
            Jeton premierJeton = grille->GetCellule(i, j);
            if (premierJeton != Jeton::Vide &&
                premierJeton == grille->GetCellule(i + 1, j) &&
                premierJeton == grille->GetCellule(i + 2, j) &&
                premierJeton == grille->GetCellule(i + 3, j)) {
                return true;
            }
        }
    }
    return false;
}

bool JeuPuissance4::VerifieDiagonales() const {
    for (int i = 0; i < grille->getNbLigne() - 3; ++i) {
            for (int j = 0; j < 4; ++j) {
            Jeton premierJeton = grille->GetCellule(i, j);
            if (premierJeton != Jeton::Vide &&
                premierJeton == grille->GetCellule(i + 1, j + 1) &&
                premierJeton == grille->GetCellule(i + 2, j + 2) &&
                premierJeton == grille->GetCellule(i + 3, j + 3)) {
                return true;
            }
            }
    }
    for (int i = 3; i < grille->getNbLigne(); ++i) {
            for (int j = 0; j < 4; ++j) {
            Jeton premierJeton = grille->GetCellule(i, j);
            if (premierJeton != Jeton::Vide &&
                premierJeton == grille->GetCellule(i - 1, j + 1) &&
                premierJeton == grille->GetCellule(i - 2, j + 2) &&
                premierJeton == grille->GetCellule(i - 3, j + 3)) {
                return true;
            }
            }
    }

    return false;
}
