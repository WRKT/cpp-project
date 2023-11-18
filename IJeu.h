#ifndef IJEU_H
#define IJEU_H

#include "jeton.h"

class IJeu {
public:
    virtual void Jouer() = 0;
    virtual void TourHumain() = 0;
    virtual void TourOrdi() = 0;
    virtual bool AGagne() const = 0;
    virtual void PlacerJeton(int ligne, int colonne, Jeton jeton) = 0;
    virtual bool PartieFinie() const = 0;
    virtual ~IJeu() = default;
};

#endif // IJEU_H
