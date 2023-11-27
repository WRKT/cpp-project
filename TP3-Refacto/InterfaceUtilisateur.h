#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

#include <iostream>
#include "TypesJeu.h"
#include "affichageconsole.h"
#include <string>

class InterfaceUtilisateur {
public:
    static TypesJeu demanderTypeDeJeu();
    static int demanderModeDeJeu();
    static bool demanderRejouer();
    static std::pair<int, int> demanderCoupMorpion(int tailleGrille);
    static int demanderCoupPuissance4(int nbColonnes);
    static std::pair<int, int> demanderCoupOthello(int tailleGrille);
    static std::string demanderPrenomJoueur(const std::string& prompt);

private:
    AffichageConsole affichage;
};

#endif // INTERFACEUTILISATEUR_H
