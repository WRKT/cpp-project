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
    virtual void InitialiserGrille() override;
    virtual void AfficherGrille() const override;
};

#endif // GRILLE_H
