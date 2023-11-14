#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H

#include "IJoueur.h"
#include "Jeton.h"
#include <string>
#include <memory>

class JoueurHumain : public IJoueur {
private:
    std::string nom;
     Jeton jeton;

public:
    JoueurHumain(const std::string& nom, Jeton jeton);
    virtual std::string ObtenirNom() const override;
};

#endif // JOUEUR_HUMAIN_H
