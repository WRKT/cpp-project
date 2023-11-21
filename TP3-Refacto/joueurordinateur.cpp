#include "joueurordinateur.h"
#include <chrono>

JoueurOrdinateur::JoueurOrdinateur(Jeton jeton) : jeton(jeton), generateur(std::chrono::system_clock::now().time_since_epoch().count()) {}

std::string JoueurOrdinateur::getNom() const {
    return nom;
}

Jeton JoueurOrdinateur::getJeton() const {
    return jeton;
}
