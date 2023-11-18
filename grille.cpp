#include "grille.h"
#include <iostream>

Grille::Grille(int nbLignes, int nbColonnes)
    : nbLignes(nbLignes), nbColonnes(nbColonnes), table(nbLignes, std::vector<Jeton>(nbColonnes, Jeton::Vide)) {}

void Grille::InitialiserGrille() {
    for (auto& ligne : table) {
        std::fill(ligne.begin(), ligne.end(), Jeton::Vide);
    }
}

int Grille::getNbColonne() const {
    return nbColonnes;
}

int Grille::getNbLigne() const {
    return nbLignes;
}

void Grille::AfficherGrille() const {
    std::cout << std::endl;
    for (int i = 0; i < nbLignes; i++)
    {
        for(int j = 0; j < nbColonnes; j++)
        {
            if (j == 0)
            {
                std::cout << "| " << static_cast<char>(table[i][j]) <<  " | ";
            }
            else
            {
                std::cout << static_cast<char>(table[i][j]) << " | ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};


bool Grille::ACaseVide(int x, int y) const {
    return table[x][y] == Jeton::Vide;
}

void Grille::ChangeCellule(int x, int y, Jeton jeton) {
    table[x][y] = jeton;
}

bool Grille::EstRemplie() const {
    for (int i = 0; i < getNbColonne(); ++i) {
        for (int j = 0; j < getNbLigne(); ++j) {
            if (ACaseVide(i, j)) {
                return false;
            }
        }
    }
    return true;
}









