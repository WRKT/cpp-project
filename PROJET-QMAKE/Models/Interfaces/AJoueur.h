#ifndef AJoueur_H
#define AJoueur_H

#include "Models/Grille/jeton.h"
#include <string>
#include "IChoisirCoup.h"

class AJoueur : public IChoisirCoup
{

public:
    AJoueur(const std::string &nom, const Jeton &jeton) : nom(nom), jeton(jeton) {}
    std::string getNom() const { return nom; }
    Jeton getJeton() const { return jeton; }
    std::string getInformations() const { return nom + "(" + static_cast<char>(jeton) + ")"; };
    ~AJoueur() = default;

protected:
    const std::string nom;
    const Jeton jeton;
};

#endif // AJoueur_H
