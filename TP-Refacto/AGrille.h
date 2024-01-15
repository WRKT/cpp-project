#ifndef AGrille_H
#define AGrille_H

#include "IGrilleInit.h"
#include "jeton.h"
#include <vector>

class AGrille : public IGrilleInit
{
public:
    AGrille(const int nbLignes, const int nbColonnes) : nbLignes(nbLignes), nbColonnes(nbColonnes), table(nbLignes, std::vector<Jeton>(nbColonnes, Jeton::Vide)) {}
    int getNbLignes() const { return nbLignes; }
    int getNbColonnes() const { return nbColonnes; }
    virtual bool EstDansGrille(const int x, const int y) const = 0;
    virtual Jeton GetCellule(const int x, const int y) const = 0;
    virtual void ChangeCellule(const int x, const int y, const Jeton& jeton) = 0;
    virtual bool ACaseVide(const int, const int) const = 0;
    virtual int CompteJetons(const Jeton& jeton) const = 0;
    virtual bool EstRemplie() const = 0;
    virtual bool VerifieLigne(const int nbJetons, const Jeton& jeton) const = 0;
    virtual bool VerifieColonne(const int nbJetons, const Jeton& jeton) const = 0;
    virtual bool VerifieDiagonaleASC(const int nbJetons, const Jeton& jeton) const = 0;
    virtual bool VerifieDiagonaleDESC(const int nbJetons, const Jeton& jeton) const = 0;
    virtual std::vector<Jeton> GetLigne(const int x, const int y) const = 0;
    virtual std::vector<Jeton> GetColonne(const int x, const int y) const = 0;
    virtual std::vector<Jeton> GetDiagonaleASC(const int x, const int y) const = 0;
    virtual std::vector<Jeton> GetDiagonaleDESC(const int x, const int y) const = 0;
    virtual ~AGrille() = default;

protected:
    const int nbLignes, nbColonnes;
    std::vector<std::vector<Jeton>> table;
};

#endif // AGRILLE_H
