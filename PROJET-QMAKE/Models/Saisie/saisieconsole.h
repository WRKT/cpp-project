#ifndef INPUTCONSOLE_H
#define INPUTCONSOLE_H

#include <string>
#include "Models/Jeux/TypesJeu.h"

class SaisieConsole
{
public:
    static TypesJeu demanderTypeDeJeu();
    static int demanderModeDeJeu();
    static bool demanderRejouer();
    static std::pair<int, int> demanderCordonnee();
    static int demanderColonne();
    static std::string demanderPrenomJoueur(const std::string&);
    static std::string getString(const std::string&);
    static int getInt(const std::string&);

private:
    static void ViderBuffer();
};

#endif // INPUTCONSOLE_H
