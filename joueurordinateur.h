#ifndef JOUEUR_ORDINATEUR_H
#define JOUEUR_ORDINATEUR_H

#include "IJoueur.h"
#include <string>
#include "Jeton.h"

class JoueurOrdinateur : public IJoueur {
private:
    std::string nom = "Ordinateur";
    Jeton jeton;

public:
    JoueurOrdinateur(Jeton jeton);
    virtual std::string ObtenirNom() const override;
};

#endif // JOUEUR_ORDINATEUR_H
