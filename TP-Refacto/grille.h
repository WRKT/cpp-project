#ifndef GRILLE_H
#define GRILLE_H

#include "AGrille.h"
#include <vector>

class Grille : public AGrille
{

public:
    Grille(const int nbLignes, const int nbColonnes) : AGrille(nbLignes, nbColonnes){};
    void InitialiserGrilleOthello() override;
    void InitialiserGrilleDame() override;
    bool ACaseVide(const int x, const int y) const override;
    Jeton GetCellule(const int x, const int y) const override;
    void ChangeCellule(const int x, const int y, const Jeton& jeton) override;
    int CompteJetons(const Jeton& jeton) const override;
    bool EstRemplie() const override;
    std::vector<Jeton> GetLigne(const int x, const int y) const override;
    std::vector<Jeton> GetColonne(const int x, const int y) const override;
    std::vector<Jeton> GetDiagonaleASC(const int x, const int y) const override;
    std::vector<Jeton> GetDiagonaleDESC(const int x, const int y) const override;
    bool VerifieLigne(const int sequenceGagnante, const Jeton& jeton) const override;
    bool VerifieColonne(const int sequenceGagnante, const Jeton& jeton) const override;
    bool VerifieDiagonaleASC(const int sequenceGagnante, const Jeton& jeton) const override;
    bool VerifieDiagonaleDESC(const int sequenceGagnante, const Jeton& jeton) const override;
    int CompteSequence(const std::vector<Jeton> &vecteur, const Jeton& jeton) const;
    bool EstDansGrille(const int x, const int y) const;


};

#endif // GRILLE_H
