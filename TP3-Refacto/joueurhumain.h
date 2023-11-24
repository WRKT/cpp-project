#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H

#include "IJoueur.h"
#include <string>
#include <memory>

class JoueurHumain : public IJoueur {

public:
    JoueurHumain(const std::string& nom, Jeton jeton) : IJoueur(nom, jeton) {};
    bool estHumain() const override { return true; }
};

#endif // JOUEUR_HUMAIN_H
