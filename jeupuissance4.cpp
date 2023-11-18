#include "jeupuissance4.h"

#include "jeuPuissance4.h"
#include <iostream>

JeuPuissance4::JeuPuissance4(IGrille& g, IJoueur& j1, IJoueur& j2)
    : grille(g), joueur1(j1), joueur2(j2), joueurCourantPion(joueur1.getJeton()) {}

void JeuPuissance4::jouer() {
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

bool JeuPuissance4::estFinDuJeu() const {
    // Implémentez la logique pour vérifier si le jeu est fini
    return false; // Placeholder
}

bool JeuPuissance4::aGagne(char pion) const {
    // Implémentez la logique pour vérifier si un joueur a gagné
    return false; // Placeholder
}

bool JeuPuissance4::colonneValide(int colonne) const {
    // Implémentez la logique pour vérifier si une colonne est valide pour un coup
    return false; // Placeholder
}
