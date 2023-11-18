#ifndef GRILLE_H
#define GRILLE_H

#include "IGrille.h"
#include <vector>

class Grille : public IGrille {
private:
    int nbLignes, nbColonnes;
    std::vector<std::vector<char>> table;

public:
    Grille(int nbLignes, int nbColonnes);
    void InitialiserGrille() override;
    void AfficherGrille() const override;
    int GetLignes() const override;
    int GetColonnes() const override;
    int GetTaille() const override;
    char GetCellule(int ligne, int colonne) const override;
    bool estCoupValide(int x, int y, char jeton) const override;
    int CompteJeton(const int ligneDepart, const int colonneDepart, const int dirLigne, const int dirColonne) const override;
    bool placerPion(int x, int y, char jeton) override;
    bool estLigne(const char JETON) const override;
    bool estColonne(const char JETON) const override;
    bool estDiagonale(const char JETON) const override;
    bool estRempli() const override;
};

#endif // GRILLE_H
