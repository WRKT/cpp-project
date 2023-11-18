#ifndef GRILLE_H
#define GRILLE_H

#include "IGrille.h"
#include <vector>
#include "Jeton.h"

class Grille : public IGrille {
private:
    int nbLignes, nbColonnes;
    std::vector<std::vector<char>> table;

public:
    Grille(int nbLignes, int nbColonnes);
    virtual void InitialiserGrille() override;
    virtual void AfficherGrille() const override;
    virtual bool placerPion(int x, int y, char jeton) override;
    virtual int getTaille() const override;
    bool estCoupValide(int x, int y, char jeton) const override;
};

#endif // GRILLE_H
