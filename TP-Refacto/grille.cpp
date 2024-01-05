#include "grille.h"
#include "jeton.h"

Jeton Grille::GetCellule(const int x, const int y) const
{
    return table[x][y];
}

void Grille::InitialiserGrilleOthello()
{
    int centreX = getNbLignes() / 2 - 1;
    int centreY = getNbColonnes() / 2 - 1;

    Jeton positions[2][2] = {
        {Jeton::X, Jeton::O},
        {Jeton::O, Jeton::X}};

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            ChangeCellule(centreX + i, centreY + j, positions[i][j]);
        }
    }
}

void Grille::InitialiserGrilleDame()
{

    for (int i = 0; i < getNbLignes(); ++i)
    {
        for (int j = 0; j < getNbColonnes(); ++j)
        {
            ChangeCellule(i, j, Jeton::Vide);
        }
    }

    for (int i = 0; i < getNbLignes(); ++i)
    {
        for (int j = 0; j < getNbColonnes(); ++j)
        {

            if ((i % 2 == 0 && j % 2 == 1) || (i % 2 == 1 && j % 2 == 0))
            {
                if (i < 3)
                {

                    ChangeCellule(i, j, Jeton::X);
                }
                else if (i >= getNbLignes() - 3)
                {

                    ChangeCellule(i, j, Jeton::O);
                }

            }
        }
    }
}


bool Grille::ACaseVide(const int x, const int y) const
{
    return table[x][y] == Jeton::Vide;
}

void Grille::ChangeCellule(const int x, const int y, const Jeton& jeton)
{
    table[x][y] = jeton;
}

bool Grille::EstRemplie() const
{
    for (int i = 0; i < getNbLignes(); i++)
    {
        for (int j = 0; j < getNbColonnes(); j++)
        {
            if (ACaseVide(i, j))
            {
                return false;
            }
        }
    }
    return true;
}

int Grille::CompteJetons(const Jeton& jeton) const
{
    int nbJeton = 0;
    for (int i = 0; i < getNbColonnes(); ++i)
    {
        for (int j = 0; j < getNbLignes(); ++j)
        {
            if (table[i][j] == jeton)
            {
                nbJeton++;
            }
        }
    }
    return nbJeton;
}


std::vector<Jeton> Grille::GetLigne(int x, int y) const
{
    std::vector<Jeton> ligne;
    for (int i = 0; i < getNbColonnes(); ++i)
    {
        ligne.push_back(GetCellule(x, i));
    }
    return ligne;
}

std::vector<Jeton> Grille::GetColonne(int x, int y) const
{
    std::vector<Jeton> colonne;

    for (int i = 0; i < getNbLignes(); ++i)
    {
        colonne.push_back(GetCellule(i, y));
    }
    return colonne;
}

std::vector<Jeton> Grille::GetDiagonaleDESC(int x, int y) const
{
    std::vector<Jeton> diagonaleDESC;

    for (int i = 0; x - i >= 0 && y - i >= 0; ++i)
    {
        diagonaleDESC.push_back(GetCellule(x - i, y - i));
    }

    for (int i = 1; x + i < getNbLignes() && y + i < getNbColonnes(); ++i)
    {
        diagonaleDESC.push_back(GetCellule(x + i, y + i));
    }

    return diagonaleDESC;
}

std::vector<Jeton> Grille::GetDiagonaleASC(int x, int y) const
{
    std::vector<Jeton> diagonaleASC;

    for (int i = 0; x + i < getNbLignes() && y - i >= 0; ++i)
    {
        diagonaleASC.push_back(GetCellule(x + i, y - i));
    }

    for (int i = 1; x - i >= 0 && y + i < getNbColonnes(); ++i)
    {
        diagonaleASC.push_back(GetCellule(x - i, y + i));
    }

    return diagonaleASC;
}
bool Grille::VerifieLigne(const int sequenceGagnante, const Jeton& jeton) const
{
    for (int i = 0; i < getNbLignes(); ++i)
    {
        std::vector<Jeton> ligne = GetLigne(i, 0);
        if (CompteSequence(ligne, jeton) >= sequenceGagnante)
            return true;
    }
    return false;
}

bool Grille::VerifieColonne(const int sequenceGagnante, const Jeton& jeton) const
{
    for (int j = 0; j < getNbColonnes(); ++j)
    {
        std::vector<Jeton> colonne = GetColonne(0, j);
        if (CompteSequence(colonne, jeton) >= sequenceGagnante)
            return true;
    }
    return false;
}

bool Grille::VerifieDiagonaleASC(const int sequenceGagnante, const Jeton& jeton) const
{
    for (int i = 0; i < getNbLignes(); ++i)
    {
        for (int j = 0; j < getNbColonnes(); ++j)
        {
            std::vector<Jeton> diagonaleASC = GetDiagonaleASC(i, j);
            if (CompteSequence(diagonaleASC, jeton) >= sequenceGagnante)
                return true;
        }
    }
    return false;
}

bool Grille::VerifieDiagonaleDESC(const int sequenceGagnante, const Jeton& jeton) const
{
    for (int i = 0; i < getNbLignes(); ++i)
    {
        for (int j = 0; j < getNbColonnes(); ++j)
        {
            std::vector<Jeton> diagonaleDESC = GetDiagonaleDESC(i, j);
            if (CompteSequence(diagonaleDESC, jeton) >= sequenceGagnante)
                return true;
        }
    }
    return false;
}

int Grille::CompteSequence(const std::vector<Jeton> &vecteur, const Jeton& jeton) const
{
    int nbJetons = 0;
    int maxSequence = 0;

    for (const Jeton &token : vecteur)
    {
        if (token == jeton)
        {
            nbJetons++;
            if (nbJetons > maxSequence)
            {
                maxSequence = nbJetons;
            }
        }
        else
        {
            nbJetons = 0;
        }
    }
    return maxSequence;
}
