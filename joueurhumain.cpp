#include "JoueurHumain.h"
#include <iostream>
#include <memory>

JoueurHumain::JoueurHumain(const std::string& nom, char jeton)
    : nom(nom), jeton(jeton) {}

std::string JoueurHumain::ObtenirNom() const {
    return nom;
}

char JoueurHumain::getJeton() const {
    return jeton;
}

void JoueurHumain::jouerJeton(IGrille& grille) {
    int x, y;
    bool coupValide = false;

    while (!coupValide) {
        std::cout << "Joueur " << (jeton == 'X' ? 'X' : 'O') << ", entrez votre coup (ligne et colonne): ";
        std::cin >> x >> y;

        if (grille.estCoupValide(x, y, jeton)) {
            grille.placerPion(x, y, jeton);
            coupValide = true;
        } else {
            std::cout << "Coup invalide, veuillez réessayer." << std::endl;
        }
    }
}
