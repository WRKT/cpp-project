#include "jeumorpion.h"
#include <iostream>

JeuMorpion::JeuMorpion(IGrille& g, IJoueur& j1, IJoueur& j2)
    : grille(g), joueur1(j1), joueur2(j2), joueurCourantPion(joueur1.getJeton()) {}

void JeuMorpion::jouer() {
    while (!estFinDuJeu()) {
        grille.AfficherGrille();
        std::cout << "Tour du joueur " << joueurCourantPion << std::endl;

        if (joueurCourantPion == joueur1.getJeton()) {
            joueur1.jouerJeton(grille);
            joueurCourantPion = joueur2.getJeton();
        } else {
            joueur2.jouerJeton(grille);
            joueurCourantPion = joueur1.getJeton();
        }

        if (aGagne(joueur1.getJeton()) || aGagne(joueur2.getJeton())) {
            grille.AfficherGrille();
            std::cout << "Le joueur " << joueurCourantPion << " a gagné !" << std::endl;
                return;
        }
    }

    std::cout << "Match nul !" << std::endl;
}

bool JeuMorpion::estFinDuJeu() const {
    // Implémentez la logique pour vérifier si le jeu est fini
    return false;
}

bool JeuMorpion::aGagne(char pion) const {
    // Implémentez la logique pour vérifier si un joueur a gagné
    return false;
}
