#ifndef INPUTCONSOLE_H
#define INPUTCONSOLE_H

#include <string>
#include "TypesJeu.h"


class InputConsole {
public:;
    static TypesJeu demanderTypeDeJeu();
    static int demanderModeDeJeu();
    static bool demanderRejouer();
    static std::pair<int, int> demanderCoupMorpion(int tailleGrille);
    static int demanderCoupPuissance4(int nbColonnes);
    static std::pair<int, int> demanderCoupOthello(int tailleGrille);
    static std::string demanderPrenomJoueur(const std::string& prompt);
    static std::string getString(const std::string& message);
    static int getInt(const std::string&);

private:
    static void ViderBuffer();
};

#endif // INPUTCONSOLE_H
