#include "jeudames.h"
#include <vector>
#include <algorithm>

JeuDames::JeuDames(std::shared_ptr<AGrille> grille, std::shared_ptr<AJoueur> j1, std::shared_ptr<AJoueur> j2, std::shared_ptr<IAffichage> modeAffichage)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1), modeAffichage(modeAffichage){}

void JeuDames::Jouer() {

    grille->InitialiserGrilleDame();
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

    for (int ligne = 0; ligne < grille->getNbLignes(); ++ligne) {
        for (int colonne = 0; colonne < grille->getNbColonnes(); ++colonne) {
            if (grille->GetCellule(ligne, colonne) == joueurCourant->getJeton()) {

                if (PeutDeplacerEnDiagonale(ligne, colonne, ligne - 1, colonne - 1)) {
                    coupsPossibles.emplace_back(ligne - 1, colonne - 1);
                }
                if (PeutDeplacerEnDiagonale(ligne, colonne, ligne - 1, colonne + 1)) {
                    coupsPossibles.emplace_back(ligne - 1, colonne + 1);
                }
                if (PeutDeplacerEnDiagonale(ligne, colonne, ligne + 1, colonne - 1)) {
                    coupsPossibles.emplace_back(ligne + 1, colonne - 1);
                }
                if (PeutDeplacerEnDiagonale(ligne, colonne, ligne + 1, colonne + 1)) {
                    coupsPossibles.emplace_back(ligne + 1, colonne + 1);
                }
                AjouterCapturesPossibles(ligne, colonne, coupsPossibles);
            }
        }
    }

    return coupsPossibles;
}


bool JeuDames::PeutDeplacerEnDiagonale(int xDepart, int yDepart, int xArrivee, int yArrivee) const {
    return grille->ACaseVide(xArrivee, yArrivee) &&
           grille->GetCellule(xArrivee, yArrivee) == Jeton::Vide &&
           std::abs(xArrivee - xDepart) == 1 &&
           std::abs(yArrivee - yDepart) == 1;
}

void JeuDames::AjouterCapturesPossibles(int x, int y, std::vector<std::pair<int, int>>& coupsPossibles) const {
    const Jeton jetonCourant = joueurCourant->getJeton();

    if (grille->ACaseVide(x - 1, y - 1) && grille->GetCellule(x - 1, y - 1) != jetonCourant &&
        grille->ACaseVide(x - 2, y - 2) && grille->GetCellule(x - 2, y - 2) == Jeton::Vide) {
        coupsPossibles.emplace_back(x - 2, y - 2);
    }

    if (grille->ACaseVide(x - 1, y + 1) && grille->GetCellule(x - 1, y + 1) != jetonCourant &&
        grille->ACaseVide(x - 2, y + 2) && grille->GetCellule(x - 2, y + 2) == Jeton::Vide) {
        coupsPossibles.emplace_back(x - 2, y + 2);
    }

    if (grille->ACaseVide(x + 1, y - 1) && grille->GetCellule(x + 1, y - 1) != jetonCourant &&
        grille->ACaseVide(x + 2, y - 2) && grille->GetCellule(x + 2, y - 2) == Jeton::Vide) {
        coupsPossibles.emplace_back(x + 2, y - 2);
    }

    if (grille->ACaseVide(x + 1, y + 1) && grille->GetCellule(x + 1, y + 1) != jetonCourant &&
        grille->ACaseVide(x + 2, y + 2) && grille->GetCellule(x + 2, y + 2) == Jeton::Vide) {
        coupsPossibles.emplace_back(x + 2, y + 2);
    }
}

void JeuDames::AfficherResultat() const {
    modeAffichage->AfficherMessage("Match nul !");
}

void JeuDames::DeplacerPiece(int xDepart, int yDepart, int xArrivee, int yArrivee) {
    grille->ChangeCellule(xArrivee, yArrivee, joueurCourant->getJeton());
    grille->ChangeCellule(xDepart, yDepart, Jeton::Vide);
}

bool JeuDames::EstDeplacementValide(int xDepart, int yDepart, int xArrivee, int yArrivee) const {
    if (grille->GetCellule(xArrivee, yArrivee) != Jeton::Vide) {
        return false;
    }

    int deltaX = std::abs(xArrivee - xDepart);
    int deltaY = std::abs(yArrivee - yDepart);
    if (deltaX != 1 || deltaY != 1) {
        return false;
    }

    return true;
}

void JeuDames::CapturerPiece(int xDepart, int yDepart, int xArrivee, int yArrivee)
{
    if (EstDeplacementValide(xDepart, yDepart, xArrivee, yArrivee)) {
        grille->ChangeCellule(xArrivee, yArrivee, joueurCourant->getJeton());
        int xCapture = (xDepart + xArrivee) / 2;
        int yCapture = (yDepart + yArrivee) / 2;
        grille->ChangeCellule(xCapture, yCapture, Jeton::Vide);
        positionsJoueurs[joueurCourant] = {xArrivee, yArrivee};
    }
}

bool JeuDames::PeutCapturer(int x, int y) const
{
    const Jeton jetonCourant = joueurCourant->getJeton();

    return (grille->ACaseVide(x, y) &&
            ((grille->ACaseVide(x - 2, y - 2) && grille->GetCellule(x - 1, y - 1) != jetonCourant && grille->GetCellule(x - 2, y - 2) == Jeton::Vide) ||
             (grille->ACaseVide(x - 2, y + 2) && grille->GetCellule(x - 1, y + 1) != jetonCourant && grille->GetCellule(x - 2, y + 2) == Jeton::Vide) ||
             (grille->ACaseVide(x + 2, y - 2) && grille->GetCellule(x + 1, y - 1) != jetonCourant && grille->GetCellule(x + 2, y - 2) == Jeton::Vide) ||
             (grille->ACaseVide(x + 2, y + 2) && grille->GetCellule(x + 1, y + 1) != jetonCourant && grille->GetCellule(x + 2, y + 2) == Jeton::Vide)));
}

