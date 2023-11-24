#ifndef IJOUEUR_H
#define IJOUEUR_H

#include <iostream>
#include "jeton.h"
#include <string>

class IJoueur{

public:
    IJoueur(const std::string& nom, const Jeton& jeton) : nom(nom), jeton(jeton) {}
    std::string getNom() const { return nom; }
    Jeton getJeton() const { return jeton; }
    virtual ~IJoueur() = default;
    virtual bool estHumain() const = 0;

protected:
    const std::string nom;
    const Jeton jeton;
};



#endif // IJOUEUR_H

