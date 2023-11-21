#include "joueurhumain.h"
#include <iostream>
#include <memory>

JoueurHumain::JoueurHumain(const std::string& nom, Jeton jeton)
    : nom(nom), jeton(jeton) {}

std::string JoueurHumain::getNom() const {
    return nom;
}

Jeton JoueurHumain::getJeton() const {
    return jeton;
}

