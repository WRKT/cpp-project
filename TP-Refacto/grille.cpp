#include "grille.h"
#include "jeton.h"

Jeton Grille::GetCellule(const int x, const int y) const
{
    return table[x][y];
}

void Grille::InitialiserGrilleOthello() {
    int centreX = getNbLignes() / 2 - 1;
    int centreY = getNbColonnes() / 2 - 1;

    Jeton positions[2][2] = {
        {Jeton::X, Jeton::O},
        {Jeton::O, Jeton::X}
    };

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ChangeCellule(centreX + i, centreY + j, positions[i][j]);
        }
    }
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

int Grille::CompteJetons(Jeton jeton) const
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

bool Grille::VerifieLigne(const int sequenceGagnante, const Jeton jeton) const
{
    for (int i = 0; i < getNbLignes(); i++)
    {
        for (int j = 0; j < getNbColonnes(); j++)
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
    for (int i = 0; i < getNbLignes(); i++)
    {
        for (int j = 0; j < getNbColonnes(); j++)
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
    for (int i = 0; i < getNbLignes(); i++)
    {
        for (int j = 0; j < getNbColonnes(); j++)
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

    while (ligne >= 0 && ligne < getNbLignes() &&
           colonne >= 0 && colonne < getNbColonnes() &&
           GetCellule(ligne, colonne) == jetonDeDepart)
    {
        compteur++;
        ligne += dirLigne;
        colonne += dirColonne;
    }
    return compteur;
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
