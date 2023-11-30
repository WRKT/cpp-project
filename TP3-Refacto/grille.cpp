#include "grille.h"
#include <iostream>

void Grille::InitialiserGrille() {
    for (auto& ligne : table) {
        std::fill(ligne.begin(), ligne.end(), Jeton::Vide);
    }
}

int Grille::getNbColonne() const {
    return nbColonnes;
}

Jeton Grille::GetCellule(const int x, const int y) const
{
    return table[x][y];
}

void Grille::SetCellule(int x, int y, Jeton valeur)
{
    table[x][y] = valeur;
}

int Grille::getNbLigne() const {
    return nbLignes;
}

bool Grille::ACaseVide(const int x, const int y) const {
    return table[x][y] == Jeton::Vide;
}

void Grille::ChangeCellule(const int x, const int y, Jeton jeton) {
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









