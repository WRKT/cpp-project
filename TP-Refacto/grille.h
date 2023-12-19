#ifndef GRILLE_H
#define GRILLE_H

#include "AGrille.h"
#include <vector>

class Grille : public AGrille
{

public:
    Grille(const int nbLignes, const int nbColonnes) : AGrille(nbLignes, nbColonnes){};
    void InitialiserGrilleOthello() override;
    bool ACaseVide(const int x, const int y) const override;
    Jeton GetCellule(const int x, const int y) const override;
    void ChangeCellule(const int x, const int y, Jeton jeton) override;
    int CompteJetons(Jeton jeton) const override;
    bool EstRemplie() const override;
    bool VerifieLigne(const int sequenceGagnante, const Jeton jeton) const override;
    bool VerifieColonne(const int sequenceGagnante, const Jeton jeton) const override;
    bool VerifieDiagonaleASC(const int sequenceGagnante, const Jeton jeton) const override;
    bool VerifieDiagonaleDESC(const int sequenceGagnante, const Jeton jeton) const override;
    int CompteSequence(const std::vector<Jeton> &vecteur, Jeton jeton) const;
    std::vector<Jeton> GetLigne(int x, int y) const override;
    std::vector<Jeton> GetColonne(int x, int y) const override;
    std::vector<Jeton> GetDiagonaleASC(int x, int y) const override;
    std::vector<Jeton> GetDiagonaleDESC(int x, int y) const override;
};

#endif // GRILLE_H
