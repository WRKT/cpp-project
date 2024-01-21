#ifndef AJoueur_H
#define AJoueur_H

#include <string>
#include "jeton.h"
#include "IChoisirCoup.h"

class AJoueur : public IChoisirCoup
{

public:
    AJoueur(const std::string &nom, const Jeton &jeton) : nom(nom), jeton(jeton) {}
    std::string getNom() const { return nom; }
    Jeton getJeton() const { return jeton; }
    std::string getInformations() const { return nom + "(" + static_cast<char>(jeton) + ")"; };
    void AttribuerListeJeton(const std::vector<Jeton> liste) { listeJeton = liste; }
    std::vector<Jeton> GetListeJeton() const { return listeJeton; }
    ~AJoueur() = default;

protected:
    const std::string nom;
    const Jeton jeton;
    std::vector<Jeton> listeJeton;
};

#endif // AJoueur_H
