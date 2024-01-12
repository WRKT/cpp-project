#include "jeudames.h"
#include <vector>
#include <algorithm>
#include <iostream>

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
    bool coupJouable = false;

    while (!coupJouable) {
        auto pionsJouables = PionsJouables();
        modeAffichage->AfficherMessage("Tour de " + joueurCourant->getInformations());
        modeAffichage->AfficherMessage("Choisissez votre pion :");
        modeAffichage->AfficherCoupsPossibles(pionsJouables);

        std::pair<int, int> pionChoisi = joueurCourant->ChoisirCoupDames(pionsJouables);

        xPionSelectionne = pionChoisi.first;
        yPionSelectionne = pionChoisi.second;

        if (std::find(pionsJouables.begin(), pionsJouables.end(), pionChoisi) != pionsJouables.end()) {
            auto coupsPossibles = CoupsPossibles();

            modeAffichage->AfficherMessage("Coups possibles pour le pion choisi :");
            modeAffichage->AfficherCoupsPossibles(coupsPossibles);

            std::pair<int, int> coupChoisi = joueurCourant->ChoisirCoupDames(coupsPossibles);

            if (std::find(coupsPossibles.begin(), coupsPossibles.end(), coupChoisi) != coupsPossibles.end()) {
                DeplacerPiece(pionChoisi.first, pionChoisi.second, coupChoisi.first, coupChoisi.second);
                coupJouable = true;
            } else {
                modeAffichage->AfficherErreur("Coup impossible pour le pion choisi");
            }
        } else {
            modeAffichage->AfficherErreur("Pion choisi n'est pas valide");
        }
    }

    joueurCourant = (joueurCourant == joueur1) ? joueur2 : joueur1;

    modeAffichage->AfficherGrille(grille);
}

bool JeuDames::AGagne() const {

    return false;
}

bool JeuDames::PartieFinie() const {

    return false;
}

std::vector<std::pair<int, int>> JeuDames::PionsJouables() {
    std::vector<std::pair<int, int>> pionsJouables;
    for (int ligne = 0; ligne < grille->getNbLignes(); ++ligne) {
        for (int colonne = 0; colonne < grille->getNbColonnes(); ++colonne) {
            if (grille->GetCellule(ligne, colonne) == joueurCourant->getJeton()) {
                if (PeutDeplacerEnDiagonale(ligne, colonne, ligne - 1, colonne - 1) ||
                    PeutDeplacerEnDiagonale(ligne, colonne, ligne - 1, colonne + 1) ||
                    PeutDeplacerEnDiagonale(ligne, colonne, ligne + 1, colonne - 1) ||
                    PeutDeplacerEnDiagonale(ligne, colonne, ligne + 1, colonne + 1) ||
                    PeutCapturer(ligne, colonne, ligne + 1, colonne + 1)) {
                    pionsJouables.emplace_back(ligne, colonne);
                }
            }
        }
    }
    return pionsJouables;
}

std::vector<std::pair<int, int>> JeuDames::CoupsPossibles() {
    std::vector<std::pair<int, int>> coupsPossibles;

    // Vérifier les déplacements vers l'avant en diagonale d'une seule case
    if (PeutDeplacerEnDiagonale(xPionSelectionne, yPionSelectionne, xPionSelectionne - 1, yPionSelectionne - 1)) {
        coupsPossibles.emplace_back(xPionSelectionne - 1, yPionSelectionne - 1);
    }
    if (PeutDeplacerEnDiagonale(xPionSelectionne, yPionSelectionne, xPionSelectionne - 1, yPionSelectionne + 1)) {
        coupsPossibles.emplace_back(xPionSelectionne - 1, yPionSelectionne + 1);
    }

    // Vérifier les captures possibles
    AjouterCapturesPossibles(xPionSelectionne, yPionSelectionne, coupsPossibles);

    return coupsPossibles;
}



bool JeuDames::PeutDeplacerEnDiagonale(int xDepart, int yDepart, int xArrivee, int yArrivee) const {
    if (xArrivee < 0 || xArrivee >= grille->getNbLignes() || yArrivee < 0 || yArrivee >= grille->getNbColonnes()) {
        return false;
    }

    const Jeton jetonAdverse = (joueurCourant == joueur1) ? joueur2->getJeton() : joueur1->getJeton();

    if (grille->ACaseVide(xArrivee, yArrivee) &&
        ((xArrivee - xDepart == -1 && yArrivee - yDepart == -1) ||
         (xArrivee - xDepart == -1 && yArrivee - yDepart == 1) ||
         (xArrivee - xDepart == 1 && yArrivee - yDepart == -1) ||
         (xArrivee - xDepart == 1 && yArrivee - yDepart == 1))) {
        return true;
    } else if (grille->GetCellule((xDepart + xArrivee) / 2, (yDepart + yArrivee) / 2) == jetonAdverse &&
               std::abs(xArrivee - xDepart) == 2 &&
               std::abs(yArrivee - yDepart) == 2) {
        return true;
    }
    return false;
}


void JeuDames::AjouterCapturesPossibles(int x, int y, std::vector<std::pair<int, int>>& coupsPossibles) const {
    const Jeton jetonCourant = joueurCourant->getJeton();

    // Vérifier les captures possibles dans toutes les directions
    if (PeutCapturer(x, y, x - 1, y - 1)) {
        coupsPossibles.emplace_back(x - 2, y - 2);
    }
    if (PeutCapturer(x, y, x - 1, y + 1)) {
        coupsPossibles.emplace_back(x - 2, y + 2);
    }
    if (PeutCapturer(x, y, x + 1, y - 1)) {
        coupsPossibles.emplace_back(x + 2, y - 2);
    }
    if (PeutCapturer(x, y, x + 1, y + 1)) {
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

bool JeuDames::PeutCapturer(int x, int y, int xAdversaire, int yAdversaire) const {
    const Jeton jetonCourant = joueurCourant->getJeton();

    // Vérifier si la capture est possible dans une direction spécifique
    return (xAdversaire >= 0 && xAdversaire < grille->getNbLignes() &&
            yAdversaire >= 0 && yAdversaire < grille->getNbColonnes() &&
            grille->ACaseVide(xAdversaire, yAdversaire) &&
            grille->GetCellule(xAdversaire, yAdversaire) != jetonCourant &&
            grille->ACaseVide(x - (x - xAdversaire) / 2, y - (y - yAdversaire) / 2) &&
            grille->GetCellule(x - (x - xAdversaire) / 2, y - (y - yAdversaire) / 2) == Jeton::Vide);
}
