#ifndef AJoueur_H
#define AJoueur_H

#include "jeton.h"
#include <string>
#include "IChoisirCoup.h"
#include "Input.h"

class AJoueur : public IChoisirCoup
{

public:
    AJoueur(const std::string &nom, const Jeton &jeton, const Input& input) : nom(nom), jeton(jeton), input(input) {}
    std::string getNom() const { return nom; }
    Jeton getJeton() const { return jeton; }
    std::string getInformations() const { return nom + "(" + static_cast<char>(jeton) + ")"; };
    void AttribuerListeJeton(const std::vector<Jeton> liste) { listeJeton = liste; }
    std::vector<Jeton> GetListeJeton() const { return listeJeton; }

protected:
    const std::string nom;
    const Jeton jeton;
    std::vector<Jeton> listeJeton;
    const Input& input;
};

#endif // AJoueur_H
