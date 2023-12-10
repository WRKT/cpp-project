#ifndef AGRILLE_H
#define AGRILLE_H

#include "IGrilleInit.h"
#include "jeton.h"
#include <vector>

class AGrille : public IGrilleInit
{
public:
    virtual int getNbLigne() const = 0;
    virtual int getNbColonne() const = 0;
    virtual Jeton GetCellule(const int x, const int y) const = 0;
    virtual void ChangeCellule(const int x, const int y, Jeton jeton) = 0;
    virtual bool ACaseVide(const int, const int) const = 0;
    virtual int CompteJetons(Jeton jeton) const = 0;
    virtual bool EstRemplie() const = 0;
    virtual bool VerifieLigne(const int nbJetons, const Jeton jeton) const = 0;
    virtual bool VerifieColonne(const int nbJetons, const Jeton jeton) const = 0;
    virtual bool VerifieDiagonale(const int nbJetons, const Jeton jeton) const = 0;

    virtual std::vector<Jeton> GetLigne(int x, int y) const = 0;
    virtual std::vector<Jeton> GetColonne(int x, int y) const = 0;
    virtual std::vector<Jeton> GetDiagonaleASC(int x, int y) const = 0;
    virtual std::vector<Jeton> GetDiagonaleDESC(int x, int y) const = 0;

    virtual ~AGrille() = default;
};

#endif // AGRILLE_H
