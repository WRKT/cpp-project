#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H

#include "AJoueur.h"
#include <string>
#include <memory>

class JoueurHumain : public AJoueur
{

public:
    JoueurHumain(const std::string &nom, Jeton jeton) : AJoueur(nom, jeton){};
    bool estHumain() const override { return true; }
    std::pair<int, int> ChoisirCoupMorpion(std::vector<std::pair<int, int>> CoupsPossible);
    int ChoisirCoupPuissance4(std::vector<std::pair<int, int>> CoupsPossible);
    std::pair<int, int> ChoisirCoupOthello(std::vector<std::pair<int, int>> CoupsPossible);
};

#endif // JOUEUR_HUMAIN_H
