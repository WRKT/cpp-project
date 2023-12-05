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
    for (int i = 0; i < getNbLigne(); i++)
    {
        for (int j = 0; j < getNbColonne(); j++)
        {
            if (ACaseVide(i, j))
            {
                return false;
            }
        }
    }
    return true;
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

bool Grille::VerifieLigne(const int sequenceGagnante, const Jeton jeton) const
{
    for (int i = 0; i < getNbLigne(); i++)
    {
        for (int j = 0; j < getNbColonne(); j++)
        {
            Jeton premierJeton = GetCellule(i, j);
            if (premierJeton == jeton)
            {
                if (CompteSequence(i, j, 0, +1) >= sequenceGagnante)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Grille::VerifieColonne(const int sequenceGagnante, const Jeton jeton) const
{
    for (int i = 0; i < getNbLigne(); i++)
    {
        for (int j = 0; j < getNbColonne(); j++)
        {
            Jeton jetonCase = GetCellule(i, j);
            if (jetonCase == jeton)
            {
                if (CompteSequence(i, j, +1, 0) >= sequenceGagnante)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Grille::VerifieDiagonale(const int sequenceGagnante, const Jeton jeton) const
{
    for (int i = 0; i < getNbLigne(); i++)
    {
        for (int j = 0; j < getNbColonne(); j++)
        {
            Jeton jetonCase = GetCellule(i, j);
            if (jetonCase == jeton)
            {
                if (CompteSequence(i, j, -1, +1) >= sequenceGagnante || CompteSequence(i, j, +1, +1) >= sequenceGagnante)
                {
                    return true;
                }
            }
        }
    }
    return false;
}


int Grille::CompteSequence(const int ligneDepart, const int colonneDepart, const int dirLigne, const int dirColonne) const
{
    int compteur = 0;
    int ligne = ligneDepart;
    int colonne = colonneDepart;
    Jeton jetonDeDepart = GetCellule(ligneDepart, colonneDepart);

    while (ligne >= 0 && ligne < getNbLigne() &&
           colonne >= 0 && colonne < getNbColonne() &&
           GetCellule(ligne, colonne) == jetonDeDepart)
    {
        compteur++;
        ligne += dirLigne;
        colonne += dirColonne;
    }
    return compteur;
}
