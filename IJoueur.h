#ifndef IJOUEUR_H
#define IJOUEUR_H

#include <iostream>
#include "IGrille.h"

class IJoueur {
public:
    virtual std::string ObtenirNom() const = 0;
    virtual char getJeton() const = 0;
    virtual void jouerJeton(IGrille& grille) = 0;
    virtual ~IJoueur() = default;
};

#endif // IJOUEUR_H
