#include "jeudames.h"
#include <vector>
#include <algorithm>

JeuDames::JeuDames(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage){}

void JeuDames::Jouer() {
    modeAffichage->AfficherGrille(grille);
    while (!PartieFinie()) {
        Tour();
    }
    AfficherResultat();
}

void JeuDames::Tour() {
    auto coupsPossibles = CoupsPossibles();
    bool coupValide = false;
    while (!coupValide) {
        modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations());
        std::pair<int, int> coup = joueurCourant->ChoisirCoupDames(coupsPossibles);
        if (std::find(coupsPossibles.begin(), coupsPossibles.end(), coup) != coupsPossibles.end()) {
            grille->ChangeCellule(coup.first, coup.second, joueurCourant->getJeton());
            coupValide = true;
        }
        else {
            modeAffichage->AfficherErreur("Coups Impossible");
        }
    }
    joueurCourant->getJeton() == joueur1->getJeton() ? joueurCourant = joueur2 : joueurCourant = joueur1;
    modeAffichage->AfficherGrille(grille);
}

bool JeuDames::AGagne() const {
    return false;
}

bool JeuDames::PartieFinie() const {
    return false;
}

std::vector<std::pair<int, int>> JeuDames::CoupsPossibles() {
    std::vector<std::pair<int, int>> coupsPossibles;
    for (int colonne = 0; colonne < grille->getNbColonnes(); ++colonne) {
        for (int ligne = grille->getNbLignes() - 1; ligne >= 0; --ligne) {
            if (grille->GetCellule(ligne, colonne) == Jeton::Vide) {
                coupsPossibles.emplace_back(ligne, colonne);
                break;
            }
        }
    }
    return coupsPossibles;
}

void JeuDames::AfficherResultat() const {
    modeAffichage->AfficherMessage("Match nul !");
}

