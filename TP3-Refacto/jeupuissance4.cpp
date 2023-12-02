#include "jeupuissance4.h"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "inputconsole.h"

JeuPuissance4::JeuPuissance4(std::shared_ptr<IGrille> grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage) {}

void JeuPuissance4::Jouer() {

    modeAffichage->AfficherGrille(grille);

    while (!PartieFinie()) {
        Tour();
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

void JeuPuissance4::Tour() {
    auto coupsPossibles = CoupsPossibles();
    if (joueurCourant->estHumain()) {
        bool coupValide = false;
        int colonne;
        while (!coupValide) {
            colonne = InputConsole::demanderCoupPuissance4(grille->getNbColonne());

            for (auto& coup : coupsPossibles) {
                if (coup.second == colonne) {
                    grille->ChangeCellule(coup.first, colonne, joueurCourant->getJeton());
                    coupValide = true;
                    break;
                }
            }
            if (!coupValide) {
                modeAffichage->AfficherErreur ("Coup invalide.");
            }
        }
    } else {
        if (!coupsPossibles.empty()) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(0, coupsPossibles.size() - 1);

            auto coupChoisi = coupsPossibles[distrib(gen)];
            grille->ChangeCellule(coupChoisi.first, coupChoisi.second, joueurCourant->getJeton());        }
    }
}

std::vector<std::pair<int, int>> JeuPuissance4::CoupsPossibles() {
    std::vector<std::pair<int, int>> coupsPossibles;
    for (int colonne = 0; colonne < grille->getNbColonne(); ++colonne) {
        for (int ligne = grille->getNbLigne() - 1; ligne >= 0; --ligne) {
            if (grille->GetCellule(ligne, colonne) == Jeton::Vide) {
                coupsPossibles.emplace_back(ligne, colonne);
                break;
            }
        }
    }
    return coupsPossibles;
}


bool JeuPuissance4::PartieFinie() const {
    return AGagne() || grille->EstRemplie();
}

bool JeuPuissance4::AGagne() const {
    return VerifieLignes() || VerifieColonnes() || VerifieDiagonales();
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
