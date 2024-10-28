#ifndef INPUTCONSOLE_H
#define INPUTCONSOLE_H

#include <string>
#include "Input.h"
#include "TypesJeu.h"

class InputConsole : public Input
{
public:
    TypesJeu demanderTypeDeJeu() const;
    int demanderModeDeJeu() const;
    bool demanderRejouer() const;
    virtual Position demanderCoordonnees() const override;
    virtual int demanderColonne() const override;
    std::string demanderPrenomJoueur(const std::string &) const;
    virtual std::string getString(const std::string &) const override;
    virtual int getInt(const std::string &) const override;

private:
    static void ViderBuffer();
};

#endif // INPUTCONSOLE_H
