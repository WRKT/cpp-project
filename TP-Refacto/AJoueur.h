#ifndef AJoueur_H
#define AJoueur_H

#include <iostream>
#include "jeton.h"
#include <string>

class AJoueur
{

public:
    AJoueur(const std::string &nom, const Jeton &jeton) : nom(nom), jeton(jeton) {}
    std::string getNom() const { return nom; }
    Jeton getJeton() const { return jeton; }
    std::string getInformations() const { return nom + "(" + static_cast<char>(jeton) + ")"; };
    virtual bool estHumain() const = 0;
    ~AJoueur() = default;

protected:
    const std::string nom;
    const Jeton jeton;
};

#endif // AJoueur_H
