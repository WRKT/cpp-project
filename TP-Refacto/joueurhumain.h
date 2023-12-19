#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H

#include "AJoueur.h"
#include <string>

class JoueurHumain : public AJoueur
{

public:
    JoueurHumain(const std::string &nom, const Jeton& jeton) : AJoueur(nom, jeton){};

private:
    std::vector<std::pair<int, int>> CoupsPossibles;
    std::vector<int> CoupsPossible;
    std::pair<int, int> ChoisirCoupMorpion(const std::vector<std::pair<int, int>> &CoupsPossibles) override;
    std::pair<int, int> ChoisirCoupPuissance4(const std::vector<std::pair<int, int>> &CoupsPossibles) override;
    std::pair<int, int> ChoisirCoupOthello(const std::vector<std::pair<int, int>> &CoupsPossibles) override;
};

#endif // JOUEUR_HUMAIN_H
