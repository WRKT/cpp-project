#include "jeumorpion.h"
#include <iostream>

JeuMorpion::JeuMorpion(IGrille& grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2): grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1) {}

void JeuMorpion::TourHumain() {
    int x, y;
    bool coupValide = false;
    while (!coupValide) {
        std::cout << joueurCourant->getNom()<< " (" << static_cast<char>(joueurCourant->getJeton()) << "), entrez la ligne (1 - " << grille.getNbLigne() << ") : ";
        std::cin >> x;
        std::cout << joueurCourant->getNom() << " (" << static_cast<char>(joueurCourant->getJeton()) << "), entrez la colonne (1 - " << grille.getNbColonne() << ") : ";
        std::cin >> y;

        if (grille.ACaseVide(x-1, y-1)) {
            PlacerJeton(x, y, joueurCourant->getJeton());
            coupValide = true;
        } else {
            std::cout << "Coup invalide, réessayez.\n";
        }
    }
}

void JeuMorpion::TourOrdi() {

}

bool JeuMorpion::AGagne() const {

    return false;
}

bool JeuMorpion::PartieFinie() const {
    return AGagne() || grille.EstRemplie();
}

void JeuMorpion::PlacerJeton(int x, int y, Jeton jeton) {
    grille.ChangeCellule(x-1, y-1, jeton);
};

void JeuMorpion::Jouer() {

    grille.AfficherGrille();

    while (!PartieFinie()) {
        if (joueurCourant->estHumain()) {
            TourHumain();
        } else {
            TourOrdi();
        }

        if (joueurCourant->getJeton() == joueur1->getJeton()) {
            joueurCourant = joueur2;

        } else {
           joueurCourant = joueur1;
        }

        grille.AfficherGrille();
    }

    if (AGagne()) {
        std::cout << "Le joueur " << joueurCourant->getNom() << " a gagné !" << std::endl;
    } else {
        std::cout << "Match nul !" << std::endl;
    }
}
