#ifndef JOUEUR_ORDINATEUR_H
#define JOUEUR_ORDINATEUR_H

#include "IJoueur.h"
#include "IGrille.h"
#include <string>
#include <random>

class JoueurOrdinateur : public IJoueur {
private:
    std::string nom = "Ordinateur";
    char jeton;
    std::mt19937 generateur;
    std::pair<int, int> choisirCoup(IGrille& grille);

public:
    JoueurOrdinateur(char jeton);
    virtual char getJeton() const override;
    virtual std::string ObtenirNom() const override;
    virtual void jouerJeton(IGrille& grille) override;
};

#endif // JOUEUR_ORDINATEUR_H
