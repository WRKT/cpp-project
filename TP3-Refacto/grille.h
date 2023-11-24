#ifndef GRILLE_H
#define GRILLE_H

#include "IGrille.h"
#include <vector>

class Grille : public IGrille {
private:
    const int nbLignes, nbColonnes;
    std::vector<std::vector<Jeton>> table;

public:
    Grille(const int nbLignes, const int nbColonnes) : nbLignes(nbLignes), nbColonnes(nbColonnes), table(nbLignes, std::vector<Jeton>(nbColonnes, Jeton::Vide)) {};
    void InitialiserGrille() override;
    void AfficherGrille() const override;
    bool EstRemplie() const override;
    bool ACaseVide(const int x, const int y) const override;
    int getNbLigne() const override;
    int getNbColonne() const override;
    Jeton GetCellule(const int x, const int y) const override;
    void ChangeCellule(const int x, const int y, Jeton jeton) override;

};

#endif // GRILLE_H
