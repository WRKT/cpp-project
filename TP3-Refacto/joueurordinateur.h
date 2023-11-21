#ifndef JOUEUR_ORDINATEUR_H
#define JOUEUR_ORDINATEUR_H

#include "IJoueur.h"
#include <string>
#include "jeton.h"
#include "IGrille.h"
#include <random>

class JoueurOrdinateur : public IJoueur {
private:
    std::string nom = "Ordinateur";
    Jeton jeton;
    std::mt19937 generateur;
    std::pair<int, int> choisirCoup(IGrille& grille);

public:
    JoueurOrdinateur(Jeton jeton);
    Jeton getJeton() const override;
    std::string getNom() const override;
    bool estHumain() const override { return false; }

};

#endif // JOUEUR_ORDINATEUR_H
