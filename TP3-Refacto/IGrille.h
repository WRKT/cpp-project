#ifndef IGRILLE_H
#define IGRILLE_H

#include <iostream>
#include "jeton.h"

class IGrille {
public:
    virtual void InitialiserGrille() = 0;
    virtual int getNbLigne() const = 0;
    virtual int getNbColonne() const = 0;
    virtual bool ACaseVide(const int, const int) const = 0;
    virtual Jeton GetCellule(const int, const int) const = 0;
    virtual void ChangeCellule(const int, const int, Jeton) = 0;
    virtual bool EstRemplie() const = 0;
    virtual ~IGrille() = default;
};

#endif // IGRILLE_H
