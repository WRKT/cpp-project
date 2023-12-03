#ifndef IGRILLE_H
#define IGRILLE_H

#include "jeton.h"

class IGrille
{
public:
    virtual void InitialiserGrille() = 0;
    virtual int getNbLigne() const = 0;
    virtual int getNbColonne() const = 0;
    virtual Jeton GetCellule(const int x, const int y) const = 0;
    virtual void ChangeCellule(const int x, const int y, Jeton jeton) = 0;
    virtual bool ACaseVide(const int, const int) const = 0;
    virtual int CompteJetons(Jeton jeton) const = 0;
    virtual bool EstRemplie() const = 0;
    virtual ~IGrille() = default;
};

#endif // IGRILLE_H
