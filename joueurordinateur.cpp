#include "joueurordinateur.h"
#include <chrono>

JoueurOrdinateur::JoueurOrdinateur(char jeton) : jeton(jeton), generateur(std::chrono::system_clock::now().time_since_epoch().count()) {}

std::string JoueurOrdinateur::ObtenirNom() const {
    return nom;
}

char JoueurOrdinateur::getJeton() const {
    return jeton;
}

void JoueurOrdinateur::jouerJeton(IGrille& grille) {
    auto [x, y] = choisirCoup(grille);
    grille.placerPion(x, y, jeton);
}

std::pair<int, int> JoueurOrdinateur::choisirCoup(IGrille& grille) {
    std::uniform_int_distribution<int> distribution(0, grille.GetTaille() - 1);
    int x, y;

    do {
        x = distribution(generateur);
        y = distribution(generateur);
    } while (!grille.estCoupValide(x, y, jeton));

    return {x, y};
}
