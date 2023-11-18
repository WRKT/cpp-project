#ifndef IGRILLE_H
#define IGRILLE_H

#include <iostream>
#include "Jeton.h"

class IGrille {
public:
    virtual void InitialiserGrille() = 0;
    virtual bool placerPion(int x, int y, char jeton) = 0;
    virtual void AfficherGrille() const = 0;
    virtual bool estCoupValide(int x, int y, char jeton) const = 0;
    virtual int getTaille() const = 0;
    virtual ~IGrille() = default;
};

#endif // IGRILLE_H
