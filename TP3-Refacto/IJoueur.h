#ifndef IJOUEUR_H
#define IJOUEUR_H

#include <iostream>
#include "jeton.h"

class IJoueur {
public:
    virtual std::string getNom() const = 0;
    virtual Jeton getJeton() const = 0;
    virtual ~IJoueur() = default;
    virtual bool estHumain() const = 0;
};

#endif // IJOUEUR_H
