#include "grille.h"
#include <iostream>

Grille::Grille(int nbLignes, int nbColonnes)
    : nbLignes(nbLignes), nbColonnes(nbColonnes), table(nbLignes, std::vector<char>(nbColonnes, '-')) {}

void Grille::InitialiserGrille() {
    for (auto& ligne : table) {
        std::fill(ligne.begin(), ligne.end(), '-');
    }
}

void Grille::AfficherGrille() const
{
    std::cout << std::endl;
    for (int i = 0; i < nbLignes; i++)
    {
        for(int j = 0; j < nbColonnes; j++)
        {
            if (j == 0)
            {
                std::cout << "| " << table[i][j] << " | ";
            }
            else
            {
                std::cout << table[i][j] << " | ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

bool Grille::placerPion(int x, int y, char jeton) {
    if (x >= 0 && x < nbLignes && y >= 0 && y < nbColonnes && table[x][y] == '-') {
        table[x][y] = 'X' ? 'X' : 'O';
        return true;
    }
    return false;
}

bool Grille::estCoupValide(int x, int y, char jeton) const {
    if (x < 0 || x >= nbLignes || y < 0 || y >= nbColonnes) {
        return false;
    }

    return table[x][y] == '-';
}

bool Grille::estLigne() const
{
    for(int i = 0; i < this->GetLignes(); i++)
    {
        for(int j = 0; j < this->GetColonnes(); j++)
        {
            char jetonCase = this->table[i][j];
            if (jetonCase == jeton)
            {
                if(CompteJeton(i, j, 0, +1) >= 4)
                {
                    return true;
                }
            }
        }
    }
    return false;

    return false;
}

bool Grille::estColonne() const
{
    return false;
}

bool Grille::estDiagonale() const
{
    return false;
}

bool Grille::estRempli() const
{
    return false;
}










