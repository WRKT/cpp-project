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
    Position ChoisirCoupMorpion(const std::vector<Position> &CoupsPossibles) override;
    Position ChoisirCoupPuissance4(const std::vector<Position> &CoupsPossibles) override;
    Position ChoisirCoupOthello(const std::vector<Position> &CoupsPossibles) override;
    Position ChoisirCoupDames(const std::vector<Position> &CoupsPossibles) override;
};

#endif // JOUEUR_HUMAIN_H
