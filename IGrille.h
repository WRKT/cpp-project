#ifndef IGRILLE_H
#define IGRILLE_H

#include <iostream>

class IGrille {
public:
    virtual void InitialiserGrille() = 0;
    virtual bool placerPion(int x, int y, char jeton) = 0;
    virtual void AfficherGrille() const = 0;
    virtual bool estCoupValide(int x, int y, char jeton) const = 0;
    virtual int GetLignes() const = 0;
    virtual int GetColonnes() const = 0;
    virtual int GetTaille() const = 0;
    virtual char GetCellule(int ligne, int colonne) const = 0;
    virtual int CompteJeton(const int ligneDepart, const int colonneDepart, const int dirLigne, const int dirColonne) const = 0;
    virtual bool estLigne(const char JETON) const = 0;
    virtual bool estColonne(const char JETON) const = 0;
    virtual bool estDiagonale(const char JETON) const = 0;
    virtual bool estRempli() const = 0;
    virtual ~IGrille() = default;
};

#endif // IGRILLE_H
