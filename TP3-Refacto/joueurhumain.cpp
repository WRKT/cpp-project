#include "joueurhumain.h"
#include <iostream>
#include <memory>

JoueurHumain::JoueurHumain(const std::string& nom, Jeton jeton)
    : nom(nom), jeton(jeton) {}


Jeton JoueurHumain::getJeton() const {
    return jeton;
}

