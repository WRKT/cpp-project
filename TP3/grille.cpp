#include "grille.h"
#include <iostream>

Grille::Grille(const int _nbLignes, const int _nbColonnes)
{
    nbLignes = _nbLignes;
    nbColonnes = _nbColonnes;
    table = new char*[nbLignes];

    for(int i = 0; i < nbLignes; i++)
    {
        table[i] = new char[nbColonnes];
    }
    InitialiserGrille();
}

int Grille::GetLignes() const
{
    return nbLignes;
}

int Grille::GetColonnes() const
{
    return nbColonnes;
}

void Grille::InitialiserGrille()
{
    for (int i = 0; i < nbLignes; i++)
    {
        for (int j = 0; j < nbColonnes; j++)
        {
            table[i][j] = ' ' ;
        }
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
};

bool Grille::CaseVide(const int ligne, const int colonne) const
{
    if(ligne > 0 && ligne <= nbLignes && colonne > 0 && colonne <= nbColonnes)
    {
        return this->table[ligne-1][colonne-1] == ' ';
    }
    else
    {
        return false;
    }
}

void Grille::DeposerMorpion(const int ligne, const int colonne, const char jeton)
{
    if (CaseVide(ligne, colonne))
    {
        table[ligne-1][colonne-1] = jeton;
    } else {
        return;
    }
}

bool Grille::EstLigne(const char jeton) const
{
    for (int i = 0; i < nbLignes; i++)
    {
        bool ligneGagnante = true;

        for (int j = 0; j < nbColonnes; j++)
        {
            if (table[i][j] != jeton)
            {
                ligneGagnante = false;
                break;
            }
        }

        if (ligneGagnante)
        {
            return true;
        }
    }
    return false;
}

bool Grille::EstColonne(const char jeton) const
{
    for (int j = 0; j < nbColonnes; j++)
    {
        bool colonneGagnante = true;

        for (int i = 0; i < nbLignes; i++)
        {
            if (table[i][j] != jeton)
            {
                colonneGagnante = false;
                break;
            }
        }

        if (colonneGagnante)
        {
            return true;
        }
    }
    return false;
}

bool Grille::EstDiagonale(const char jeton) const
{
    bool diagonale1 = true;
    bool diagonale2 = true;

    for (int i = 0; i < nbLignes; i++)
    {
        if (table[i][i] != jeton)
        {
            diagonale1 = false;
        }

        if (table[i][nbColonnes - 1 - i] != jeton)
        {
            diagonale2 = false;
        }
    }

    return diagonale1 || diagonale2;
}

bool Grille::EstGagnant(const char jeton) const
{
    return EstLigne(jeton) || EstColonne(jeton) || EstDiagonale(jeton);
}

bool Grille::EstEgalite() const
{
    for (int i = 0; i < nbLignes; i++) {
        for (int j = 0; j < nbColonnes; j++) {
            if (table[i][j] != 'X' && table[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

bool GrillePuissance4::DeposerPuissance4(const int colonne, const char jeton)
{
    int ligne = this->GetLignes() - 1;

    if(colonne > this->GetColonnes())
    {
        return false;
    }

    bool colonnePleine = false;

    while(!colonnePleine && this->table[ligne][colonne-1] != ' ')
    {
        if(ligne == 0)
        {
            colonnePleine = true;
        }
        else
        {
            --ligne;
        }
    }

    if (!colonnePleine)
    {
        this->table[ligne][colonne-1] = jeton;
        return true;
    }
    else
    {
        return false;
    }

}

int GrillePuissance4::CompteJeton(const int ligneDepart, const int colonneDepart, const int dirLigne, const int dirColonne) const
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

bool GrillePuissance4::EstLigne(const char jeton) const
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
}

bool GrillePuissance4::EstColonne(const char jeton) const
{
    for(int i = 0; i < this->GetLignes(); i++)
    {
        for(int j = 0; j < this->GetColonnes(); j++)
        {
            char jetonCase = this->table[i][j];
            if (jetonCase == jeton)
            {
                if(CompteJeton(i, j, +1, 0) >= 4)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool GrillePuissance4::EstDiagonale(const char jeton) const
{
    for(int i = 0; i < this->GetLignes(); i++)
    {
        for(int j = 0; j < this->GetColonnes(); j++)
        {
            char jetonCase = this->table[i][j];
            if (jetonCase == jeton)
            {
                // Diagonale haut droite ----------- Diagonale bas droite
                if(CompteJeton(i, j, -1, +1) >= 4 || CompteJeton(i, j, +1, +1) >= 4)
                {
                    return true;
                }
            }
        }
    }
    return false;
}










