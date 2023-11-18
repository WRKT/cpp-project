#ifndef IGRILLE_H
#define IGRILLE_H

#include <iostream>

class IGrille {
public:
    virtual void InitialiserGrille() = 0;
    virtual bool placerPion(int x, int y, char jeton) = 0;
    virtual void AfficherGrille() const = 0;
    virtual bool estCoupValide(int x, int y, char jeton) const = 0;
    virtual int getNbLignes() const = 0;
    virtual int getNbColonnes() const = 0;
    virtual bool estLigne() const = 0;
    virtual bool estColonne() const = 0;
    virtual bool estDiagonale() const = 0;
    virtual bool estRempli() const = 0;
    virtual ~IGrille() = default;
};

#endif // IGRILLE_H
