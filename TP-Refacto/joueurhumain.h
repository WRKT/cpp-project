#ifndef JOUEUR_HUMAIN_H
#define JOUEUR_HUMAIN_H

#include "AJoueur.h"
#include "IChoisirCoup.h"
#include <string>
#include <memory>

class JoueurHumain : public IChoisirCoup, public AJoueur
{

public:
    JoueurHumain(const std::string &nom, Jeton jeton) : AJoueur(nom, jeton){};
    bool estHumain() const override { return true; }
    std::pair<int, int> ChoisirCoupMorpion(std::vector<std::pair<int, int>> CoupsPossibles) override;
    int ChoisirCoupPuissance4(std::vector<int> CoupsPossibles) override;
    std::pair<int, int> ChoisirCoupOthello(std::vector<std::pair<int, int>> CoupsPossibles) override;
};

#endif // JOUEUR_HUMAIN_H
