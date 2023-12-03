#include "grille.h"
#include <iostream>
#include "jeton.h"

void Grille::InitialiserGrille()
{
    for (auto &ligne : table)
    {
        std::fill(ligne.begin(), ligne.end(), Jeton::Vide);
    }
}

int Grille::getNbColonne() const
{
    return nbColonnes;
}

Jeton Grille::GetCellule(const int x, const int y) const
{
    return table[x][y];
}

int Grille::getNbLigne() const
{
    return nbLignes;
}

bool Grille::ACaseVide(const int x, const int y) const
{
    return table[x][y] == Jeton::Vide;
}

void Grille::ChangeCellule(const int x, const int y, Jeton jeton)
{
    table[x][y] = jeton;
}

bool Grille::EstRemplie() const
{
    for (int i = 0; i < getNbColonne(); ++i)
    {
        for (int j = 0; j < getNbLigne(); ++j)
        {
            if (ACaseVide(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

std::vector<Jeton> Grille::GetLigne(const int ligne) const
{
    std::vector<Jeton> jetons;
    for (int i = 0; i < getNbColonne(); ++i)
    {
        jetons.push_back(GetCellule(ligne, i));
    }
    return jetons;
}

std::vector<Jeton> Grille::GetColonne(const int colonne) const
{
    std::vector<Jeton> jetons;
    for (int i = 0; i < getNbLigne(); ++i)
    {
        jetons.push_back(GetCellule(i, colonne));
    }
    return jetons;
}

std::vector<Jeton> Grille::GetDiagonale(const int sens) const
{
    std::vector<Jeton> jetons;
    if (sens == 1) // Diagonale principale
    {
        for (int i = 0; i < getNbLigne(); ++i)
        {
            jetons.push_back(GetCellule(i, i));
        }
    }
    else // Diagonale secondaire
    {
        for (int i = 0; i < getNbLigne(); ++i)
        {
            jetons.push_back(GetCellule(i, getNbLigne() - i - 1));
        }
    }
    return jetons;
}

int Grille::CompteJetons(Jeton jeton) const
{
    int nbJeton = 0;
    for (int i = 0; i < getNbColonne(); ++i)
    {
        for (int j = 0; j < getNbLigne(); ++j)
        {
            if (table[i][j] == jeton)
            {
                ++nbJeton;
            }
        }
    }
    return nbJeton;
}
