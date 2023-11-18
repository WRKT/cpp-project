#include "jeumorpion.h"
#include <iostream>

JeuMorpion::JeuMorpion(IGrille& g, IJoueur& j1, IJoueur& j2)
    : grille(g), joueur1(j1), joueur2(j2), joueurCourantPion(joueur1.getJeton()) {}

void JeuMorpion::jouer() {

    while (!gameOver) {
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

bool JeuMorpion::aGagne(char pion) const {

    return grille.estColonne(pion) || grille.estLigne(pion) || grille.estDiagonale(pion);
}

bool JeuMorpion::estEgalite() const
{
    return false;
}
