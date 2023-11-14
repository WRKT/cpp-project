
#include "JoueurHumain.h"
#include <iostream>
#include <memory>

JoueurHumain::JoueurHumain(const std::string& nom, Jeton jeton)
    : nom(nom), jeton(jeton) {}

std::string JoueurHumain::ObtenirNom() const {
    return nom;
}
