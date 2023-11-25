#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

#include <iostream>
#include "TypesJeu.h"

class InterfaceUtilisateur {
public:
    TypesJeu demanderTypeDeJeu();
    int demanderModeDeJeu();
    bool demanderRejouer();
    std::pair<int, int> choisirCoup(); // à voir pour intégrer une classe Position

    std::string demanderPrenomJoueur(const std::string& prompt);
};

#endif // INTERFACEUTILISATEUR_H
