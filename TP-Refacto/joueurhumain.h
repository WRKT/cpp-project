#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H

#include "AJoueur.h"
#include <string>
#include <memory>

class JoueurHumain : public AJoueur {

public:
    JoueurHumain(const std::string& nom, Jeton jeton) : AJoueur(nom, jeton) {};
    bool estHumain() const override { return true; }
};

#endif // JOUEUR_HUMAIN_H
