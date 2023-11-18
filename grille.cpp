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
    if (GetCellule(x, y) == '-')
    {
        table[x][y] = jeton;
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

int Grille::GetLignes() const
{
    return nbLignes;
}

int Grille::GetColonnes() const
{
    return nbColonnes;
}

int Grille::GetTaille() const
{
    return nbLignes * nbColonnes;
}

char Grille::GetCellule(int ligne, int colonne) const
{
    return table[ligne][colonne];
}

int Grille::CompteJeton(const int ligneDepart, const int colonneDepart, const int dirLigne, const int dirColonne) const
{
    int compteur = 0;
    int ligne = ligneDepart;
    int colonne = colonneDepart;
    while(ligne < this->GetLignes() && colonne < this->GetColonnes() &&
           this->table[ligneDepart][colonneDepart] == this->table[ligne][colonne]
           )
    {
        compteur++;
        ligne = ligne + dirLigne;
        colonne = colonne + dirColonne;
    }
    return compteur;

}

bool Grille::estLigne(const char JETON) const
{
    for(int i = 0; i < nbLignes; i++)
    {
        for(int j = 0; j < nbColonnes; j++)
        {
            if (GetCellule(i,j) == JETON)
            {
                if(CompteJeton(i, j, 0, +1) >= nbLignes)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Grille::estColonne(const char JETON) const
{
    for(int i = 0; i < nbLignes; i++)
    {
        for(int j = 0; j < nbColonnes; j++)
        {
            if (GetCellule(i,j) == JETON)
            {
                if(CompteJeton(i, j, +1, 0) >= nbLignes)
                {
                    return true;
                }
            }
        }
    }
    return false;

}

bool Grille::estDiagonale(const char JETON) const
{
    bool diagonale1 = true;
    bool diagonale2 = true;

    for (int i = 0; i < nbLignes; i++)
    {
        if (table[i][i] != JETON)
        {
            diagonale1 = false;
        }

        if (table[i][nbColonnes - 1 - i] != JETON)
        {
            diagonale2 = false;
        }
    }

    return diagonale1 || diagonale2;

    return false;
}

bool Grille::estRempli() const
{
    return false;
}










