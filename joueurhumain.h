#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H

#include "IJoueur.h"
#include "Jeton.h"
#include <string>
#include <memory>

class JoueurHumain : public IJoueur {
private:
    std::string nom;
    char jeton;

public:
    JoueurHumain(const std::string& nom, char jeton);
    virtual std::string ObtenirNom() const override;
    virtual char getJeton() const override;
    void jouerJeton(IGrille& grille) override;
};

#endif // JOUEUR_HUMAIN_H
