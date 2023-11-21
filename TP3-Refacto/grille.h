#ifndef GRILLE_H
#define GRILLE_H

#include "IGrille.h"
#include <vector>

class Grille : public IGrille {
private:
    int nbLignes, nbColonnes;
    std::vector<std::vector<Jeton>> table;

public:
    Grille(int nbLignes, int nbColonnes);
    void InitialiserGrille() override;
    void AfficherGrille() const override;
    bool EstRemplie() const override;
    bool ACaseVide(int x, int y) const override;
    int getNbLigne() const override;
    int getNbColonne() const override;
    Jeton GetCellule(int x, int y) const override;
    void ChangeCellule(int x, int y, Jeton jeton) override;

};

#endif // GRILLE_H
