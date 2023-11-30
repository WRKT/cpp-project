#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

#include <iostream>
#include <memory>
#include "IAffichage.h"
#include "TypesJeu.h"
#include "affichageconsole.h"
#include <string>
#include "ISaisie.h"

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
    std::unique_ptr<ISaisie> modeSaisie;
    std::unique_ptr<IAffichage> modeAffichage;
};

#endif // INTERFACEUTILISATEUR_H
