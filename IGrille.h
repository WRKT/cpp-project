#ifndef IGRILLE_H
#define IGRILLE_H

#include <iostream>
#include "jeton.h"

class IGrille {
public:
    virtual void InitialiserGrille() = 0;
    virtual void AfficherGrille() const = 0;
    virtual bool EstRemplie() const = 0;
    virtual int getNbLigne() const = 0;
    virtual bool ACaseVide(int x, int y) const = 0;
    virtual int getNbColonne() const = 0;
    virtual Jeton GetCellule(int x, int y) const = 0;
    virtual void ChangeCellule(int x, int y, Jeton jeton) = 0;
    virtual ~IGrille() = default;
};

#endif // IGRILLE_H