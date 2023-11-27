#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

#include <iostream>
#include <memory>
#include "IAffichage.h"
#include "TypesJeu.h"
#include "ISaisie.h"

class InterfaceUtilisateur {
public:
    TypesJeu demanderTypeDeJeu();
    int demanderModeDeJeu();
    bool demanderRejouer();
    std::pair<int, int> choisirCoup();
    std::string demanderPrenomJoueur(const std::string& prompt);

private:
    std::unique_ptr<ISaisie> modeSaisie;
    std::unique_ptr<IAffichage> modeAffichage;
};

#endif // INTERFACEUTILISATEUR_H
