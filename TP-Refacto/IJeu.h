#ifndef IJEU_H
#define IJEU_H

#include <vector>
#include "coordonnees.h"

class IJeu
{
public:
    virtual void Jouer() = 0;
    virtual void Tour() = 0;
    virtual std::vector<Position> CoupsPossibles() = 0;
    virtual bool AGagne() const = 0;
    virtual bool PartieFinie() const = 0;
    virtual void AfficherResultat() const = 0;
    virtual ~IJeu() = default;
};

#endif // IJEU_H
