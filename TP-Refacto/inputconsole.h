#ifndef INPUTCONSOLE_H
#define INPUTCONSOLE_H

#include <string>
#include "TypesJeu.h"
#include "coordonnees.h"

class InputConsole
{
public:
    static TypesJeu demanderTypeDeJeu();
    static int demanderModeDeJeu();
    static bool demanderRejouer();
    static Position demanderCordonnee();
    static int demanderColonne();
    static std::string demanderPrenomJoueur(const std::string&);
    static std::string getString(const std::string&);
    static int getInt(const std::string&);

private:
    static void ViderBuffer();
};

#endif // INPUTCONSOLE_H
