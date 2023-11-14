#include "JoueurOrdinateur.h"


JoueurOrdinateur::JoueurOrdinateur(Jeton jeton) : jeton(jeton) {}

std::string JoueurOrdinateur::ObtenirNom() const {
    return nom;
}
