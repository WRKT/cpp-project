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










