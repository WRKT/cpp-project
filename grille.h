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
    bool placerPion(int x, int y, char jeton) override;
    bool estCoupValide(int x, int y, char jeton) const override;
    int getNbLignes() const override;
    int getNbColonnes() const override;
    bool estLigne() const override;
    bool estColonne() const override;
    bool estDiagonale() const override;
    bool estRempli() const override;
};

#endif // GRILLE_H
