#include "grille.h"
#include <iostream>

Grille::Grille(int nbLignes, int nbColonnes)
    : nbLignes(nbLignes), nbColonnes(nbColonnes), table(nbLignes, std::vector<char>(nbColonnes, '-')) {}

void Grille::InitialiserGrille() {
    for (auto& ligne : table) {
        std::fill(ligne.begin(), ligne.end(), '-');
    }
}

void Grille::AfficherGrille() const {
    for (const auto& ligne : table) {
        for (char cell : ligne) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

bool Grille::placerPion(int x, int y, char jeton) {
    if (x >= 0 && x < nbLignes && y >= 0 && y < nbColonnes && table[x][y] == '.') {
        table[x][y] = 'X' ? 'X' : 'O';
        return true;
    }
    return false;
}

int Grille::getTaille() const {
    return nbLignes * nbColonnes;
}

bool Grille::estCoupValide(int x, int y, char jeton) const {
    // Vérifier si les coordonnées sont dans les limites de la grille
    if (x < 0 || x >= nbLignes || y < 0 || y >= nbColonnes) {
        return false;
    }

    // Vérifier si la case est déjà occupée
    return table[x][y] == '.';
}










