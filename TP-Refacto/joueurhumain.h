#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H

#include "AJoueur.h"
#include <string>
#include <memory>

class JoueurHumain : public AJoueur
{

public:
    JoueurHumain(const std::string &nom, Jeton jeton) : AJoueur(nom, jeton){};
    std::pair<int, int> ChoisirCoupMorpion(std::vector<std::pair<int, int>> CoupsPossibles) override;
    std::pair<int, int> ChoisirCoupPuissance4(std::vector<std::pair<int, int>> CoupsPossibles) override;
    std::pair<int, int> ChoisirCoupOthello(std::vector<std::pair<int, int>> CoupsPossibles) override;

private:
    std::vector<std::pair<int, int>> CoupsPossibles;
    std::vector<int> CoupsPossible;
};

#endif // JOUEUR_HUMAIN_H
