#include "jeumorpion.h"
#include <iostream>

JeuMorpion::JeuMorpion(IGrille& grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2): grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1) {}

void JeuMorpion::TourHumain() {
    int x, y;
    bool coupValide = false;
    while (!coupValide) {
        std::cout << joueurCourant->getNom()<< " entrez la ligne (1 - " << grille.getNbLigne() << ") : ";
        std::cin >> x;
        std::cout << joueurCourant->getNom() << " Entrez la colonne (1 - " << grille.getNbColonne() << ") : ";
        std::cin >> y;

        // Vérifier si le coup est valide (la case est libre)
        if (grille.ACaseVide(x-1, y-1)) {
            PlacerJeton(x, y, joueurCourant->getJeton());
            coupValide = true;
        } else {
            std::cout << "Coup invalide, réessayez.\n";
        }
    }
}

void JeuMorpion::TourOrdi() {
    // Logique pour gérer le tour de l'ordinateur
    // Implémenter l'IA ou la logique de décision pour l'ordinateur
}

bool JeuMorpion::AGagne() const {
    // Vérifie si l'un des joueurs a gagné
    // Implémenter la logique pour vérifier les conditions de victoire
    return false; // Retourner vrai si un joueur a gagné
}

bool JeuMorpion::PartieFinie() const {
    return AGagne() || grille.EstRemplie();
}

void JeuMorpion::PlacerJeton(int x, int y, Jeton jeton) {
    grille.ChangeCellule(x-1, y-1, jeton);
};

void JeuMorpion::Jouer() {

    while (!PartieFinie()) {
        if (joueurCourant->estHumain()) {
            TourHumain();
        } else {
            TourOrdi();
        }
        if (joueurCourant->getJeton() == joueur1->getJeton()) {
            joueurCourant = joueur2;
            std::cout << "Le joueur 2 " << std::endl;

        } else {
            joueurCourant = joueur1;
            std::cout << "Le joueur 1 " << std::endl;

        }

        grille.AfficherGrille();
    }

    if (AGagne()) {
        std::cout << "Le joueur " << joueurCourant->getNom() << " a gagné !" << std::endl;
    } else {
        std::cout << "Match nul !" << std::endl;
    }
}
