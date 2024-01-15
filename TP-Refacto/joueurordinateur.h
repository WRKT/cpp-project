#ifndef JOUEUR_ORDINATEUR_H
#define JOUEUR_ORDINATEUR_H

#include "AJoueur.h"
#include <string>
#include <random>
#include <chrono>

class JoueurOrdinateur : public AJoueur
{

public:
    JoueurOrdinateur(Jeton jeton) : AJoueur("Ordinateur", jeton), generateur(std::chrono::system_clock::now().time_since_epoch().count()){};

private:
    std::mt19937 generateur;
    std::vector<Position> CoupsPossibles;
    Position ChoisirCoupMorpion(const std::vector<Position> &CoupsPossibles) override;
    Position ChoisirCoupPuissance4(const std::vector<Position> &CoupsPossibles) override;
    Position ChoisirCoupOthello(const std::vector<Position> &CoupsPossibles) override;
    Position ChoisirCoupDames(const std::vector<Position> &CoupsPossibles) override;
};

#endif // JOUEUR_ORDINATEUR_H
