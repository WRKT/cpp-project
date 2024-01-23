#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H

#include "AJoueur.h"
#include <string>

class JoueurHumain : public AJoueur
{

public:
    JoueurHumain(const std::string &nom, const Jeton& jeton, const Input& input) : AJoueur(nom, jeton, input){};

private:
    std::vector<Position> CoupsPossibles;
    std::vector<int> CoupsPossible;
    Position ChoisirCoordonnees(const std::vector<Position> &CoupsPossibles) override;
    Position ChoisirColonne(const std::vector<Position> &CoupsPossibles) override;
};

#endif // JOUEUR_HUMAIN_H
