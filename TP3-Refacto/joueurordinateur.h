#ifndef JOUEUR_ORDINATEUR_H
#define JOUEUR_ORDINATEUR_H

#include "IJoueur.h"
#include <string>
#include "jeton.h"
#include <random>
#include <chrono>

class JoueurOrdinateur : public IJoueur {

public:
    JoueurOrdinateur(Jeton jeton) : IJoueur("Ordinateur", jeton), generateur(std::chrono::system_clock::now().time_since_epoch().count()) {};
    bool estHumain() const override { return false; }

private:
    std::mt19937 generateur;
};

#endif // JOUEUR_ORDINATEUR_H
