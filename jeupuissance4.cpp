#include "jeupuissance4.h"
#include <iostream>

JeuPuissance4::JeuPuissance4(IGrille& grille, std::shared_ptr<IJoueur> j1, std::shared_ptr<IJoueur> j2)
    : grille(grille), joueur1(j1), joueur2(j2), joueurCourant(j1) {}

void JeuPuissance4::Jouer() {
 //
}

bool JeuPuissance4::PartieFinie() const {
    // Implémentez la logique pour vérifier si le jeu est fini
    return false; // Placeholder
}

bool JeuPuissance4::AGagne() const {
    // Implémentez la logique pour vérifier si un joueur a gagné
    return false; // Placeholder
}

bool JeuPuissance4::colonneValide(int colonne) const {
    // Implémentez la logique pour vérifier si une colonne est valide pour un coup
    return false; // Placeholder
}
