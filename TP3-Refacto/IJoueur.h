#ifndef IJOUEUR_H
#define IJOUEUR_H

#include <iostream>
#include "jeton.h"
#include <string>

class IJoueur{

public:
    std::string getNom() { return nom; }
    virtual Jeton getJeton() const = 0;
    virtual ~IJoueur() = default;
    virtual bool estHumain() const = 0;
private:
    const std::string nom;
};



#endif // IJOUEUR_H

