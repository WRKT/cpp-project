#ifndef GRILLE_H
#define GRILLE_H

#include "IGrille.h"
#include <vector>

class Grille : public IGrille {

public:
    Grille(const int nbLignes, const int nbColonnes) : nbLignes(nbLignes), nbColonnes(nbColonnes), table(nbLignes, std::vector<Jeton>(nbColonnes, Jeton::Vide)) {};
    void InitialiserGrille() override;
    int getNbLigne() const override;
    int getNbColonne() const override;
    bool ACaseVide(const int x, const int y) const override;
    Jeton GetCellule(const int x, const int y) const override;
    void ChangeCellule(const int x, const int y, Jeton jeton) override;
    bool EstRemplie() const override;

private:
    const int nbLignes, nbColonnes;
    std::vector<std::vector<Jeton>> table;
};

#endif // GRILLE_H
